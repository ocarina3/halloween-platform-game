#ifndef DRAWTEXTURE_H
#define DRAWTEXTURE_H

#ifndef ENEMY_H
#include "enemy.h"
#endif

#ifndef BOSS_H
#include "boss.h"
#endif

#include "main_character.h"
#include "get_map.h"




//___________________________________VARIABLES_______________________________________________
//map
static Texture2D background;              
static Texture2D mapTiles[17];

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
    LoadBossTextures();
    background = LoadTexture("resources/textures/map_tiles/Background.png");
    for ( int x = 1; x < 17; x++ ) 
    {
        mapTiles[x] = LoadTexture(
            FormatText("resources/textures/map_tiles/Tile (%i).png", x)
        );
    }
    
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
                    for (int x = 1; x < 17; x++) 
                    {
                        if (buildings[i][j].sprite == x) 
                            DrawTexture(mapTiles[x], buildings[i][j].block.x, buildings[i][j].block.y, WHITE);
                        else if (buildings[i][j].sprite == 17)
                            DrawTexture(arrowSign, buildings[i][j].block.x, buildings[i][j].block.y, WHITE);
                    }
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
    UnloadBossTextures();
    UnloadTexture(background);

    for ( int x = 1; x < 17; x++ ) 
    {
        UnloadTexture(mapTiles[x]);
    }

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