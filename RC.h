//
// Created by pablo on 27/09/18.
//

#ifndef MPOINTER_RC_H
#define MPOINTER_RC_H


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


#endif //MPOINTER_RC_H
