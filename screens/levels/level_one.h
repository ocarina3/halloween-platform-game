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
    int sprite;
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
static Texture2D background;       
static Texture2D character;       
static Texture2D tileOne;       
static Texture2D tileTwo;       
static Texture2D tileThree;       
static Texture2D tileFour;       
static Texture2D tileFive;       
static Texture2D tileSix;       
static Texture2D tileSeven;       
static Texture2D tileEight;       
static Texture2D tileNine;       
static Texture2D tileTen;       
static Texture2D tileEleven;       
static Texture2D tileTwelve;       
static Texture2D tileThirteen;       
static Texture2D tileFourteen;       
static Texture2D tileFifteen;       
static Texture2D tileSixteen;       
Vector2 tilePosition;

//----------------------------------------------------------------------------------
// Gameplay Screen Functions Definition
//----------------------------------------------------------------------------------

//functions
void start_variables();
Vector2 get_player_block();
void create_line(Vector2 inicial, Vector2 final, int sprite);
void create_map();
void create_physic_map();


// Gameplay Screen Initialization logic
void initLevelOneScreen(void)
{
    // Initialize GAMEPLAY screen variables here!
    framesCounter = 0;
    finishScreen = 0;
    background = LoadTexture("resources/textures/map_tiles/Background.png");
    character = LoadTexture("resources/textures/map_tiles/Bone (1).png");
    tileOne = LoadTexture("resources/textures/map_tiles/Tile (1).png");
    tileTwo = LoadTexture("resources/textures/map_tiles/Tile (2).png");
    tileThree = LoadTexture("resources/textures/map_tiles/Tile (3).png");
    tileFour = LoadTexture("resources/textures/map_tiles/Tile (4).png");
    tileFive = LoadTexture("resources/textures/map_tiles/Tile (5).png");
    tileSix = LoadTexture("resources/textures/map_tiles/Tile (6).png");
    tileSeven = LoadTexture("resources/textures/map_tiles/Tile (7).png");
    tileEight = LoadTexture("resources/textures/map_tiles/Tile (8).png");
    tileNine = LoadTexture("resources/textures/map_tiles/Tile (9).png");
    tileTen = LoadTexture("resources/textures/map_tiles/Tile (10).png");
    tileEleven = LoadTexture("resources/textures/map_tiles/Tile (11).png");
    tileTwelve = LoadTexture("resources/textures/map_tiles/Tile (12).png");
    tileThirteen = LoadTexture("resources/textures/map_tiles/Tile (13).png");
    tileFourteen = LoadTexture("resources/textures/map_tiles/Tile (14).png");
    tileFifteen = LoadTexture("resources/textures/map_tiles/Tile (15).png");
    tileSixteen = LoadTexture("resources/textures/map_tiles/Tile (16).png");
    
    create_map();
}

