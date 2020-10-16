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

#include "raylib.h"
#define PHYSAC_IMPLEMENTATION
#define PHYSAC_NO_THREADS

#include "physac.h"
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

    // TODO: Load global data here (assets that must be available in all screens, i.e. fonts)
    
    // Define and init first screen
    currentScreen = LEVEL_ONE;   // NOTE: currentScreen is defined in screens.h as a global variable
    initLevelOneScreen();
    
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
                    currentScreen = LEVEL_ONE;
                    initLevelOneScreen();
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
    
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
