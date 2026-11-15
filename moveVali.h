#pragma once

bool postojiFigura(char tabla[8][8], int pred, int pkolona);
bool istaBoja(char tabla[8][8], int pred, int pkolona, int kred, int kkolona);
bool ispravanIgrac(char tabla[8][8], int pred, int pkolona, bool potez);
bool ispravanPotezP(char tabla[8][8], int pred, int pkolona, int kred, int kkolona);
bool ispravanPotezN(char tabla[8][8], int pred, int pkolona, int kred, int kkolona);
bool ispravanPotezR(char tabla[8][8], int pred, int pkolona, int kred, int kkolona);
bool ispravanPotezB(char tabla[8][8], int pred, int pkolona, int kred, int kkolona);
bool ispravanPotezQ(char tabla[8][8], int pred, int pkolona, int kred, int kkolona);
bool ispravanPotezK(char tabla[8][8], int pred, int pkolona, int kred, int kkolona);
bool jeSah(char tabla[8][8], bool potez);