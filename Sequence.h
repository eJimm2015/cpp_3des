//
// Created by PERSONNE on 26/05/2020.
//

#ifndef DES_SEQUENCE_H
#define DES_SEQUENCE_H
#include <deque>
#include <list>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <bitset>

class Sequence
{

private:
    std::deque<int> de;

public:
    Sequence(const int l = 4)
    {
        srand(time(NULL));
        for(int i = 0; i<l; i++) {
            de.push_front(rand()%2);
        }
    }

    Sequence(const std::list<Sequence> seqs)
    {
        for(Sequence i : seqs) {
            std::deque<int> d = i.de;
            for(int j=0; j<d.size(); j ++) de.push_back(d.at(j));
        }
    }

    int& operator[](int i) {
        return de.at(i);
    }

    int operator() (int i) {
        return de.at(i);
    }

    void decalage(int shift) {
        for(int i=0; i<shift; i++) {
            int first = de.front();
            de.pop_front();
            de.push_back(first);
        }
    }

    Sequence operator*(Sequence s) {
        int length = std::min(s.size(), (int)de.size());
        Sequence seq(length);
        for(int i=0; i<length; i++) seq[i] = s[i]^de.at(i);
        return seq;

    }

    Sequence permutation(std::vector<int> v) {
        int length = v.size();
        Sequence s(length);
        for(int i=0; i<length; i++) {
            s[i] = de.at(v[i]);
        }
        return s;
    }

    int size() {
        return de.size();
    }

    Sequence sous_sequence(int deb, int fin) {
        int length = fin-deb+1;
        Sequence s(length);
        for(int i=0; i<length; i++) s[i] = de.at(deb+i);
        return s;
    }

    Sequence& operator=(const int val) {
        std::bitset<64> char_bits(val);
        int length = de.size();
        de.empty();
        for(int i=0; i<length; i++) {
            de.push_back(char_bits[size()- 1 - i]);
        }
        return *this;
    }


};
#endif //DES_SEQUENCE_H
