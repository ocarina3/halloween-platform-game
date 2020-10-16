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
#include <math.h> 
#include <stdlib.h> 

//----------------------------------------------------------------------------------
// Global Variables Definition (local to this module)
//----------------------------------------------------------------------------------

// Gameplay screen global variables
static int framesCounter;
static int finishScreen;

static Texture2D new;       
static Texture2D load;        
static Texture2D quit;       
static Texture2D currentTexture;
static int currentCounter;

static Vector2 scleraLeftPosition = { 800/2 - 65, 450/2 - 150};
static Vector2 scleraRightPosition = { 800/2 + 85, 450/2 - 150 };
static float scleraRadius;

static Vector2 irisLeftPosition = { 800/2 - 100, 450/2 };
static Vector2 irisRightPosition = { 800/2 + 100, 450/2};
static float irisRadius;

static float angle;
static float dx, dy, dxx, dyy;

//----------------------------------------------------------------------------------
// Gameplay Screen Functions Definition
//----------------------------------------------------------------------------------

// Gameplay Screen Initialization logic
void initMenuOneScreen(void)
{
    // TODO: Initialize GAMEPLAY screen variables here!
    framesCounter = 0;
    finishScreen = 0;

    new = LoadTexture("resources/textures/main_screen/menu_one.png");
    load = LoadTexture("resources/textures/main_screen/menu_two.png");
    quit = LoadTexture("resources/textures/main_screen/menu_three.png");
    currentTexture = new;
    currentCounter = 1;

    scleraRadius = 30;

    irisRadius = 14;

    angle = 0.0f;
    dx = 0.0f; 
    dy = 0.0f; 
    dxx = 0.0f; 
    dyy = 0.0f;

}

// Gameplay Screen Update logic
void updateMenuOneScreen(void)
{
    // TODO: Update GAMEPLAY screen variables here!

    irisLeftPosition = GetMousePosition();
        irisRightPosition = GetMousePosition();

        if (!CheckCollisionPointCircle(irisLeftPosition, scleraLeftPosition, scleraRadius - 20))
        {
            dx = irisLeftPosition.x - scleraLeftPosition.x;
            dy = irisLeftPosition.y - scleraLeftPosition.y;

            angle = atan2f(dy, dx);

            dxx = (scleraRadius - irisRadius)*cosf(angle);
            dyy = (scleraRadius - irisRadius)*sinf(angle);

            irisLeftPosition.x = scleraLeftPosition.x + dxx;
            irisLeftPosition.y = scleraLeftPosition.y + dyy;
        }

        if (!CheckCollisionPointCircle(irisRightPosition, scleraRightPosition, scleraRadius - 20))
        {
            dx = irisRightPosition.x - scleraRightPosition.x;
            dy = irisRightPosition.y - scleraRightPosition.y;

            angle = atan2f(dy, dx);

            dxx = (scleraRadius - irisRadius)*cosf(angle);
            dyy = (scleraRadius - irisRadius)*sinf(angle);

            irisRightPosition.x = scleraRightPosition.x + dxx;
            irisRightPosition.y = scleraRightPosition.y + dyy;
        }


    if (IsKeyPressed(KEY_UP))
        {
            if(currentCounter == 1){
               currentCounter = 3;
               currentTexture = quit; 
            }else if (currentCounter == 2){
               currentCounter = 1;
               currentTexture = new;
            }else{
               currentCounter = 2;
               currentTexture = load; 
            }

        }

        if (IsKeyPressed(KEY_DOWN))
        {
            if(currentCounter == 1){
               currentCounter = 2;
               currentTexture = load; 
            }else if (currentCounter == 2){
               currentCounter = 3;
               currentTexture = quit;
            }else{
               currentCounter = 1;
               currentTexture = new; 
            }
        }

    // Press enter or tap to change to ENDING screen
    if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
    {
        finishScreen = 1;
    }
}

// Gameplay Screen Draw logic
void drawMenuOneScreen(void)
{
    ClearBackground(RAYWHITE);
    // TODO: Draw GAMEPLAY screen here!
    DrawTexture(currentTexture, 0, 0, WHITE);

    DrawCircleV(irisRightPosition, irisRadius, DARKPURPLE);
    DrawCircleV(irisRightPosition, 7, BLACK);

    DrawCircleV(irisLeftPosition, irisRadius, DARKPURPLE);
    DrawCircleV(irisLeftPosition, 7, BLACK);
}

// Gameplay Screen Unload logic
void unloadMenuOneScreen(void)
{
    // TODO: Unload GAMEPLAY screen variables here!
    UnloadTexture(currentTexture);
    UnloadTexture(new);
    UnloadTexture(load);
    UnloadTexture(quit);
}

// Gameplay Screen should finish?
int finishMenuOneScreen(void)
{
    return finishScreen;
}