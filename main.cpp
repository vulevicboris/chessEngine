#include <iostream>
#include <string>

void pomeriFiguru(char tabla[8][8], int pred, int pkolona, int kred, int kkolona) {
    tabla[kred][kkolona] = tabla[pred][pkolona];
    tabla[pred][pkolona] = '.';
}

void postaviFigure(char tabla[8][8]) {
    for (int i = 0; i < 8; i++) { //punjenje table
        for (int j = 0; j < 8; j++) {
            tabla[i][j] = '.';
        }
    }
    //beli pesaci
    for (int j = 0; j < 8; j++) {
        tabla[6][j] = 'P';
    }
    //crni pesaci
    for (int j = 0; j < 8; j++) {
        tabla[1][j] = 'p';
    }
    //beli topovi
    tabla[7][0] = 'R';
    tabla[7][7] = 'R';
    //crni topovi
    tabla[0][0] = 'r';
    tabla[0][7] = 'r';
    //beli konji
    tabla[7][1] = 'N';
    tabla[7][6] = 'N';
    //crni konji
    tabla[0][1] = 'n';
    tabla[0][6] = 'n';
    //beli lovci
    tabla[7][2] = 'B';
    tabla[7][5] = 'B';
    //crni lovci
    tabla[0][2] = 'b';
    tabla[0][5] = 'b';
    //beli kralj i kraljica
    tabla[7][3] = 'Q';
    tabla[7][4] = 'K';
    //crni kralj i kraljica
    tabla[0][3] = 'q';
    tabla[0][4] = 'k';
}

void ispisTable(char tabla[8][8]) {
    for (int i = 0; i < 8; i++) { //ispis table
        for (int j = 0; j < 8; j++) {
            std::cout << tabla[i][j];
        }
        std::cout << std::endl;
    }
}

int main() {

    char tabla[8][8];

    postaviFigure(tabla);

    std::string pomeri; //potez koji igrac igra
    std::cout << "Unesite potez: " << std::endl;
    std::cin >> pomeri;

    int pkolona = pomeri[0] - 'a';
    int pred = 8-(pomeri[1] - '0');
    int kkolona = pomeri[2] - 'a';
    int kred = 8-(pomeri[3] - '0');

pomeriFiguru(tabla, pred, pkolona, kkolona, kred);
ispisTable(tabla);


    return 0;
}