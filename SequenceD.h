//
// Created by PERSONNE on 26/05/2020.
//

#ifndef DES_SEQUENCED_H
#define DES_SEQUENCED_H
#include "Sequence.h"
#include <istream>
#include <ostream>
#include <cmath>
#include <iostream>
#include <bitset>

template<int s> class SequenceD : private Sequence
{
private:
    Sequence seq;

public:
    SequenceD() : Sequence(s/2)
    {
        seq = Sequence(s/2);
    }
    SequenceD(Sequence s1, Sequence s2) : Sequence(s2) {
        seq = s1;
    }
    int& operator[](int i) {
        return i < s/2 ? seq[i] : Sequence::operator[](i-(s/2));
    }

    int operator()(int i) {
        return i < s/2 ? seq(i) : Sequence::operator()(i-(s/2));
    }

    int size() {
        return seq.size() + Sequence::size();
    }

    void decalage(int shift) {
/*
            seq.decalage(shift);
            Sequence::decalage(shift);
*/

        int last = seq.size() - 1;
        for(int i=0; i<shift; i++) {
            int r0 = Sequence::operator()(0);
            int l0 = seq(0);
            seq.decalage(1);
            Sequence::decalage(1);
            seq[last] = r0;
            Sequence::operator[](last) = l0;
        }

    }


    SequenceD operator *(SequenceD seqD) {
        // seqD.Sequence::operator*(seq);
        return SequenceD(seq*seqD.seq, seqD.Sequence::operator*(*this));
    }

    Sequence left() {
        return seq;
    }

    Sequence right() {
        return (*this);
    }

};

std::ostream & operator << (std::ostream &out, SequenceD<64> seq) {
    for(int i=0; i<8; i++) {
        int dec = 0;
        for(int j=0; j<8; j++) {
            int tmp = seq(8*i + j);
            dec = dec + std::pow(2, 7-j)*tmp;
        }
        out << char(dec);
    }
    return out;
}

std::istream& operator>>(std::istream& in, SequenceD<64>& seq) {

    for(int i=0; i<8; i++) {
        char c;
        in >> c;
        int val = (int)c;
        std::bitset<8> char_bits(val);
        for(int j=0; j<8; j++) {
            seq[8*i + j] = char_bits[7-j];
        }
    }
}

void write(std::ostream &out, SequenceD<64> s) {
    for(int i=0; i<s.size(); i++) out.write((char*)s[i], sizeof(int));
}

void read(std::istream &in, SequenceD<64> s) {
    for(int i=0; i<s.size(); i++) in.read((char*)s[i], sizeof(int));
}

template <class T> void affichage(T t) {
    for(int i=0; i<t.size(); i++) std::cout << t(i);
}


#endif //DES_SEQUENCED_H
