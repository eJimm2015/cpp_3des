//
// Created by PERSONNE on 26/05/2020.
//

#ifndef DES_DECRYPT_H
#define DES_DECRYPT_H
#include <string>
#include "SequenceD.h"
#include "DES.h"

class Decrypt {

private :
    SequenceD<64> key1;
    SequenceD<64> key2;
public :
    Decrypt(SequenceD<64> _key1, SequenceD<64> _key2) {
        key1 = _key1;
        key2 = _key2;
    }

    SequenceD<64> operator()(SequenceD<64> x) {
        DES<true> d_des = DES<true>(key1);
        DES<false> c_des = DES<false>(key2);
        return d_des(c_des(d_des(x)));
    }
};
#endif //DES_DECRYPT_H
