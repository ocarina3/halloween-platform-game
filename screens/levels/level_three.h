#include "../../components/phase.h"
#include "../../components/boss.h"

//----------------------------------------------------------------------------------
// Global Variables DefInition (local to this module)
//----------------------------------------------------------------------------------

// Gameplay screen global variables
Vector2 playerBlock;
Vector2 cameraPosition;
static int framesCounter;
static int finishScreen;
static int isAlive;
bool wallCreated;

static FILE *fileWriteLevelThree;
static FILE *fileReadLevelThreeCurrentUser;
static FILE *fileReadLevelThree;

static char usernameLevelThree[300];
static char nickLevelThree[100];
static char currentUserLevelThree[100];
static char spaceLevelThree[100];

//----------------------------------------------------------------------------------
// Gameplay Screen Functions DefInition
//----------------------------------------------------------------------------------

// Gameplay Screen Initialization logic
void InitLevelThreeScreen(void)
{
    framesCounter = 0;
    finishScreen = 0;
    isAlive = 1;
    wallCreated = false;
    StartBoss();
    StartVariables();
    LoadAllTextures();
    CreateMap(3);
    CreateWall(7,92);
    CreateEnemiesMap(3);
    
    fileWriteLevelThree = fopen("save/save.txt", "a");
    fileReadLevelThreeCurrentUser = fopen("save/current_player.txt", "r");
    fileReadLevelThree = fopen("save/save.txt", "r");
}

// Gameplay Screen Update logic
void UpdateLevelThreeScreen(void)
{
    framesCounter++;
    playerBlock = GetPlayerBlock();
    UpdateGame(&hero);
    UpdateEnemy();
    //get the physical part of map
    ActivatePhysics();

    //ajust camera position
    if(wallCreated == false)
    {
        camera.target = (Vector2){hero.physic->position.x + 20, hero.physic->position.y > 100 ? 200 : hero.physic->position.y + 100};
        if(boss.life <= 0) UpdateBoss();
    }
    else
    {
        UpdateBoss();
        if(cameraPosition.x < 1550) cameraPosition.x += 5;
        if(cameraPosition.y > 200) cameraPosition.y -= 1;
        if(cameraPosition.y < 200) cameraPosition.y += 1;
        camera.target = (Vector2){cameraPosition.x,cameraPosition.y};
    }
    if(playerBlock.x >= 23 && wallCreated == false && boss.life > 0)
    {
        cameraPosition.x = hero.physic->position.x;
        cameraPosition.y = hero.physic->position.y;
        CreateWall(22,38);
        wallCreated = true;
    }
    if(boss.life <= 0 && wallCreated == true)
    {
        DestroyWalls();
        CreateWall(2,92);
        wallCreated = false;
    }    
    //_________________________________________________________
    

    if(hero.isAlive == false && isAlive != 0){
        isAlive = 0; 
        framesCounter = 0;
    }

    if(framesCounter > 2*fps && isAlive == 0){
        finishScreen = 1;
    }
       
    
    //_________________________________________________
    //get the player coordinate in blocks
    


    

    fgets(currentUserLevelThree, 300, fileReadLevelThreeCurrentUser);
    fclose(fileReadLevelThreeCurrentUser);

    if(fileWriteLevelThree == NULL){

    }else{
        while(fgets(usernameLevelThree, 300, fileReadLevelThree)!= NULL){

        }
        fclose(fileReadLevelThree);

        strcpy(spaceLevelThree, " ");
        strcat(spaceLevelThree, currentUserLevelThree);
        strcpy(nickLevelThree, spaceLevelThree);
        strcat(nickLevelThree, " 3");

        if (strstr(usernameLevelThree, nickLevelThree) != NULL){
                
        }else{
            fprintf(fileWriteLevelThree, " %s %i ", currentUserLevelThree, 3);
            fclose(fileWriteLevelThree);
        }
    }

    // Press enter or tap to change to ENDING screen
    if (playerBlock.x == 50)
    {
        finishScreen = 1;
    }
}

// Gameplay Screen Draw logic
void DrawLevelThreeScreen(void)
{
    
    DrawTexture(background, 0, 0, WHITE);
    BeginMode2D(camera);
        DrawTextureMap();
        DrawEnemy();
        DrawEntities(&hero);
        DrawBoss();
        DrawSign(playerBlock.x,playerBlock.y,3);
    EndMode2D();    
    DrawLifeBar(&hero);
    if ( wallCreated ) DrawBossLifeBar();
    //DrawText(TextFormat("bloco: [%i,%i]\ncoordenada: [%f,%f]", (int)(playerBlock.x), (int)(playerBlock.y),(hero.physic->position.x),(hero.physic->position.y)), 315, 250, 20, DARKGRAY);
    //DrawFPS(screenWidth - 90, screenHeight - 30);
}

// Gameplay Screen Unload logic
void UnloadLevelThreeScreen(void)
{
    DestroyWalls();
    DestroyAllPhysics();
    UnloadAllTextures();
}

// Gameplay Screen should Finish?
int FinishLevelThreeScreen(void)
{
    return finishScreen;
}

int IsAliveLevelThree(void)
{
    return isAlive;
}