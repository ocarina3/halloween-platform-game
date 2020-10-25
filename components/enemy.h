#ifndef ENEMY_H
#define ENEMY_H

#include "get_map.h"
#include "main_character.h"
#include "../resources/enemy_textures.h"

typedef struct 
{
    Rectangle bodyRec;
    Vector2 limits;
    Texture2D enemyState;
    int enemyAnimation;
    int damageDuration;
    int bodyLife;
    int detect;
    int currentPhase;
    bool reverse;
    bool gerated;
    bool attacked;
} Enemy;

Enemy enemies[13];
int counterEnemies = 0;

void StartEnemyVariables();
void CreateEnemy(Vector2 inicial,Vector2 final,int lifes, int phase);
void UpdateEnemy();
//void check_enemy_physics(int i);
void CheckEnemyAttacked(int i);
void DrawEnemy();
void CreateEnemiesMap(int phase);
void UpdateEnemyState();


void StartEnemyVariables()
{
    for (int i = 0; i < 10; i++)
    {
        enemies[i].attacked = false;
        enemies[i].reverse = false;
        enemies[i].gerated = false;
    }
}

void CreateEnemy(Vector2 inicial,Vector2 final,int lifes, int phase)
{
    if ( counterEnemies == 13 ) return;

    enemies[counterEnemies].detect=0;
    enemies[counterEnemies].bodyLife = lifes;
    if(enemies[counterEnemies].bodyLife==2)enemies[counterEnemies].detect=2;
    else enemies[counterEnemies].detect=1;
    enemies[counterEnemies].bodyRec = (Rectangle){(inicial.x*50) + 1,(inicial.y*50),60,60};
    enemies[counterEnemies].gerated = true;
    enemies[counterEnemies].limits = (Vector2){inicial.x*50,final.x*50};
    enemies[counterEnemies].enemyState = strongRunning[0];
    enemies[counterEnemies].enemyAnimation = 0;
    enemies[counterEnemies].damageDuration = 0;       
    enemies[counterEnemies].currentPhase = phase;
    counterEnemies++;
}

void UpdateEnemy()
{
    UpdateEnemyState();
    for(int i = 0; i < 13; i++)
    {
        if(enemies[i].gerated == true && enemies[i].reverse == false)
        {
            if(enemies[i].damageDuration == 0) enemies[i].bodyRec.x += 3;
            if(enemies[i].bodyRec.x >= enemies[i].limits.y)
            {
                enemies[i].reverse = true;
            }
        }
        else if(enemies[i].gerated == true && enemies[i].reverse == true)
        {
            if(enemies[i].damageDuration == 0) enemies[i].bodyRec.x -= 3;
            if(enemies[i].bodyRec.x <= enemies[i].limits.x)
            {
                enemies[i].reverse = false;
            }
        }

        CheckEnemyAttacked(i);

        if(enemies[i].bodyLife <= 0)
        {
            enemies[i].attacked = true;
            if(enemies[i].enemyAnimation == 44) enemies[i].gerated = false;
        }

        //check_enemy_physics(i);
    }
}

void CheckEnemyAttacked(int i)
{
    Rectangle attack_area = CharacterAttack(&hero,hero.reverse);

    if (enemies[i].attacked == true && hero.attackCooldown == 0) enemies[i].attacked = false;
    
    if(hero.attacking == true && enemies[i].attacked == false)
    {
        if(hero.reverse == false)
        {
            //if Enemy is on CharacterAttack area
            if((enemies[i].bodyRec.x <= attack_area.x + attack_area.width && enemies[i].bodyRec.x + enemies[i].bodyRec.width >= attack_area.x + attack_area.width) && (enemies[i].bodyRec.y <= attack_area.y && enemies[i].bodyRec.y + enemies[i].bodyRec.height >= attack_area.y))
            {
                enemies[i].damageDuration=36;
                enemies[i].enemyAnimation=0;
                enemies[i].attacked = true;
                enemies[i].bodyLife--;
            }
        }
        else
        {
            //if Enemy is on CharacterAttack area
            if((enemies[i].bodyRec.x >= attack_area.x + attack_area.width && enemies[i].bodyRec.x + enemies[i].bodyRec.width <= attack_area.x + attack_area.width) && (enemies[i].bodyRec.y >= attack_area.y && enemies[i].bodyRec.y + enemies[i].bodyRec.height <= attack_area.y))
            {
                enemies[i].damageDuration=36;
                enemies[i].enemyAnimation=0;
                enemies[i].attacked = true;
                enemies[i].bodyLife--;
            }    
        }
    }
    
}