// Gameplay Screen Update logic
void updateLevelOneScreen(void)
{
    //ajust camera position
    camera.target = (Vector2){ player->position.x + 20, player->position.y + 20};
    
    //get the player coordinate in blocks
    player_block = get_player_block();
    
    
    //player movimentation   
    if (IsKeyDown(KEY_RIGHT) ) player->velocity.x = 0.5;
    else if (IsKeyDown(KEY_LEFT)) player->velocity.x = -0.5;
    if (IsKeyDown(KEY_UP) && player->velocity.y < 0.1 && player->velocity.y > 0) player->velocity.y = -2;
    
    //get player vertex
    PhysicsBody body = GetPhysicsBody(0);
    vertexA = GetPhysicsShapeVertex(body, 1);
    vertexB = GetPhysicsShapeVertex(body, 3);

    //get a int position for player (bug)
    player->position.x = (int)(player->position.x);
    player->position.y = (int)(player->position.y);
    
    //get the physical part of map
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
    //Get the camera
    DrawTexture(background, 0, 0, WHITE);
    BeginMode2D(camera);
    
        for(int i = 0; i < 320 ; i++)
        {
            for(int j = 0; j< 9; j++)
            {
                if(buildings[i][j].draw == true)
                {
                    if((buildings[i][j].block.x < player->position.x + screenWidth/2) + 25 && (buildings[i][j].block.x > player->position.x - screenWidth/2) - 25)
                    {
                        // Verifica qual sprite deverá ser impressa
                        if (buildings[i][j].sprite == 1) 
                            DrawTexture(tileOne, buildings[i][j].block.x, buildings[i][j].block.y, WHITE);
                        else if (buildings[i][j].sprite == 2)
                            DrawTexture(tileTwo, buildings[i][j].block.x, buildings[i][j].block.y, WHITE);
                        else if (buildings[i][j].sprite == 3)
                            DrawTexture(tileThree, buildings[i][j].block.x, buildings[i][j].block.y, WHITE);
                        else if (buildings[i][j].sprite == 4)
                            DrawTexture(tileFour, buildings[i][j].block.x, buildings[i][j].block.y, WHITE);
                        else if (buildings[i][j].sprite == 5)
                            DrawTexture(tileFive, buildings[i][j].block.x, buildings[i][j].block.y, WHITE);
                        else if (buildings[i][j].sprite == 6)
                            DrawTexture(tileSix, buildings[i][j].block.x, buildings[i][j].block.y, WHITE);
                        else if (buildings[i][j].sprite == 7)
                            DrawTexture(tileSeven, buildings[i][j].block.x, buildings[i][j].block.y, WHITE);
                        else if (buildings[i][j].sprite == 8)
                            DrawTexture(tileEight, buildings[i][j].block.x, buildings[i][j].block.y, WHITE);
                        else if (buildings[i][j].sprite == 9)
                            DrawTexture(tileNine, buildings[i][j].block.x, buildings[i][j].block.y, WHITE);
                        else if (buildings[i][j].sprite == 10)
                            DrawTexture(tileTen, buildings[i][j].block.x, buildings[i][j].block.y, WHITE);
                        else if (buildings[i][j].sprite == 11)
                            DrawTexture(tileEleven, buildings[i][j].block.x, buildings[i][j].block.y, WHITE);
                        else if (buildings[i][j].sprite == 12)
                            DrawTexture(tileTwelve, buildings[i][j].block.x, buildings[i][j].block.y, WHITE);
                        else if (buildings[i][j].sprite == 13)
                            DrawTexture(tileThirteen, buildings[i][j].block.x, buildings[i][j].block.y, WHITE);
                        else if (buildings[i][j].sprite == 14)
                            DrawTexture(tileFourteen, buildings[i][j].block.x, buildings[i][j].block.y, WHITE);
                        else if (buildings[i][j].sprite == 15)
                            DrawTexture(tileFifteen, buildings[i][j].block.x, buildings[i][j].block.y, WHITE);
                        else if (buildings[i][j].sprite == 16)
                            DrawTexture(tileSixteen, buildings[i][j].block.x, buildings[i][j].block.y, WHITE);
                    }
                }
            }
        }
    DrawTexture(character, player->position.x - 25, player->position.y - 25, WHITE);
    EndMode2D();    
    DrawText(TextFormat("bloco: [%i,%i]\ncoordenada: [%f,%f]", (int)(player_block.x), (int)(player_block.y),(player->position.x),(player->position.y)), 315, 250, 20, DARKGRAY);
    DrawFPS(screenWidth - 90, screenHeight - 30);
}

// Gameplay Screen Unload logic
void unloadLevelOneScreen(void)
{
    UnloadTexture(background);
    UnloadTexture(character);
    UnloadTexture(tileOne);
    UnloadTexture(tileTwo);
    UnloadTexture(tileThree);
    UnloadTexture(tileFour);
    UnloadTexture(tileFive);
    UnloadTexture(tileSix);
    UnloadTexture(tileSeven);
    UnloadTexture(tileEight);
    UnloadTexture(tileNine);
    UnloadTexture(tileTen);
    UnloadTexture(tileEleven);
    UnloadTexture(tileTwelve);
    UnloadTexture(tileThirteen);
    UnloadTexture(tileFourteen);
    UnloadTexture(tileFifteen);
    UnloadTexture(tileSixteen);
    // TODO: Unload GAMEPLAY screen variables here!
}

