#include "moveVali.h"
#include <iostream>
#include <cctype>

bool postojiFigura(char tabla[8][8], int pred, int pkolona) {
    if (tabla[pred][pkolona] == '.') {
       return false;
    }
    else {
        return true;
    }

}

bool istaBoja(char tabla[8][8], int pred, int pkolona, int kred, int kkolona) {
    if (std::isupper(tabla[pred][pkolona]) && std::isupper(tabla[kred][kkolona])) {
        return true;
    }
    if (std::islower(tabla[pred][pkolona]) && std::islower(tabla[kred][kkolona])) {
        return true;
    }
        return false;
}

bool ispravanIgrac(char tabla[8][8], int pred, int pkolona, bool potez) {
    if (std::isupper(tabla[pred][pkolona]) && potez == true) {
        return true;
    }
    if (std::islower(tabla[pred][pkolona]) && potez == false) {
        return true;
    }
        return false;
}