#include "velha.hpp"

int verificar_estado_jogo(const int tabuleiro[3][3]) {
    int vencedorX = 0; // Contador para vitórias de X
    int vencedorO = 0; // Contador para vitórias de O

    // Verificar vitórias em linhas
    for (int i = 0; i < 3; ++i) {
        if (tabuleiro[i][0] == tabuleiro[i][1] && 
            tabuleiro[i][1] == tabuleiro[i][2] && 
            tabuleiro[i][0] != 0) {
            if (tabuleiro[i][0] == 1) vencedorX++;
            if (tabuleiro[i][0] == 2) vencedorO++;
        }
    }

    // Verificar vitórias em colunas
    for (int i = 0; i < 3; ++i) {
        if (tabuleiro[0][i] == tabuleiro[1][i] && 
            tabuleiro[1][i] == tabuleiro[2][i] && 
            tabuleiro[0][i] != 0) {
            if (tabuleiro[0][i] == 1) vencedorX++;
            if (tabuleiro[0][i] == 2) vencedorO++;
        }
    }

    // Verificar diagonal principal
    if (tabuleiro[0][0] == tabuleiro[1][1] && 
        tabuleiro[1][1] == tabuleiro[2][2] && 
        tabuleiro[0][0] != 0) {
        if (tabuleiro[0][0] == 1) vencedorX++;
        if (tabuleiro[0][0] == 2) vencedorO++;
    }

    // Verificar diagonal secundária
    if (tabuleiro[0][2] == tabuleiro[1][1] && 
        tabuleiro[1][1] == tabuleiro[2][0] && 
        tabuleiro[0][2] != 0) {
        if (tabuleiro[0][2] == 1) vencedorX++;
        if (tabuleiro[0][2] == 2) vencedorO++;
    }

    // Verificar se há dois vencedores simultâneos
    if (vencedorX > 0 && vencedorO > 0) {
        return -2; // Jogo impossível
    }

    // Verificar vitórias simples
    if (vencedorX > 0) return 1; // X venceu
    if (vencedorO > 0) return 2; // O venceu

    // Verificar se o tabuleiro está cheio (empate)
    bool cheio = true;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (tabuleiro[i][j] == 0) {
                cheio = false;
                break;
            }
        }
    }
    if (cheio) {
        return 0; // Empate
    }

    // Caso contrário, o jogo está indefinido
    return -1; 
}