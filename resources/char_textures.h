#ifndef CHAR_TEXTURES_H
#define CHAR_TEXTURES_H

#include "raylib.h"

static Texture2D mc_stop;
static Texture2D mc_running[12];
static Texture2D mc_jumping[6];
static Texture2D mc_slashing[12];

void loadAllTextures() {
    mc_stop = LoadTexture("resources/textures/main_character/Idle Blinking/0_Fallen_Angels_Idle Blinking_000.png");

    mc_running[0] = LoadTexture("resources/textures/main_character/Running/0_Fallen_Angels_Running_000.png");
    mc_running[1] = LoadTexture("resources/textures/main_character/Running/0_Fallen_Angels_Running_001.png");
    mc_running[2] = LoadTexture("resources/textures/main_character/Running/0_Fallen_Angels_Running_002.png");
    mc_running[3] = LoadTexture("resources/textures/main_character/Running/0_Fallen_Angels_Running_003.png");
    mc_running[4] = LoadTexture("resources/textures/main_character/Running/0_Fallen_Angels_Running_004.png");
    mc_running[5] = LoadTexture("resources/textures/main_character/Running/0_Fallen_Angels_Running_005.png");
    mc_running[6] = LoadTexture("resources/textures/main_character/Running/0_Fallen_Angels_Running_006.png");
    mc_running[7] = LoadTexture("resources/textures/main_character/Running/0_Fallen_Angels_Running_007.png");
    mc_running[8] = LoadTexture("resources/textures/main_character/Running/0_Fallen_Angels_Running_008.png");
    mc_running[9] = LoadTexture("resources/textures/main_character/Running/0_Fallen_Angels_Running_009.png");
    mc_running[10] = LoadTexture("resources/textures/main_character/Running/0_Fallen_Angels_Running_010.png");
    mc_running[11] = LoadTexture("resources/textures/main_character/Running/0_Fallen_Angels_Running_011.png");

    mc_jumping[0] = LoadTexture("resources/textures/main_character/Jump Start/0_Fallen_Angels_Jump Start_000.png");
    mc_jumping[1] = LoadTexture("resources/textures/main_character/Jump Start/0_Fallen_Angels_Jump Start_001.png");
    mc_jumping[2] = LoadTexture("resources/textures/main_character/Jump Start/0_Fallen_Angels_Jump Start_002.png");
    mc_jumping[3] = LoadTexture("resources/textures/main_character/Jump Start/0_Fallen_Angels_Jump Start_003.png");
    mc_jumping[4] = LoadTexture("resources/textures/main_character/Jump Start/0_Fallen_Angels_Jump Start_004.png");
    mc_jumping[5] = LoadTexture("resources/textures/main_character/Jump Start/0_Fallen_Angels_Jump Start_005.png");

    mc_slashing[0] = LoadTexture("resources/textures/main_character/Slashing/0_Fallen_Angels_Slashing_000.png");
    mc_slashing[1] = LoadTexture("resources/textures/main_character/Slashing/0_Fallen_Angels_Slashing_001.png");
    mc_slashing[2] = LoadTexture("resources/textures/main_character/Slashing/0_Fallen_Angels_Slashing_002.png");
    mc_slashing[3] = LoadTexture("resources/textures/main_character/Slashing/0_Fallen_Angels_Slashing_003.png");
    mc_slashing[4] = LoadTexture("resources/textures/main_character/Slashing/0_Fallen_Angels_Slashing_004.png");
    mc_slashing[5] = LoadTexture("resources/textures/main_character/Slashing/0_Fallen_Angels_Slashing_005.png");
    mc_slashing[6] = LoadTexture("resources/textures/main_character/Slashing/0_Fallen_Angels_Slashing_006.png");
    mc_slashing[7] = LoadTexture("resources/textures/main_character/Slashing/0_Fallen_Angels_Slashing_007.png");
    mc_slashing[8] = LoadTexture("resources/textures/main_character/Slashing/0_Fallen_Angels_Slashing_008.png");
    mc_slashing[9] = LoadTexture("resources/textures/main_character/Slashing/0_Fallen_Angels_Slashing_009.png");
    mc_slashing[10] = LoadTexture("resources/textures/main_character/Slashing/0_Fallen_Angels_Slashing_010.png");
    mc_slashing[11] = LoadTexture("resources/textures/main_character/Slashing/0_Fallen_Angels_Slashing_011.png");
}

void unloadAllTextures() {
    UnloadTexture(mc_stop);

    for ( int x = 0; x < 12; x++ ) {
        UnloadTexture(mc_running[x]);
    }

    for ( int x = 0; x < 6; x++ ) {
        UnloadTexture(mc_jumping[x]);
    }

    for ( int x = 0; x < 12; x++ ) {
        UnloadTexture(mc_slashing[x]);
    }
}

#endif