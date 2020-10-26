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