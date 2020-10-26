#ifndef ENEMY_TEXTURES_H
#define ENEMY_TEXTURES_H

#include "raylib.h"

static Texture2D weakRunning[12];
static Texture2D weakDying[15];

static Texture2D strongRunning[12];
static Texture2D strongDying[15];
static Texture2D strongHurt[12];


void LoadEnemyTextures() {

    weakRunning[0] = LoadTexture("resources/textures/main_weakenemy/Running/0_Goblin_Running_000.png");
    weakRunning[1] = LoadTexture("resources/textures/main_weakenemy/Running/0_Goblin_Running_001.png");
    weakRunning[2] = LoadTexture("resources/textures/main_weakenemy/Running/0_Goblin_Running_002.png");
    weakRunning[3] = LoadTexture("resources/textures/main_weakenemy/Running/0_Goblin_Running_003.png");
    weakRunning[4] = LoadTexture("resources/textures/main_weakenemy/Running/0_Goblin_Running_004.png");
    weakRunning[5] = LoadTexture("resources/textures/main_weakenemy/Running/0_Goblin_Running_005.png");
    weakRunning[6] = LoadTexture("resources/textures/main_weakenemy/Running/0_Goblin_Running_006.png");
    weakRunning[7] = LoadTexture("resources/textures/main_weakenemy/Running/0_Goblin_Running_007.png");
    weakRunning[8] = LoadTexture("resources/textures/main_weakenemy/Running/0_Goblin_Running_008.png");
    weakRunning[9] = LoadTexture("resources/textures/main_weakenemy/Running/0_Goblin_Running_009.png");
    weakRunning[10] = LoadTexture("resources/textures/main_weakenemy/Running/0_Goblin_Running_010.png");
    weakRunning[11] = LoadTexture("resources/textures/main_weakenemy/Running/0_Goblin_Running_011.png");

    weakDying[0] = LoadTexture("resources/textures/main_weakenemy/Dying/0_Goblin_Dying_000.png");
    weakDying[1] = LoadTexture("resources/textures/main_weakenemy/Dying/0_Goblin_Dying_001.png");
    weakDying[2] = LoadTexture("resources/textures/main_weakenemy/Dying/0_Goblin_Dying_002.png");
    weakDying[3] = LoadTexture("resources/textures/main_weakenemy/Dying/0_Goblin_Dying_003.png");
    weakDying[4] = LoadTexture("resources/textures/main_weakenemy/Dying/0_Goblin_Dying_004.png");
    weakDying[5] = LoadTexture("resources/textures/main_weakenemy/Dying/0_Goblin_Dying_005.png");
    weakDying[6] = LoadTexture("resources/textures/main_weakenemy/Dying/0_Goblin_Dying_006.png");
    weakDying[7] = LoadTexture("resources/textures/main_weakenemy/Dying/0_Goblin_Dying_007.png");
    weakDying[8] = LoadTexture("resources/textures/main_weakenemy/Dying/0_Goblin_Dying_008.png");
    weakDying[9] = LoadTexture("resources/textures/main_weakenemy/Dying/0_Goblin_Dying_009.png");
    weakDying[10] = LoadTexture("resources/textures/main_weakenemy/Dying/0_Goblin_Dying_010.png");
    weakDying[11] = LoadTexture("resources/textures/main_weakenemy/Dying/0_Goblin_Dying_011.png");
    weakDying[12] = LoadTexture("resources/textures/main_weakenemy/Dying/0_Goblin_Dying_012.png");
    weakDying[13] = LoadTexture("resources/textures/main_weakenemy/Dying/0_Goblin_Dying_013.png");
    weakDying[14] = LoadTexture("resources/textures/main_weakenemy/Dying/0_Goblin_Dying_014.png");





    strongRunning[0] = LoadTexture("resources/textures/main_strongenemy/Running/0_Orc_Running_000.png");
    strongRunning[1] = LoadTexture("resources/textures/main_strongenemy/Running/0_Orc_Running_001.png");
    strongRunning[2] = LoadTexture("resources/textures/main_strongenemy/Running/0_Orc_Running_002.png");
    strongRunning[3] = LoadTexture("resources/textures/main_strongenemy/Running/0_Orc_Running_003.png");
    strongRunning[4] = LoadTexture("resources/textures/main_strongenemy/Running/0_Orc_Running_004.png");
    strongRunning[5] = LoadTexture("resources/textures/main_strongenemy/Running/0_Orc_Running_005.png");
    strongRunning[6] = LoadTexture("resources/textures/main_strongenemy/Running/0_Orc_Running_006.png");
    strongRunning[7] = LoadTexture("resources/textures/main_strongenemy/Running/0_Orc_Running_007.png");
    strongRunning[8] = LoadTexture("resources/textures/main_strongenemy/Running/0_Orc_Running_008.png");
    strongRunning[9] = LoadTexture("resources/textures/main_strongenemy/Running/0_Orc_Running_009.png");
    strongRunning[10] = LoadTexture("resources/textures/main_strongenemy/Running/0_Orc_Running_010.png");
    strongRunning[11] = LoadTexture("resources/textures/main_strongenemy/Running/0_Orc_Running_011.png");

    strongHurt[0] = LoadTexture("resources/textures/main_strongenemy/Hurt/0_Orc_Hurt_000.png");
    strongHurt[1] = LoadTexture("resources/textures/main_strongenemy/Hurt/0_Orc_Hurt_001.png");
    strongHurt[2] = LoadTexture("resources/textures/main_strongenemy/Hurt/0_Orc_Hurt_002.png");
    strongHurt[3] = LoadTexture("resources/textures/main_strongenemy/Hurt/0_Orc_Hurt_003.png");
    strongHurt[4] = LoadTexture("resources/textures/main_strongenemy/Hurt/0_Orc_Hurt_004.png");
    strongHurt[5] = LoadTexture("resources/textures/main_strongenemy/Hurt/0_Orc_Hurt_005.png");
    strongHurt[6] = LoadTexture("resources/textures/main_strongenemy/Hurt/0_Orc_Hurt_006.png");
    strongHurt[7] = LoadTexture("resources/textures/main_strongenemy/Hurt/0_Orc_Hurt_007.png");
    strongHurt[8] = LoadTexture("resources/textures/main_strongenemy/Hurt/0_Orc_Hurt_008.png");
    strongHurt[9] = LoadTexture("resources/textures/main_strongenemy/Hurt/0_Orc_Hurt_009.png");
    strongHurt[10] = LoadTexture("resources/textures/main_strongenemy/Hurt/0_Orc_Hurt_010.png");
    strongHurt[11] = LoadTexture("resources/textures/main_strongenemy/Hurt/0_Orc_Hurt_011.png");

    strongDying[0] = LoadTexture("resources/textures/main_strongenemy/Dying/0_Orc_Dying_000.png");
    strongDying[1] = LoadTexture("resources/textures/main_strongenemy/Dying/0_Orc_Dying_001.png");
    strongDying[2] = LoadTexture("resources/textures/main_strongenemy/Dying/0_Orc_Dying_002.png");
    strongDying[3] = LoadTexture("resources/textures/main_strongenemy/Dying/0_Orc_Dying_003.png");
    strongDying[4] = LoadTexture("resources/textures/main_strongenemy/Dying/0_Orc_Dying_004.png");
    strongDying[5] = LoadTexture("resources/textures/main_strongenemy/Dying/0_Orc_Dying_005.png");
    strongDying[6] = LoadTexture("resources/textures/main_strongenemy/Dying/0_Orc_Dying_006.png");
    strongDying[7] = LoadTexture("resources/textures/main_strongenemy/Dying/0_Orc_Dying_007.png");
    strongDying[8] = LoadTexture("resources/textures/main_strongenemy/Dying/0_Orc_Dying_008.png");
    strongDying[9] = LoadTexture("resources/textures/main_strongenemy/Dying/0_Orc_Dying_009.png");
    strongDying[10] = LoadTexture("resources/textures/main_strongenemy/Dying/0_Orc_Dying_010.png");
    strongDying[11] = LoadTexture("resources/textures/main_strongenemy/Dying/0_Orc_Dying_011.png");
    strongDying[12] = LoadTexture("resources/textures/main_strongenemy/Dying/0_Orc_Dying_012.png");
    strongDying[13] = LoadTexture("resources/textures/main_strongenemy/Dying/0_Orc_Dying_013.png");
    strongDying[14] = LoadTexture("resources/textures/main_strongenemy/Dying/0_Orc_Dying_014.png");

}

void UnloadEnemyTextures() {

    for ( int x = 0; x < 12; x++ ) {
        UnloadTexture(weakRunning[x]);
    }

    for ( int x = 0; x < 15; x++ ) {
        UnloadTexture(weakDying[x]);
    }


    for ( int x = 0; x < 12; x++ ) {
        UnloadTexture(strongRunning[x]);
    }

    for ( int x = 0; x < 12; x++ ) {
        UnloadTexture(strongHurt[x]);
    }

    for ( int x = 0; x < 15; x++ ) {
        UnloadTexture(strongDying[x]);
    }

}

#endif