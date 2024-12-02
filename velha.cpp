#include "velha.hpp"
#include <cmath>

int verificar_estado_jogo(const int tabuleiro[3][3]) {
    // Verificar linha
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][0] != 0) {
            return tabuleiro[i][0];
        }
    }

    // Verificar coluna
    for (int i = 0; i < 3; ++i) {
        if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i] && tabuleiro[0][i] != 0) {
            return tabuleiro[0][i];
        }
    }

    // Diagonal principal
    if (tabuleiro[0][0] == tabuleiro[1][1] && 
        tabuleiro[1][1] == tabuleiro[2][2] && 
        tabuleiro[0][0] != 0) {
        return tabuleiro[0][0]; // Retorna 1 (X) ou 2 (O)
    }

    // Diagonal secundária 
    if (tabuleiro[0][2] == tabuleiro[1][1] && 
        tabuleiro[1][1] == tabuleiro[2][0] && 
        tabuleiro[0][2] != 0) {
        return tabuleiro[0][2]; // Retorna 1 (X) ou 2 (O)
    }

    // Empate
    bool empate = true;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (tabuleiro[i][j] == 0) { 
                empate = false;
                break;
            }
        }
    }
    if (empate) {
        return 0;
    }

    //Indefinido
    return -1;
}