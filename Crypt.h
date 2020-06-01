//
// Created by PERSONNE on 26/05/2020.
//

#ifndef DES_CRYPT_H
#define DES_CRYPT_H
#include <string>
#include <fstream>
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

    void operator()(const char* from, const char* to) {

    /*
        DES<false> c_des = DES<false>(key1);
        DES<true> d_des = DES<true>(key2);
        return c_des(d_des(c_des(x)));
    */
        DES<false> c_des = DES<false>(key1);
        DES<true> d_des = DES<true>(key2);

        std::ifstream in(from, std::ios::in);
        std::ofstream  out(to, std::ios::out);

        while(!in.eof()) {
            SequenceD<64> x = SequenceD<64>();
            operator>>(in >> std::noskipws, x);
            out << c_des(d_des(c_des(x)));
        }
        in.close();
        out.close();
    }
};
#endif //DES_CRYPT_H
