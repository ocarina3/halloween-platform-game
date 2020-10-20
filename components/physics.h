
#ifndef PHYSIC_H
#define PHYSIC_H

#include "main_character.h"
#include "get_map.h"

Vector2 get_player_block()
{
    //variables
    Vector2 player_block;
    player_block.x = 0;
    player_block.y = 0 ;
    
    //get the player block position
    for(int i = 0; i < 320 ; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if(heroi.physic->position.y >= buildings[i][j].block.y && heroi.physic->position.y < buildings[i][j].block.y + buildings[i][j].block.height)
            {
                player_block.y = j;
            }
            if(heroi.physic->position.x >= buildings[i][j].block.x && heroi.physic->position.x < buildings[i][j].block.x + buildings[i][j].block.width)
            {
                player_block.x = i;
            }    
        }
    }
    return player_block;   
}


void ativate_physics()
{
    for(int i = 0; i < 320 ; i++)
    {
        for(int j = 0; j< 9; j++)
        {
            if(buildings[i][j].physics == true)
            {
                if((buildings[i][j].block.x < heroi.physic->position.x + screenWidth/8) && (buildings[i][j].block.x > heroi.physic->position.x - screenWidth/8))
                {
                    if (buildings[i][j].physics_created == false)
                    {
                        buildings[i][j].physics_block = CreatePhysicsBodyRectangle((Vector2){buildings[i][j].block.x +25 ,buildings[i][j].block.y +25},buildings[i][j].block.width,buildings[i][j].block.height,10);
                        buildings[i][j].physics_block->enabled = false;
                        buildings[i][j].physics_created = true;
                    }
                }
                else if (buildings[i][j].physics_created == true)
                {
                    DestroyPhysicsBody(buildings[i][j].physics_block);
                    buildings[i][j].physics_created = false;
                }
            }
        }        
    }                
                    
                        
}


void destroy_all_physics()
{
    DestroyPhysicsBody(heroi.physic);
    for(int i = 0; i < 320 ; i++)
    {
        for(int j = 0; j< 9; j++)
        {
            if (buildings[i][j].physics_created == true)
            {
                DestroyPhysicsBody(buildings[i][j].physics_block);
                buildings[i][j].physics_created = false;
            }
        }
    }    
}


#endif