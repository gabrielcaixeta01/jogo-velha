#include "velha.hpp"
#include <cmath>

int verificar_estado_jogo(const int tabuleiro[3][3]) {
    //Verificar linha
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][0] != 0) {
            return tabuleiro[i][0];
        }
    }
    return -1;
}