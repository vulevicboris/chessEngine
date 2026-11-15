#include "moveVali.h"
#include <iostream>
#include <cctype>
#include <cstdlib>

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

bool ispravanPotezP(char tabla[8][8], int pred, int pkolona, int kred, int kkolona) {
    if (tabla[pred][pkolona] == 'P') {
        if (pred == 6 && tabla[pred-1][pkolona] == '.' && kred == pred - 2 && pkolona == kkolona && tabla[kred][kkolona] == '.') {
            return true;
        }
    if (kred == pred - 1 && pkolona == kkolona && tabla[kred][kkolona] == '.') {
        return true;
    }
        if (kred == pred - 1 && std::abs(kkolona - pkolona) == 1 && tabla[kred][kkolona] != '.' && istaBoja(tabla, pred, pkolona, kred, kkolona) == false) {
return true;
        }
    }
    if (tabla[pred][pkolona] == 'p') {
        if (pred == 1 && tabla[pred+1][pkolona] == '.' && kred == pred + 2 && pkolona == kkolona && tabla[kred][kkolona] == '.') {
            return true;
        }
        if (kred == pred + 1 && pkolona == kkolona && tabla[kred][kkolona] == '.') {
            return true;
        }
        if (kred == pred + 1 && std::abs(kkolona - pkolona) == 1 && tabla[kred][kkolona] != '.' && istaBoja(tabla, pred, pkolona, kred, kkolona) == false) {
            return true;
        }
    }
    return false;
}

bool ispravanPotezN(char tabla[8][8], int pred, int pkolona, int kred, int kkolona) {
    if (std::abs(pred - kred) == 1 && std::abs(pkolona - kkolona) == 2) {
        return true;
    }
    if (std::abs(pred - kred) == 2 && std::abs(pkolona - kkolona) == 1) {
        return true;
    }
    return false;
}

