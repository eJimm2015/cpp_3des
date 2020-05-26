//
// Created by PERSONNE on 26/05/2020.
//

#ifndef DES_CRYPT_H
#define DES_CRYPT_H
#include <string>
#include "SequenceD.h"
#include "DES.h"

class Crypt {

private :
    SequenceD<64> key1;
    SequenceD<64> key2;
public :
    Crypt(SequenceD<64> _key1, SequenceD<64> _key2) {
        key1 = _key1;
        key2 = _key2;
    }

    SequenceD<64> operator()(SequenceD<64> x) {
        DES<false> c_des = DES<false>(key1);
        DES<true> d_des = DES<true>(key2);
        return c_des(d_des(c_des(x)));
    }
};
#endif //DES_CRYPT_H
