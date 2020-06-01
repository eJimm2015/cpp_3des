#include <iostream>
#include "Crypt.h"
#include "Decrypt.h"
#include <fstream>
#include "SequenceD.h"
#include <locale>

using namespace std;
int main() {
/*
    ifstream in;
    in.open(R"(C:\Users\PERSONNE\CLionProjects\des\from.txt)", ios::in);
    ofstream  out(R"(C:\Users\PERSONNE\CLionProjects\des\to.txt)", ios::out);
    ofstream  out2(R"(C:\Users\PERSONNE\CLionProjects\des\to2.txt)", ios::out);
*/


    //  std::locale utf8_locale(std::locale(), new utf8cvt<false>);
    /*
    string s;
    while(getline(in, s)) out << s << "\n";
    in.close();
    out.close();
*/



    SequenceD<64> key1 = SequenceD<64>();
    operator>>(std::cin, key1);
    SequenceD<64> key2 = SequenceD<64>();
    operator>>(std::cin, key2);
    Crypt crypt(key1, key2);
    Decrypt decrypt(key1, key2);
    SequenceD<64> x = SequenceD<64>();
    crypt(R"(C:\Users\PERSONNE\CLionProjects\des\from.txt)", R"(C:\Users\PERSONNE\CLionProjects\des\to.txt)");
    decrypt(R"(C:\Users\PERSONNE\CLionProjects\des\to.txt)", R"(C:\Users\PERSONNE\CLionProjects\des\to2.txt)");
    /*
    while(!in.eof()) {
        operator>>(in >> std::noskipws, x);
        SequenceD<64> cr = crypt(x);
        operator<<(std::cout,cr);
        out << cr;
        cout << " <-> ";
        SequenceD<64> dcr = decrypt(cr);
        operator<<(std::cout, dcr);
        out2 << dcr;
        cout << "\n";
    }


    /*
    std::cout << "Key1 : ";
    affichage(key1);
    std::cout << std::endl << "=======" << std::endl;
    std::cout << "Key2 : ";
    affichage(key2);
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
    std::cout << "crypt : ";
    affichage(crypt);
    std::cout << std::endl << "=======" << std::endl;
    operator<<(std::cout, crypt);
    std::cout << std::endl;
    std::cout << "decrypt : ";
    std::cout << std::endl << "=======" << std::endl;
    affichage(decrypt);
    std::cout << std::endl;
    operator<<(std::cout, decrypt);

    Crypt crypt1 = Crypt(key1, key2);
    SequenceD<64> cyphered = crypt1(x);
    std::cout << std::endl << "Cyphered=======" << std::endl;
    operator<<(std::cout, cyphered);
    std::cout << std::endl;
    Decrypt decrypt1 = Decrypt(key1, key2);
    SequenceD<64> decyphered = decrypt1(cyphered);
    std::cout << std::endl << "Decyphered=======" << std::endl;
    operator<<(std::cout, decyphered);
    std::cout << std::endl;
*/


    return 0;
}
