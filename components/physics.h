
#ifndef PHYSIC_H
#define PHYSIC_H

#include "main_character.h"
#include "get_map.h"

Vector2 GetPlayerBlock()
{
    //variables
    Vector2 playerBlock;
    playerBlock.x = 0;
    playerBlock.y = 0 ;
    
    //get the player block position
    for(int i = 0; i < 320 ; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if(hero.physic->position.y >= buildings[i][j].block.y && hero.physic->position.y < buildings[i][j].block.y + buildings[i][j].block.height)
            {
                playerBlock.y = j;
            }
            if(hero.physic->position.x >= buildings[i][j].block.x && hero.physic->position.x < buildings[i][j].block.x + buildings[i][j].block.width)
            {
                playerBlock.x = i;
            }    
        }
    }
    return playerBlock;   
}


void ActivatePhysics()
{
    for(int i = 0; i < 320 ; i++)
    {
        for(int j = 0; j< 14; j++)
        {
            if(buildings[i][j].physics == true)
            {
                if((buildings[i][j].block.x < hero.physic->position.x + screenWidth/10) && (buildings[i][j].block.x > hero.physic->position.x - screenWidth/10)&&(buildings[i][j].block.y < hero.physic->position.y + screenHeight/4) && (buildings[i][j].block.y > hero.physic->position.y - screenHeight/4))
                {
                    if (buildings[i][j].physicsCreated == false)
                    {
                        buildings[i][j].physicsBlock = CreatePhysicsBodyRectangle((Vector2){buildings[i][j].block.x +25 ,buildings[i][j].block.y +25},buildings[i][j].block.width,buildings[i][j].block.height,10);
                        buildings[i][j].physicsBlock->enabled = false;
                        buildings[i][j].physicsCreated = true;
                    }
                }
                else
                {
                    if (buildings[i][j].physicsCreated == true)
                    {
                        DestroyPhysicsBody(buildings[i][j].physicsBlock);
                        buildings[i][j].physicsCreated = false;
                    }
                }
            }
        }        
    }                
                    
                        
}

void CreateWall(int inicial, int final)
{
    wall[0] = CreatePhysicsBodyRectangle((Vector2){inicial*50 + 25, 200},1,600,10);
    wall[0]->enabled = false;
    wall[1] = CreatePhysicsBodyRectangle((Vector2){final*50 + 25, 200},1,600,10);
    wall[1]->enabled = false;
}

void DestroyWalls()
{
    DestroyPhysicsBody(wall[0]);
    DestroyPhysicsBody(wall[1]);
}

void DestroyAllPhysics()
{
    DestroyPhysicsBody(hero.physic);
    for(int i = 0; i < 320 ; i++)
    {
        for(int j = 0; j< 14; j++)
        {
            if(buildings[i][j].physics == true)
            {
                DestroyPhysicsBody(buildings[i][j].physicsBlock);
            }
        }
    }
}


#endif