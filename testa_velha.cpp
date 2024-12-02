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