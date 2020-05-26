//
// Created by PERSONNE on 26/05/2020.
//

#ifndef DES_KEYGEN_H
#define DES_KEYGEN_H
#include "SequenceD.h"
#include "Permutation.h"

template<bool inv> class KeyGen
{
private:
    SequenceD<56> seq;
    std::vector<int> pc1{56,48,40,32,24,16,8,0,57,49,41,33,25,17,9,1,58,50,42,34,26,18,10,2,59,51,43,35,62,54,46,38,30,22,14,6,61,53,45,37,29,21,13,5,60,52,44,36,28,20,12,4,27,19,11,3};
    std::vector<int> pc2{13,16,10,23,0,4,2,27,14,5,20,9,22,18,11,3,25,7,15,6,26,19,12,1,40,51,30,36,46,54,29,39,50,44,32,47,43,48,38,55,33,52,45,41,49,35,28,31};
    std::vector<int> left_shift{1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};
public:
    int rounds = inv ? 16 : 0;
    KeyGen(){}
    KeyGen(SequenceD<64> _seq) {
        Permutation<64, 56> p;
        seq = p(_seq, pc1);
    }
    SequenceD<48> next() {
        Permutation<56, 48> p;
        if(!inv && rounds < 16) {
            seq.decalage(left_shift[rounds]);
            rounds++;
            return p(seq, pc2);
        }
        if(inv && rounds > 0) {
            SequenceD<56> tmp = seq;
            for(int i=0; i<rounds; i++) tmp.decalage(left_shift[i]);
            rounds--;
            return p(tmp, pc2);
        }

        //inv && rounds > -1
        // if(inv) rounds--;

        /*
        if(rounds < 16) {
            seq.decalage(left_shift[rounds]);
            Permutation<56, 48> p;
            rounds++;
            return p(seq, pc2);
        }
        */
    }
};
#endif //DES_KEYGEN_H
