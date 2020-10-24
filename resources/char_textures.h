#ifndef CHAR_TEXTURES_H
#define CHAR_TEXTURES_H

#include "raylib.h"

static Texture2D characterIdle;
static Texture2D characterRunning[12];
static Texture2D characterJumping[6];
static Texture2D characterSlashing[12];
static Texture2D characterDying[15];
static Texture2D characterHurt[12];

void LoadCharacterTextures() {
    characterIdle = LoadTexture("resources/textures/main_character/Idle Blinking/0_Fallen_Angels_Idle Blinking_000.png");

    characterRunning[0] = LoadTexture("resources/textures/main_character/Running/0_Fallen_Angels_Running_000.png");
    characterRunning[1] = LoadTexture("resources/textures/main_character/Running/0_Fallen_Angels_Running_001.png");
    characterRunning[2] = LoadTexture("resources/textures/main_character/Running/0_Fallen_Angels_Running_002.png");
    characterRunning[3] = LoadTexture("resources/textures/main_character/Running/0_Fallen_Angels_Running_003.png");
    characterRunning[4] = LoadTexture("resources/textures/main_character/Running/0_Fallen_Angels_Running_004.png");
    characterRunning[5] = LoadTexture("resources/textures/main_character/Running/0_Fallen_Angels_Running_005.png");
    characterRunning[6] = LoadTexture("resources/textures/main_character/Running/0_Fallen_Angels_Running_006.png");
    characterRunning[7] = LoadTexture("resources/textures/main_character/Running/0_Fallen_Angels_Running_007.png");
    characterRunning[8] = LoadTexture("resources/textures/main_character/Running/0_Fallen_Angels_Running_008.png");
    characterRunning[9] = LoadTexture("resources/textures/main_character/Running/0_Fallen_Angels_Running_009.png");
    characterRunning[10] = LoadTexture("resources/textures/main_character/Running/0_Fallen_Angels_Running_010.png");
    characterRunning[11] = LoadTexture("resources/textures/main_character/Running/0_Fallen_Angels_Running_011.png");

    characterJumping[0] = LoadTexture("resources/textures/main_character/Jump Start/0_Fallen_Angels_Jump Start_000.png");
    characterJumping[1] = LoadTexture("resources/textures/main_character/Jump Start/0_Fallen_Angels_Jump Start_001.png");
    characterJumping[2] = LoadTexture("resources/textures/main_character/Jump Start/0_Fallen_Angels_Jump Start_002.png");
    characterJumping[3] = LoadTexture("resources/textures/main_character/Jump Start/0_Fallen_Angels_Jump Start_003.png");
    characterJumping[4] = LoadTexture("resources/textures/main_character/Jump Start/0_Fallen_Angels_Jump Start_004.png");
    characterJumping[5] = LoadTexture("resources/textures/main_character/Jump Start/0_Fallen_Angels_Jump Start_005.png");

    characterSlashing[0] = LoadTexture("resources/textures/main_character/Slashing/0_Fallen_Angels_Slashing_000.png");
    characterSlashing[1] = LoadTexture("resources/textures/main_character/Slashing/0_Fallen_Angels_Slashing_001.png");
    characterSlashing[2] = LoadTexture("resources/textures/main_character/Slashing/0_Fallen_Angels_Slashing_002.png");
    characterSlashing[3] = LoadTexture("resources/textures/main_character/Slashing/0_Fallen_Angels_Slashing_003.png");
    characterSlashing[4] = LoadTexture("resources/textures/main_character/Slashing/0_Fallen_Angels_Slashing_004.png");
    characterSlashing[5] = LoadTexture("resources/textures/main_character/Slashing/0_Fallen_Angels_Slashing_005.png");
    characterSlashing[6] = LoadTexture("resources/textures/main_character/Slashing/0_Fallen_Angels_Slashing_006.png");
    characterSlashing[7] = LoadTexture("resources/textures/main_character/Slashing/0_Fallen_Angels_Slashing_007.png");
    characterSlashing[8] = LoadTexture("resources/textures/main_character/Slashing/0_Fallen_Angels_Slashing_008.png");
    characterSlashing[9] = LoadTexture("resources/textures/main_character/Slashing/0_Fallen_Angels_Slashing_009.png");
    characterSlashing[10] = LoadTexture("resources/textures/main_character/Slashing/0_Fallen_Angels_Slashing_010.png");
    characterSlashing[11] = LoadTexture("resources/textures/main_character/Slashing/0_Fallen_Angels_Slashing_011.png");

    characterDying[0] = LoadTexture("resources/textures/main_character/Dying/0_Fallen_Angels_Dying_000.png");
    characterDying[1] = LoadTexture("resources/textures/main_character/Dying/0_Fallen_Angels_Dying_001.png");
    characterDying[2] = LoadTexture("resources/textures/main_character/Dying/0_Fallen_Angels_Dying_002.png");
    characterDying[3] = LoadTexture("resources/textures/main_character/Dying/0_Fallen_Angels_Dying_003.png");
    characterDying[4] = LoadTexture("resources/textures/main_character/Dying/0_Fallen_Angels_Dying_004.png");
    characterDying[5] = LoadTexture("resources/textures/main_character/Dying/0_Fallen_Angels_Dying_005.png");
    characterDying[6] = LoadTexture("resources/textures/main_character/Dying/0_Fallen_Angels_Dying_006.png");
    characterDying[7] = LoadTexture("resources/textures/main_character/Dying/0_Fallen_Angels_Dying_007.png");
    characterDying[8] = LoadTexture("resources/textures/main_character/Dying/0_Fallen_Angels_Dying_008.png");
    characterDying[9] = LoadTexture("resources/textures/main_character/Dying/0_Fallen_Angels_Dying_009.png");
    characterDying[10] = LoadTexture("resources/textures/main_character/Dying/0_Fallen_Angels_Dying_010.png");
    characterDying[11] = LoadTexture("resources/textures/main_character/Dying/0_Fallen_Angels_Dying_011.png");
    characterDying[12] = LoadTexture("resources/textures/main_character/Dying/0_Fallen_Angels_Dying_012.png");
    characterDying[13] = LoadTexture("resources/textures/main_character/Dying/0_Fallen_Angels_Dying_013.png");
    characterDying[14] = LoadTexture("resources/textures/main_character/Dying/0_Fallen_Angels_Dying_014.png");

    characterHurt[0] = LoadTexture("resources/textures/main_character/Hurt/0_Fallen_Angels_Hurt_000.png");
    characterHurt[1] = LoadTexture("resources/textures/main_character/Hurt/0_Fallen_Angels_Hurt_001.png");
    characterHurt[2] = LoadTexture("resources/textures/main_character/Hurt/0_Fallen_Angels_Hurt_002.png");
    characterHurt[3] = LoadTexture("resources/textures/main_character/Hurt/0_Fallen_Angels_Hurt_003.png");
    characterHurt[4] = LoadTexture("resources/textures/main_character/Hurt/0_Fallen_Angels_Hurt_004.png");
    characterHurt[5] = LoadTexture("resources/textures/main_character/Hurt/0_Fallen_Angels_Hurt_005.png");
    characterHurt[6] = LoadTexture("resources/textures/main_character/Hurt/0_Fallen_Angels_Hurt_006.png");
    characterHurt[7] = LoadTexture("resources/textures/main_character/Hurt/0_Fallen_Angels_Hurt_007.png");
    characterHurt[8] = LoadTexture("resources/textures/main_character/Hurt/0_Fallen_Angels_Hurt_008.png");
    characterHurt[9] = LoadTexture("resources/textures/main_character/Hurt/0_Fallen_Angels_Hurt_009.png");
    characterHurt[10] = LoadTexture("resources/textures/main_character/Hurt/0_Fallen_Angels_Hurt_010.png");
    characterHurt[11] = LoadTexture("resources/textures/main_character/Hurt/0_Fallen_Angels_Hurt_011.png");
}

void UnloadCharacterTextures() {
    UnloadTexture(characterIdle);

    for ( int x = 0; x < 12; x++ ) {
        UnloadTexture(characterRunning[x]);
    }

    for ( int x = 0; x < 6; x++ ) {
        UnloadTexture(characterJumping[x]);
    }

    for ( int x = 0; x < 12; x++ ) {
        UnloadTexture(characterSlashing[x]);
    }

    for ( int x = 0; x < 15; x++ ) {
        UnloadTexture(characterDying[x]);
    }

    for ( int x = 0; x < 12; x++ ) {
        UnloadTexture(characterHurt[x]);
    }
}

#endif