#ifndef BOSS_TEXTURES_H
#define BOSS_TEXTURES_H

#include "raylib.h"

static Texture2D bossIdle[12];
static Texture2D bossDying[15];
static Texture2D bossCasting[18];


void LoadBossTextures(){
    
    for ( int x = 0; x < 12; x++ ) {
        bossIdle[x] = LoadTexture(
            x > 9 ? 
            FormatText("resources/textures/boss/Running/Wraith_01_Idle_0%i.png", x) :
            FormatText("resources/textures/boss/Running/Wraith_01_Idle_00%i.png", x)
        );
    }

    for ( int x = 0; x < 18; x++ ) {
        bossCasting[x] = LoadTexture(
            x > 9 ? 
            FormatText("resources/textures/boss/Running/Wraith_01_Casting Speels_0%i.png", x) :
            FormatText("resources/textures/boss/Running/Wraith_01_Casting Speels_00%i.png", x)
        );
    }

    for ( int x = 0; x < 15; x++ ) {
        bossDying[x] = LoadTexture(
            x > 9 ? 
            FormatText("resources/textures/boss/Running/Wraith_01_Dying_0%i.png", x) :
            FormatText("resources/textures/boss/Running/Wraith_01_Dying_00%i.png", x)
        );
    }
}

void UnloadBossTextures() {

    for ( int x = 0; x < 12; x++ ) {
        UnloadTexture(bossIdle[x]);
    }

    for ( int x = 0; x < 18; x++ ) {
        UnloadTexture(bossCasting[x]);
    }

    for ( int x = 0; x < 15; x++ ) {
        UnloadTexture(bossDying[x]);
    }

}

#endif