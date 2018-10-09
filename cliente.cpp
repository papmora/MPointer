#include "cliente.h"
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/sendfile.h>
#include <fstream>
#include "nlohmann/json.hpp"

#define FILE_TO_SEND    "/home/samuel/data.json"

using namespace std;
using json = nlohmann::json;


string SERVER_ADDRESS;
int puerto;

int cliente::conectar() {
    struct sockaddr_in remote_addr;
    int client_socket;
    int fd;
    struct stat file_stat;
    char file_size[256];
    ssize_t len;
    off_t offset;
    int remain_data;
    int sent_bytes = 0;

    //Recibir
    char buffer[BUFSIZ];
    int file_size_e;
    FILE *received_file;

    json j1;
    ifstream i(FILE_TO_SEND);
    i >> j1;

    // remote_addr estructura
    memset(&remote_addr, 0, sizeof(remote_addr));

    // Construye remote_addr
    remote_addr.sin_family = AF_INET;
    inet_pton(AF_INET, "127.0.0.1", &(remote_addr.sin_addr));
    remote_addr.sin_port = htons(puerto);

    // Crea client socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if ( client_socket == -1 ) {
        fprintf(stderr, "Erro al crear socket --> %s\n", strerror(errno));

        exit(EXIT_FAILURE);
    }


    fd = open(FILE_TO_SEND, O_RDONLY);
    if ( fd == -1 ) {
        fprintf(stderr, "Error al abrir archivo --> %s", strerror(errno));

        exit(EXIT_FAILURE);
    }


    // Obtiene el tamaño del archivo
    if ( fstat(fd, &file_stat) < 0 ) {
        fprintf(stderr, "Error al obtener el tamaño del archivo --> %s", strerror(errno));

        exit(EXIT_FAILURE);
    }

    fprintf(stdout, "Tamaño del archivo: \n%d bytes\n", file_stat.st_size);


    // Conecta con servidor
    if ( connect(client_socket, (struct sockaddr *) &remote_addr, sizeof(struct sockaddr)) == -1 ) {
        fprintf(stderr, "Error en conectar --> %s\n", strerror(errno));

        exit(EXIT_FAILURE);
    }
    sprintf(file_size, "%d", file_stat.st_size);

    // Envia el tamaño del archivo
    len = send(client_socket, file_size, sizeof(file_size), 0);
    if ( len < 0 ) {
        fprintf(stderr, "Error en enviar --> %s", strerror(errno));

        exit(EXIT_FAILURE);
    }

    fprintf(stdout, "Se envio %d bytes de tamaño\n", len);

    offset = 0;
    remain_data = file_stat.st_size;
    // Envia data del archivo
    while (((sent_bytes = sendfile(client_socket, fd, &offset, BUFSIZ)) > 0) && (remain_data > 0)) {
        fprintf(stdout, "1. Se envio %d bytes de la data del archivo, offset es : %d y resto  de data = %d\n",
                sent_bytes, offset, remain_data);
        remain_data -= sent_bytes;
        fprintf(stdout, "2. Se envio %d bytes de la data del archivo, offset es : %d y resto de data = %d\n",
                sent_bytes, offset, remain_data);
    }

    //Recibir
    if ( j1["byte"] != 0 ) {
        recv(client_socket, buffer, BUFSIZ, 0);
        file_size_e = atoi(buffer);

        if ( file_size_e != 0 ) {
            received_file = fopen(FILE_TO_SEND, "w");
            if ( received_file == nullptr ) {
                fprintf(stderr, "Error al abrir el archivo --> %s\n", strerror(errno));

                exit(EXIT_FAILURE);
            }
            remain_data = file_size_e;

            recv(client_socket, buffer, BUFSIZ, 0);
            len = remain_data;
            while ((len > 0) && (remain_data > 0)) {
                fwrite(buffer, sizeof(char), len, received_file);
                remain_data -= len;
                fprintf(stdout, "Recive %d bytes y se esperan :- %d bytes\n", len, remain_data);
            }
            fclose(received_file);

            ifstream x(FILE_TO_SEND);
            x >> j1;
            return j1["id"];
        }
    }


    close(client_socket);
    return 0;
}

void cliente::setServer(string g){
    SERVER_ADDRESS = g;
}

void cliente::setPuerto(int s){
    puerto = s;
}
