#include <iostream>
#include "Sequence.h"
#include "SequenceD.h"
#include "Permutation.h"
#include "KeyGen.h"
#include "SBox.h"
#include "S_Fonction.h"
#include "F.h"
#include "DES.h"
#include "Crypt.h"
#include "Decrypt.h"

int main() {
    SequenceD<64> key1 = SequenceD<64>();
    operator>>(std::cin, key1);
    std::cout << "Key : ";
    affichage(key1);
    std::cout << std::endl << "=======" << std::endl;
    SequenceD<64> x = SequenceD<64>();
    operator>>(std::cin, x);
    std::cout << "x : ";
    affichage(x);
    std::cout << std::endl << "=======" << std::endl;
    DES<false> des = DES<false>(key1);
    DES<true> inv_des = DES<true>(key1);
    SequenceD<64> crypt = des(x);
    SequenceD<64> decrypt = inv_des(crypt);
    affichage(crypt);
    std::cout << std::endl;
    operator<<(std::cout, crypt);
    std::cout << std::endl << "=======" << std::endl;
    affichage(decrypt);
    std::cout << std::endl;
    operator<<(std::cout, decrypt);
    return 0;
}
