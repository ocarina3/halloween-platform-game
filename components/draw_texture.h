#ifndef DRAWTEXTURE_H
#define DRAWTEXTURE_H



#include "main_character.h"
#include "get_map.h"




//___________________________________VARIABLES_______________________________________________

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


int teste;

//_____________________________________________________________________________________________

//___________________________________FUNCTIONS_______________________________________________

//get the texture
void load_texture()
{
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
}

//draw the map
void draw_texture_map()
{
    for(int i = 0; i < 320 ; i++)
    {
        for(int j = 0; j< 14; j++)
        {
            if(buildings[i][j].draw == true)
            {
                if((buildings[i][j].block.x < heroi.physic->position.x + screenWidth/2) + 25 && (buildings[i][j].block.x > heroi.physic->position.x - screenWidth/2) - 25)
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
}

void draw_enemy()
{
    
    for(int i = 0; i < 10; i++)
    {
        if(week[i].active == true)
        {
            if(((hit.x  >= week[i].block.x ) && (hit.y  >= week[i].block.y)) || teste == 1)
            {
                DrawRectangleRec(week[i].block,RED);
                teste = 1;    
            }
            DrawRectangleRec(week[i].block,GREEN);
        }
    }
}

//draw the character
void draw_texture_character()
{
    DrawTexture(character, heroi.physic->position.x - 25, heroi.physic->position.y - 25, WHITE);
}

//unload the texture
void unload_texture()
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
}

//________________________________________________________________________________________________
#endif