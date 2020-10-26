#include "raylib.h"

//----------------------------------------------------------------------------------
// Global Variables DefInition (local to this module)
//----------------------------------------------------------------------------------

// Gameplay screen global variables
static int framesCounter;
static int finishScreen;

static Texture2D mainTexture;
static Texture2D loadOne;
static Texture2D loadTwo;
static Texture2D loadThree;


//----------------------------------------------------------------------------------
// Gameplay Screen Functions DefInition
//----------------------------------------------------------------------------------

// Gameplay Screen Initialization logic
void InitMenuLoadingScreen(void)
{
    // TODO: Initialize GAMEPLAY screen variables here!
    framesCounter = 0;
    finishScreen = 0;

    loadOne = LoadTexture("resources/textures/loading_screen/loading_one.png");
    loadTwo = LoadTexture("resources/textures/loading_screen/loading_two.png");
    loadThree = LoadTexture("resources/textures/loading_screen/loading_three.png");
    mainTexture = loadOne;
}

// Gameplay Screen Update logic
void UpdateMenuLoadingScreen(void)
{
    framesCounter++;
    // TODO: Update GAMEPLAY screen variables here!

      if(framesCounter == 60){
            mainTexture = loadTwo;
        }else if (framesCounter == 120){
            mainTexture = loadThree;
        }else if (framesCounter == 180){
            mainTexture = loadOne;
        }else if(framesCounter == 240){
            mainTexture = loadTwo;
        }else if (framesCounter == 300){
            mainTexture = loadThree;
        }

        if(framesCounter == 360){
            finishScreen = 1;
        }
        
}

// Gameplay Screen Draw logic
void DrawMenuLoadingScreen(void)
{
    ClearBackground(RAYWHITE);
    // TODO: Draw GAMEPLAY screen here!
   DrawTexture(mainTexture, 0, 0, WHITE);
}

// Gameplay Screen Unload logic
void UnloadMenuLoadingScreen(void)
{
    // TODO: Unload GAMEPLAY screen variables here!
    UnloadTexture(loadOne);
    UnloadTexture(loadTwo);
    UnloadTexture(loadThree);
    UnloadTexture(mainTexture);
}

// Gameplay Screen should Finish?
int FinishMenuLoadingScreen(void)
{
    return finishScreen;
}