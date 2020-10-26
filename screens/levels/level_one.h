#include "../../components/phase.h"


Vector2 playerBlock;
static int framesCounter;
static int finishScreen;
static int isAlive;

// Gameplay Screen Initialization logic
void InitLevelOneScreen(void)
{
    // Initialize GAMEPLAY screen variables here!
    framesCounter = 0;
    finishScreen = 0;
    isAlive = 1;

    StartVariables();
    CreateEnemiesMap(1);
    LoadAllTextures();
    CreateMap(1);
    CreateWall(7,92);
}


// Gameplay Screen Update logic
void UpdateLevelOneScreen(void)
{
    framesCounter++;
    //ajust camera position
    camera.target = (Vector2){hero.physic->position.x + 20, 250};
    //_________________________________________________________
    UpdateGame(&hero);
    UpdateEnemy();
    //get the physical part of map
    ActivatePhysics();
    
    if(hero.isAlive == false && isAlive != 0){
        isAlive = 0; 
        framesCounter = 0;
    }

    if(framesCounter>120 && isAlive == 0){
        finishScreen = 1;
    }
    
    //_________________________________________________
    //get the player coordinate in blocks
    playerBlock = GetPlayerBlock();
    

    // Press enter or tap to change to ENDING screen
    if (playerBlock.x == 91)
    {
        finishScreen = 1;
    }
}

// Gameplay Screen Draw logic
void DrawLevelOneScreen(void)
{
    //Get the camera
    DrawTexture(background, 0, 0, WHITE);
    BeginMode2D(camera);
        DrawTextureMap();
        DrawEnemy();
        DrawEntities(&hero);
        DrawSign(playerBlock.x,playerBlock.y,1);
    EndMode2D();    
    DrawLifeBar(&hero);
    //DrawText(TextFormat("bloco: [%i,%i]\ncoordenada: [%f,%f]", (int)(playerBlock.x), (int)(playerBlock.y),(hero.physic->position.x),(hero.physic->position.y)), 315, 250, 20, DARKGRAY);
    //DrawFPS(screenWidth - 90, screenHeight - 30);
}

// Gameplay Screen Unload logic
void UnloadLevelOneScreen(void)
{
    DestroyWalls();
    DestroyAllPhysics();
    UnloadAllTextures();
}

// Gameplay Screen should Finish?
int FinishLevelOneScreen(void)
{
    return finishScreen;
}

int IsAliveLevelOne(void)
{
    return isAlive;
}









