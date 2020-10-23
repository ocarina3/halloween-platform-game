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
#include "../../components/boss.h"

//----------------------------------------------------------------------------------
// Global Variables Definition (local to this module)
//----------------------------------------------------------------------------------

// Gameplay screen global variables
Vector2 camera_pos;
static int framesCounter;
static int finishScreen;
static int isAlive;
bool wall_created;

static FILE *fileWriteLevelThree;
static FILE *fileReadLevelThreeCurrentUser;
static FILE *fileReadLevelThree;

static char username_lvl_three[300];
static char nick_lvl_three[100];
static char current_user_lvl_three[100];
static char space_lvl_three[100];

//----------------------------------------------------------------------------------
// Gameplay Screen Functions Definition
//----------------------------------------------------------------------------------

// Gameplay Screen Initialization logic
void initLevelThreeScreen(void)
{
    framesCounter = 0;
    finishScreen = 0;
    isAlive = 1;
    wall_created = false;
    loadAllTextures();
    startBoss();
    start_variables();
    load_texture();
    create_map(3);
    create_wall(7,92);
    
    fileWriteLevelThree = fopen("save/save.txt", "a");
    fileReadLevelThreeCurrentUser = fopen("save/current_player.txt", "r");
    fileReadLevelThree = fopen("save/save.txt", "r");
}

// Gameplay Screen Update logic
void updateLevelThreeScreen(void)
{
    framesCounter++;
    player_block = get_player_block();
    updateGame(&heroi);

    //ajust camera position
    if(wall_created == false)
    {
        camera.target = (Vector2){heroi.physic->position.x + 20, heroi.physic->position.y > 100 ? 200 : heroi.physic->position.y + 100};
        if(boss.life <= 0) updateBoss();
    }
    else
    {
        updateBoss();
        if(camera_pos.x < 1550) camera_pos.x += 5;
        if(camera_pos.y > 200) camera_pos.y -= 1;
        camera.target = (Vector2){camera_pos.x,camera_pos.y};
    }
    if(player_block.x >= 23 && wall_created == false && boss.life > 0)
    {
        camera_pos.x = heroi.physic->position.x;
        camera_pos.y = heroi.physic->position.y;
        create_wall(22,38);
        wall_created = true;
    }
    if(boss.life <= 0 && wall_created == true)
    {
        destroy_walls();
        create_wall(2,92);
        wall_created = false;
    }    
    //_________________________________________________________
    

    if(heroi.isAlive == false && isAlive != 0){
        isAlive = 0; 
        framesCounter = 0;
    }

    if(framesCounter > 2*fps && isAlive == 0){
            finishScreen = 1;
    }
       
    
    //_________________________________________________
    //get the player coordinate in blocks
    


    //get the physical part of map
    ativate_physics();

    fgets(current_user_lvl_three, 300, fileReadLevelThreeCurrentUser);
    fclose(fileReadLevelThreeCurrentUser);

    if(fileWriteLevelThree == NULL){

    }else{
        while(fgets(username_lvl_three, 300, fileReadLevelThree)!= NULL){

        }
        fclose(fileReadLevelThree);

        strcpy(space_lvl_three, " ");
        strcat(space_lvl_three, current_user_lvl_three);
        strcpy(nick_lvl_three, space_lvl_three);
        strcat(nick_lvl_three, " 3");

        if (strstr(username_lvl_three, nick_lvl_three) != NULL){
                
        }else{
            fprintf(fileWriteLevelThree, " %s %i ", current_user_lvl_three, 3);
            fclose(fileWriteLevelThree);
        }
    }

    // Press enter or tap to change to ENDING screen
    if (IsKeyPressed(KEY_ENTER))
    {
        finishScreen = 1;
    }
}

// Gameplay Screen Draw logic
void drawLevelThreeScreen(void)
{
    DrawTexture(background, 0, 0, WHITE);
    BeginMode2D(camera);
        draw_texture_map();
        DrawEntities(&heroi);
        drawBoss();
    EndMode2D();    
    DrawText(FormatText("Lives: %i", heroi.lives), screenWidth - 80, 80, 14, YELLOW);
    DrawText(TextFormat("bloco: [%i,%i]\ncoordenada: [%f,%f]", (int)(player_block.x), (int)(player_block.y),(heroi.physic->position.x),(heroi.physic->position.y)), 315, 250, 20, DARKGRAY);
    DrawFPS(screenWidth - 90, screenHeight - 30);
}

// Gameplay Screen Unload logic
void unloadLevelThreeScreen(void)
{
    destroy_walls();
    unloadAllTextures();
    destroy_all_physics();
    unload_texture();
}

// Gameplay Screen should finish?
int finishLevelThreeScreen(void)
{
    return finishScreen;
}

int isAliveLevelThree(void)
{
    return isAlive;
}