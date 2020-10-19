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

#include "../../components/phase.h"

static int framesCounter;
static int finishScreen;

// Gameplay Screen Initialization logic
void initLevelOneScreen(void)
{
    // Initialize GAMEPLAY screen variables here!
    framesCounter = 0;
    finishScreen = 0;

    load_texture();
    start_variables();
    create_map();
}


// Gameplay Screen Update logic
void updateLevelOneScreen(void)
{
    //ajust camera position
    camera.target = (Vector2){ heroi.physic->position.x + 20, heroi.physic->position.y + 20};
    //_________________________________________________________
    updateGame(&heroi, enemys, lifes, &countEnemys, &countLifes);
    //_________________________________________________
    //get the player coordinate in blocks
    player_block = get_player_block();
    //get the physical part of map
    create_physic_map();

    // Press enter or tap to change to ENDING screen
    if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
    {
        finishScreen = 1;
    }
}

// Gameplay Screen Draw logic
void drawLevelOneScreen(void)
{
    //Get the camera
    DrawTexture(background, 0, 0, WHITE);
    BeginMode2D(camera);
    
        draw_texture_map();
        draw_texture_character();

    EndMode2D();    
    DrawText(TextFormat("bloco: [%i,%i]\ncoordenada: [%f,%f]", (int)(player_block.x), (int)(player_block.y),(heroi.physic->velocity.x),(heroi.physic->velocity.y)), 315, 250, 20, DARKGRAY);
    DrawFPS(screenWidth - 90, screenHeight - 30);
}

// Gameplay Screen Unload logic
void unloadLevelOneScreen(void)
{
    int i = GetPhysicsBodiesCount();
    destroy_all_physics(i);
    unload_texture();
}

// Gameplay Screen should finish?
int finishLevelOneScreen(void)
{
    return finishScreen;
}









