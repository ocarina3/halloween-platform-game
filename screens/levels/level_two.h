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

#include "raylib.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//----------------------------------------------------------------------------------
// Global Variables DefInition (local to this module)
//----------------------------------------------------------------------------------

// Gameplay screen global variables
static int framesCounter;
static int finishScreen;
static int isAlive;

static int cameraTarget;

static FILE *fileWriteLevelTwo;
static FILE *fileReadLevelTwoCurrentUser;
static FILE *fileReadLevelTwo;

static char usernameLevelTwo[300];
static char nickLevelTwo[100];
static char currentUserLevelTwo[100];
static char spaceLevelTwo[100];

//----------------------------------------------------------------------------------
// Gameplay Screen Functions DefInition
//----------------------------------------------------------------------------------

// Gameplay Screen Initialization logic
void InitLevelTwoScreen(void)
{
    // TODO: Initialize GAMEPLAY screen variables here!
    framesCounter = 0;
    finishScreen = 0;
    isAlive = 1;

    cameraTarget = 200;

    LoadCharacterTextures();
    StartVariables();
    LoadAllTextures();
    CreateMap(2);
    CreateWall(7,106);
    
    fileWriteLevelTwo = fopen("save/save.txt", "a");
    fileReadLevelTwo = fopen("save/save.txt", "r");
    fileReadLevelTwoCurrentUser = fopen("save/current_player.txt", "r");

}

void UpdateLevelTwoScreen(void)
{

    framesCounter++;
    // TODO: Update GAMEPLAY screen variables here!
    camera.target = (Vector2){cameraTarget, hero.physic->position.y > 100 ? 200 : hero.physic->position.y + 100};
    cameraTarget += 2.5;
    //_________________________________________________________
    UpdateGame(&hero);

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
    fgets(currentUserLevelTwo, 300, fileReadLevelTwoCurrentUser);
    fclose(fileReadLevelTwoCurrentUser);

    if(fileWriteLevelTwo == NULL){

    }else{
        while(fgets(usernameLevelTwo, 300, fileReadLevelTwo)!= NULL){

        }
        fclose(fileReadLevelTwo);

        strcpy(spaceLevelTwo, " ");
        strcat(spaceLevelTwo, currentUserLevelTwo);
        strcpy(nickLevelTwo, spaceLevelTwo);
        strcat(nickLevelTwo, " 2");

        if (strstr(usernameLevelTwo, nickLevelTwo) != NULL){
                
        }else{
            fprintf(fileWriteLevelTwo, " %s %i ", currentUserLevelTwo, 2);
            fclose(fileWriteLevelTwo);
        }
    }

    // Press enter or tap to change to ENDING screen
    if (playerBlock.x == 105)
    {
        finishScreen = 1;
    }
    // Condition to end the level if the player gets out of the screen
    // else if (playerBlock.x == cameraTarget)
    // {
    //     FinishScreen = 2;
    // }
}

// Gameplay Screen Draw logic
void DrawLevelTwoScreen(void)
{
    DrawTexture(background, 0, 0, WHITE);
    BeginMode2D(camera);
        DrawTextureMap();
        DrawEntities(&hero);

    EndMode2D();    
    DrawText(FormatText("Lives: %i", hero.lives), screenWidth - 80, 80, 14, YELLOW);
    DrawText(TextFormat("bloco: [%i,%i]\ncoordenada: [%f,%f]", (int)(playerBlock.x), (int)(playerBlock.y),(hero.physic->position.x),(hero.physic->position.y)), 315, 250, 20, DARKGRAY);
    DrawFPS(screenWidth - 90, screenHeight - 30);
}

// Gameplay Screen Unload logic
void UnloadLevelTwoScreen(void)
{
    DestroyWalls();
    UnloadCharacterTextures();
    DestroyAllPhysics();
    UnloadAllTextures();
}

// Gameplay Screen should Finish?
int FinishLevelTwoScreen(void)
{
    return finishScreen;
}

int isAliveLevelTwo(void)
{
    return isAlive;
}