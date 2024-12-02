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
TEST_CASE("Coluna completa de O deve retornar O como vencedor", "[vencedor]") {
    int tabuleiro[3][3] = {
        {2, 0, 0},
        {2, 0, 0},
        {2, 0, 0}
    };
    REQUIRE(verificar_estado_jogo(tabuleiro) == 2); // Deve retornar 2 (O venceu)
}