/**********************************************************************************************
*
*   raylib - Standard Game template
*
*   Gameplay Screen Functions DefInitions (Init, Update, Draw, Unload)
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

#include "../../components/phase.h"

static int framesCounter;
static int finishScreen;
static int isAlive;

// Gameplay Screen Initialization logic
void InitLevelOneScreen(void)
{
    // Initialize GAMEPLAY screen variables here!
    framesCounter = 0;
    finishScreen = 0;
    isAlive = 1;

    StartVariables();
    CreateEnemiesMap(1);
    LoadAllTextures();
    CreateMap(1);
    CreateWall(7,92);
}


// Gameplay Screen Update logic
void UpdateLevelOneScreen(void)
{
    framesCounter++;
    //ajust camera position
    camera.target = (Vector2){hero.physic->position.x + 20, 250};
    //_________________________________________________________
    UpdateGame(&hero);
    UpdateEnemy();

    if(hero.isAlive == false && isAlive != 0){
        isAlive = 0; 
        framesCounter = 0;
    }

    if(framesCounter>120 && isAlive == 0){
        finishScreen = 1;
    }
    
    //_________________________________________________
    //get the player coordinate in blocks
    playerBlock = GetPlayerBlock();
    //get the physical part of map
    ActivatePhysics();

    // Press enter or tap to change to ENDING screen
    if (playerBlock.x == 91)
    {
        finishScreen = 1;
    }
}

// Gameplay Screen Draw logic
void DrawLevelOneScreen(void)
{
    //Get the camera
    DrawTexture(background, 0, 0, WHITE);
    BeginMode2D(camera);
        DrawTextureMap();
        DrawEnemy();
        DrawEntities(&hero);

    EndMode2D();    
    DrawText(FormatText("Lives: %i", hero.lives), screenWidth - 80, 80, 14, YELLOW);
    DrawText(TextFormat("bloco: [%i,%i]\ncoordenada: [%f,%f]", (int)(playerBlock.x), (int)(playerBlock.y),(hero.physic->position.x),(hero.physic->position.y)), 315, 250, 20, DARKGRAY);
    DrawFPS(screenWidth - 90, screenHeight - 30);
}

// Gameplay Screen Unload logic
void UnloadLevelOneScreen(void)
{
    DestroyWalls();
    DestroyAllPhysics();
    UnloadAllTextures();
}

// Gameplay Screen should Finish?
int FinishLevelOneScreen(void)
{
    return finishScreen;
}

int isAliveLevelOne(void)
{
    return isAlive;
}









