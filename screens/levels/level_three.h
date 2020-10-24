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
#include "../../components/boss.h"

//----------------------------------------------------------------------------------
// Global Variables DefInition (local to this module)
//----------------------------------------------------------------------------------

// Gameplay screen global variables
Vector2 cameraPosition;
static int framesCounter;
static int finishScreen;
static int isAlive;
bool wallCreated;

static FILE *fileWriteLevelThree;
static FILE *fileReadLevelThreeCurrentUser;
static FILE *fileReadLevelThree;

static char usernameLevelThree[300];
static char nickLevelThree[100];
static char currentUserLevelThree[100];
static char spaceLevelThree[100];

//----------------------------------------------------------------------------------
// Gameplay Screen Functions DefInition
//----------------------------------------------------------------------------------

// Gameplay Screen Initialization logic
void InitLevelThreeScreen(void)
{
    framesCounter = 0;
    finishScreen = 0;
    isAlive = 1;
    wallCreated = false;
    LoadCharacterTextures();
    StartBoss();
    StartVariables();
    LoadAllTextures();
    CreateMap(3);
    CreateWall(7,92);
    CreateEnemiesMap(3);
    
    fileWriteLevelThree = fopen("save/save.txt", "a");
    fileReadLevelThreeCurrentUser = fopen("save/current_player.txt", "r");
    fileReadLevelThree = fopen("save/save.txt", "r");
}

// Gameplay Screen Update logic
void UpdateLevelThreeScreen(void)
{
    framesCounter++;
    playerBlock = GetPlayerBlock();
    UpdateGame(&hero);
    UpdateEnemy();

    //ajust camera position
    if(wallCreated == false)
    {
        camera.target = (Vector2){hero.physic->position.x + 20, hero.physic->position.y > 100 ? 200 : hero.physic->position.y + 100};
        if(boss.life <= 0) UpdateBoss();
    }
    else
    {
        UpdateBoss();
        if(cameraPosition.x < 1550) cameraPosition.x += 5;
        if(cameraPosition.y > 200) cameraPosition.y -= 1;
        camera.target = (Vector2){cameraPosition.x,cameraPosition.y};
    }
    if(playerBlock.x >= 23 && wallCreated == false && boss.life > 0)
    {
        cameraPosition.x = hero.physic->position.x;
        cameraPosition.y = hero.physic->position.y;
        CreateWall(22,38);
        wallCreated = true;
    }
    if(boss.life <= 0 && wallCreated == true)
    {
        DestroyWalls();
        CreateWall(2,92);
        wallCreated = false;
    }    
    //_________________________________________________________
    

    if(hero.isAlive == false && isAlive != 0){
        isAlive = 0; 
        framesCounter = 0;
    }

    if(framesCounter > 2*fps && isAlive == 0){
        finishScreen = 1;
    }
       
    
    //_________________________________________________
    //get the player coordinate in blocks
    


    //get the physical part of map
    ActivatePhysics();

    fgets(currentUserLevelThree, 300, fileReadLevelThreeCurrentUser);
    fclose(fileReadLevelThreeCurrentUser);

    if(fileWriteLevelThree == NULL){

    }else{
        while(fgets(usernameLevelThree, 300, fileReadLevelThree)!= NULL){

        }
        fclose(fileReadLevelThree);

        strcpy(spaceLevelThree, " ");
        strcat(spaceLevelThree, currentUserLevelThree);
        strcpy(nickLevelThree, spaceLevelThree);
        strcat(nickLevelThree, " 3");

        if (strstr(usernameLevelThree, nickLevelThree) != NULL){
                
        }else{
            fprintf(fileWriteLevelThree, " %s %i ", currentUserLevelThree, 3);
            fclose(fileWriteLevelThree);
        }
    }

    // Press enter or tap to change to ENDING screen
    if (IsKeyPressed(KEY_ENTER))
    {
        finishScreen = 1;
    }
}

// Gameplay Screen Draw logic
void DrawLevelThreeScreen(void)
{
    DrawTexture(background, 0, 0, WHITE);
    BeginMode2D(camera);
        DrawTextureMap();
        DrawEnemy();
        DrawEntities(&hero);
        DrawBoss();
    EndMode2D();    
    DrawLifeBar(&hero);
    DrawText(TextFormat("bloco: [%i,%i]\ncoordenada: [%f,%f]", (int)(playerBlock.x), (int)(playerBlock.y),(hero.physic->position.x),(hero.physic->position.y)), 315, 250, 20, DARKGRAY);
    DrawFPS(screenWidth - 90, screenHeight - 30);
}

// Gameplay Screen Unload logic
void UnloadLevelThreeScreen(void)
{
    DestroyWalls();
    UnloadCharacterTextures();
    DestroyAllPhysics();
    UnloadAllTextures();
}

// Gameplay Screen should Finish?
int FinishLevelThreeScreen(void)
{
    return finishScreen;
}

int IsAliveLevelThree(void)
{
    return isAlive;
}