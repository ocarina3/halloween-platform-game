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

//----------------------------------------------------------------------------------
// Global Variables Definition (local to this module)
//----------------------------------------------------------------------------------

// Gameplay screen global variables
static int framesCounter;
static int finishScreen;

//----------------------------------------------------------------------------------
// Gameplay Screen Functions Definition
//----------------------------------------------------------------------------------

// Gameplay Screen Initialization logic
void initLevelTwoScreen(void)
{
    // TODO: Initialize GAMEPLAY screen variables here!
    framesCounter = 0;
    finishScreen = 0;

    loadAllTextures();
    start_variables();
    load_texture();
    create_map(2);
    create_wall(7,106);
}

// Gameplay Screen Update logic
void updateLevelTwoScreen(void)
{
    // TODO: Update GAMEPLAY screen variables here!
    camera.target = (Vector2){heroi.physic->position.x + 20, heroi.physic->position.y > 100 ? 200 : heroi.physic->position.y + 100};
    //_________________________________________________________
    updateGame(&heroi);
    //_________________________________________________
    //get the player coordinate in blocks
    player_block = get_player_block();
    //get the physical part of map
    ativate_physics();

    // Press enter or tap to change to ENDING screen
    if (IsKeyPressed(KEY_ENTER))
    {
        finishScreen = 3;
    }
}

// Gameplay Screen Draw logic
void drawLevelTwoScreen(void)
{
    DrawTexture(background, 0, 0, WHITE);
    BeginMode2D(camera);
        draw_texture_map();
        DrawEntities(&heroi);

    EndMode2D();    
    DrawText(FormatText("Lives: %i", heroi.lives), screenWidth - 80, 80, 14, YELLOW);
    DrawText(TextFormat("bloco: [%i,%i]\ncoordenada: [%f,%f]", (int)(player_block.x), (int)(player_block.y),(heroi.physic->position.x),(heroi.physic->position.y)), 315, 250, 20, DARKGRAY);
    DrawFPS(screenWidth - 90, screenHeight - 30);
}

// Gameplay Screen Unload logic
void unloadLevelTwoScreen(void)
{
    destroy_walls();
    unloadAllTextures();
    destroy_all_physics();
    unload_texture();
}

// Gameplay Screen should finish?
int finishLevelTwoScreen(void)
{
    return finishScreen;
}