#ifndef BOSS_H
#define BOSS_H

#include "main_character.h"
#include <stdlib.h>
#include <time.h>

//___________________________________STRUCTS_______________________________________________

typedef struct
{
	Rectangle hitbox;
	int life;
}main_enemy;

typedef struct
{
	int y;
	int mode;
	bool alreadyHit;
}laser;

//___________________________________VARIABLES_______________________________________________
int randomOne;
int randomTwo;
int fps;
int state;
int numberOfAttacks;

//________________________________FUNCTIONS DECLARATIONS_______________________________________

void bossAttack();
void checkState();
void startBoss();
void updateBoss();
void drawBoss();



int frameAttackCounter;
main_enemy boss;
laser ray[2];

void bossAttack()
{
	if (frameAttackCounter <= fps * 2)
	{
		//Carregando o ataque
		if(randomOne == 3 && randomTwo == 3)
		{
			randomOne = rand() % 3;
			randomTwo = rand() % 3;
		}


		if(randomOne == randomTwo && randomTwo > 0)
		{
			randomTwo--;
		}
		else if(randomOne == randomTwo)
		{
			randomTwo++;
		}

		switch (randomOne)
		{
			case 0:
				ray[0].y = 50;

				break;
			
			case 1:
				ray[0].y = 150;
				
				break;

			case 2:
				ray[0].y = 250;
				
				break;
				
			default:
				break;
		}

		switch (randomTwo)
		{
			case 0:
				ray[1].y = 50;

				break;
			
			case 1:
				ray[1].y = 150;
				
				break;

			case 2:
				ray[1].y = 250;
				
				break;
				
			default:
				break;
		}
		ray[0].mode = 1;
		if(boss.life <= 5)
		{
			ray[1].mode = 1;
		}
		
	}
	else if(frameAttackCounter <= fps * 4)
	{
		//Ataque
		ray[0].mode = 2;
		
		if(boss.life <= 5)
		{
			ray[1].mode = 2;
		}
	}
	
	else
	{

		ray[0].mode = 0;
		ray[1].mode = 0;
		ray[0].alreadyHit = 0;
		ray[1].alreadyHit = 0;

		frameAttackCounter = 0;

		randomOne   = 3;
		randomTwo   = 3;

		if(numberOfAttacks != 0)
		{
			state = 2; 

			numberOfAttacks--;
		}
		else
		{
			boss.life -= 5;
			state = 3;
			
			numberOfAttacks = 3;
		}
		
	}

}

void checkState()
{
	//boss parado
	if (state == 0)
	{  
		if(frameAttackCounter <= fps * 5);
		
		else
		{
			frameAttackCounter = 0;
			state = 1;
		}  
	}

	//boss subindo
	if (state == 1)
	{
		if (frameAttackCounter <= fps * 3)
		{
			boss.hitbox.y -= 1.6f;
		}
		else
		{
			frameAttackCounter = 0;
			state = 2;
		} 
	}
	// boss atacando

	
	if (state == 2)
	{
		bossAttack();
	
	}
	// boss descendo
	if (state == 3)
	{
		if (frameAttackCounter <= fps * 3)
		{
			boss.hitbox.y += 1.6f;
		}
		else
		{
			frameAttackCounter = 0;
			state = 0;
		} 
	}
}

void startBoss()
{
    fps = 60;

    randomOne = 3;
    randomTwo = 3;

    numberOfAttacks = 3;

    boss.life = 10;
    boss.hitbox = (Rectangle){1600, 100, 50, 50};

    ray[0].mode = 0;
    ray[1].mode = 0;
    ray[0].y = 280; 
    ray[1].y = 200;
	ray[0].alreadyHit = 0;
	ray[1].alreadyHit = 0;

    state = 0;

    frameAttackCounter = 0;
}

void updateBoss()
{
	if(boss.life != 0)
	{
		frameAttackCounter++;
		
		checkState();

	}else
	{

		boss.hitbox.x += 3.0f;

	}
}

void drawBoss()
{
	if(ray[1].mode == 1)
	{
			DrawRectangle(1650, ray[1].y, 40, 40, BLUE);
	}
	else if(ray[1].mode == 2)
	{
		DrawRectangle(1650, ray[1].y, 40, 40, RED);
	}

	if(ray[0].mode == 1)
	{
			DrawRectangle(1650, ray[0].y, 40, 40, BLUE);
	}
	else if(ray[0].mode == 2)
	{
		DrawRectangle(1650, ray[0].y, 40, 40, RED);
	}
	

	DrawRectangleRec(boss.hitbox, BLACK);
}

#endif