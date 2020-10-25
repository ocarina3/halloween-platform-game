#ifndef BOSS_TEXTURES_H
#define BOSS_TEXTURES_H

#define MAX_FRAME_IDLE 12
#define MAX_FRAME_CASTING 18 
#define MAX_FRAME_DYING 15

#include "raylib.h"

static Texture2D bossIdle[12];
static Texture2D bossDying[15];
static Texture2D bossCasting[18];


void LoadBossTextures(){
    
    for ( int x = 0; x < MAX_FRAME_IDLE; x++ ) {
        bossIdle[x] = LoadTexture(
            x > 9 ? 
            FormatText("resources/textures/boss/Idle/Wraith_01_Idle_0%i.png", x) :
            FormatText("resources/textures/boss/Idle/Wraith_01_Idle_00%i.png", x)
        );
    }

    for ( int x = 0; x < MAX_FRAME_CASTING; x++ ) {
        bossCasting[x] = LoadTexture(
            x > 9 ? 
            FormatText("resources/textures/boss/Casting/Wraith_01_Casting Spells_0%i.png", x) :
            FormatText("resources/textures/boss/Casting/Wraith_01_Casting Spells_00%i.png", x)
        );
    }

    for ( int x = 0; x < MAX_FRAME_DYING; x++ ) {
        bossDying[x] = LoadTexture(
            x > 9 ? 
            FormatText("resources/textures/boss/Dying/Wraith_01_Dying_0%i.png", x) :
            FormatText("resources/textures/boss/Dying/Wraith_01_Dying_00%i.png", x)
        );
    }
}

void UnloadBossTextures() {

    for ( int x = 0; x < MAX_FRAME_IDLE; x++ ) {
        UnloadTexture(bossIdle[x]);
    }

    for ( int x = 0; x < MAX_FRAME_CASTING; x++ ) {
        UnloadTexture(bossCasting[x]);
    }

    for ( int x = 0; x < MAX_FRAME_DYING; x++ ) {
        UnloadTexture(bossDying[x]);
    }

}

#endif