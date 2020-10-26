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

#define VELOCITY 0.3f

//___________________________________STRUCTS_______________________________________________
typedef struct {
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
} Player;

typedef struct
{
    bool hitted;
    int enemy;
}HeroHitted;


//__________________________________________________________________________________________

//___________________________________VARIABLES_______________________________________________
Vector2 playerBlock;
Player hero;
PhysicsBody wall[2];
Vector2 hit;


//____________________________________________________________________________________________

//________________________________FUNCTIONS DECLARATIONS_______________________________________

Rectangle CharacterAttack(Player *hero, bool reverse);
void UpdatePhysicsBody(Player *hero);
void UpdateGame(Player *hero);
void UpdatePlayerState(Player *hero);
void DrawEntities(Player *hero);
void HandleInputs(Player *hero);
void KillPlayer(Player *hero);
HeroHitted CheckPlayerAttacked(Player *hero);
//_____________________________________________________________________________________________

//___________________________________FUNCTIONS_________________________________________________

// Returns the area being attacked to check for collisions later
Rectangle CharacterAttack(Player *hero, bool reverse) {
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
void UpdatePhysicsBody(Player *hero)
{
    //for the hero
    hero->body.x = hero->physic->position.x - (hero->body.width / 2);
    hero->body.y = hero->physic->position.y - (hero->body.height / 2);

}

//Update the hero animation
void UpdatePlayerState(Player *hero) 
{
    if ( !hero->isAlive ) 
    {        
        // Dying animation
        int dyingFrame = hero->currentAnimation / 3;

        hero->state = characterDying[dyingFrame];

        if ( hero->currentAnimation < 44 ) hero->currentAnimation = hero->currentAnimation + 1;
    } 
    else if ( hero->attackCooldown != 0 ) 
    {    
        // Attacking animation
        if ( hero->currentAnimation > 11 ) hero->currentAnimation = 0;

        hero->state = characterSlashing[hero->currentAnimation];

        if ( hero->currentAnimation < 10 ) hero->currentAnimation = hero->currentAnimation + 1;
    } 
    else if ( hero->physic->velocity.y > 0.1 || hero->physic->velocity.y < -0.1 ) 
    { 
        // Jump animation
        if ( hero->currentAnimation > 10 ) hero->currentAnimation = 0;

        int jumpingFrame = hero->currentAnimation / 2;

        hero->state = characterJumping[jumpingFrame];

        if ( hero->currentAnimation < 10 ) hero->currentAnimation = hero->currentAnimation + 1;
    } 
    else if ( (hero->physic->velocity.x > 0.1 || hero->physic->velocity.x < -0.1) && hero->damageCooldown < 18 ) 
    {    
        // Running animation
        int runningFrame = hero->currentAnimation / 3;
        hero->state = characterRunning[runningFrame];

        hero->currentAnimation = hero->currentAnimation == 35 ? 0 : hero->currentAnimation + 1;
    }
    else if ( hero->damageCooldown != 0 ) 
    {   
        // Damage Animation
        int hurtingFrame = hero->currentAnimation / 3;

        hero->state = characterHurt[hurtingFrame];

        if ( hero->currentAnimation < 35 ) hero->currentAnimation++;
    }
    else if (hero->physic->velocity.y < 0.001 && hero->physic->velocity.y > 0) 
    {      
        // Stop Player
        hero->state = characterIdle;
        hero->currentAnimation = 0;
    }
}

void HandleInputs(Player *hero) 
{
    //left
    if ( IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) 
    {
        hero->physic->velocity.x = VELOCITY;
        hero->reverse = false;
    }

    //right
    if ( IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) 
    {
        hero->physic->velocity.x = -VELOCITY;
        hero->reverse = true;
    }
    
    //jump
    if ( (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) && hero->physic->velocity.y < 0.001 && hero->physic->velocity.y > 0 ) hero->physic->velocity.y = -VELOCITY*7;

    // Attack
    if ( (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) || IsKeyPressed(KEY_J)) && !hero->attackCooldown ) 
    {
        hero->attacking = true;
        CharacterAttack(hero, hero->reverse);
        hero->attackCooldown = 12;
    }
}

