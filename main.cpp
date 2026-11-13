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
        pomeriFiguru(tabla, pred, pkolona, kred, kkolona);
        potez = !potez;
        ispisTable(tabla);
    }

    return 0;
}