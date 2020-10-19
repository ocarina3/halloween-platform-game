#ifndef MAIN_CHARACTER_H
#define MAIN_CHARACTER_H


#include "raylib.h"
#include "math.h"

#define PHYSAC_IMPLEMENTATION
#define PHYSAC_NO_THREADS


#include "physac.h"

#define screenWidth 800
#define screenHeight 450

#define VELOCITY 0.4f

//___________________________________STRUCTS_______________________________________________
typedef struct enemy {
    PhysicsBody physic;
    Color color;
    Rectangle body;
    int health;
    bool isAlive;
} enemy;

typedef struct player {
    PhysicsBody physic;
    Color color;
    Rectangle body;
    int attackCooldown;
    int lives;
    bool reverse;
    bool isAlive;
} player;

typedef struct life {
    PhysicsBody physic;
    float radius;
    bool hasBeenTaken;
} life;

//__________________________________________________________________________________________

//___________________________________VARIABLES_______________________________________________

player heroi;

//____________________________________________________________________________________________

//________________________________FUNCTIONS DECLARATIONS_______________________________________

void attack(player *heroi, bool reverse, enemy *enemys[100], int counterEnemy, bool valid);
void updatePhysicsBody(player *heroi, enemy *enemys[100], int counterEnemy);
void updateGame(player *heroi, enemy *enemys[100], life *lifes[50], int *countEnemys, int *countLifes);
void DrawEntities(player *heroi, enemy *enemys[100], life *lifes[50], int countEnemys, int countLifes);
enemy addEnemy(Vector2 pos);
int checkheroiCollision(player *heroi, enemy *enemys[100], int counterEnemy, life *lifes[50], int counterLifes);

//_____________________________________________________________________________________________

//___________________________________FUNCTIONS_________________________________________________

//attack configuration
void attack(player *heroi, bool reverse, enemy *enemys[100], int counterEnemy, bool valid) 
{

    //________________________________TODO___________________________________________
    // rever as variaveis e colocar a um bloco de distancia para que seja atingido
    //_______________________________________________________________________________


    //variables
    Rectangle attackArea;
    attackArea.width = 30;
    attackArea.height = heroi->body.height;
    attackArea.y = heroi->physic->position.y - (heroi->body.height / 2);
    
    //check if the hero is attacking right or left
    if ( !reverse ) 
    {
        attackArea.x = heroi->physic->position.x + (heroi->body.width / 2);
    } else 
    {
        attackArea.x = heroi->physic->position.x - (heroi->body.width / 2) - attackArea.width;
    }

    //check if hits a enemy
    if ( valid ) {
        for ( int x = 0; x < counterEnemy; x++ ) 
        {
            if ( CheckCollisionRecs(attackArea, enemys[x]->body) ) 
            {
                enemys[x]->health--;
                if ( enemys[x]->health == 2 ) enemys[x]->color = YELLOW;
                if ( enemys[x]->health == 1 ) enemys[x]->color = RED;
                if ( enemys[x]->health == 0 ) enemys[x]->isAlive = false;
            }
        }
    }
}

//Get the new position of all the physics body
void updatePhysicsBody(player *heroi, enemy *enemys[100], int counterEnemy)
{
    //for the hero
    heroi->body.x = (heroi->physic->position.x - (heroi->body.width / 2));
    heroi->body.y = (heroi->physic->position.y - (heroi->body.height / 2));

    //for the enemys
    for ( int x = 0; x < counterEnemy; x++ ) 
    {
        enemys[x]->body.x = enemys[x]->physic->position.x - (enemys[x]->body.width / 2);
        enemys[x]->body.y = enemys[x]->physic->position.y - (enemys[x]->body.height / 2);
    }
}

