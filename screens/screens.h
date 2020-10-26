#ifndef SCREENS_H
#define SCREENS_H

//----------------------------------------------------------------------------------
// Types and Structures DefInition
//----------------------------------------------------------------------------------
typedef enum { 
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