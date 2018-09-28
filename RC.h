//
// Created by pablo on 27/09/18.
//

#ifndef PROYECTO1_RC_H
#define PROYECTO1_RC_H


class RC {
private:
    int count; /// Contador de referencias

public:
    void AddRef()
    {
        /// Incrementa el contador de referencias
        count++;
    }

    int Release()
    {
        /// resta al contador de referencias
        /// return del contador
        return --count;
    }

};


#endif //PROYECTO1_RC_H
