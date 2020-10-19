
#ifndef PHYSIC_H
#define PHYSIC_H

#include "main_character.h"
#include "get_map.h"

PhysicsBody physics_block[3][3];
bool check_existence[6]; 

Vector2 get_player_block()
{
    //variables
    Vector2 player_block;
    player_block.x = 0;
    player_block.y = 0 ;
    
    //get the player block position
    for(int i = 0; i < 320 ; i++)
    {
        for(int j = 0; j < 14; j++)
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

void create_physic_map()
{
    //variables
    Vector2 player_block = get_player_block();
    int posi_down = 0;
    int posj_down = 0;
    int posi_right = 0;
    int posj_right = 0;
    int posi_left = 0;
    int posj_left = 0;

    //checks if the body is close to an object, if it is, make it physical
    
    //create the physic block on the floor
    if( buildings[(int)(player_block.x)][(int)(player_block.y) +1].draw == true && check_existence[0] == false )
    {       
        physics_block[1][2] = CreatePhysicsBodyRectangle((Vector2){buildings[(int)(player_block.x)][(int)(player_block.y) + 1].block.x,buildings[(int)(player_block.x)][(int)(player_block.y) + 1].block.y + 25},buildings[(int)(player_block.x)][(int)(player_block.y) + 1].block.width,buildings[(int)(player_block.x)][(int)(player_block.y) + 1].block.height,10);
        physics_block[1][2]->enabled = false;
        heroi.physic->velocity.y -= 0.1;
        //create the right floor
        if(buildings[(int)(player_block.x) + 1][(int)(player_block.y) + 1].draw == true)
        {
            physics_block[2][2] = CreatePhysicsBodyRectangle((Vector2){buildings[(int)(player_block.x) + 1][(int)(player_block.y) + 1].block.x,buildings[(int)(player_block.x) + 1][(int)(player_block.y) + 1].block.y + 25},buildings[(int)(player_block.x)+1][(int)(player_block.y) + 1].block.width,buildings[(int)(player_block.x)+1][(int)(player_block.y) +1].block.height,10);
            physics_block[2][2]->enabled = false;
        }
        //create the left floor
        if(buildings[(int)(player_block.x) - 1][(int)(player_block.y) + 1].draw == true)
        {
            physics_block[0][2] = CreatePhysicsBodyRectangle((Vector2){buildings[(int)(player_block.x) -1][(int)(player_block.y) + 1].block.x,buildings[(int)(player_block.x) -1][(int)(player_block.y) + 1].block.y + 25},buildings[(int)(player_block.x)-1][(int)(player_block.y) + 1].block.width,buildings[(int)(player_block.x)-1][(int)(player_block.y) +1].block.height,10);
            physics_block[0][2]->enabled = false;
        }
        posi_down = player_block.x;
        posj_down = player_block.y + 1;
        check_existence[0] = true;
    }

    //destroy the physic block on the right
    else if(check_existence[0] == true && ((posi_down < player_block.x && posj_down == player_block.y+1)||(posj_down != player_block.y+1)))
    {
        heroi.physic->position.y -=1;
        DestroyPhysicsBody(physics_block[0][2]);
        DestroyPhysicsBody(physics_block[1][2]);
        DestroyPhysicsBody(physics_block[2][2]);
        check_existence[0] = false;
    }
    else if(check_existence[0] == true && ((posi_down > player_block.x && posj_down == player_block.y + 1)||(posj_down != player_block.y + 1)))
    {
        heroi.physic->position.y -=1;
        DestroyPhysicsBody(physics_block[2][2]);
        DestroyPhysicsBody(physics_block[1][2]);
        DestroyPhysicsBody(physics_block[0][2]);
        check_existence[0] = false;
    }
    
    //create the physic block on the right
    if(buildings[(int)(player_block.x) + 1][(int)(player_block.y)].draw == true && check_existence[1] == false)
    {
        physics_block[2][1] = CreatePhysicsBodyRectangle((Vector2){buildings[(int)(player_block.x)+1][(int)(player_block.y)].block.x + 25,buildings[(int)(player_block.x) + 1][(int)(player_block.y)].block.y+25},buildings[(int)(player_block.x)+1][(int)(player_block.y)].block.width,buildings[(int)(player_block.x)+1][(int)(player_block.y)].block.height,10);
        physics_block[2][1]->enabled = false;
        posi_right = player_block.x + 1;
        posj_right = player_block.y;
        check_existence[1] = true;
    }
    //destroy the physic block on the right
    else if(check_existence[1] == true && ((posi_right > player_block.x + 1 && posj_right == player_block.y)||(posj_right != player_block.y)))
    {
        DestroyPhysicsBody(physics_block[2][1]);
        check_existence[1] = false;
    }

    //create the physic block on the left
    if(buildings[(int)(player_block.x) - 1][(int)(player_block.y)].draw == true && check_existence[2] == false)
    {
        physics_block[0][1] = CreatePhysicsBodyRectangle((Vector2){buildings[(int)(player_block.x)-1][(int)(player_block.y)].block.x + 25,buildings[(int)(player_block.x) - 1][(int)(player_block.y)].block.y+25},buildings[(int)(player_block.x)-1][(int)(player_block.y)].block.width,buildings[(int)(player_block.x)-1][(int)(player_block.y)].block.height,10);
        physics_block[0][1]->enabled = false;
        posi_right = player_block.x - 1;
        posj_right = player_block.y;
        check_existence[2] = true;
    }
    //destroy the physic block on the left
    else if(check_existence[2] == true && ((posi_left > player_block.x - 1 && posj_left == player_block.y)||(posj_left != player_block.y)))
    {
        DestroyPhysicsBody(physics_block[0][1]);
        check_existence[2] = false;
    }
}

void destroy_all_physics(int num_body)
{
    for(int i = 0; i < num_body; i++)
    {
        PhysicsBody body = GetPhysicsBody(i);
        DestroyPhysicsBody(body);
    }
}


#endif