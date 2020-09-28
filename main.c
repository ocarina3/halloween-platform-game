#include "raylib.h"

int main(void) {
    // Inicializa a largura e altura da janela como constantes
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Exemplo de Janela");

    SetTargetFPS(60); // Rodará a 60 FPS

    // Loop principal do game
    // Roda o game enquanto o usuário não apertar ESC
    while (!WindowShouldClose()) {
        
        // Inicializa a janela
        BeginDrawing();

            // Cor do background da janela
            ClearBackground(RAYWHITE);

            // Escreve um texto, recebe o TEXTO, POSIÇÃO EM X, POSIÇÃO EM Y, TAMANHO DA FONTE, COR DA FONTE
            DrawText("Janela simples!", screenWidth - 170, screenHeight - 50, 20, LIGHTGRAY);

        EndDrawing();
    }

    CloseWindow();        // Fecha a janela

    return 0;
}