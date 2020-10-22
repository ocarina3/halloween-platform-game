#ifndef MAIN_CHARACTER_H
#define MAIN_CHARACTER_H


#include "raylib.h"
#include "../resources/char_textures.h"

#ifndef PHYSAC_H
#define PHYSAC_IMPLEMENTATION
#define PHYSAC_NO_THREADS


#include "physac.h"
#endif

#define screenWidth 800
#define screenHeight 450

#define VELOCITY 0.4f

//___________________________________STRUCTS_______________________________________________
typedef struct player {
    PhysicsBody physic;
    Texture2D state;
    Rectangle body;
    int attackCooldown;
    int damageCooldown;
    int lives;
    int currentAnimation;
    bool reverse;
    bool isAlive;
    bool attacking;
} player;

//__________________________________________________________________________________________

//___________________________________VARIABLES_______________________________________________
Vector2 player_block;
player heroi;
PhysicsBody wall[2];
Vector2 hit;


//____________________________________________________________________________________________

//________________________________FUNCTIONS DECLARATIONS_______________________________________

Rectangle attack(player *heroi, bool reverse);
void updatePhysicsBody(player *heroi);
void updateGame(player *heroi);
void updatePlayerState(player *heroi);
void DrawEntities(player *heroi);
bool CheckPlayerAttacked(player *heroi);
//_____________________________________________________________________________________________

//___________________________________FUNCTIONS_________________________________________________

// Retorna a área que está sendo atacada para checar colisões posteriormente
Rectangle attack(player *heroi, bool reverse) {
    Rectangle attackArea;
    attackArea.width = 30;
    attackArea.height = heroi->body.height;
    attackArea.y = heroi->physic->position.y - (heroi->body.height / 2);
    if ( !reverse ) 
    {
        attackArea.x = heroi->physic->position.x + (heroi->body.width / 2);
    } else 
    {
        attackArea.x = heroi->physic->position.x - (heroi->body.width / 2) - attackArea.width/2;
    }

    return attackArea;
}

#ifndef ENEMY_H
#include "enemy.h"
#endif

//Get the new position of all the physics body
void updatePhysicsBody(player *heroi)
{
    //for the hero
    heroi->body.x = heroi->physic->position.x - (heroi->body.width / 2);
    heroi->body.y = heroi->physic->position.y - (heroi->body.height / 2);

}

void updatePlayerState(player *heroi) {
    if ( !heroi->isAlive ) {
        int dyingFrame = heroi->currentAnimation / 3;

        heroi->state = mc_dying[dyingFrame];

        if ( heroi->currentAnimation < 44 ) heroi->currentAnimation = heroi->currentAnimation + 1;
    }
    else if ( heroi->attackCooldown != 0 ) {
        if ( heroi->currentAnimation > 11 ) heroi->currentAnimation = 0;

        heroi->state = mc_slashing[heroi->currentAnimation];

        if ( heroi->currentAnimation < 10 ) heroi->currentAnimation = heroi->currentAnimation + 1;
    }
    else if ( heroi->physic->velocity.y > 0.1 || heroi->physic->velocity.y < -0.1 ) {
        // Jump animation

        if ( heroi->currentAnimation > 10 ) heroi->currentAnimation = 0;

        int jumpingFrame = heroi->currentAnimation / 2;

        heroi->state = mc_jumping[jumpingFrame];

        if ( heroi->currentAnimation < 10 ) heroi->currentAnimation = heroi->currentAnimation + 1;
    } else
     if ( heroi->physic->velocity.x > 0.1 || heroi->physic->velocity.x < -0.1 ) {
        // Running animation
        int runningFrame = heroi->currentAnimation / 3;
        heroi->state = mc_running[runningFrame];

        heroi->currentAnimation = heroi->currentAnimation == 35 ? 0 : heroi->currentAnimation + 1;

    } else if (heroi->physic->velocity.y < 0.001 && heroi->physic->velocity.y > 0) {
        // Stop player
        heroi->state = mc_stop;
        heroi->currentAnimation = 0;
    }
}