// Gameplay Screen should finish?
int finishLevelOneScreen(void)
{
    return finishScreen;
}

//creates a map line and divides it into blocks
void create_line(Vector2 inicial, Vector2 final, int sprite)
{
    //takes the final and initial coordinates of the line
    Vector2 num_blocks = {((final.x - inicial.x)+ 1),((final.y - inicial.y) + 1)};
    
    //create the blocks
    for (int i = 0; i < (int)num_blocks.x; i++)
    {
        for(int j = 0; j < (int)num_blocks.y; j++)
        {
            buildings[(int)inicial.x + i][(int)inicial.y + j].draw = true;
            buildings[(int)inicial.x + i][(int)inicial.y + j].sprite = sprite;
        }
    }
}

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
    //start player position
    player = CreatePhysicsBodyRectangle((Vector2){400,250}, 50, 50, 10);
    player->freezeOrient = true;

    //start camera position
    camera.target = (Vector2){ player->position.x + 20, player->position.y + 20};
    camera.offset = (Vector2){ screenWidth/2, screenHeight/2 };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
    
    //start the physic check
    check_existence[0] = false;
    check_existence[1] = false;
    check_existence[2] = false;
    check_existence[3] = false;
    check_existence[4] = false;
    check_existence[5] = false;

    //start the blocks
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


void create_map()
{
    //draw the map
    start_variables();

    // Primeira linha
    create_line((Vector2){0,7}, (Vector2){0,7}, 1);
    create_line((Vector2){1,7}, (Vector2){14,7}, 2);
    create_line((Vector2){15,7}, (Vector2){15,7}, 3);
    
    // Terra embaixo da primeira linha
    create_line((Vector2){0,8}, (Vector2){0,8}, 4);
    create_line((Vector2){1,8}, (Vector2){14,8}, 5);
    create_line((Vector2){15,8}, (Vector2){15,8}, 10);

    // Linha
    create_line((Vector2){16,8}, (Vector2){16,8}, 11);
    create_line((Vector2){17,8}, (Vector2){24,8}, 2);
    create_line((Vector2){25,8}, (Vector2){25,8}, 7);
    
    // Linha
    create_line((Vector2){26,7}, (Vector2){26,7}, 1);
    create_line((Vector2){27,7}, (Vector2){29,7}, 2);
    create_line((Vector2){30,7}, (Vector2){30,7}, 3);
    
    // Terra embaixo
    create_line((Vector2){26,8}, (Vector2){26,8}, 8);
    create_line((Vector2){27,8}, (Vector2){29,8}, 5);
    create_line((Vector2){30,8}, (Vector2){30,8}, 6);
    
    //   
    create_line((Vector2){31,6}, (Vector2){35,6}, 2);
    create_line((Vector2){36,5}, (Vector2){38,5}, 2);
    create_line((Vector2){39,4}, (Vector2){40,4}, 2);
    create_line((Vector2){41,7}, (Vector2){44,7}, 2);
    create_line((Vector2){45,6}, (Vector2){50,6}, 2);
    create_line((Vector2){51,7}, (Vector2){52,7}, 2);
    // Plataforma
    create_line((Vector2){55,6}, (Vector2){55,6}, 14);
    create_line((Vector2){56,6}, (Vector2){56,6}, 15);
    create_line((Vector2){57,6}, (Vector2){57,6}, 16);
    // 
    create_line((Vector2){60,7}, (Vector2){64,7}, 2);
    create_line((Vector2){65,6}, (Vector2){67,6}, 2);
    // Plataforma
    create_line((Vector2){70,4}, (Vector2){70,4}, 14);
    create_line((Vector2){71,4}, (Vector2){71,4}, 15);
    create_line((Vector2){72,4}, (Vector2){72,4}, 16);
    // Linha
    create_line((Vector2){75,6}, (Vector2){78,6}, 2);
    create_line((Vector2){81,7}, (Vector2){83,7}, 2);
    create_line((Vector2){84,6}, (Vector2){96,6}, 2);
}