#include "raylib.h"

//----------------------------------------------------------------------------------
// Global Variables DefInition (local to this module)
//----------------------------------------------------------------------------------

// Gameplay screen global variables
static int framesCounter;
static int finishScreen;

static Texture2D mainTexture;
static Texture2D winScreen;
static Texture2D creditsScreen;


//----------------------------------------------------------------------------------
// Gameplay Screen Functions DefInition
//----------------------------------------------------------------------------------

// Gameplay Screen Initialization logic
void InitWinScreen(void)
{
    // TODO: Initialize GAMEPLAY screen variables here!
    framesCounter = 0;
    finishScreen = 0;

    winScreen = LoadTexture("resources/textures/win-game-screen/win-game-screen.png");
    creditsScreen = LoadTexture("resources/textures/win-game-screen/credits.png");
    mainTexture = winScreen;
}

// Gameplay Screen Update logic
void UpdateWinScreen(void)
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
void DrawWinScreen(void)
{
    ClearBackground(RAYWHITE);
    // TODO: Draw GAMEPLAY screen here!
    DrawTexture(mainTexture, 0, 0, WHITE);
}

// Gameplay Screen Unload logic
void UnloadWinScreen(void)
{
    // TODO: Unload GAMEPLAY screen variables here!
    UnloadTexture(winScreen);
    UnloadTexture(creditsScreen);
    UnloadTexture(mainTexture);
}

// Gameplay Screen should Finish?
int FinishWinScreen(void)
{
    return finishScreen;
}