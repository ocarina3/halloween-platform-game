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

static Texture2D mainTexture;
static Texture2D winScreen;
static Texture2D creditsScreen;


//----------------------------------------------------------------------------------
// Gameplay Screen Functions Definition
//----------------------------------------------------------------------------------

// Gameplay Screen Initialization logic
void initWinScreen(void)
{
    // TODO: Initialize GAMEPLAY screen variables here!
    framesCounter = 0;
    finishScreen = 0;

    winScreen = LoadTexture("resources/textures/win-game-screen/win-game-screen.png");
    creditsScreen = LoadTexture("resources/textures/win-game-screen/credits.png");
    mainTexture = winScreen;
}

// Gameplay Screen Update logic
void updateWinScreen(void)
{
    framesCounter++;
    // TODO: Update GAMEPLAY screen variables here!

      if(framesCounter == 360){
            mainTexture = creditsScreen;
        }

        if(framesCounter == 720){
            finishScreen = 1;
        }
        
}

// Gameplay Screen Draw logic
void drawWinScreen(void)
{
    ClearBackground(RAYWHITE);
    // TODO: Draw GAMEPLAY screen here!
   DrawTexture(mainTexture, 0, 0, WHITE);
}

// Gameplay Screen Unload logic
void unloadWinScreen(void)
{
    // TODO: Unload GAMEPLAY screen variables here!
    UnloadTexture(winScreen);
    UnloadTexture(creditsScreen);
    UnloadTexture(mainTexture);
}

// Gameplay Screen should finish?
int finishWinScreen(void)
{
    return finishScreen;
}