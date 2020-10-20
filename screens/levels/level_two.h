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

#include "raylib.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//----------------------------------------------------------------------------------
// Global Variables Definition (local to this module)
//----------------------------------------------------------------------------------

// Gameplay screen global variables
static int framesCounter;
static int finishScreen;

static FILE *fileWriteLevelTwo;
static FILE *fileReadLevelTwoCurrentUser;
static FILE *fileReadLevelTwo;

static char username_lvl_two[300];
static char nick_lvl_two[100];
static char current_user_lvl_two[100];
static char space_lvl_two[100];

//----------------------------------------------------------------------------------
// Gameplay Screen Functions Definition
//----------------------------------------------------------------------------------

// Gameplay Screen Initialization logic
void initLevelTwoScreen(void)
{
    // TODO: Initialize GAMEPLAY screen variables here!
    framesCounter = 0;
    finishScreen = 0;

    load_texture();
    create_map(2);
    create_wall(7,106);
    fileWriteLevelTwo = fopen("save/save.txt", "a");
    fileReadLevelTwo = fopen("save/save.txt", "r");
    fileReadLevelTwoCurrentUser = fopen("save/current_player.txt", "r");

}

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
    fgets(current_user_lvl_two, 300, fileReadLevelTwoCurrentUser);
    fclose(fileReadLevelTwoCurrentUser);

    if(fileWriteLevelTwo == NULL){

    }else{
        while(fgets(username_lvl_two, 300, fileReadLevelTwo)!= NULL){

        }
        fclose(fileReadLevelTwo);

        strcpy(space_lvl_two, " ");
        strcat(space_lvl_two, current_user_lvl_two);
        strcpy(nick_lvl_two, space_lvl_two);
        strcat(nick_lvl_two, " 2");

        if (strstr(username_lvl_two, nick_lvl_two) != NULL){
                
        }else{
            fprintf(fileWriteLevelTwo, " %s %i ", current_user_lvl_two, 2);
            fclose(fileWriteLevelTwo);
        }
    }

    // Press enter or tap to change to ENDING screen
    if (IsKeyPressed(KEY_ENTER))
    {
        finishScreen = 3;
    }
}

// Gameplay Screen Draw logic
void drawLevelTwoScreen(void)
{
    // TODO: Draw GAMEPLAY screen here!
    DrawTexture(background, 0, 0, WHITE);
    BeginMode2D(camera);
    
        draw_texture_map();
        draw_texture_character();

    EndMode2D();    
    DrawText(TextFormat("bloco: [%i,%i]\ncoordenada: [%f,%f]", (int)(player_block.x), (int)(player_block.y),(heroi.physic->position.x),(heroi.physic->position.y)), 315, 250, 20, DARKGRAY);
    DrawFPS(screenWidth - 90, screenHeight - 30);
}

// Gameplay Screen Unload logic
void unloadLevelTwoScreen(void)
{
    // TODO: Unload GAMEPLAY screen variables here!
    destroy_all_physics();
    unload_texture();
}

// Gameplay Screen should finish?
int finishLevelTwoScreen(void)
{
    return finishScreen;
}