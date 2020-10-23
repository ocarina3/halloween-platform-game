#ifndef ENEMY_TEXTURES_H
#define ENEMY_TEXTURES_H

#include "raylib.h"

static Texture2D weak_running[12];
static Texture2D weak_dying[15];

static Texture2D strong_running[12];
static Texture2D strong_dying[15];
static Texture2D strong_hurt[12];


void loadEnemyTextures() {

    weak_running[0] = LoadTexture("resources/textures/main_weakenemy/Running/0_Goblin_Running_000.png");
    weak_running[1] = LoadTexture("resources/textures/main_weakenemy/Running/0_Goblin_Running_001.png");
    weak_running[2] = LoadTexture("resources/textures/main_weakenemy/Running/0_Goblin_Running_002.png");
    weak_running[3] = LoadTexture("resources/textures/main_weakenemy/Running/0_Goblin_Running_003.png");
    weak_running[4] = LoadTexture("resources/textures/main_weakenemy/Running/0_Goblin_Running_004.png");
    weak_running[5] = LoadTexture("resources/textures/main_weakenemy/Running/0_Goblin_Running_005.png");
    weak_running[6] = LoadTexture("resources/textures/main_weakenemy/Running/0_Goblin_Running_006.png");
    weak_running[7] = LoadTexture("resources/textures/main_weakenemy/Running/0_Goblin_Running_007.png");
    weak_running[8] = LoadTexture("resources/textures/main_weakenemy/Running/0_Goblin_Running_008.png");
    weak_running[9] = LoadTexture("resources/textures/main_weakenemy/Running/0_Goblin_Running_009.png");
    weak_running[10] = LoadTexture("resources/textures/main_weakenemy/Running/0_Goblin_Running_010.png");
    weak_running[11] = LoadTexture("resources/textures/main_weakenemy/Running/0_Goblin_Running_011.png");

    weak_dying[0] = LoadTexture("resources/textures/main_weakenemy/Dying/0_Goblin_Dying_000.png");
    weak_dying[1] = LoadTexture("resources/textures/main_weakenemy/Dying/0_Goblin_Dying_001.png");
    weak_dying[2] = LoadTexture("resources/textures/main_weakenemy/Dying/0_Goblin_Dying_002.png");
    weak_dying[3] = LoadTexture("resources/textures/main_weakenemy/Dying/0_Goblin_Dying_003.png");
    weak_dying[4] = LoadTexture("resources/textures/main_weakenemy/Dying/0_Goblin_Dying_004.png");
    weak_dying[5] = LoadTexture("resources/textures/main_weakenemy/Dying/0_Goblin_Dying_005.png");
    weak_dying[6] = LoadTexture("resources/textures/main_weakenemy/Dying/0_Goblin_Dying_006.png");
    weak_dying[7] = LoadTexture("resources/textures/main_weakenemy/Dying/0_Goblin_Dying_007.png");
    weak_dying[8] = LoadTexture("resources/textures/main_weakenemy/Dying/0_Goblin_Dying_008.png");
    weak_dying[9] = LoadTexture("resources/textures/main_weakenemy/Dying/0_Goblin_Dying_009.png");
    weak_dying[10] = LoadTexture("resources/textures/main_weakenemy/Dying/0_Goblin_Dying_010.png");
    weak_dying[11] = LoadTexture("resources/textures/main_weakenemy/Dying/0_Goblin_Dying_011.png");
    weak_dying[12] = LoadTexture("resources/textures/main_weakenemy/Dying/0_Goblin_Dying_012.png");
    weak_dying[13] = LoadTexture("resources/textures/main_weakenemy/Dying/0_Goblin_Dying_013.png");
    weak_dying[14] = LoadTexture("resources/textures/main_weakenemy/Dying/0_Goblin_Dying_014.png");





    strong_running[0] = LoadTexture("resources/textures/main_strongenemy/Running/0_Orc_Running_000.png");
    strong_running[1] = LoadTexture("resources/textures/main_strongenemy/Running/0_Orc_Running_001.png");
    strong_running[2] = LoadTexture("resources/textures/main_strongenemy/Running/0_Orc_Running_002.png");
    strong_running[3] = LoadTexture("resources/textures/main_strongenemy/Running/0_Orc_Running_003.png");
    strong_running[4] = LoadTexture("resources/textures/main_strongenemy/Running/0_Orc_Running_004.png");
    strong_running[5] = LoadTexture("resources/textures/main_strongenemy/Running/0_Orc_Running_005.png");
    strong_running[6] = LoadTexture("resources/textures/main_strongenemy/Running/0_Orc_Running_006.png");
    strong_running[7] = LoadTexture("resources/textures/main_strongenemy/Running/0_Orc_Running_007.png");
    strong_running[8] = LoadTexture("resources/textures/main_strongenemy/Running/0_Orc_Running_008.png");
    strong_running[9] = LoadTexture("resources/textures/main_strongenemy/Running/0_Orc_Running_009.png");
    strong_running[10] = LoadTexture("resources/textures/main_strongenemy/Running/0_Orc_Running_010.png");
    strong_running[11] = LoadTexture("resources/textures/main_strongenemy/Running/0_Orc_Running_011.png");

    strong_hurt[0] = LoadTexture("resources/textures/main_strongenemy/Hurt/0_Orc_Hurt_000.png");
    strong_hurt[1] = LoadTexture("resources/textures/main_strongenemy/Hurt/0_Orc_Hurt_001.png");
    strong_hurt[2] = LoadTexture("resources/textures/main_strongenemy/Hurt/0_Orc_Hurt_002.png");
    strong_hurt[3] = LoadTexture("resources/textures/main_strongenemy/Hurt/0_Orc_Hurt_003.png");
    strong_hurt[4] = LoadTexture("resources/textures/main_strongenemy/Hurt/0_Orc_Hurt_004.png");
    strong_hurt[5] = LoadTexture("resources/textures/main_strongenemy/Hurt/0_Orc_Hurt_005.png");
    strong_hurt[6] = LoadTexture("resources/textures/main_strongenemy/Hurt/0_Orc_Hurt_006.png");
    strong_hurt[7] = LoadTexture("resources/textures/main_strongenemy/Hurt/0_Orc_Hurt_007.png");
    strong_hurt[8] = LoadTexture("resources/textures/main_strongenemy/Hurt/0_Orc_Hurt_008.png");
    strong_hurt[9] = LoadTexture("resources/textures/main_strongenemy/Hurt/0_Orc_Hurt_009.png");
    strong_hurt[10] = LoadTexture("resources/textures/main_strongenemy/Hurt/0_Orc_Hurt_010.png");
    strong_hurt[11] = LoadTexture("resources/textures/main_strongenemy/Hurt/0_Orc_Hurt_011.png");

    strong_dying[0] = LoadTexture("resources/textures/main_strongenemy/Dying/0_Orc_Dying_000.png");
    strong_dying[1] = LoadTexture("resources/textures/main_strongenemy/Dying/0_Orc_Dying_001.png");
    strong_dying[2] = LoadTexture("resources/textures/main_strongenemy/Dying/0_Orc_Dying_002.png");
    strong_dying[3] = LoadTexture("resources/textures/main_strongenemy/Dying/0_Orc_Dying_003.png");
    strong_dying[4] = LoadTexture("resources/textures/main_strongenemy/Dying/0_Orc_Dying_004.png");
    strong_dying[5] = LoadTexture("resources/textures/main_strongenemy/Dying/0_Orc_Dying_005.png");
    strong_dying[6] = LoadTexture("resources/textures/main_strongenemy/Dying/0_Orc_Dying_006.png");
    strong_dying[7] = LoadTexture("resources/textures/main_strongenemy/Dying/0_Orc_Dying_007.png");
    strong_dying[8] = LoadTexture("resources/textures/main_strongenemy/Dying/0_Orc_Dying_008.png");
    strong_dying[9] = LoadTexture("resources/textures/main_strongenemy/Dying/0_Orc_Dying_009.png");
    strong_dying[10] = LoadTexture("resources/textures/main_strongenemy/Dying/0_Orc_Dying_010.png");
    strong_dying[11] = LoadTexture("resources/textures/main_strongenemy/Dying/0_Orc_Dying_011.png");
    strong_dying[12] = LoadTexture("resources/textures/main_strongenemy/Dying/0_Orc_Dying_012.png");
    strong_dying[13] = LoadTexture("resources/textures/main_strongenemy/Dying/0_Orc_Dying_013.png");
    strong_dying[14] = LoadTexture("resources/textures/main_strongenemy/Dying/0_Orc_Dying_014.png");

}

void unloadEnemyTextures() {

    for ( int x = 0; x < 12; x++ ) {
        UnloadTexture(weak_running[x]);
    }

    for ( int x = 0; x < 15; x++ ) {
        UnloadTexture(weak_dying[x]);
    }


    for ( int x = 0; x < 12; x++ ) {
        UnloadTexture(strong_running[x]);
    }

    for ( int x = 0; x < 12; x++ ) {
        UnloadTexture(strong_hurt[x]);
    }

    for ( int x = 0; x < 15; x++ ) {
        UnloadTexture(strong_dying[x]);
    }

}

#endif