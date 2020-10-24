#ifndef ENEMY_TEXTURES_H
#define ENEMY_TEXTURES_H

#include "raylib.h"

static Texture2D strongRunning[12];
static Texture2D weakRunning[12];


void LoadEnemyTextures() {

    weakRunning[0] = LoadTexture("resources/textures/main_weakenemy/Running/0_Goblin_Running_000.png");
    weakRunning[1] = LoadTexture("resources/textures/main_character/Running/0_Goblin_Running_001.png");
    weakRunning[2] = LoadTexture("resources/textures/main_character/Running/0_Goblin_Running_002.png");
    weakRunning[3] = LoadTexture("resources/textures/main_character/Running/0_Goblin_Running_003.png");
    weakRunning[4] = LoadTexture("resources/textures/main_character/Running/0_Goblin_Running_004.png");
    weakRunning[5] = LoadTexture("resources/textures/main_character/Running/0_Goblin_Running_005.png");
    weakRunning[6] = LoadTexture("resources/textures/main_character/Running/0_Goblin_Running_006.png");
    weakRunning[7] = LoadTexture("resources/textures/main_character/Running/0_Goblin_Running_007.png");
    weakRunning[8] = LoadTexture("resources/textures/main_character/Running/0_Goblin_Running_008.png");
    weakRunning[9] = LoadTexture("resources/textures/main_character/Running/0_Goblin_Running_009.png");
    weakRunning[10] = LoadTexture("resources/textures/main_character/Running/0_Goblin_Running_010.png");
    weakRunning[11] = LoadTexture("resources/textures/main_character/Running/0_Goblin_Running_011.png");

    strongRunning[0] = LoadTexture("resources/textures/main_weakenemy/Running/0_Orc_Running_000.png");
    strongRunning[1] = LoadTexture("resources/textures/main_character/Running/0_Orc_Running_001.png");
    strongRunning[2] = LoadTexture("resources/textures/main_character/Running/0_Orc_Running_002.png");
    strongRunning[3] = LoadTexture("resources/textures/main_character/Running/0_Orc_Running_003.png");
    strongRunning[4] = LoadTexture("resources/textures/main_character/Running/0_Orc_Running_004.png");
    strongRunning[5] = LoadTexture("resources/textures/main_character/Running/0_Orc_Running_005.png");
    strongRunning[6] = LoadTexture("resources/textures/main_character/Running/0_Orc_Running_006.png");
    strongRunning[7] = LoadTexture("resources/textures/main_character/Running/0_Orc_Running_007.png");
    strongRunning[8] = LoadTexture("resources/textures/main_character/Running/0_Orc_Running_008.png");
    strongRunning[9] = LoadTexture("resources/textures/main_character/Running/0_Orc_Running_009.png");
    strongRunning[10] = LoadTexture("resources/textures/main_character/Running/0_Orc_Running_010.png");
    strongRunning[11] = LoadTexture("resources/textures/main_character/Running/0_Orc_Running_011.png");

}

void UnloadEnemyTextures() {

    for ( int x = 0; x < 12; x++ ) {
        UnloadTexture(weakRunning[x]);
    }

    for ( int x = 0; x < 12; x++ ) {
        UnloadTexture(strongRunning[x]);
    }

}

#endif