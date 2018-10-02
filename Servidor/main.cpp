#include <iostream>
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
#include "nlohmann/json.hpp"
#include <fstream>
#include <iomanip>
#include "ListaEnlazadaServidor.h"

#define PORT_NUMBER     5000
#define SERVER_ADDRESS  "localhost"
#define FILENAME        "/home/samuel/CLionProjects/s2/data.json"

using namespace std;
using json = nlohmann::json;

typedef ListaEnlazada LE;
typedef ListaEnlazada::pagina pag;

int main() {
    int server_socket;
    struct sockaddr_in server_addr;
    char buffer[BUFSIZ];
    int file_size;
    FILE *received_file;
    int remain_data = 0;
    ssize_t len;
    int peer_socket;
    socklen_t sock_len;
    struct sockaddr_in peer_addr;

    //enviar
    int fd;
    struct stat file_stat;
    char file_size_e[256];;
    off_t offset;
    int sent_bytes = 0;

    json j1 = {{"byte",  0},
               {"id",    0},
               {"value", 0}};
    size_t bytes = 12;
    static LE lista;
    int contador = 0;
    int ID = 0;

    cout << "Cantidad de bytes a almacenar" << endl;
    cin >> bytes;
    int *ptr = (int *) malloc(bytes);
    if ( !ptr ) {
        cout << "Memory Allocation Failed" << endl;
        exit(1);
    }
    if ( contador == 0 ) {
        contador = 1;
        for (int i = 0; i < (bytes / sizeof(int)); i++) {
            ptr[i] = 0;
        }
    }

    cout << "El servidor a sido iniciado" << endl;


    // Creacion del socket de servidor
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if ( server_socket == -1 ) {
        fprintf(stderr, "Error creando sockets --> %s", strerror(errno));

        exit(EXIT_FAILURE);
    }

    // server_addr estructura
    memset(&server_addr, 0, sizeof(server_addr));
    // Construir server_addr
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, SERVER_ADDRESS, &(server_addr.sin_addr));
    server_addr.sin_port = htons(PORT_NUMBER);

    // Vincular
    if ((bind(server_socket, (struct sockaddr *) &server_addr, sizeof(struct sockaddr))) == -1 ) {
        fprintf(stderr, "Error en vincular --> %s", strerror(errno));

        exit(EXIT_FAILURE);
    }

    while (true) {
        /* Busca llamadas entrantes */
        if ((listen(server_socket, 5)) == -1 ) {
            fprintf(stderr, "Error en buscar --> %s", strerror(errno));

            exit(EXIT_FAILURE);
        }
        sock_len = sizeof(struct sockaddr_in);
        peer_socket = accept(server_socket, (struct sockaddr *) &peer_addr, &sock_len);
        if ( peer_socket == -1 ) {
            fprintf(stderr, "Error en aceptar --> %s", strerror(errno));

            exit(EXIT_FAILURE);
        }
        fprintf(stdout, "Aceptado --> %s\n", inet_ntoa(peer_addr.sin_addr));
        /* Recibe el tamaño del archivo */
        recv(peer_socket, buffer, BUFSIZ, 0);
        file_size = atoi(buffer);

        if ( file_size != 0 ) {
            remove(FILENAME);
            received_file = fopen(FILENAME, "w");
            if ( received_file == nullptr ) {
                fprintf(stderr, "Error al abrir el archivo --> %s\n", strerror(errno));

                exit(EXIT_FAILURE);
            }
            remain_data = file_size;

            len = recv(peer_socket, buffer, BUFSIZ, 0);
            len = remain_data;
            while ((len > 0) && (remain_data > 0)) {
                fwrite(buffer, sizeof(char), len, received_file);
                remain_data -= len;
                fprintf(stdout, "Recive %d bytes y se esperan :- %d bytes\n", len, remain_data);
            }
            fclose(received_file);

            ifstream i(FILENAME);
            i >> j1;

            // Enviar
            int bytes_1 = j1["byte"];
            if ( bytes_1 != 0 ) {

                if ((bytes - bytes_1) > 0 ) {
                    pag pagina;
                    pagina.id = ID;
                    for (int x = 0; x < (bytes / bytes_1); x++) {
                        if ( ptr[x] == 0 ) {
                            ptr[x] = -1;
                            pagina.lenght = x;
                            pagina.offset = &ptr[x];
                            lista.agregar(pagina);
                            lista.mostrar();
                            break;
                        }
                    }
                }
                j1["byte"] = 0;
                j1["value"] = 0;
                j1["id"] = ID;
                ID++;
                remove(FILENAME);
                ofstream o(FILENAME);
                o << setw(10) << j1 << std::endl;
                fd = open(FILENAME, O_RDONLY);
                if ( fd == -1 ) {
                    fprintf(stderr, "Error al abrir el archivo --> %s", strerror(errno));

                    exit(EXIT_FAILURE);
                }


                // Obtiene el tamaño del archivo
                if ( fstat(fd, &file_stat) < 0 ) {
                    fprintf(stderr, "Error al obtener el tamaño --> %s", strerror(errno));

                    exit(EXIT_FAILURE);
                }

                fprintf(stdout, "Tamaño del archivo: \n%d bytes\n", file_stat.st_size);

                sprintf(file_size_e, "%d", file_stat.st_size);

                // Envia el tamaño del archivo
                len = send(peer_socket, file_size_e, sizeof(file_size_e), 0);
                if ( len < 0 ) {
                    fprintf(stderr, "Error en el envio --> %s", strerror(errno));

                    exit(EXIT_FAILURE);
                }

                fprintf(stdout, "Servidor envio %d bytes de tamaño\n", len);

                offset = 0;
                remain_data = file_stat.st_size;
                // Enviar datos del archivo
                while (((sent_bytes = sendfile(peer_socket, fd, &offset, BUFSIZ)) > 0) && (remain_data > 0)) {
                    fprintf(stdout,
                            "1. Servidor envio %d bytes de los datos del archivo, offset es : %d y resto de data = %d\n",
                            sent_bytes, offset, remain_data);
                    remain_data -= sent_bytes;
                    fprintf(stdout,
                            "2. Servidor envio %d bytes de los datos del archivo, offset es : %d y resto de data = %d\n",
                            sent_bytes, offset, remain_data);
                }
            } else {
                int id = j1["id"];
                int dist = lista.buscar(id);
                if ( dist != -1 ) {
                    ptr[dist] = j1["value"];
                    cout << "El valor almacenado es: " << ptr[dist] << endl;
                }
                remove(FILENAME);
            }
        }
    }
}