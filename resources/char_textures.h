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

    for ( int x = 0; x < 12; x++ ) {
        characterRunning[x] = LoadTexture(
            x > 9 ? 
            FormatText("resources/textures/main_character/Running/0_Fallen_Angels_Running_0%i.png", x) :
            FormatText("resources/textures/main_character/Running/0_Fallen_Angels_Running_00%i.png", x)
        );
    }

    for ( int x = 0; x < 6; x++ ) {
        characterJumping[x] = LoadTexture(FormatText("resources/textures/main_character/Jump Start/0_Fallen_Angels_Jump Start_00%i.png", x));
    }

    for ( int x = 0; x < 12; x++ ) {
        characterSlashing[x] = LoadTexture(
            x > 9 ? 
            FormatText("resources/textures/main_character/Slashing/0_Fallen_Angels_Slashing_0%i.png", x) :
            FormatText("resources/textures/main_character/Slashing/0_Fallen_Angels_Slashing_00%i.png", x)
        );
    }

    for ( int x = 0; x < 15; x++ ) {
        characterDying[x] = LoadTexture(
            x > 9 ? 
            FormatText("resources/textures/main_character/Dying/0_Fallen_Angels_Dying_0%i.png", x) :
            FormatText("resources/textures/main_character/Dying/0_Fallen_Angels_Dying_00%i.png", x)
        );
    }
    
    for ( int x = 0; x < 12; x++ ) {
        characterHurt[x] = LoadTexture(
            x > 9 ? 
            FormatText("resources/textures/main_character/Hurt/0_Fallen_Angels_Hurt_0%i.png", x) :
            FormatText("resources/textures/main_character/Hurt/0_Fallen_Angels_Hurt_00%i.png", x)
        );
    }
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