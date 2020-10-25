#ifndef PHASE_H
#define PHASE_H

#include "physics.h"
#include "draw_texture.h"
#include "enemy.h"

Camera2D camera;

void StartVariables()
{
    StartEnemyVariables();
    //_______________________________________________________
    hero.body = (Rectangle) { screenWidth / 2, 40, 30, 40 };
    hero.physic = CreatePhysicsBodyRectangle(
        (Vector2) { hero.body.x, hero.body.y }, 
        hero.body.width, 
        hero.body.height, 
        1
    );
    hero.physic->velocity.y = 0;
    hero.physic->velocity.x = 0;
    hero.physic->freezeOrient = true;
    hero.attackCooldown = 0;
    hero.damageCooldown = 0;
    hero.lives = 3;
    hero.reverse = false;
    hero.isAlive = true;
    hero.attacking = false;

    //__________________________________________________________________________________________________
    //start camera position
    camera.target = (Vector2){ hero.physic->position.x + 20, hero.physic->position.y + 20};
    camera.offset = (Vector2){ screenWidth/2, screenHeight/2 };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    //start the blocks
    for(int i = 0; i < 320 ; i++)
    {
        for(int j = 0; j < 14; j++)
        {
            
            buildings[i][j].draw = false;
            buildings[i][j].block.x = (i)*buildings_height;
            buildings[i][j].block.y = (j)*buildings_height;
            buildings[i][j].block.width = buildings_width;
            buildings[i][j].block.height = buildings_height;
            buildings[i][j].physics = false;
            buildings[i][j].physicsCreated = false;
        }
    }

    
}

#endif