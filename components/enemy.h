#ifndef ENEMY_H
#define ENEMY_H

#include "get_map.h"
#include "main_character.h"

typedef struct 
{
    Rectangle body_rec;
    Vector2 limits;
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
            enemies[i].body_rec = (Rectangle){(inicial.x*50) + 1,(inicial.y*50),50,50};
            enemies[i].gerated = true;
            enemies[i].limits = (Vector2){inicial.x*50,final.x*50};
        }
    }
}

void UpdateEnemy()
{
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
            DrawRectangleRec(enemies[i].body_rec,BLUE);
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

#endif