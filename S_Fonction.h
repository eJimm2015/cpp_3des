//
// Created by PERSONNE on 26/05/2020.
//

#ifndef DES_S_FONCTION_H
#define DES_S_FONCTION_H
#include "SBox.h"
#include <vector>
#include <list>
class S_Fonction {
private :
    std::vector<Sbox> sboxes;

public :
    S_Fonction(){}
    S_Fonction(int* seqs[8]) {
        sboxes.reserve(8);
        for(int i=0; i<8; i++) sboxes.push_back(Sbox(seqs[i]));
    }
    ~S_Fonction() {
        sboxes.clear();
    }
    S_Fonction(const S_Fonction& sfunc) {
        sboxes = sfunc.sboxes;
    }

    S_Fonction& operator=(const S_Fonction& sfunc) {
        sboxes.clear();
        sboxes.reserve(8);
        sboxes = sfunc.sboxes;
        return *this;
    }

    Sequence operator()(Sequence seq) {
        std::list<Sequence> seqs;
        for(int i=0; i<8; i++) seqs.push_back(sboxes.at(i)(seq.sous_sequence(6*i, 6*i + 5)));
        return seqs;
    }
};
#endif //DES_S_FONCTION_H
