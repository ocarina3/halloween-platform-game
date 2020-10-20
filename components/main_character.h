#ifndef MAIN_CHARACTER_H
#define MAIN_CHARACTER_H


#include "raylib.h"


#define PHYSAC_IMPLEMENTATION
#define PHYSAC_NO_THREADS


#include "physac.h"

#define screenWidth 800
#define screenHeight 450

#define VELOCITY 0.4f

//___________________________________STRUCTS_______________________________________________

typedef struct player {
    PhysicsBody physic;
    Color color;
    Rectangle body;
    int attackCooldown;
    int lives;
    bool reverse;
    bool isAlive;
} player;

//__________________________________________________________________________________________

//___________________________________VARIABLES_______________________________________________
Vector2 player_block;
player heroi;
PhysicsBody wall[2];
Vector2 hit;
//____________________________________________________________________________________________

//________________________________FUNCTIONS DECLARATIONS_______________________________________

Vector2 attack(player *heroi, bool reverse, bool valid);
void updatePhysicsBody(player *heroi);
void updateGame(player *heroi);

//_____________________________________________________________________________________________

//___________________________________FUNCTIONS_________________________________________________

//attack configuration
Vector2 attack(player *heroi, bool reverse, bool valid) 
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
    } 
    else 
    {
        attackArea.x = heroi->physic->position.x - (heroi->body.width / 2) - attackArea.width;
    }

    return (Vector2){attackArea.x,attackArea.y};

}

//Get the new position of all the physics body
void updatePhysicsBody(player *heroi)
{
    //for the hero
    heroi->body.x = heroi->physic->position.x - (heroi->body.width / 2);
    heroi->body.y = heroi->physic->position.y - (heroi->body.height / 2);

}

//update the game variables
void updateGame(player *heroi) 
{
    //bug fix
    heroi->physic->position.y -= 0.0005;
    heroi->physic->velocity.y -= 0.008175;
    
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
    if ( IsKeyPressed(KEY_W) && heroi->physic->velocity.y < 0.001 && heroi->physic->velocity.y >= 0) heroi->physic->velocity.y = -VELOCITY*5;

    // Attack
    if ( IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && !heroi->attackCooldown && heroi->isAlive ) 
    {
        hit = attack(heroi, heroi->reverse, true);
        heroi->attackCooldown = 5;
    }

    //change color for Cooldown
    if ( heroi->attackCooldown && heroi->isAlive ) 
    {
        heroi->attackCooldown--;
        attack(heroi, heroi->reverse,false);
    }


    //checks collision between bodies
    updatePhysicsBody(heroi);

}


#endif