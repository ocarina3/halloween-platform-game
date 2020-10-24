#ifndef ENEMY_H
#define ENEMY_H

#include "get_map.h"
#include "main_character.h"
#include "../resources/enemy_textures.h"

typedef struct 
{
    Rectangle body_rec;
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

Enemy enemies[10];
int counterEnemies = 0;

void StartEnemyVariables();
void CreateEnemy(Vector2 inicial,Vector2 final,int lifes, int phase);
void UpdateEnemy();
//void check_enemy_physics(int i);
void CheckEnemyAttacked(int i);
void DrawEnemy();
void CreateEnemiesMap(int phase);



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
    if ( counterEnemies == 10 ) return;

    enemies[counterEnemies].detect=0;
    enemies[counterEnemies].bodyLife = lifes;
    if(enemies[counterEnemies].bodyLife==2)enemies[counterEnemies].detect=2;
    else enemies[counterEnemies].detect=1;
    enemies[counterEnemies].body_rec = (Rectangle){(inicial.x*50) + 1,(inicial.y*50),60,60};
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
    for(int i = 0; i < 10; i++)
    {
        if(enemies[i].gerated == true && enemies[i].reverse == false)
        {
            if(enemies[i].damageDuration == 0) enemies[i].body_rec.x += 3;
            if(enemies[i].body_rec.x >= enemies[i].limits.y)
            {
                enemies[i].reverse = true;
            }
        }
        else if(enemies[i].gerated == true && enemies[i].reverse == true)
        {
            if(enemies[i].damageDuration == 0) enemies[i].body_rec.x -= 3;
            if(enemies[i].body_rec.x <= enemies[i].limits.x)
            {
                enemies[i].reverse = false;
            }
        }

        CheckEnemyAttacked(i);

        if(enemies[i].bodyLife <= 0)
        {
            if(enemies[i].enemyAnimation==44) enemies[i].gerated = false;
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
            if((enemies[i].body_rec.x <= attack_area.x + attack_area.width && enemies[i].body_rec.x + enemies[i].body_rec.width >= attack_area.x + attack_area.width) && (enemies[i].body_rec.y <= attack_area.y && enemies[i].body_rec.y + enemies[i].body_rec.height >= attack_area.y))
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
            if((enemies[i].body_rec.x >= attack_area.x + attack_area.width && enemies[i].body_rec.x + enemies[i].body_rec.width <= attack_area.x + attack_area.width) && (enemies[i].body_rec.y >= attack_area.y && enemies[i].body_rec.y + enemies[i].body_rec.height <= attack_area.y))
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
    for(int i = 0; i < 10; i++)
    {
        if(enemies[i].gerated == true)
        {
            if (enemies[i].reverse == false) DrawTextureRec(enemies[i].enemyState, (Rectangle){0,0, enemies[i].body_rec.width, enemies[i].body_rec.height}, (Vector2){enemies[i].body_rec.x, enemies[i].body_rec.y}, WHITE);
            else DrawTextureRec(enemies[i].enemyState, (Rectangle){0, 0, -1*enemies[i].body_rec.width, enemies[i].body_rec.height}, (Vector2){enemies[i].body_rec.x, enemies[i].body_rec.y}, WHITE);
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

    };
    if(phase == 3)
    {

    };
}

void UpdateEnemyState(){
    for(int i = 0; i < 10; i++){
        if(enemies[i].bodyLife == 0){

            int enemyDyingFrame = enemies[i].enemyAnimation /3;

            if(enemies[i].detect==2) enemies[i].enemyState = strongDying[enemyDyingFrame];
            else enemies[i].enemyState = weakDying[enemyDyingFrame];

            enemies[i].enemyState = strongDying[enemyDyingFrame];
            if (enemies[i].enemyAnimation < 44) enemies[i].enemyAnimation++;

        } 

        else if (enemies[i].damageDuration != 0) {

            int enemyHurtFrame = enemies[i].enemyAnimation /3;

            enemies[i].enemyState = strongHurt[enemyHurtFrame];
            enemies[i].damageDuration--;

            if (enemies[i].enemyAnimation < 35) enemies[i].enemyAnimation++;

        }
        else {

            int enemyRunningFrame = enemies[i].enemyAnimation /3;
            enemies[i].enemyState = strongRunning[enemyRunningFrame];

            if(enemies[i].detect==2) enemies[i].enemyState = strongRunning[enemyRunningFrame];
            else enemies[i].enemyState = weakRunning[enemyRunningFrame];

            if (enemies[i].enemyAnimation < 35) enemies[i].enemyAnimation++;
            else if (enemies[i].enemyAnimation == 35) enemies[i].enemyAnimation = 0;

        }

    }

}
#endif