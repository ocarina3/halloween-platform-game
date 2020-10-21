#ifndef ENEMY_TEXTURES_H
#define ENEMY_TEXTURES_H

#include "raylib.h"

static Texture2D strong_running[12];
static Texture2D weak_running[12];


void loadAllTextures() {

    weak_running[0] = LoadTexture("resources/textures/main_weakenemy/Running/0_Goblin_Running_000.png");
    weak_running[1] = LoadTexture("resources/textures/main_character/Running/0_Goblin_Running_001.png");
    weak_running[2] = LoadTexture("resources/textures/main_character/Running/0_Goblin_Running_002.png");
    weak_running[3] = LoadTexture("resources/textures/main_character/Running/0_Goblin_Running_003.png");
    weak_running[4] = LoadTexture("resources/textures/main_character/Running/0_Goblin_Running_004.png");
    weak_running[5] = LoadTexture("resources/textures/main_character/Running/0_Goblin_Running_005.png");
    weak_running[6] = LoadTexture("resources/textures/main_character/Running/0_Goblin_Running_006.png");
    weak_running[7] = LoadTexture("resources/textures/main_character/Running/0_Goblin_Running_007.png");
    weak_running[8] = LoadTexture("resources/textures/main_character/Running/0_Goblin_Running_008.png");
    weak_running[9] = LoadTexture("resources/textures/main_character/Running/0_Goblin_Running_009.png");
    weak_running[10] = LoadTexture("resources/textures/main_character/Running/0_Goblin_Running_010.png");
    weak_running[11] = LoadTexture("resources/textures/main_character/Running/0_Goblin_Running_011.png");

    strong_running[0] = LoadTexture("resources/textures/main_weakenemy/Running/0_Orc_Running_000.png");
    strong_running[1] = LoadTexture("resources/textures/main_character/Running/0_Orc_Running_001.png");
    strong_running[2] = LoadTexture("resources/textures/main_character/Running/0_Orc_Running_002.png");
    strong_running[3] = LoadTexture("resources/textures/main_character/Running/0_Orc_Running_003.png");
    strong_running[4] = LoadTexture("resources/textures/main_character/Running/0_Orc_Running_004.png");
    strong_running[5] = LoadTexture("resources/textures/main_character/Running/0_Orc_Running_005.png");
    strong_running[6] = LoadTexture("resources/textures/main_character/Running/0_Orc_Running_006.png");
    strong_running[7] = LoadTexture("resources/textures/main_character/Running/0_Orc_Running_007.png");
    strong_running[8] = LoadTexture("resources/textures/main_character/Running/0_Orc_Running_008.png");
    strong_running[9] = LoadTexture("resources/textures/main_character/Running/0_Orc_Running_009.png");
    strong_running[10] = LoadTexture("resources/textures/main_character/Running/0_Orc_Running_010.png");
    strong_running[11] = LoadTexture("resources/textures/main_character/Running/0_Orc_Running_011.png");

}

void unloadAllTextures() {

    for ( int x = 0; x < 12; x++ ) {
        UnloadTexture(weak_running[x]);
    }

    for ( int x = 0; x < 12; x++ ) {
        UnloadTexture(strong_running[x]);
    }

}

#endif