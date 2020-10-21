#ifndef PHASE_H
#define PHASE_H

#include "physics.h"
#include "draw_texture.h"



Camera2D camera;


void start_variables()
{

    //_______________________________________________________
    heroi.body = (Rectangle) { screenWidth / 2, 40, 40, 40 };
    heroi.physic = CreatePhysicsBodyRectangle(
        (Vector2) { heroi.body.x, heroi.body.y }, 
        heroi.body.width, 
        heroi.body.height, 
        1
    );
    heroi.physic->velocity.y = 0;
    heroi.physic->velocity.x = 0;
    heroi.physic->freezeOrient = true;
    heroi.attackCooldown = 0;
    heroi.lives = 3;
    heroi.reverse = false;
    heroi.isAlive = true;

    //__________________________________________________________________________________________________
    //start camera position
    camera.target = (Vector2){ heroi.physic->position.x + 20, heroi.physic->position.y + 20};
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
            buildings[i][j].physics_created = false;
        }
    }

    for(int i = 0 ;i < 10; i++)
    {
        week[i].active = false;
    }    
}

#endif