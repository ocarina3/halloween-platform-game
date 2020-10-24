/**********************************************************************************************
*
*   raylib - Standard Game template
*
*   Screens Functions Declarations (Init, Update, Draw, Unload)
*
*   Copyright (c) 2014-2020 Ramon Santamaria (@raysan5)
*
*   This software is provided "as-is", without any express or implied warranty. In no event
*   will the authors be held liable for any damages arising from the use of this software.
*
*   Permission is granted to anyone to use this software for any purpose, including commercial
*   applications, and to alter it and redistribute it freely, subject to the following restrictions:
*
*     1. The origin of this software must not be misrepresented; you must not claim that you
*     wrote the original software. If you use this software in a product, an acknowledgment
*     in the product documentation would be appreciated but is not required.
*
*     2. Altered source versions must be plainly marked as such, and must not be misrepresented
*     as being the original software.
*
*     3. This notice may not be removed or altered from any source distribution.
*
**********************************************************************************************/

#ifndef SCREENS_H
#define SCREENS_H

//----------------------------------------------------------------------------------
// Types and Structures DefInition
//----------------------------------------------------------------------------------
typedef enum GameScreen { 
	LEVEL_ONE, 
	LEVEL_TWO, 
	LEVEL_THREE, 
	MENU_ONE, 
	MENU_USER, 
	MENU_LOADING, 
	GAME_OVER, 
	WIN_GAME 
} GameScreen;

//----------------------------------------------------------------------------------
// Global Variables DefInition
//----------------------------------------------------------------------------------
GameScreen currentScreen;

#ifdef __cplusplus
extern "C" {            // Prevents name mangling of functions
#endif

#include "levels/level_one.h"
#include "levels/level_two.h"
#include "levels/level_three.h"


#include "menu/menu_one.h"
#include "menu/menu_user.h"
#include "menu/menu_loading.h"
#include "menu/game_over.h"
#include "menu/win_game.h"


#ifdef __cplusplus
}
#endif

#endif // SCREENS_H