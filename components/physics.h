
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
        for(int j = 0; j< 14; j++)
        {
            if(buildings[i][j].physics == true)
            {
                if((buildings[i][j].block.x < heroi.physic->position.x + screenWidth/10) && (buildings[i][j].block.x > heroi.physic->position.x - screenWidth/10)&&(buildings[i][j].block.y < heroi.physic->position.y + screenHeight/4) && (buildings[i][j].block.y > heroi.physic->position.y - screenHeight/4))
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

void create_wall(int inicial, int final)
{
    wall[0] = CreatePhysicsBodyRectangle((Vector2){inicial*50 + 25, 200},1,600,10);
    wall[0]->enabled = false;
    wall[1] = CreatePhysicsBodyRectangle((Vector2){final*50 + 25, 200},1,600,10);
    wall[1]->enabled = false;
}

void destroy_walls()
{
    DestroyPhysicsBody(wall[0]);
    DestroyPhysicsBody(wall[1]);
}

void destroy_all_physics()
{
  int num_body = GetPhysicsBodiesCount();
  for (int i = 0; i < num_body; i++)
  {
      PhysicsBody body = GetPhysicsBody(i);
      DestroyPhysicsBody(body);
  }  
}


#endif