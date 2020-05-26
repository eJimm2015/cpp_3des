//
// Created by PERSONNE on 26/05/2020.
//

#ifndef DES_DES_H
#define DES_DES_H
#include "SequenceD.h"
#include "Permutation.h"
#include "F.h"

template<bool inv> class DES {
private :
    SequenceD<64> key;
    std::vector<int> init_p = {57,49,41,33,25,17,9,1,59,51,43,35,27,19,11,3,61,53,45,37,29,21,13,5,63,55,47,39,31,23,15,7,56,48,40,32,24,16,8,0,58,50,42,34,26,18,10,2,60,52,44,36,28,20,12,4,62,54,46,38,30,22,14,6};
    std::vector<int> inv_init_p = {39,7,47,15,55,23,63,31,38,6,46,14,54,22,62,30,37,5,45,13,53,21,61,29,36,4,44,12,52,20,60,28,35,3,43,11,51,19,59,27,34,2,42,10,50,18,58,26,33,1,41,9,49,17,57,25,32,0,40,8,48,16,56,24};

public :
    DES(SequenceD<64> _key){key = _key;}
    SequenceD<64> operator()(SequenceD<64> txt) {
        Permutation<64, 64> p;
        F<inv> f = F<inv>(key);
        SequenceD<64> init_p_seq = p(txt, init_p);
        Sequence left = init_p_seq.left();
        Sequence right = init_p_seq.right();
        for (int i = 0; i<16; i++) {
            Sequence tmp = Sequence({right});
            right = left*f(right);
            left = Sequence({tmp});
        }
        SequenceD<64> swapped32 = SequenceD<64>(right, left);
        return p(swapped32, inv_init_p);
    }

};


#endif //DES_DES_H
