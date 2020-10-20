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

    // TODO: Load global data here (assets that must be available in all screens, i.e. fonts)
    
    // Define and init first screen
    currentScreen = MENU_USER;   // NOTE: currentScreen is defined in screens.h as a global variable
    initMenuUserScreen();
    
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
                updateLevelOneScreen();
                
                if (finishLevelOneScreen())
                {
                    unloadLevelOneScreen();
                    currentScreen = LEVEL_TWO;
                    initLevelTwoScreen();
                }
            } break;
            case LEVEL_TWO:
            {
                updateLevelTwoScreen();
                
                if (finishLevelTwoScreen())
                {
                    unloadLevelTwoScreen();
                    currentScreen = LEVEL_THREE;
                    initLevelThreeScreen();
                } 
            } break;
            case LEVEL_THREE:
            { 
                updateLevelThreeScreen();
                
                if (finishLevelThreeScreen())
                {
                    unloadLevelThreeScreen();
                    currentScreen = MENU_USER;
                    initMenuUserScreen();
                }   
            } break;
            case MENU_USER:
            { 
                updateMenuUserScreen();
                
                if (finishMenuUserScreen())
                {
                    unloadMenuUserScreen();
                    currentScreen = MENU_LOADING;
                    initMenuLoadingScreen();
                }   
            } break;
            case MENU_LOADING:
            { 
                updateMenuLoadingScreen();
                
                if (finishMenuLoadingScreen())
                {
                    unloadMenuLoadingScreen();
                    currentScreen = MENU_ONE;
                    initMenuOneScreen();
                }   
            } break;
            case MENU_ONE:
            { 
                updateMenuOneScreen();
                
                if (finishMenuOneScreen())
                {
                    unloadMenuOneScreen();
                    if(loadOption() == 1){
                        currentScreen = LEVEL_ONE;
                        initLevelOneScreen();
                    }else if(loadOption() == 2){
                        if(loadLevel() == 1){
                            currentScreen = LEVEL_ONE;
                            initLevelOneScreen();  
                        }else if(loadLevel() == 2){
                            currentScreen = LEVEL_TWO;
                            initLevelTwoScreen();
                        }else if(loadLevel() == 3){
                            currentScreen = LEVEL_THREE;
                            initLevelThreeScreen();
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
                case LEVEL_ONE: drawLevelOneScreen(); break;
                case LEVEL_TWO: drawLevelTwoScreen(); break;
                case LEVEL_THREE: drawLevelThreeScreen(); break;
                case MENU_ONE: drawMenuOneScreen(); break;
                case MENU_USER: drawMenuUserScreen(); break;
                case MENU_LOADING: drawMenuLoadingScreen(); break;
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
