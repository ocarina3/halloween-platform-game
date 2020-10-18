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

#define MAX_INPUT_CHARS     10

// Gameplay screen global variables
static int framesCounter;
static int finishScreen;

static FILE *fileWrtite;
static FILE *fileRead;

static char name[MAX_INPUT_CHARS + 1] = "\0";      // NOTE: One extra space required for line ending char '\0'
static int letterCount;

static char username[100];
static char nick[12];
static char space[12];

static Rectangle textBox = { 800/2 - 120, 280, 240, 50 };

static Texture2D user_background;

//----------------------------------------------------------------------------------
// Gameplay Screen Functions Definition
//----------------------------------------------------------------------------------

// Gameplay Screen Initialization logic
void initMenuUserScreen(void)
{
    // TODO: Initialize GAMEPLAY screen variables here!
    framesCounter = 0;
    finishScreen = 0;

    user_background = LoadTexture("resources/textures/menu_user_screen/menu_user.png");

    letterCount = 0;

    fileWrtite= fopen("save/save.txt", "a");
    fileRead = fopen("save/save.txt", "r");

    strcpy(space, " ");

}

// Gameplay Screen Update logic
void updateMenuUserScreen(void)
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
    if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
    {
        if(fileWrtite == NULL){

        }else{
            while(fgets(username, 100, fileRead)!= NULL){

            }

            fclose(fileRead);

            if(strcmp(username, "") == 0){
                fprintf(fileWrtite, " %s ", name);
                fclose(fileWrtite); 
            }else{
                strcat(space, name);
                strcpy(nick, space);
               if(strstr(username, nick) == NULL){
                    fprintf(fileWrtite, " %s ", name);
                    fclose(fileWrtite);
                }else{

                } 
            }
            
            finishScreen = 1;
        }
        
    }
}

// Gameplay Screen Draw logic
void drawMenuUserScreen(void)
{
    ClearBackground(RAYWHITE);
    // TODO: Draw GAMEPLAY screen here!
    DrawTexture(user_background, 0, 0, WHITE);
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
void unloadMenuUserScreen(void)
{
    // TODO: Unload GAMEPLAY screen variables here!
}

// Gameplay Screen should finish?
int finishMenuUserScreen(void)
{
    return finishScreen;
}
