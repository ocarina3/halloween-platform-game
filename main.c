#include "raylib.h"

#define PHYSAC_IMPLEMENTATION
#define PHYSAC_NO_THREADS
#include "src/physac.h"

#define VELOCITY 0.3f

typedef struct player {
    PhysicsBody physic;
    Color color;
    int attackCooldown;
    Vector2 size;
} player;

void attackAni(player *player);

int main(void) {
    // Inicializa a largura e altura da janela como constantes
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitPhysics();
    InitWindow(screenWidth, screenHeight, "Exemplo de Janela");

    PhysicsBody floor = CreatePhysicsBodyRectangle((Vector2) { screenWidth / 2, screenHeight }, screenWidth, 320, 10);
    PhysicsBody wallLeft = CreatePhysicsBodyRectangle((Vector2) { -4, screenHeight / 2 }, 10, screenHeight, 10);
    PhysicsBody wallRight = CreatePhysicsBodyRectangle((Vector2) { screenWidth + 5, screenHeight / 2 }, 10, screenHeight, 10);

    floor->enabled = false;
    wallLeft->enabled = false;
    wallRight->enabled = false;
    
    player player;
    player.size = (Vector2) { 40, 40 };
    player.physic = CreatePhysicsBodyRectangle((Vector2) { screenWidth / 2, 50 }, player.size.x, player.size.y, 1);

    player.physic->freezeOrient = true;
    player.color = GREEN;

    SetTargetFPS(60); // Rodará a 60 FPS

    // Loop principal do game
    // Roda o game enquanto o usuário não apertar ESC
    while (!WindowShouldClose()) {

        RunPhysicsStep();

        if ( IsKeyDown(KEY_D) ) player.physic->velocity.x = VELOCITY;
        if ( IsKeyDown(KEY_A) ) player.physic->velocity.x = -VELOCITY;
        if ( IsKeyPressed(KEY_W) && player.physic->isGrounded ) player.physic->velocity.y = -VELOCITY*5;
        if ( IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && !player.attackCooldown ) {
            attackAni(&player);
            player.attackCooldown = 5;
        }

        player.color = player.attackCooldown ? YELLOW : GREEN;
        if ( player.attackCooldown ) {
            player.attackCooldown--;
            attackAni(&player);
        }

        // Inicializa a janela
        BeginDrawing();

            // Cor do background da janela
            ClearBackground(BLACK);

            int bodyCount = GetPhysicsBodiesCount();
            for ( int x = 0;  x < bodyCount; x++ ) {
                PhysicsBody drawedBody = GetPhysicsBody(x);

                int drawedBodyVertices = GetPhysicsShapeVerticesCount(x);
                for ( int y = 0; y < drawedBodyVertices; y++ ) {
                    Vector2 pointA = GetPhysicsShapeVertex(drawedBody, y);

                    int nextVertex = (y + 1) < drawedBodyVertices ? y + 1 : 0;
                    Vector2 pointB = GetPhysicsShapeVertex(drawedBody, nextVertex);

                    DrawLineV((Vector2) pointA, (Vector2) pointB, drawedBody->enabled ? player.color : BLUE);
                }
            }

        EndDrawing();
    }

    ClosePhysics();

    CloseWindow();        // Fecha a janela

    return 0;
}

void attackAni(player *player) {
    Rectangle attackArea;
    attackArea.x = player->physic->position.x + (player->size.x / 2);
    attackArea.y = player->physic->position.y - (player->size.y / 2);
    attackArea.width = 20;
    attackArea.height = player->size.y;

    BeginDrawing();

        DrawRectangle(attackArea.x, attackArea.y, attackArea.width, attackArea.height, RED);

    EndDrawing();
}