//update the game variables
void updateGame(player *heroi, enemy *enemys[100], life *lifes[50], int *countEnemys, int *countLifes) 
{
    //check if a enemy is dead
    for( int x = 0; x < *countEnemys; x++ ) 
    {
        if ( !enemys[x]->isAlive ) 
        {
            DestroyPhysicsBody(enemys[x]->physic);

            for ( int y = x; y < *countEnemys - 1; y++) enemys[y] = enemys[y + 1];
            *countEnemys = *countEnemys - 1;
        }
    }

    //check if life has been taken
    for( int x = 0; x < *countLifes; x++ ) 
    {
        if ( lifes[x]->hasBeenTaken ) 
        {
            DestroyPhysicsBody(lifes[x]->physic);

            for ( int y = x; y < *countLifes - 1; y++) lifes[y] = lifes[y + 1];
            *countLifes = *countLifes - 1;
        }
    }

    // Inputs
    if ( IsKeyDown(KEY_D) ) 
    {
        heroi->physic->velocity.x = VELOCITY;
        heroi->reverse = false;
    }
    if ( IsKeyDown(KEY_A) ) 
    {
        heroi->physic->velocity.x = -VELOCITY;
        heroi->reverse = true;
    }
    if ( IsKeyPressed(KEY_W) && heroi->physic->velocity.y < 0.2 && heroi->physic->velocity.y > 0) heroi->physic->velocity.y = -VELOCITY*5;

    // Attack
    if ( IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && !heroi->attackCooldown && heroi->isAlive ) 
    {
        attack(heroi, heroi->reverse, enemys, *countEnemys, true);
        heroi->attackCooldown = 5;
    }

    //change color for Cooldown
    if ( heroi->isAlive ) heroi->color = heroi->attackCooldown ? YELLOW : GREEN;
    if ( heroi->attackCooldown && heroi->isAlive ) 
    {
        heroi->attackCooldown--;
        attack(heroi, heroi->reverse, enemys, *countEnemys, false);
    }

    //checks collision between bodies
    updatePhysicsBody(heroi, enemys, *countEnemys);

    int entityCollision = checkheroiCollision(heroi, enemys, *countEnemys, lifes, *countLifes);
    
    //hero touched the enemy
    if ( entityCollision == 1 && heroi->isAlive ) 
    {
        heroi->lives--;
        heroi->color = RED;

        if ( heroi->lives == 0 ) heroi->isAlive = false;
        else 
        {
            heroi->physic->position.x = screenWidth / 2;
            heroi->physic->position.y = 50;
        }
    }

    //hero get the life
    if ( entityCollision == 2 && heroi->isAlive ) 
    {
        if ( heroi->lives < 3 ) heroi->lives++;
    }
}

//add the enemy
enemy addEnemy(Vector2 pos) 
{
    //create enemy
    enemy enemy;
    enemy.body = (Rectangle) { pos.x, pos.y, 25, 40 };
    enemy.physic = CreatePhysicsBodyRectangle(
        (Vector2) { enemy.body.x, enemy.body.y },
        enemy.body.width,
        enemy.body.height,
        8
    );
    enemy.physic->freezeOrient = true;
    enemy.color = BROWN;
    enemy.health = 3;
    enemy.isAlive = true;

    return enemy;
}

//check if the hero touched something
int checkheroiCollision(player *heroi, enemy *enemys[100], int counterEnemy, life *lifes[50], int counterLifes) 
{
    bool hasEnemyCollision = false, hasLifeCollision = false;

    int bodyCount = GetPhysicsBodiesCount();
    for ( int x = 0; x < bodyCount; x++ ) 
    {
        //variables
        PhysicsBody body = GetPhysicsBody(x);

        int isEnemy = 0;
        int isLife = 0;

        enemy enemy;
        life *life;

        //check enemys
        for ( int x = 0; x < counterEnemy; x++ ) 
        {
            if ( body->id == enemys[x]->physic->id ) 
            {
                isEnemy = 1;
                enemy = *enemys[x];
            }
        }

        //check lifes
        for ( int x = 0; x < counterLifes; x++ ) 
        {
            if ( body->id == lifes[x]->physic->id ) 
            {
                isLife = 1;
                life = lifes[x];
            }
        }
        
        if( isEnemy && CheckCollisionRecs(heroi->body, enemy.body) ) hasEnemyCollision = true;
        if ( isLife && CheckCollisionCircleRec((Vector2) life->physic->position, life->radius, heroi->body) ) 
        {
            life->hasBeenTaken = true;
            hasLifeCollision = true;
        }
    }

    if (hasEnemyCollision) return 1;
    if (hasLifeCollision) return 2;
    return 0;
}


#endif