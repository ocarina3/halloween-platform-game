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
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//----------------------------------------------------------------------------------
// Global Variables Definition (local to this module)
//----------------------------------------------------------------------------------

// Gameplay screen global variables
static int framesCounter;
static int finishScreen;

static FILE *fileWriteLevelTwo;
static FILE *fileReadLevelTwoCurrentUser;
static FILE *fileReadLevelTwo;

static char username_lvl_two[300];
static char nick_lvl_two[100];
static char current_user_lvl_two[100];
static char space_lvl_two[100];

//----------------------------------------------------------------------------------
// Gameplay Screen Functions Definition
//----------------------------------------------------------------------------------

// Gameplay Screen Initialization logic
void initLevelTwoScreen(void)
{
    // TODO: Initialize GAMEPLAY screen variables here!
    framesCounter = 0;
    finishScreen = 0;

    fileWriteLevelTwo = fopen("save/save.txt", "a");
    fileReadLevelTwoCurrentUser = fopen("save/current_player.txt", "r");
    fileReadLevelTwo = fopen("save/save.txt", "r");
}

// Gameplay Screen Update logic
void updateLevelTwoScreen(void)
{
    // TODO: Update GAMEPLAY screen variables here!
    fgets(current_user_lvl_two, 300, fileReadLevelTwoCurrentUser);
    fclose(fileReadLevelTwoCurrentUser);

    if(fileWriteLevelTwo == NULL){

    }else{
        while(fgets(username_lvl_two, 300, fileReadLevelTwo)!= NULL){

        }
        fclose(fileReadLevelTwo);

        strcpy(space_lvl_two, " ");
        strcat(space_lvl_two, current_user_lvl_two);
        strcpy(nick_lvl_two, space_lvl_two);
        strcat(nick_lvl_two, " 2");

        if (strstr(username_lvl_two, nick_lvl_two) != NULL){
                
        }else{
            fprintf(fileWriteLevelTwo, " %s %i ", current_user_lvl_two, 2);
            fclose(fileWriteLevelTwo);
        }
    }

    // Press enter or tap to change to ENDING screen
    if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
    {
        finishScreen = 1;
    }
}

// Gameplay Screen Draw logic
void drawLevelTwoScreen(void)
{
    // TODO: Draw GAMEPLAY screen here!
    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), BLUE);
    DrawText("LEVEL_TWO SCREEN", 20, 20, 40, DARKBLUE);
    DrawText("PRESS ENTER or TAP to JUMP to ENDING SCREEN", 130, 220, 20, DARKBLUE);
}

// Gameplay Screen Unload logic
void unloadLevelTwoScreen(void)
{
    // TODO: Unload GAMEPLAY screen variables here!
}

// Gameplay Screen should finish?
int finishLevelTwoScreen(void)
{
    return finishScreen;
}