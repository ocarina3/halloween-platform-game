#ifndef BOSS_H
#define BOSS_H

#include "main_character.h"
#include "../resources/boss_textures.h"
#include <stdlib.h>
#include <time.h>

#define MAX_HEALTH_BOSS 40

//___________________________________STRUCTS_______________________________________________

typedef struct
{
	Rectangle hitbox;
	Texture2D bossState;
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
void DrawRayAttacked(int ray);
void DrawRayPrepared(int ray);
void DrawBossLifeBar();


int frameAttackCounter;
MainEnemy boss;
Laser ray[2];

void BossAttack()
{
	if (frameAttackCounter <= fps * 1)
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
		if(boss.life <= MAX_HEALTH_BOSS / 2)
		{
			ray[1].mode = 1;
		}
		
	}
	else if(frameAttackCounter <= fps * 2)
	{
		//Ataque
		ray[0].mode = 2;
		
		if(boss.life <= MAX_HEALTH_BOSS / 2)
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
		int idleFrame = frameAttackCounter%MAX_FRAME_IDLE;
		if(frameAttackCounter <= fps * 3) boss.bossState = bossIdle[idleFrame];
		else
		{
			frameAttackCounter = 0;
			state = 1;
		}  
	}

	//boss subindo
	if (state == 1)
	{
		int idleFrame = frameAttackCounter%MAX_FRAME_IDLE;
		if (frameAttackCounter <= fps * 3)
		{
			boss.bossState = bossIdle[idleFrame];
			boss.hitbox.y -= 1.5f;
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
		int frameCasting = frameAttackCounter%MAX_FRAME_CASTING;
		boss.bossState = bossCasting[frameCasting];
		BossAttack();
	}
	// boss descendo
	if (state == 3)
	{
		int idleFrame = frameAttackCounter%MAX_FRAME_IDLE;
		boss.bossState = bossIdle[idleFrame];
		if (frameAttackCounter <= fps * 3)
		{
			boss.hitbox.y += 1.5f;
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
    boss.life = MAX_HEALTH_BOSS;
    boss.hitbox = (Rectangle){1550, 250, 40, 50};

    ray[0].mode = 0;
    ray[1].mode = 0;
    ray[0].y = 280; 
    ray[1].y = 200;
	ray[0].alreadyHit = 0;
	ray[1].alreadyHit = 0;

    state = 1;

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
		
		int frameDying = frameAttackCounter%MAX_FRAME_DYING;
		boss.bossState = bossDying[frameDying];

		ray[0].mode = 0;
		ray[1].mode = 0;
		boss.hitbox.y--;
	}
}

void DrawBossLifeBar() {
    // Desenha a borda da vida
    DrawRectangleLines(screenWidth - 300, screenHeight - 60, 200, 30, GRAY);
    // Desenha a vida
    DrawRectangle(screenWidth - 299, screenHeight - 59, ((200 / (float)(MAX_HEALTH_BOSS)) * boss.life) - 2, 28, YELLOW);
}

int rayPreparedAnimation = 0;
void DrawRayPrepared(int iRay) {
	Color animationColor = GRAY;
	if (rayPreparedAnimation > 8) animationColor = BLACK;
	rayPreparedAnimation = rayPreparedAnimation == 15 ? 0 : rayPreparedAnimation + 1;

	DrawCircle(1650, ray[iRay].y + 20, 20, animationColor);
}

int rayAttackedAnimation = 0;
void DrawRayAttacking(int iRay) {
	Color animationColor = ORANGE;
	if (rayAttackedAnimation > 8) animationColor = RED;
	rayAttackedAnimation = rayAttackedAnimation == 15 ? 0 : rayAttackedAnimation + 1;

	DrawRectangle(0, ray[iRay].y, 3000, 40, animationColor);
}

void DrawBoss()
{
	if(ray[1].mode == 1)
	{
		DrawRayPrepared(1);
	}
	else if(ray[1].mode == 2)
	{
		DrawRayAttacking(1);
	}

	if(ray[0].mode == 1)
	{
		DrawRayPrepared(0);
	}
	else if(ray[0].mode == 2)
	{
		DrawRayAttacking(0);
	}
	
	
	DrawTextureRec(boss.bossState, (Rectangle){0,0, boss.hitbox.width + 10, boss.hitbox.height}, (Vector2){boss.hitbox.x - 15, boss.hitbox.y - 10}, WHITE);
	DrawRectangleLines(boss.hitbox.x,boss.hitbox.y,boss.hitbox.width,boss.hitbox.height,BLACK);
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