void DrawEntities(player *heroi) {

    

    // Desenha os 'PhysicBodies'
    int bodyCount = GetPhysicsBodiesCount();
    for ( int x = 0;  x < bodyCount; x++ ) {
        PhysicsBody drawedBody = GetPhysicsBody(x);

        //help indentification
        int drawedBodyVertices = GetPhysicsShapeVerticesCount(x);
        for ( int y = 0; y < drawedBodyVertices; y++ ) 
        {
            Vector2 pointA = GetPhysicsShapeVertex(drawedBody, y);

            int nextVertex = (y + 1) < drawedBodyVertices ? y + 1 : 0;
            Vector2 pointB = GetPhysicsShapeVertex(drawedBody, nextVertex);

            //if ( drawedBody->id == heroi->physic->id ) continue;
            DrawLineV((Vector2) pointA, (Vector2) pointB, BLUE);
            
            if (heroi->attacking ==true)
            {
                DrawRectangleRec(attack(heroi,heroi->reverse), BLUE);
            }

        }

        Color filteredColor = WHITE;

        if ( heroi->damageCooldown != 0 ) {
            int colorSelector = heroi->damageCooldown % 6;

            if ( colorSelector < 3 ) filteredColor = RED;
            else filteredColor = GREEN;
        }

        if ( drawedBody->id == heroi->physic->id ) DrawTextureRec(
            heroi->state, 
            heroi->reverse ?
            (Rectangle) { 0, 0, -(heroi->body.width + 20), heroi->body.height + 15 } :
            (Rectangle) { 0, 0, heroi->body.width + 20, heroi->body.height + 15 },
            (Vector2) { heroi->body.x - 10, heroi->body.y - 10 },
            heroi->isAlive ? filteredColor : GRAY
        );
    }
}

//update the game variables
void updateGame(player *heroi) 
{
    //bug fix
    heroi->physic->position.y -= 0.0005;
    heroi->physic->velocity.y -= 0.008175;
    
    // Atualiza as animações
    updatePlayerState(heroi);

    // Inputs
    if ( IsKeyDown(KEY_D) && heroi->isAlive ) {
        heroi->physic->velocity.x = VELOCITY;
        heroi->reverse = false;
    }
    if ( IsKeyDown(KEY_A) && heroi->isAlive ) {
        heroi->physic->velocity.x = -VELOCITY;
        heroi->reverse = true;
    }
    if ( IsKeyPressed(KEY_W) && heroi->physic->velocity.y < 0.001 && heroi->physic->velocity.y > 0 && heroi->isAlive ) heroi->physic->velocity.y = -VELOCITY*5;

    // Ataca
    if ( IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && !heroi->attackCooldown && heroi->isAlive ) 
    {
        heroi->attacking = true;
        attack(heroi, heroi->reverse);
        heroi->attackCooldown = 12;
    }

    bool didGotDamage = CheckPlayerAttacked(heroi);
    if ( didGotDamage && heroi->damageCooldown == 0 && heroi->isAlive ) 
    {
        heroi->lives = heroi->lives - 1;

        if ( heroi->lives == 0 ) {
            heroi->currentAnimation = 0;
            heroi->isAlive = false;
        }
        else heroi->damageCooldown = 36;
    }

    if ( heroi->damageCooldown > 0 ) heroi->damageCooldown = heroi->damageCooldown - 1;


    if ( heroi->attackCooldown && heroi->isAlive ) 
    {
        heroi->attacking = true;
        heroi->attackCooldown--;
        attack(heroi, heroi->reverse);
    }

    if (heroi->attackCooldown == 0) 
    {
        heroi->attacking = false;
    }

    // makes sure player body rectangle coordenates is equal to player physics coordenates
    updatePhysicsBody(heroi);

}

bool CheckPlayerAttacked(player *heroi) {
    bool didGotDamage = false;
    for ( int x = 0; x < 10; x++ ) {
        if ( CheckCollisionRecs(heroi->body, enemies[x].body_rec) && enemies[x].gerated ) didGotDamage = true;
    }
    return didGotDamage;
}

#endif