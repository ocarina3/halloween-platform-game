#ifndef PHASE_H
#define PHASE_H

#include "physics.h"
#include "draw_texture.h"


int countEnemys = 0, countLifes = 0;
enemy *enemys[100];
life *lifes[50];

enemy e1 ,e2, e3;
life l1, l2;

Vector2 player_block;
Camera2D camera;
Vector2 tilePosition;

void start_variables()
{
    //_______________________________________________________
    heroi.body = (Rectangle) { screenWidth / 2, 50, 40, 40 };
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
    heroi.color = GREEN;
    heroi.reverse = false;
    heroi.isAlive = true;

    //inicializar os inimigos
    e1 = addEnemy((Vector2) { screenWidth - 40, 50 });
    e2 = addEnemy((Vector2) { 40, 50 });
    e3 = addEnemy((Vector2) { 120, 50 });
    enemys[countEnemys++] = &e1;
    enemys[countEnemys++] = &e2;
    enemys[countEnemys++] = &e3;
    
    //inicializar as vidas
    
    l1.radius = 10;
    l1.hasBeenTaken = false;
    l2.radius = 10;
    l2.hasBeenTaken = false;
    l1.physic = CreatePhysicsBodyCircle((Vector2) { 90, screenHeight / 2 }, l1.radius, 10);
    l1.physic->enabled = false;
    l2.physic = CreatePhysicsBodyCircle((Vector2) { screenWidth - 90, screenHeight / 2 }, l2.radius, 10);
    l2.physic->enabled = false;
    lifes[countLifes++] = &l1;
    lifes[countLifes++] = &l2; 
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
}

#endif