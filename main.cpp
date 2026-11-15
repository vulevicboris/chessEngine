#include <iostream>
#include <string>
#include "board.h"
#include "moveVali.h"


int main() {

    char tabla[8][8];
    bool potez = true;

    postaviFigure(tabla);


    std::string pomeri; //potez koji igrac igra
    while (pomeri != "exit") {
        std::cout << "Unesite potez: " << std::endl;
        std::cin >> pomeri;
if (pomeri == "exit") {
    break;
}
        if (pomeri.length() != 4) { //potez veci od 4
            std::cout << "Neispravan potez" << std::endl;
            continue;
        }
        if (pomeri[0] < 'a' || pomeri[0] > 'h' || pomeri[1] < '1' || pomeri[1] > '8' || pomeri[2] < 'a' || pomeri[2] > 'h' || pomeri[3] < '1' || pomeri[3] > '8') {
            std::cout << "Neispravan potez" << std::endl;
            continue; //provera da li pozicija postoji na tabli
        }

        int pkolona = pomeri[0] - 'a';
        int pred = 8-(pomeri[1] - '0');
        int kkolona = pomeri[2] - 'a';
        int kred = 8-(pomeri[3] - '0');

        if (postojiFigura(tabla, pred, pkolona) == false) {
            std::cout << "Neispravan potez" << std::endl;
            continue;
        }
        if (istaBoja(tabla, pred, pkolona, kred, kkolona) == true) {
            std::cout << "Neispravan potez" << std::endl;
            continue;
        }
        if (ispravanIgrac(tabla, pred, pkolona, potez) == false) {
            std::cout << "Neispravan potez" << std::endl;
            continue;
        }
        if (tabla[pred][pkolona] == 'P' || tabla[pred][pkolona] == 'p') {
            if (ispravanPotezP(tabla, pred, pkolona, kred, kkolona) == false) {
                std::cout << "Neispravan potez" << std::endl;
                continue;
            }
        }
        if (tabla[pred][pkolona] == 'N' || tabla[pred][pkolona] == 'n') {
            if (ispravanPotezN(tabla, pred, pkolona, kred, kkolona) == false) {
                std::cout << "Neispravan potez" << std::endl;
                continue;
            }
        }
        if (tabla[pred][pkolona] == 'R' || tabla[pred][pkolona] == 'r') {
            if (ispravanPotezR(tabla, pred, pkolona, kred, kkolona) == false) {
                std::cout << "Neispravan potez" << std::endl;
                continue;
            }
        }
        if (tabla[pred][pkolona] == 'B' || tabla[pred][pkolona] == 'b') {
            if (ispravanPotezB(tabla, pred, pkolona, kred, kkolona) == false) {
                std::cout << "Neispravan potez" << std::endl;
                continue;
            }
        }
        if (tabla[pred][pkolona] == 'Q' || tabla[pred][pkolona] == 'q') {
            if (ispravanPotezQ(tabla, pred, pkolona, kred, kkolona) == false) {
                std::cout << "Neispravan potez" << std::endl;
                continue;
            }
        }
        if (tabla[pred][pkolona] == 'K' || tabla[pred][pkolona] == 'k') {
            if (ispravanPotezK(tabla, pred, pkolona, kred, kkolona) == false) {
                std::cout << "Neispravan potez" << std::endl;
                continue;
            }
        }
        char staraFigura = tabla[pred][pkolona];
        char novaFigura = tabla[kred][kkolona];
        if (tabla[kred][kkolona] == 'k' || tabla[kred][kkolona] == 'K') {
            std::cout << "Neispravan potez" << std::endl;
            continue;
        }
        pomeriFiguru(tabla, pred, pkolona, kred, kkolona);
            if (jeSah(tabla, potez) == true) {
                std::cout << "Neispravan potez" << std::endl;
                tabla[pred][pkolona] = staraFigura;
                tabla[kred][kkolona] = novaFigura;
                continue;
            }
        potez = !potez;
        if (jeSah(tabla, potez)) {
            std::cout << "SAH" << std::endl;
        }
        ispisTable(tabla);
    }

    return 0;
}