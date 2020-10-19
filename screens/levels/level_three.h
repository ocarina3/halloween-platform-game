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

// Gameplay screen global variables
static int framesCounter;
static int finishScreen;

static FILE *fileWriteLevelThree;
static FILE *fileReadLevelThreeCurrentUser;
static FILE *fileReadLevelThree;

static char username_lvl_three[300];
static char nick_lvl_three[100];
static char current_user_lvl_three[100];
static char space_lvl_three[100];

//----------------------------------------------------------------------------------
// Gameplay Screen Functions Definition
//----------------------------------------------------------------------------------

// Gameplay Screen Initialization logic
void initLevelThreeScreen(void)
{
    // TODO: Initialize GAMEPLAY screen variables here!
    framesCounter = 0;
    finishScreen = 0;

    fileWriteLevelThree = fopen("save/save.txt", "a");
    fileReadLevelThreeCurrentUser = fopen("save/current_player.txt", "r");
    fileReadLevelThree = fopen("save/save.txt", "r");
}

// Gameplay Screen Update logic
void updateLevelThreeScreen(void)
{
    // TODO: Update GAMEPLAY screen variables here!

    fgets(current_user_lvl_three, 300, fileReadLevelThreeCurrentUser);
    fclose(fileReadLevelThreeCurrentUser);

    if(fileWriteLevelThree == NULL){

    }else{
        while(fgets(username_lvl_three, 300, fileReadLevelThree)!= NULL){

        }
        fclose(fileReadLevelThree);

        strcpy(space_lvl_three, " ");
        strcat(space_lvl_three, current_user_lvl_three);
        strcpy(nick_lvl_three, space_lvl_three);
        strcat(nick_lvl_three, " 3");

        if (strstr(username_lvl_three, nick_lvl_three) != NULL){
                
        }else{
            fprintf(fileWriteLevelThree, " %s %i ", current_user_lvl_three, 3);
            fclose(fileWriteLevelThree);
        }
    }

    // Press enter or tap to change to ENDING screen
    if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
    {
        finishScreen = 1;
    }
}

// Gameplay Screen Draw logic
void drawLevelThreeScreen(void)
{
    // TODO: Draw GAMEPLAY screen here!
    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), GREEN);
    DrawText("LEVEL_THREE SCREEN", 20, 20, 40, DARKGREEN);
    DrawText("PRESS ENTER or TAP to JUMP to ENDING SCREEN", 130, 220, 20, DARKGREEN);
}

// Gameplay Screen Unload logic
void unloadLevelThreeScreen(void)
{
    // TODO: Unload GAMEPLAY screen variables here!
}

// Gameplay Screen should finish?
int finishLevelThreeScreen(void)
{
    return finishScreen;
}