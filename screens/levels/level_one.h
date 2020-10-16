/**********************************************************************************************
*
*   raylib - Standard Game template
*
*   Gameplay Screen Functions Definitions (Init, Update, Draw, Unload)
*
*   Copyright (c) 2014-2020 Ramon Santamaria (@raysan5)
*
*   This software is provided "as-is", without any express or implied warranty. In no event
*   will the authors be held liable for any damages arising from the use of this software.
*
*   Permission is granted to anyone to use this software for any purpose, including commercial
*   applications, and to alter it and redistribute it freely, subject to the following restrictions:
*
*     1. The origin of this software must not be misrepresented; you must not claim that you
*     wrote the original software. If you use this software in a product, an acknowledgment
*     in the product documentation would be appreciated but is not required.
*
*     2. Altered source versions must be plainly marked as such, and must not be misrepresented
*     as being the original software.
*
*     3. This notice may not be removed or altered from any source distribution.
*
**********************************************************************************************/

#include "raylib.h"


//----------------------------------------------------------------------------------
// Global Variables Definition (local to this module)
//----------------------------------------------------------------------------------

#define screenWidth             800
#define screenHeight            450
#define buildings_width         50
#define buildings_height        50
//Structs

typedef struct
{
    Rectangle block;
    bool draw;
}blocks;

// Gameplay screen global variables
static int framesCounter;
static int finishScreen;

blocks buildings[320][9];
PhysicsBody physics_block[3][3];
PhysicsBody player;
bool check_existence[6]; 
Vector2 vertexA;
Vector2 vertexB;   
Vector2 player_block;
Camera2D camera;

//----------------------------------------------------------------------------------
// Gameplay Screen Functions Definition
//----------------------------------------------------------------------------------

//functions
void start_variables();
Vector2 get_player_block();
void create_line(Vector2 inicial, Vector2 final);
void create_map(int phase);
void create_physic_map();


// Gameplay Screen Initialization logic
void initLevelOneScreen(void)
{
    // TODO: Initialize GAMEPLAY screen variables here!
    framesCounter = 0;
    finishScreen = 0;

   
    create_map(1);
}

// Gameplay Screen Update logic
void updateLevelOneScreen(void)
{
    camera.target = (Vector2){ player->position.x + 20, player->position.y + 20};
    // TODO: Update GAMEPLAY screen variables here!
    player_block = get_player_block();
    //Draw the game    
    if (IsKeyDown(KEY_RIGHT) ) player->velocity.x = 0.5;
    else if (IsKeyDown(KEY_LEFT)) player->velocity.x = -0.5;
    if (IsKeyDown(KEY_UP) && player->velocity.y < 0.1 && player->velocity.y > 0) player->velocity.y = -2;
    
    PhysicsBody body = GetPhysicsBody(0);
    vertexA = GetPhysicsShapeVertex(body, 1);
    vertexB = GetPhysicsShapeVertex(body, 3);

    player->position.x = (int)(player->position.x);
    player->position.y = (int)(player->position.y);
    
    create_physic_map();
    // Press enter or tap to change to ENDING screen
    if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
    {
        finishScreen = 1;
    }
}

// Gameplay Screen Draw logic
void drawLevelOneScreen(void)
{
    BeginMode2D(camera);
        DrawLineV(vertexA, vertexB, GREEN);  
    
        for(int i = 0; i < 320 ; i++)
        {
            for(int j = 0; j< 9; j++)
            {
                if(buildings[i][j].draw == true)
                {
                    DrawRectangleRec(buildings[i][j].block, RED);
                }
            }
        }
    EndMode2D();    
    DrawText(TextFormat("bloco: [%i,%i]\n coordenada: [%f,%f]", (int)(player_block.x), (int)(player_block.y),(player->position.x),(player->position.y)), 315, 250, 20, DARKGRAY);
    DrawFPS(screenWidth - 90, screenHeight - 30);
}

// Gameplay Screen Unload logic
void unloadLevelOneScreen(void)
{
    // TODO: Unload GAMEPLAY screen variables here!
}

// Gameplay Screen should finish?
int finishLevelOneScreen(void)
{
    return finishScreen;
}




//creates a map line and divides it into blocks
void create_line(Vector2 inicial, Vector2 final)
{
    //size of the blocks


    //takes the final and initial coordinates of the line
    Vector2 num_blocks = {((final.x - inicial.x)+ 1),((final.y - inicial.y) + 1)};
    //create the blocks

    for (int i = 0; i < (int)num_blocks.x; i++)
    {
        for(int j = 0; j < (int)num_blocks.y; j++)
        {
            buildings[(int)inicial.x + i][(int)inicial.y + j].draw = true;
        }
    }
}

Vector2 get_player_block()
{

    Vector2 player_block;
    player_block.x = 0;
    player_block.y = 0 ;

    for(int i = 0; i < 320 ; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if(player->position.y >= buildings[i][j].block.y && player->position.y < buildings[i][j].block.y + buildings[i][j].block.height)
            {
                player_block.y = j;
            }
            if(player->position.x >= buildings[i][j].block.x && player->position.x < buildings[i][j].block.x + buildings[i][j].block.width)
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
        player->position.y -=1;
        DestroyPhysicsBody(physics_block[0][2]);
        DestroyPhysicsBody(physics_block[1][2]);
        DestroyPhysicsBody(physics_block[2][2]);
        check_existence[0] = false;
    }
    else if(check_existence[0] == true && ((posi_down > player_block.x && posj_down == player_block.y + 1)||(posj_down != player_block.y + 1)))
    {
        player->position.y -=1;
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

void start_variables()
{
    player = CreatePhysicsBodyRectangle((Vector2){400,225}, 40, 40, 10);
 
    camera.target = (Vector2){ player->position.x + 20, player->position.y + 20};
    camera.offset = (Vector2){ screenWidth/2, screenHeight/2 };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
 
    check_existence[0] = false;
    check_existence[1] = false;
    check_existence[2] = false;
    check_existence[3] = false;
    check_existence[4] = false;
    check_existence[5] = false;

    player->freezeOrient = true;

    for(int i = 0; i < 320 ; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            buildings[i][j].draw = false;
            buildings[i][j].block.x = (i)*buildings_height;
            buildings[i][j].block.y = (j)*buildings_height;
            buildings[i][j].block.width = buildings_width;
            buildings[i][j].block.height = buildings_height;
        }
    }    
}


void create_map(int phase)
{
    if (phase == 1)
    {
        start_variables();
        create_line((Vector2){0,8},(Vector2){15,8});
        create_line((Vector2){9,5},(Vector2){12,5});
        create_line((Vector2){4,5},(Vector2){7,5});
        create_line((Vector2){8,6},(Vector2){8,8});    
    }
}