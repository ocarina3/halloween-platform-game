#ifndef BOSS_H
#define BOSS_H

#include "main_character.h"
#include "../resources/boss_textures.h"
#include <stdlib.h>
#include <time.h>

//___________________________________STRUCTS_______________________________________________

typedef struct
{
	Rectangle hitbox;
	int life;
	bool attacked;
} MainEnemy;

typedef struct
{
	int y;
	int mode;
	bool alreadyHit;
} Laser;

//___________________________________VARIABLES_______________________________________________
int randomOne;
int randomTwo;
int fps;
int state;
int numberOfAttacks;

//________________________________FUNCTIONS DECLARATIONS_______________________________________

void BossAttack();
void CheckState();
void StartBoss();
void UpdateBoss();
void DrawBoss();
void CheckBossAttacked();



int frameAttackCounter;
MainEnemy boss;
Laser ray[2];

void BossAttack()
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
			state = 3;
			
			numberOfAttacks = 3;
		}
		
	}

}

void CheckState()
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
		BossAttack();
	
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

void StartBoss()
{
    fps = 60;

    randomOne = 3;
    randomTwo = 3;

    numberOfAttacks = 3;

	boss.attacked = false;
    boss.life = 10;
    boss.hitbox = (Rectangle){1550, 250, 50, 50};

    ray[0].mode = 0;
    ray[1].mode = 0;
    ray[0].y = 280; 
    ray[1].y = 200;
	ray[0].alreadyHit = 0;
	ray[1].alreadyHit = 0;

    state = 0;

    frameAttackCounter = 0;
}

void UpdateBoss()
{
	CheckBossAttacked();
	if(boss.life > 0)
	{
		frameAttackCounter++;
		
		CheckState();

	}
	else if (boss.life <= 0)
	{
		ray[0].mode = 0;
		ray[1].mode = 0;
		boss.hitbox.y -= 3.0;

	}
}

void DrawBoss()
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
	
	if(boss.attacked == true)
	{
		DrawRectangleRec(boss.hitbox, RED);
	}
	else
	{
		DrawRectangleRec(boss.hitbox, BLACK);
	}
}
	
void CheckBossAttacked()
{
    Rectangle attack_area = CharacterAttack(&hero,hero.reverse);

	if (boss.attacked == true && hero.attackCooldown == 0) boss.attacked = false;
    
    if(hero.attacking == true && boss.attacked == false) {
		if ( CheckCollisionRecs(boss.hitbox, attack_area) )
		{
			boss.attacked = true;
			boss.life--;
		}
	}
}

#endif