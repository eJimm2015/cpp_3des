//
// Created by PERSONNE on 26/05/2020.
//

#ifndef DES_PERMUTATION_H
#define DES_PERMUTATION_H
#include "SequenceD.h"
#include <vector>

template<int in, int out> class Permutation {

public :
    SequenceD<out> operator()(SequenceD<in> seq, std::vector<int> v) {
        SequenceD<out> s = SequenceD<out>();
        for(int i=0; i<out; i++) {
            s[i] = seq(v[i]);
        }
        return s;
    }
};
#endif //DES_PERMUTATION_H