//if the hero died
void KillPlayer(Player *hero) 
{
    hero->currentAnimation = 0;
    hero->lives = 0;
    hero->isAlive = false;
    hero->physic->enabled = false;
}

//Draw hero life bar
void DrawLifeBar(Player *hero) 
{
    // draw the border
    DrawRectangleLines(50, screenHeight - 60, 100, 30, GRAY);
    // draw the life
    DrawRectangle(51, screenHeight - 59, ((100 / 3) * hero->lives) - 2, 28, RED);
}

//Draw the hero
void DrawEntities(Player *hero) 
{
    // Desenha os 'PhysicBodies'
    int bodyCount = GetPhysicsBodiesCount();
    for ( int x = 0;  x < bodyCount; x++ ) 
    {
        PhysicsBody DrawedBody = GetPhysicsBody(x);
        
        /* DEBUG
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

        }*/

        Color filteredColor = WHITE;

        if ( hero->damageCooldown != 0 ) 
        {
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


#ifndef ENEMY_H
#include "enemy.h"
#endif

#ifndef BOSS_H
#include "boss.h"
#endif

#ifndef SCREENS_H
#include "../screens/screens.h"
#endif

//Update the game variables
void UpdateGame(Player *hero) 
{
    //bug fix
    hero->physic->position.y -= 0.0005;
    hero->physic->velocity.y -= 0.008175;
    
    // Atualiza as animações
    UpdatePlayerState(hero);

    // Inputs
    if ( hero->isAlive && hero->damageCooldown < 18 ) HandleInputs(hero);

    if ( hero->body.y > screenHeight ) KillPlayer(hero);

    bool didGotDamage = CheckPlayerAttacked(hero).hitted;
    if ( didGotDamage && hero->damageCooldown == 0 && hero->isAlive ) 
    {
        hero->lives = hero->lives - 1;

        if ( hero->lives == 0 ) KillPlayer(hero);
        else {
            // hero gets damage
            hero->damageCooldown = 36;
            hero->currentAnimation = 0;
            if(hero->physic->position.x > (enemies[CheckPlayerAttacked(hero).enemy].bodyRec.x + enemies[CheckPlayerAttacked(hero).enemy].bodyRec.width/2))
            {
                hero->physic->velocity.x = VELOCITY*1.8;
            }
            else 
            {
                hero->physic->velocity.x = -VELOCITY*1.8;
            }

            if(hero->physic->position.x > boss.hitbox.x + boss.hitbox.width && CheckCollisionRecs(hero->body,boss.hitbox))
            {
                hero->physic->velocity.x = VELOCITY*1.8;
            }
            else if (CheckCollisionRecs(hero->body,boss.hitbox))
            {
                hero->physic->velocity.x = -VELOCITY*1.8;
            }
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

    // makes sure Player body rectangle coordenates is equal to Player physics coordenates
    UpdatePhysicsBody(hero);

}


HeroHitted CheckPlayerAttacked(Player *hero) 
{
    bool didGotDamage = false;
    int enemyHitted = 99;
    for ( int x = 0; x < 13; x++ ) 
    {
        if ( CheckCollisionRecs(hero->body, enemies[x].bodyRec) && enemies[x].gerated && enemies[x].bodyLife > 0 ) 
        {
            if ( enemies[x].currentPhase == 1 && currentScreen == LEVEL_ONE )
            {
                didGotDamage = true;
                enemyHitted = x;
            } 
            if ( enemies[x].currentPhase == 2 && currentScreen == LEVEL_TWO )
            {
                didGotDamage = true;
                enemyHitted = x;
            }
            if ( enemies[x].currentPhase == 3 && currentScreen == LEVEL_THREE )
            {
                didGotDamage = true;
                enemyHitted = x;
            }
        }
    }

    if ( CheckCollisionRecs(boss.hitbox, hero->body) && currentScreen == LEVEL_THREE && !(boss.life <= 0) ) didGotDamage = true;

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

    return (HeroHitted){didGotDamage, enemyHitted};
}

#endif