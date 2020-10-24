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
Vector2 playerBlock;
player hero;
PhysicsBody wall[2];
Vector2 hit;


//____________________________________________________________________________________________

//________________________________FUNCTIONS DECLARATIONS_______________________________________

Rectangle CharacterAttack(player *hero, bool reverse);
void UpdatePhysicsBody(player *hero);
void UpdateGame(player *hero);
void UpdatePlayerState(player *hero);
void DrawEntities(player *hero);
void HandleInputs(player *hero);
void KillPlayer(player *hero);
bool CheckPlayerAttacked(player *hero);
//_____________________________________________________________________________________________

//___________________________________FUNCTIONS_________________________________________________

// Retorna a área que está sendo atacada para checar colisões posteriormente
Rectangle CharacterAttack(player *hero, bool reverse) {
    Rectangle attackArea;
    attackArea.width = 30;
    attackArea.height = hero->body.height;
    attackArea.y = hero->physic->position.y - (hero->body.height / 2);
    if ( !reverse ) 
    {
        attackArea.x = hero->physic->position.x + (hero->body.width / 2);
    } else 
    {
        attackArea.x = hero->physic->position.x - (hero->body.width / 2) - attackArea.width;
    }

    return attackArea;
}

//Get the new position of all the physics body
void UpdatePhysicsBody(player *hero)
{
    //for the hero
    hero->body.x = hero->physic->position.x - (hero->body.width / 2);
    hero->body.y = hero->physic->position.y - (hero->body.height / 2);

}

void UpdatePlayerState(player *hero) {
    if ( !hero->isAlive ) {
        // Dying animation

        int dyingFrame = hero->currentAnimation / 3;

        hero->state = characterDying[dyingFrame];

        if ( hero->currentAnimation < 44 ) hero->currentAnimation = hero->currentAnimation + 1;
    } 
    else if ( hero->attackCooldown != 0 ) {
        // Attacking animation

        if ( hero->currentAnimation > 11 ) hero->currentAnimation = 0;

        hero->state = characterSlashing[hero->currentAnimation];

        if ( hero->currentAnimation < 10 ) hero->currentAnimation = hero->currentAnimation + 1;
    } 
    else if ( hero->physic->velocity.y > 0.1 || hero->physic->velocity.y < -0.1 ) {
        // Jump animation

        if ( hero->currentAnimation > 10 ) hero->currentAnimation = 0;

        int jumpingFrame = hero->currentAnimation / 2;

        hero->state = characterJumping[jumpingFrame];

        if ( hero->currentAnimation < 10 ) hero->currentAnimation = hero->currentAnimation + 1;
    } 
    else if ( (hero->physic->velocity.x > 0.1 || hero->physic->velocity.x < -0.1) && hero->damageCooldown < 18 ) {
        // Running animation
        int runningFrame = hero->currentAnimation / 3;
        hero->state = characterRunning[runningFrame];

        hero->currentAnimation = hero->currentAnimation == 35 ? 0 : hero->currentAnimation + 1;

    }
    else if ( hero->damageCooldown != 0 ) {
        // Damage Animation
        
        int hurtingFrame = hero->currentAnimation / 3;

        hero->state = characterHurt[hurtingFrame];

        if ( hero->currentAnimation < 35 ) hero->currentAnimation++;
    }
    else if (hero->physic->velocity.y < 0.001 && hero->physic->velocity.y > 0) {
        // Stop player
        hero->state = characterIdle;
        hero->currentAnimation = 0;
    }
}

void HandleInputs(player *hero) {
    if ( IsKeyDown(KEY_D) ) {
        hero->physic->velocity.x = VELOCITY;
        hero->reverse = false;
    }
    if ( IsKeyDown(KEY_A) ) {
        hero->physic->velocity.x = -VELOCITY;
        hero->reverse = true;
    }
    if ( IsKeyPressed(KEY_W) && hero->physic->velocity.y < 0.001 && hero->physic->velocity.y > 0 ) hero->physic->velocity.y = -VELOCITY*5;

    // Ataca
    if ( IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && !hero->attackCooldown ) {
        hero->attacking = true;
        CharacterAttack(hero, hero->reverse);
        hero->attackCooldown = 12;
    }
}

void KillPlayer(player *hero) {
    hero->currentAnimation = 0;
    hero->lives = 0;
    hero->isAlive = false;
    hero->physic->enabled = false;
}

