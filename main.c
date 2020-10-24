/*******************************************************************************************
*
*   raylib - Standard Game template
*
*   <Game title>
*   <Game description>
*
*   This game has been created using raylib (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2014-2020 Ramon Santamaria (@raysan5)
*
********************************************************************************************/
#include "screens/screens.h"    // NOTE: Defines global variable: currentScreen

//----------------------------------------------------------------------------------
// Main entry point
//----------------------------------------------------------------------------------
int main(void)
{
    // Initialization (Note windowTitle is unused on Android)
    //---------------------------------------------------------

    InitWindow(screenWidth, screenHeight, "raylib - testing transitions between screens");
    InitPhysics();
    InitAudioDevice();
    srand(time(NULL));
    
    // TODO: Load global data here (assets that must be available in all screens, i.e. fonts)
    
    // Define and Init first screen
    currentScreen = MENU_USER;   // NOTE: currentScreen is defined in screens.h as a global variable
    int continueLevel = 0;
    InitMenuUserScreen();
    
    SetTargetFPS(60);
    //----------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        RunPhysicsStep();
        // Update
        //----------------------------------------------------------------------------------
        switch(currentScreen) 
        {
            case LEVEL_ONE: 
            {
                UpdateLevelOneScreen();
                continueLevel = 1;
                
                if (FinishLevelOneScreen())
                {
                    if(IsAliveLevelOne() == 0){
                        UnloadLevelOneScreen();
                        currentScreen = GAME_OVER;
                        InitGameOverScreen();   
                    }else{
                        UnloadLevelOneScreen();
                        currentScreen = LEVEL_TWO;
                        InitLevelTwoScreen();  
                    }
                    
                }
            } break;
            case LEVEL_TWO:
            {
                UpdateLevelTwoScreen();
                continueLevel = 2;
                
                if (FinishLevelTwoScreen())
                {
                    if(IsAliveLevelTwo() == 0){
                        UnloadLevelTwoScreen();
                        currentScreen = GAME_OVER;
                        InitGameOverScreen();   
                    }else{
                        UnloadLevelTwoScreen();
                        currentScreen = LEVEL_THREE;
                        InitLevelThreeScreen(); 
                    }
                } 
            } break;
            case LEVEL_THREE:
            { 
                UpdateLevelThreeScreen();
                continueLevel = 3;
                
                if (FinishLevelThreeScreen())
                {
                    if(IsAliveLevelThree() == 0){
                        UnloadLevelThreeScreen();
                        currentScreen = GAME_OVER;
                        InitGameOverScreen();   
                    }else{
                        UnloadLevelThreeScreen();
                        currentScreen = WIN_GAME;
                        InitWinScreen();
                    }
                }   
            } break;
            case GAME_OVER:
            { 
                UpdateGameOverScreen();
                
                if (FinishGameOverScreen())
                {
                    UnloadGameOverScreen();
                    if(continueLevel == 1){
                        currentScreen = LEVEL_ONE;
                        InitLevelOneScreen();
                    }else if (continueLevel == 2){
                        currentScreen = LEVEL_TWO;
                        InitLevelTwoScreen();
                    }else if (continueLevel == 3){
                        currentScreen = LEVEL_THREE;
                        InitLevelThreeScreen();
                    }
                    
                }   
            } break;
            case MENU_USER:
            { 
                UpdateMenuUserScreen();
                
                if (FinishMenuUserScreen())
                {
                    UnloadMenuUserScreen();
                    currentScreen = MENU_LOADING;
                    InitMenuLoadingScreen();
                }   
            } break;
            case MENU_LOADING:
            { 
                UpdateMenuLoadingScreen();
                
                if (FinishMenuLoadingScreen())
                {
                    UnloadMenuLoadingScreen();
                    currentScreen = MENU_ONE;
                    InitMenuOneScreen();
                }   
            } break;
            case WIN_GAME:
            { 
                UpdateWinScreen();
                
                if (FinishWinScreen())
                {
                    UnloadWinScreen();
                    currentScreen = MENU_ONE;
                    InitMenuOneScreen();
                }   
            } break;
            case MENU_ONE:
            { 
                UpdateMenuOneScreen();
                
                if (FinishMenuOneScreen())
                {
                    UnloadMenuOneScreen();
                    if(loadOption() == 1){
                        currentScreen = LEVEL_ONE;
                        InitLevelOneScreen();
                    }else if(loadOption() == 2){
                        if(loadLevel() == 1){
                            currentScreen = LEVEL_ONE;
                            InitLevelOneScreen();  
                        }else if(loadLevel() == 2){
                            currentScreen = LEVEL_TWO;
                            InitLevelTwoScreen();
                        }else if(loadLevel() == 3){
                            currentScreen = LEVEL_THREE;
                            InitLevelThreeScreen();
                        }
                    }else{
                        CloseWindow();
                    }
                        
                    
                }   
            } break;
            default: break;
        }
        //----------------------------------------------------------------------------------
        
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        
            ClearBackground(RAYWHITE);
            
            switch(currentScreen) 
            {
                case LEVEL_ONE: DrawLevelOneScreen(); break;
                case LEVEL_TWO: DrawLevelTwoScreen(); break;
                case LEVEL_THREE: DrawLevelThreeScreen(); break;
                case MENU_ONE: DrawMenuOneScreen(); break;
                case MENU_USER: DrawMenuUserScreen(); break;
                case MENU_LOADING: DrawMenuLoadingScreen(); break;
                case GAME_OVER: DrawGameOverScreen(); break;
                case WIN_GAME: DrawWinScreen(); break;
                default: break;
            }
        
            //DrawFPS(10, 10);
        
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    ClosePhysics();
    // TODO: Unload all global loaded data (i.e. fonts) here!
    CloseAudioDevice();
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
