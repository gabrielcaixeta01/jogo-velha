#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.hpp"
#include "velha.hpp"

// Teste para verificar tabuleiro vazio
TEST_CASE("Tabuleiro vazio deve retornar jogo indefinido", "[indefinido]") {
    int tabuleiro[3][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    REQUIRE(verificar_estado_jogo(tabuleiro) == -1); // Deve retornar -1 (indefinido)
}

// Teste linha completa
TEST_CASE("Linha completa de X deve retornar X como vencedor", "[vencedor]") {
    int tabuleiro[3][3] = {
        {1, 1, 1}, // Linha completa de X
        {0, 0, 0},
        {0, 0, 0}
    };
    REQUIRE(verificar_estado_jogo(tabuleiro) == 1); // Deve retornar 1 (X venceu)
}

// Teste coluna completa
TEST_CASE("Coluna completa de X deve retornar X como vencedor", "[vencedor]") {
    int tabuleiro[3][3] = {
        {1, 0, 0},
        {1, 0, 0},
        {1, 0, 0}
    };
    REQUIRE(verificar_estado_jogo(tabuleiro) == 1); // Deve retornar 1 (X venceu)
}

// Teste diagonal completa
TEST_CASE("Diagonal principal de X deve retornar X como vencedor", "[vencedor]") {
    int tabuleiro[3][3] = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };
    REQUIRE(verificar_estado_jogo(tabuleiro) == 1); // Deve retornar 1 (X venceu)
}

TEST_CASE("Diagonal secundária de O deve retornar O como vencedor", "[vencedor]") {
    int tabuleiro[3][3] = {
        {0, 0, 2},
        {0, 2, 0},
        {2, 0, 0}
    };
    REQUIRE(verificar_estado_jogo(tabuleiro) == 2); // Deve retornar 2 (O venceu)
}

TEST_CASE("Tabuleiro cheio sem vencedor deve retornar empate", "[empate]") {
    int tabuleiro[3][3] = {
        {1, 2, 1},
        {1, 1, 2},
        {2, 1, 2}
    };
    REQUIRE(verificar_estado_jogo(tabuleiro) == 0); // Deve retornar 0 (empate)
}

TEST_CASE("Empate com tabuleiro cheio e alternância de X e O", "[empate]") {
    int tabuleiro[3][3] = {
        {1, 2, 1},
        {2, 1, 2},
        {2, 1, 2}
    };
    REQUIRE(verificar_estado_jogo(tabuleiro) == 0); // Deve retornar 0 (empate)
}

TEST_CASE("Jogo impossível com dois vencedores simultâneos", "[impossivel]") {
    int tabuleiro[3][3] = {
        {1, 1, 1}, // X vence na primeira linha
        {2, 2, 2}, // O vence na segunda linha
        {0, 0, 0}
    };
    REQUIRE(verificar_estado_jogo(tabuleiro) == -2); // Deve retornar -2 (jogo impossível)
}