void DrawEntities(player *hero) {
    // Desenha os 'PhysicBodies'
    int bodyCount = GetPhysicsBodiesCount();
    for ( int x = 0;  x < bodyCount; x++ ) {
        PhysicsBody DrawedBody = GetPhysicsBody(x);

        //help indentification
        int DrawedBodyVertices = GetPhysicsShapeVerticesCount(x);
        for ( int y = 0; y < DrawedBodyVertices; y++ ) 
        {
            Vector2 pointA = GetPhysicsShapeVertex(DrawedBody, y);

            int nextVertex = (y + 1) < DrawedBodyVertices ? y + 1 : 0;
            Vector2 pointB = GetPhysicsShapeVertex(DrawedBody, nextVertex);

            //if ( DrawedBody->id == hero->physic->id ) continue;
            DrawLineV((Vector2) pointA, (Vector2) pointB, BLUE);
            
            if (hero->attacking ==true)
            {
                DrawRectangleRec(CharacterAttack(hero,hero->reverse), BLUE);
            }

        }

        Color filteredColor = WHITE;

        if ( hero->damageCooldown != 0 ) {
            int colorSelector = hero->damageCooldown % 6;

            if ( colorSelector < 3 ) filteredColor = RED;
            else filteredColor = GREEN;
        }

        if ( DrawedBody->id == hero->physic->id ) DrawTextureRec(
            hero->state, 
            hero->reverse ?
            (Rectangle) { 0, 0, -(hero->body.width + 20), hero->body.height + 15 } :
            (Rectangle) { 0, 0, hero->body.width + 20, hero->body.height + 15 },
            (Vector2) { hero->body.x - 10, hero->body.y - 10 },
            hero->isAlive ? filteredColor : GRAY
        );
    }
}

//Update the game variables
void UpdateGame(player *hero) 
{
    //bug fix
    hero->physic->position.y -= 0.0005;
    hero->physic->velocity.y -= 0.008175;
    
    // Atualiza as animações
    UpdatePlayerState(hero);

    // Inputs
    if ( hero->isAlive && hero->damageCooldown < 18 ) HandleInputs(hero);

    if ( hero->body.y > screenHeight ) KillPlayer(hero);

    bool didGotDamage = CheckPlayerAttacked(hero);
    if ( didGotDamage && hero->damageCooldown == 0 && hero->isAlive ) 
    {
        hero->lives = hero->lives - 1;

        if ( hero->lives == 0 ) KillPlayer(hero);
        else {
            // hero gets damage
            hero->damageCooldown = 36;
            hero->currentAnimation = 0;
            hero->physic->velocity.x = hero->reverse ? 
            VELOCITY*1.8 :
            -(VELOCITY*1.8);
        }
    }

    if ( hero->damageCooldown > 0 ) hero->damageCooldown = hero->damageCooldown - 1;


    if ( hero->attackCooldown && hero->isAlive ) 
    {
        hero->attacking = true;
        hero->attackCooldown--;
        CharacterAttack(hero, hero->reverse);
    }

    if (hero->attackCooldown == 0) 
    {
        hero->attacking = false;
    }

    // makes sure player body rectangle coordenates is equal to player physics coordenates
    UpdatePhysicsBody(hero);

}

#ifndef ENEMY_H
#include "enemy.h"
#endif

#ifndef BOSS_H
#include "boss.h"
#endif

#ifndef SCREENS_H
#include "../screens/screens.h"
#endif

bool CheckPlayerAttacked(player *hero) {
    bool didGotDamage = false;
    for ( int x = 0; x < 10; x++ ) {
        if ( CheckCollisionRecs(hero->body, enemies[x].body_rec) && enemies[x].gerated && currentScreen == LEVEL_ONE ) didGotDamage = true;
    }

    if ( CheckCollisionRecs(boss.hitbox, hero->body) && currentScreen == LEVEL_THREE ) didGotDamage = true;

    for ( int x = 0; x < 2; x++ ) {
        if ( 
            hero->body.y <= ray[x].y + 30 && 
            hero->body.y + hero->body.height >= ray[x].y &&
            ray[x].mode == 2 &&
            !ray[x].alreadyHit && 
            currentScreen == LEVEL_THREE
        ) didGotDamage = true;

        if ( didGotDamage ) ray[x].alreadyHit = 1;
    }

    return didGotDamage;
}

#endif