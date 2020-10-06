#include "raylib.h"

#define PHYSAC_IMPLEMENTATION
#define PHYSAC_NO_THREADS
#include "src/physac.h"

#define VELOCITY 0.5f

int main(void) {
    // Inicializa a largura e altura da janela como constantes
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitPhysics();
    InitWindow(screenWidth, screenHeight, "Exemplo de Janela");

    PhysicsBody floor = CreatePhysicsBodyRectangle((Vector2) { screenWidth / 2, screenHeight }, screenWidth, 320, 10);
    PhysicsBody wallLeft = CreatePhysicsBodyRectangle((Vector2) { 0, screenHeight / 2 }, 10, screenHeight, 10);
    PhysicsBody wallRight = CreatePhysicsBodyRectangle((Vector2) { screenWidth, screenHeight / 2 }, 10, screenHeight, 10);

    floor->enabled = false;
    wallLeft->enabled = false;
    wallRight->enabled = false;
    
    PhysicsBody player = CreatePhysicsBodyRectangle((Vector2) { screenWidth / 2, 50 }, 40, 40, 1);

    player->freezeOrient = true;

    SetTargetFPS(60); // Rodará a 60 FPS

    // Loop principal do game
    // Roda o game enquanto o usuário não apertar ESC
    while (!WindowShouldClose()) {

        RunPhysicsStep();

        if ( IsKeyDown(KEY_D) ) player->velocity.x = VELOCITY;
        if ( IsKeyDown(KEY_A) ) player->velocity.x = -VELOCITY;
        
        // Inicializa a janela
        BeginDrawing();

            // Cor do background da janela
            ClearBackground(RAYWHITE);

            int bodyCount = GetPhysicsBodiesCount();
            for ( int x = 0;  x < bodyCount; x++ ) {
                PhysicsBody drawedBody = GetPhysicsBody(x);

                int drawedBodyVertices = GetPhysicsShapeVerticesCount(x);
                for ( int y = 0; y < drawedBodyVertices; y++ ) {
                    Vector2 pointA = GetPhysicsShapeVertex(drawedBody, y);

                    int nextVertex = (y + 1) < drawedBodyVertices ? y + 1 : 0;
                    Vector2 pointB = GetPhysicsShapeVertex(drawedBody, nextVertex);

                    DrawLineV((Vector2) pointA, (Vector2) pointB, BLUE);
                }
            }

        EndDrawing();
    }

    ClosePhysics();

    CloseWindow();        // Fecha a janela

    return 0;
}