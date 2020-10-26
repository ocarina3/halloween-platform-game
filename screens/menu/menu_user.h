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

#include "raylib.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//----------------------------------------------------------------------------------
// Global Variables DefInition (local to this module)
//----------------------------------------------------------------------------------

#define MAX_INPUT_CHARS     10

// Gameplay screen global variables
static int framesCounter;
static int finishScreen;
static int level;

static FILE *fileWriteCurrentPlayer;
static FILE *fileWrite;
static FILE *fileRead;

static char name[MAX_INPUT_CHARS + 1] = "\0";      // NOTE: One extra space required for line ending char '\0'
static int letterCount;

static char username[300];
static char nick[100];
static char nickOne[100];
static char nickTwo[100];
static char nickThree[100];
static char space[100];

static Rectangle textBox = { 800/2 - 120, 280, 240, 50 };

static Texture2D userBackground;

//----------------------------------------------------------------------------------
// Gameplay Screen Functions DefInition
//----------------------------------------------------------------------------------

// Gameplay Screen Initialization logic
void InitMenuUserScreen(void)
{
    // TODO: Initialize GAMEPLAY screen variables here!
    framesCounter = 0;
    finishScreen = 0;
    level = 0;

    userBackground = LoadTexture("resources/textures/menu_user_screen/menu_user.png");

    letterCount = 0;

    fileWriteCurrentPlayer = fopen("save/current_player.txt", "w");
    fileWrite = fopen("save/save.txt", "a");
    fileRead = fopen("save/save.txt", "r");

    strcpy(space, " ");

}

// Gameplay Screen Update logic
void UpdateMenuUserScreen(void)
{
    framesCounter++;
    // TODO: Update GAMEPLAY screen variables here!
    int key = GetKeyPressed();

            // Check if more characters have been pressed on the same frame
            while (key > 0)
            {
                // NOTE: Only allow keys in range [32..125]
                if ((key >= 32) && (key <= 125) && (letterCount < MAX_INPUT_CHARS))
                {
                    name[letterCount] = (char)key;
                    letterCount++;
                }
                
                key = GetKeyPressed();  // Check next character in the queue
            }

            if (IsKeyPressed(KEY_BACKSPACE))
            {
                letterCount--;
                name[letterCount] = '\0';

                if (letterCount < 0) letterCount = 0;
            }

    // Press enter or tap to change to ENDING screen
    if (IsKeyPressed(KEY_ENTER))
    {
        if(fileWrite == NULL){

        }else{
            while(fgets(username, 300, fileRead)!= NULL){

            }

            fclose(fileRead);

            fprintf(fileWriteCurrentPlayer, "%s", name);
            fclose(fileWriteCurrentPlayer);

            if(strcmp(username, "") == 0){
                fprintf(fileWrite, " %s %i ", name, 1);
                fclose(fileWrite); 
                level = 1;
            }else{
                strcat(space, name);
                strcpy(nick, space);
               if(strstr(username, nick) == NULL){
                    fprintf(fileWrite, " %s %i ", name, 1);
                    fclose(fileWrite);
                    level = 1;
                }else{
                    strcpy(space, " ");
                    strcat(space, name);
                    strcpy(nickOne, space);
                    strcat(nickOne, " 1");
                    strcpy(nickTwo, space);
                    strcat(nickTwo, " 2");
                    strcpy(nickThree, space);
                    strcat(nickThree, " 3");
                    
                    if(strstr(username, nickOne) != NULL && strstr(username, nickTwo) == NULL && strstr(username, nickThree) == NULL){
                        level = 1;
                    }


                    if (strstr(username, nickTwo) != NULL){
                        level = 2;
                    }
                    
                    if(strstr(username, nickThree) != NULL){
                        level = 3;
                    }
                } 
            }
            
            finishScreen = 1;
        }
        
    }
}

// Gameplay Screen Draw logic
void DrawMenuUserScreen(void)
{
    ClearBackground(RAYWHITE);
    // TODO: Draw GAMEPLAY screen here!
    DrawTexture(userBackground, 0, 0, WHITE);
    DrawRectangleRec(textBox, ORANGE);
    DrawRectangleLines(textBox.x, textBox.y, textBox.width, textBox.height, DARKPURPLE);
    DrawText(name, textBox.x + 5, textBox.y + 8, 40, DARKPURPLE);

    if (letterCount < MAX_INPUT_CHARS){
        // Draw blinking underscore char
         if (((framesCounter/30)%2) == 0){
         DrawText("_", textBox.x + 8 + MeasureText(name, 40), textBox.y + 12, 40, DARKPURPLE);

        } else{
    }
  }
}

// Gameplay Screen Unload logic
void UnloadMenuUserScreen(void)
{
    // TODO: Unload GAMEPLAY screen variables here!
    UnloadTexture(userBackground);
}

// Gameplay Screen should Finish?
int FinishMenuUserScreen(void)
{
    return finishScreen;
}

int loadLevel(void)
{
    return level;

}
