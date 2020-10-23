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
	bool attacked;
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
void check_boss_attaked();



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

void updateBoss()
{
	check_boss_attaked();
	if(boss.life > 0)
	{
		frameAttackCounter++;
		
		checkState();

	}
	else if (boss.life <= 0)
	{
		ray[0].mode = 0;
		ray[1].mode = 0;
		boss.hitbox.y -= 3.0;

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
	
	if(boss.attacked == true)
	{
		DrawRectangleRec(boss.hitbox, RED);
	}
	else
	{
		DrawRectangleRec(boss.hitbox, BLACK);
	}
}
	
void check_boss_attaked()
{
    Rectangle attack_area = attack(&heroi,heroi.reverse);

	if (boss.attacked == true && heroi.attackCooldown == 0) boss.attacked = false;
    
    if(heroi.attacking == true && boss.attacked == false)
    {
        if(heroi.reverse == false)
        {
            //if enemy is on attack area
            if((boss.hitbox.x <= attack_area.x + attack_area.width && boss.hitbox.x + boss.hitbox.width >= attack_area.x + attack_area.width) && (boss.hitbox.y <= attack_area.y && boss.hitbox.y + boss.hitbox.height >= attack_area.y))
            {
                boss.attacked = true;
                boss.life--;
            }
        }
        else
        {
            //if enemy is on attack area
            if((boss.hitbox.x >= attack_area.x + attack_area.width && boss.hitbox.x + boss.hitbox.width <= attack_area.x + attack_area.width) && (boss.hitbox.y >= attack_area.y && boss.hitbox.y + boss.hitbox.height <= attack_area.y))
            {
                boss.attacked = true;
                boss.life--;
            }    
        }
    }
    
}

#endif