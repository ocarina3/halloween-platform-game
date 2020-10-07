#include "raylib.h"

// Incluindo lib para física do game
#define PHYSAC_IMPLEMENTATION
#define PHYSAC_NO_THREADS
#include "physac.h"

// Funções para executar cada fase
// 0 - Rodando
// 1 - Perdeu
// 2 - Ganhou
int status() {
    // Code here
}

int phaseOne(bool isOneOpen) {

    while (isOneOpen) {
        // Code here
    }
    
    return status;
}

int phaseTwo(bool isTwoOpen) {}

int phaseThree(bool isThreeOpen) {}