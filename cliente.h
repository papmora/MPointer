#ifndef C2_CLIENTE_H
#define C2_CLIENTE_H

#include <iostream>
#include <stdlib.h>

class cliente {
public:
    int conectar();
    void setServer(std::string g);
    void setPuerto(int s);
};


#endif //C2_CLIENTE_H