bool ispravanPotezR(char tabla[8][8], int pred, int pkolona, int kred, int kkolona) {
    if ((pred == kred || pkolona == kkolona) && (pred != kred || pkolona != kkolona)) {
        if (pred > kred && pkolona == kkolona) {
            for (int i = pred - 1; i > kred; i--) {
                if (tabla[i][pkolona] != '.') {
            return false;
            }
            }
            return true;
        }
        if (pred < kred && pkolona == kkolona) {
            for (int i = pred + 1; i < kred; i++) {
                if (tabla[i][pkolona] != '.') {
                    return false;
                }
            }
            return true;
        }
        if (pred == kred && pkolona > kkolona) {
            for (int i = pkolona - 1; i > kkolona; i--) {
                if (tabla[pred][i] != '.') {
                    return false;
                }
            }
            return true;
        }
        if (pred == kred && pkolona < kkolona) {
            for (int i = pkolona + 1; i < kkolona; i++) {
                if (tabla[pred][i] != '.') {
                    return false;
                }
            }
            return true;
        }
    }
    return false;
}
bool ispravanPotezB(char tabla[8][8], int pred, int pkolona, int kred, int kkolona) {
    if (pred != kred) {
        if (std::abs(pred - kred) == std::abs(pkolona - kkolona)) {
            if (pred > kred && pkolona < kkolona) {
                for (int i = pred - 1, j = pkolona + 1; i > kred; i--, j++) {
                    if (tabla[i][j] != '.') {
                        return false;
                    }
                }
                return true;
            }
            if (pred > kred && pkolona > kkolona) {
                for (int i = pred - 1, j = pkolona - 1; i > kred; i--, j--) {
                    if (tabla[i][j] != '.') {
                        return false;
                    }
                }
                return true;
            }
            if (pred < kred && pkolona < kkolona) {
                for (int i = pred + 1, j = pkolona + 1; i < kred; i++, j++) {
                    if (tabla[i][j] != '.') {
                        return false;
                    }
                }
                return true;
            }
            if (pred < kred && pkolona > kkolona) {
                for (int i = pred + 1, j = pkolona - 1; i < kred; i++, j--) {
                    if (tabla[i][j] != '.') {
                        return false;
                    }
                }
                return true;
            }
        }
    }
    return false;
}
bool ispravanPotezQ(char tabla[8][8], int pred, int pkolona, int kred, int kkolona) {
    if ((ispravanPotezB(tabla, pred, pkolona, kred, kkolona) || ispravanPotezR(tabla, pred, pkolona, kred, kkolona)) == true) {
        return true;
    }
    return false;
}
bool ispravanPotezK(char tabla[8][8], int pred, int pkolona, int kred, int kkolona) {
    if (pred != kred || pkolona != kkolona) {
        if (std::abs(pred - kred) <= 1 && std::abs(pkolona - kkolona) <= 1) {
return true;
        }
    }
    return false;
}
bool jeSah(char tabla[8][8], bool potez) { //proverava da li je kralj u sahu
    int kraljred = -1;
    int kraljkolona = -1;
    if ( potez == true) { //provera za belog kralja
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (tabla[i][j] == 'K') {
                kraljred = i;
                kraljkolona = j;
            }
        }
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (std::islower(tabla[i][j])) {
                if (tabla[i][j] == 'r') {
                    if (ispravanPotezR(tabla, i, j, kraljred, kraljkolona) == true) {
                        return true;
                    }
                }
            }
        }
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (std::islower(tabla[i][j])) {
                if (tabla[i][j] == 'b') {
                    if (ispravanPotezB(tabla, i, j, kraljred, kraljkolona) == true) {
                        return true;
                    }
                }
            }
        }
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (std::islower(tabla[i][j])) {
                if (tabla[i][j] == 'q') {
                    if (ispravanPotezQ(tabla, i, j, kraljred, kraljkolona) == true) {
                        return true;
                    }
                }
            }
        }
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (std::islower(tabla[i][j])) {
                if (tabla[i][j] == 'n') {
                    if (ispravanPotezN(tabla, i, j, kraljred, kraljkolona) == true) {
                        return true;
                    }
                }
            }
        }
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (tabla[i][j] == 'p') {
                if (kraljred == i + 1 && std::abs(kraljkolona - j) == 1) {
                    return true;
                }
            }
        }
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (std::islower(tabla[i][j])) {
                if (tabla[i][j] == 'k') {
                    if (ispravanPotezK(tabla, i, j, kraljred, kraljkolona) == true) {
                        return true;
                    }
                }
            }
        }
    }
    }
    if (potez == false) { //provera za crnog kralja
     for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (tabla[i][j] == 'k') {
                kraljred = i;
                kraljkolona = j;
            }
        }
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (std::isupper(tabla[i][j])) {
                if (tabla[i][j] == 'R') {
                    if (ispravanPotezR(tabla, i, j, kraljred, kraljkolona) == true) {
                        return true;
                    }
                }
            }
        }
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (std::isupper(tabla[i][j])) {
                if (tabla[i][j] == 'B') {
                    if (ispravanPotezB(tabla, i, j, kraljred, kraljkolona) == true) {
                        return true;
                    }
                }
            }
        }
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (std::isupper(tabla[i][j])) {
                if (tabla[i][j] == 'Q') {
                    if (ispravanPotezQ(tabla, i, j, kraljred, kraljkolona) == true) {
                        return true;
                    }
                }
            }
        }
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (std::isupper(tabla[i][j])) {
                if (tabla[i][j] == 'N') {
                    if (ispravanPotezN(tabla, i, j, kraljred, kraljkolona) == true) {
                        return true;
                    }
                }
            }
        }
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (tabla[i][j] == 'P') {
                if (kraljred == i - 1 && std::abs(kraljkolona - j) == 1) {
                    return true;
                }
            }
        }
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (std::isupper(tabla[i][j])) {
                if (tabla[i][j] == 'K') {
                    if (ispravanPotezK(tabla, i, j, kraljred, kraljkolona) == true) {
                        return true;
                    }
                }
            }
        }
    }
    }

    return false;
}