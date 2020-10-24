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
    int BodyLife;
    bool reverse;
    bool gerated;
    bool attaked;
} Enemy;

Enemy enemies[10];

void StartEnemyVariables();
void CreateEnemy(Vector2 inicial,Vector2 final,int lifes);
void UpdateEnemy();
//void check_enemy_physics(int i);
void CheckEnemyAttacked(int i);
void DrawEnemy();
void CreateEnemiesMap(int phase);



void StartEnemyVariables()
{
    for (int i = 0; i < 10; i++)
    {
        enemies[i].attaked = false;
        enemies[i].reverse = false;
        enemies[i].gerated = false;
    }
}

void CreateEnemy(Vector2 inicial,Vector2 final,int lifes)
{
    for(int i = 0; i < 10; i++)
    {
        if(enemies[i].gerated == false)
        {
            enemies->BodyLife = lifes;
            enemies[i].body_rec = (Rectangle){(inicial.x*50) + 1,(inicial.y*50),60,60};
            enemies[i].gerated = true;
            enemies[i].limits = (Vector2){inicial.x*50,final.x*50};
            enemies[i].enemyState = strongRunning[0];
            enemies[i].enemyAnimation = 0;
            enemies[i].damageDuration = 0;        
        }
    }
}

void UpdateEnemy()
{
    UpdateEnemyState();
    for(int i = 0; i < 10; i++)
    {
        if(enemies[i].gerated == true && enemies[i].reverse == false)
        {
            enemies[i].body_rec.x += 3;
            if(enemies[i].body_rec.x >= enemies[i].limits.y)
            {
                enemies[i].reverse = true;
            }
        }
        else if(enemies[i].gerated == true && enemies[i].reverse == true)
        {
            enemies[i].body_rec.x -= 3;
            if(enemies[i].body_rec.x <= enemies[i].limits.x)
            {
                enemies[i].reverse = false;
            }
        }

        CheckEnemyAttacked(i);

        if(enemies[i].BodyLife <= 0)
        {
            enemies[i].gerated = false;
        }

        //check_enemy_physics(i);
    }
}

void CheckEnemyAttacked(int i)
{
    Rectangle attack_area = CharacterAttack(&hero,hero.reverse);

    if (enemies[i].attaked == true && hero.attackCooldown == 0) enemies[i].attaked = false;
    
    if(hero.attacking == true && enemies[i].attaked == false)
    {
        enemies[i].damageDuration=36;
        enemies[i].enemyAnimation=0;
        if(hero.reverse == false)
        {
            //if Enemy is on CharacterAttack area
            if((enemies[i].body_rec.x <= attack_area.x + attack_area.width && enemies[i].body_rec.x + enemies[i].body_rec.width >= attack_area.x + attack_area.width) && (enemies[i].body_rec.y <= attack_area.y && enemies[i].body_rec.y + enemies[i].body_rec.height >= attack_area.y))
            {
                enemies[i].attaked = true;
                enemies[i].BodyLife--;
            }
        }
        else
        {
            //if Enemy is on CharacterAttack area
            if((enemies[i].body_rec.x >= attack_area.x + attack_area.width && enemies[i].body_rec.x + enemies[i].body_rec.width <= attack_area.x + attack_area.width) && (enemies[i].body_rec.y >= attack_area.y && enemies[i].body_rec.y + enemies[i].body_rec.height <= attack_area.y))
            {
                enemies[i].attaked = true;
                enemies[i].BodyLife--;
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
            DrawTextureRec(enemies[i].enemyState, enemies[i].body_rec, (Vector2){enemies[i].body_rec.x, enemies[i].body_rec.y}, WHITE);

        }
    }
}

void CreateEnemiesMap(int phase)
{
    if(phase == 1)
    {
        CreateEnemy((Vector2){20,7},(Vector2){25,7} ,2);
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

        if(enemies[i].BodyLife == 0){
            int enemyDyingFrame = enemies[i].enemyAnimation /3;

            enemies[i].enemyState = strongDying[enemyDyingFrame];

            if (enemies[i].enemyAnimation < 44) enemies[i].enemyAnimation++;
        } else if (enemies[i].damageDuration != 0) {
            int enemyHurtFrame = enemies[i].enemyAnimation /3;

            enemies[i].enemyState = strongHurt[enemyHurtFrame];
            enemies[i].damageDuration--;
            if (enemies[i].enemyAnimation < 35) enemies[i].enemyAnimation++;
        } else {

            int enemyRunningFrame = enemies[i].enemyAnimation /3;

            enemies[i].enemyState = strongRunning[enemyRunningFrame];

            if (enemies[i].enemyAnimation < 44) enemies[i].enemyAnimation++;
            else if (enemies[i].enemyAnimation = 44) enemies[i].enemyAnimation = 0;
        }

    }
    


}
#endif