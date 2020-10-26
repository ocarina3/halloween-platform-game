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

//----------------------------------------------------------------------------------
// Global Variables DefInition (local to this module)
//----------------------------------------------------------------------------------

// Gameplay screen global variables
static int framesCounter;
static int finishScreen;

static Texture2D gameOver;


//----------------------------------------------------------------------------------
// Gameplay Screen Functions DefInition
//----------------------------------------------------------------------------------

// Gameplay Screen Initialization logic
void InitGameOverScreen(void)
{
    // TODO: Initialize GAMEPLAY screen variables here!
    framesCounter = 0;
    finishScreen = 0;

    gameOver = LoadTexture("resources/textures/game-over-screen/game-over-screen.png");

}

// Gameplay Screen Update logic
void UpdateGameOverScreen(void)
{
    // TODO: Update GAMEPLAY screen variables here!
    if(IsKeyPressed(KEY_ENTER)){
        finishScreen = 1;
    }

}

// Gameplay Screen Draw logic
void DrawGameOverScreen(void)
{
    ClearBackground(RAYWHITE);
    // TODO: Draw GAMEPLAY screen here!
    DrawTexture(gameOver, 0, 0, WHITE);
}

// Gameplay Screen Unload logic
void UnloadGameOverScreen(void)
{
    // TODO: Unload GAMEPLAY screen variables here!
    UnloadTexture(gameOver);
}

// Gameplay Screen should Finish?
int FinishGameOverScreen(void)
{
    return finishScreen;
}