void DrawEnemy()
{
    for(int i = 0; i < 13; i++)
    {
        if(enemies[i].gerated == true)
        {
            if (enemies[i].reverse == false) DrawTextureRec(enemies[i].enemyState, (Rectangle){0,0, enemies[i].bodyRec.width, enemies[i].bodyRec.height}, (Vector2){enemies[i].bodyRec.x, enemies[i].bodyRec.y}, WHITE);
            else DrawTextureRec(enemies[i].enemyState, (Rectangle){0, 0, -1*enemies[i].bodyRec.width, enemies[i].bodyRec.height}, (Vector2){enemies[i].bodyRec.x, enemies[i].bodyRec.y}, WHITE);
        }
    }
}

void CreateEnemiesMap(int phase)
{
    if(phase == 1)
    {
        CreateEnemy((Vector2){16,7},(Vector2){25,7},1, 1);
        CreateEnemy((Vector2){41,6},(Vector2){44,6},2, 1);
        CreateEnemy((Vector2){60,6},(Vector2){64,6},2, 1);
        CreateEnemy((Vector2){75,5},(Vector2){78,5},1, 1);
    };
    if(phase == 2)
    {
        CreateEnemy((Vector2){10,6},(Vector2){15,6},1, 2);
        CreateEnemy((Vector2){22,5},(Vector2){24,5},1, 2);
        CreateEnemy((Vector2){30,3},(Vector2){32,3},2, 2);
        CreateEnemy((Vector2){48,4},(Vector2){50,4},1, 2);    
        CreateEnemy((Vector2){56,3},(Vector2){58,3},1, 2);
        CreateEnemy((Vector2){73,0},(Vector2){75,0},1, 2);
        CreateEnemy((Vector2){85,0},(Vector2){87,0},2, 2);     
        CreateEnemy((Vector2){93,1},(Vector2){95,1},1, 2);              
    };
    if(phase == 3)
    {
        CreateEnemy((Vector2){18,1},(Vector2){20,1},1, 3);  
    };
}

void UpdateEnemyState(){
    for(int i = 0; i < 13; i++){
        if(enemies[i].bodyLife == 0){

            int enemyDyingFrame = enemies[i].enemyAnimation /3;

            if(enemies[i].detect==2) enemies[i].enemyState = strongDying[enemyDyingFrame];
            else if(enemies[i].detect==1) enemies[i].enemyState = weakDying[enemyDyingFrame];

            if (enemies[i].enemyAnimation < 44) enemies[i].enemyAnimation++;

        } 

        else if (enemies[i].damageDuration != 0 && enemies[i].detect == 2) {

            int enemyHurtFrame = enemies[i].enemyAnimation /3;

            enemies[i].enemyState = strongHurt[enemyHurtFrame];
            enemies[i].damageDuration--;

            //enemies kick
            if(hero.physic->position.x > enemies[i].bodyRec.x) enemies[i].bodyRec.x -= 2;
            else { enemies[i].bodyRec.x += 2;}
            

            if (enemies[i].enemyAnimation < 35) enemies[i].enemyAnimation++;

        }
        else {

            int enemyRunningFrame = enemies[i].enemyAnimation /3;
            enemies[i].enemyState = strongRunning[enemyRunningFrame];

            if(enemies[i].detect==2) enemies[i].enemyState = strongRunning[enemyRunningFrame];
            else if (enemies[i].detect==1) enemies[i].enemyState = weakRunning[enemyRunningFrame];

            if (enemies[i].enemyAnimation < 35) enemies[i].enemyAnimation++;
            else if (enemies[i].enemyAnimation == 35) enemies[i].enemyAnimation = 0;

        }

    }

}
#endif