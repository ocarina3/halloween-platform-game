#ifndef DRAWTEXTURE_H
#define DRAWTEXTURE_H

#ifndef ENEMY_H
#include "enemy.h"
#endif


#include "main_character.h"
#include "get_map.h"




//___________________________________VARIABLES_______________________________________________
//map
static Texture2D background;              
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

static Texture2D arrowSign;
static Texture2D bushOne;
static Texture2D bushTwo;
static Texture2D crate;
static Texture2D deadBush;
static Texture2D sign;
static Texture2D skeleton;
static Texture2D tombStoneOne;
static Texture2D tombStoneTwo;
static Texture2D tree;

//_____________________________________________________________________________________________

//___________________________________FUNCTIONS_______________________________________________

//get the texture
void LoadAllTextures()
{
    LoadEnemyTextures();
    LoadCharacterTextures();
    background = LoadTexture("resources/textures/map_tiles/Background.png");
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
    
    // Objects
    arrowSign = LoadTexture("resources/textures/map_objects/ArrowSign.png"); 
    bushOne = LoadTexture("resources/textures/map_objects/Bush (1).png");
    bushTwo = LoadTexture("resources/textures/map_objects/Bush (2).png");
    crate = LoadTexture("resources/textures/map_objects/Crate.png");
    deadBush = LoadTexture("resources/textures/map_objects/DeadBush.png");
    sign = LoadTexture("resources/textures/map_objects/Sign.png");
    skeleton = LoadTexture("resources/textures/map_objects/Skeleton.png");
    tombStoneOne = LoadTexture("resources/textures/map_objects/TombStone (1).png");
    tombStoneTwo = LoadTexture("resources/textures/map_objects/TombStone (2).png");
    tree = LoadTexture("resources/textures/map_objects/Tree.png");
}

//Draw the map
void DrawTextureMap()
{
    for(int i = 0; i < 320 ; i++)
    {
        for(int j = 0; j< 14; j++)
        {
            if(buildings[i][j].draw == true)
            {
                if((buildings[i][j].block.x < hero.physic->position.x + screenWidth/2) + 25 && (buildings[i][j].block.x > hero.physic->position.x - screenWidth/2) - 25)
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
                    else if (buildings[i][j].sprite == 17)
                        DrawTexture(arrowSign, buildings[i][j].block.x, buildings[i][j].block.y, WHITE);
                }
            }
        }
    }
}



//Unload the texture
void UnloadAllTextures()
{
    UnloadEnemyTextures();
    UnloadCharacterTextures();
    UnloadTexture(background);
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

    UnloadTexture(arrowSign);  
    UnloadTexture(bushOne);
    UnloadTexture(bushTwo);
    UnloadTexture(crate);
    UnloadTexture(deadBush);
    UnloadTexture(sign);
    UnloadTexture(skeleton);
    UnloadTexture(tombStoneOne);
    UnloadTexture(tombStoneTwo);
    UnloadTexture(tree);
}

//________________________________________________________________________________________________
#endif