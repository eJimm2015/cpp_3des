//
// Created by PERSONNE on 26/05/2020.
//

#ifndef DES_SBOX_H
#define DES_SBOX_H
#include "Sequence.h"
#include "SequenceD.h"
#include <bitset>

class Sbox {

private :
    int* seqs;

public :
    Sbox(int _seqs[64]){
        seqs = new int[64];
        for(int i=0; i<64; i++) seqs[i] = _seqs[i];
    }
    ~Sbox() {
        delete[] seqs;
    }
    Sbox(const Sbox& sbox) {
        seqs = new int[64];
        for(int i=0; i<64; i++) seqs[i] = sbox.seqs[i];
    }

    Sbox& operator=(const Sbox& _sbox) {
        if(seqs) delete[] seqs;
        seqs = new int[64];
        for(int i=0; i<64; i++) seqs[i] = _sbox.seqs[i];
        return *this;
    }

    Sequence operator()(Sequence seq) {
        int row = seq(0)*2 + seq(5);
        int col = seq(1)*8 + seq(2)*4 + seq(3)*2 + seq(4);
        int val = seqs[row*16 + col];
        std::bitset<4> char_bits(val);
        Sequence res = Sequence(4);
        for(int j=0; j<4; j++) {
            res[j] = char_bits[3 - j];
        }
        return res;
    }



};

#endif //DES_SBOX_H
