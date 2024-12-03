// Copyright [2024] Gabriel Caixeta

#define CATCH_CONFIG_MAIN
#include "include/catch_amalgamated.hpp"
#include "include/velha.hpp"

// Teste para verificar tabuleiro vazio
TEST_CASE("Tabuleiro vazio deve retornar jogo indefinido", "[indefinido]") {
    int tabuleiro[3][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    REQUIRE(verificar_estado_jogo(tabuleiro) == -1);
}

// Teste linha completa
TEST_CASE("Linha completa de X deve retornar X como vencedor", "[vencedor]") {
    int tabuleiro[3][3] = {
        {1, 1, 1},
        {2, 0, 2},
        {0, 0, 0}
    };
    REQUIRE(verificar_estado_jogo(tabuleiro) == 1);
}

// Teste coluna completa
TEST_CASE("Coluna completa de X deve retornar X como vencedor", "[vencedor]") {
    int tabuleiro[3][3] = {
        {1, 2, 0},
        {1, 0, 0},
        {1, 0, 2}
    };
    REQUIRE(verificar_estado_jogo(tabuleiro) == 1);
}

// Teste diagonal principal
TEST_CASE("Diagonal principal retorna X como vencedor", "[vencedor]") {
    int tabuleiro[3][3] = {
        {1, 0, 0},
        {0, 1, 0},
        {2, 2, 1}
    };
    REQUIRE(verificar_estado_jogo(tabuleiro) == 1);
}

// Teste diagonal secundária
TEST_CASE("Diagonal secundária retorna O como vencedor", "[vencedor]") {
    int tabuleiro[3][3] = {
        {0, 0, 2},
        {1, 2, 0},
        {2, 1, 0}
    };
    REQUIRE(verificar_estado_jogo(tabuleiro) == 2);
}

// Teste empate, tabuleiro cheio
TEST_CASE("Tabuleiro cheio sem vencedor deve retornar empate", "[empate]") {
    int tabuleiro[3][3] = {
        {1, 2, 1},
        {1, 1, 2},
        {2, 1, 2}
    };
    REQUIRE(verificar_estado_jogo(tabuleiro) == 0);
}

// Teste com mais de um vencedor
TEST_CASE("Dois vencedores simultâneos", "[impossivel]") {
    int tabuleiro[3][3] = {
        {1, 1, 1},
        {2, 2, 2},
        {0, 0, 0}
    };
    REQUIRE(verificar_estado_jogo(tabuleiro) == -2);
}

// Teste com jogo indefinido
TEST_CASE("Tabuleiro parcialmente preenchido deve retornar indefinido",
"[indefinido]") {
    int tabuleiro[3][3] = {
        {1, 0, 0},
        {0, 2, 0},
        {0, 0, 0}
    };
    REQUIRE(verificar_estado_jogo(tabuleiro) == -1);
}

// Teste com um X jogando mais vezes, jogo impossível
TEST_CASE("Jogo impossível com mais X do que O permitido", "[impossivel]") {
    int tabuleiro[3][3] = {
        {1, 1, 1},
        {1, 0, 2},
        {0, 0, 2}
    };
    REQUIRE(verificar_estado_jogo(tabuleiro) == -2);
}
