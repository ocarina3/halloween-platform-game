#ifndef GET_MAP_H
#define GET_MAP_H


#include "raylib.h"
#ifndef PHYSAC_H
#define PHYSAC_IMPLEMENTATION
#define PHYSAC_NO_THREADS


#include "physac.h"
#endif

#define buildings_width         50
#define buildings_height        50

//___________________________________STRUCTS_______________________________________________

typedef struct
{
    Rectangle block;
    bool draw;
    int sprite;
    PhysicsBody physics_block;
    bool physics;
    bool physics_created;
    bool object;
}blocks;


//_________________________________________________________________________________________

//___________________________________VARIABLES_______________________________________________

blocks buildings[320][14];

//____________________________________________________________________________________________

//___________________________________FUNCTIONS DECLARATIONS____________________________________

void create_line(Vector2 inicial, Vector2 final, int sprite);
void create_map(int phase);
void create_floor(int phase);
void create_objects(int phase);
void create_plataforms(int pos_x, int pos_y);

//____________________________________________________________________________________________


//___________________________________FUNCTIONS_______________________________________________

//creates a map line and divides it into blocks
void create_line(Vector2 inicial, Vector2 final, int sprite)
{
    //takes the final and initial coordinates of the line
    Vector2 num_blocks = {((final.x - inicial.x)+ 1),((final.y - inicial.y) + 1)};
    int  physics_sprites[9] = {1,2,3,7,6,11,14,15,16};
    //create the blocks
    for (int i = 0; i < (int)num_blocks.x; i++)
    {
        for(int j = 0; j < (int)num_blocks.y; j++)
        {
            buildings[(int)inicial.x + i][(int)inicial.y + j].draw = true;
            buildings[(int)inicial.x + i][(int)inicial.y + j].sprite = sprite;
            
            for(int k = 0; k < 9; k++)
            {
                if(physics_sprites[k] == sprite)
                {
                    buildings[(int)inicial.x + i][(int)inicial.y + j].physics = true;
                }
            }
        }
    }
}

//create the lines of the map
void create_map(int phase)
{
    if(phase == 1)
    {
        create_floor(1);
        create_objects(1);
             
    }
    else if(phase == 2)
    {
        create_floor(2);
        create_plataforms(18,7);
        create_plataforms(22,6);
        create_plataforms(26,5);
        create_plataforms(30,4);
        create_plataforms(35,4);
        create_plataforms(39,4);
        create_plataforms(44,4);
        create_plataforms(48,5);
        create_plataforms(53,6);
        create_plataforms(57,4);
        create_plataforms(62,3);
        create_plataforms(66,2);
        create_plataforms(71,3);
        create_plataforms(75,0);
        create_plataforms(80,0);
        create_plataforms(85,1);
        create_plataforms(89,2);
        create_plataforms(93,2);
        create_plataforms(98,2);
    }
    else if(phase == 3)
    {
        create_floor(3);
                
    }
    
}

void create_floor(int phase)
{
    if(phase == 1)
    {
        // Primeira linha
        create_line((Vector2){0,7}, (Vector2){0,7}, 1);
        create_line((Vector2){1,7}, (Vector2){14,7}, 2);
        create_line((Vector2){15,7}, (Vector2){15,7}, 3);
            
        // Terra embaixo da primeira
        create_line((Vector2){0,8}, (Vector2){0,10}, 4);
        create_line((Vector2){1,8}, (Vector2){15,10}, 5);
        create_line((Vector2){15,8}, (Vector2){15,8}, 10);
        
        // Segunda Linha
        create_line((Vector2){16,8}, (Vector2){16,8}, 11);
        create_line((Vector2){17,8}, (Vector2){24,8}, 2);
        create_line((Vector2){25,8}, (Vector2){25,8}, 7);
        // Terra embaixo da segunda
        create_line((Vector2){16,9}, (Vector2){25,10}, 5);
        
        // Terceira linha
        create_line((Vector2){26,7}, (Vector2){26,7}, 1);
        create_line((Vector2){27,7}, (Vector2){29,7}, 2);
        create_line((Vector2){30,7}, (Vector2){30,7}, 7);
        
        // Terra embaixo da terceira
        create_line((Vector2){26,8}, (Vector2){26,8}, 8);
        create_line((Vector2){26,9}, (Vector2){26,10}, 5);
        create_line((Vector2){27,8}, (Vector2){30,10}, 5);
        
        //Quarta linha
        create_line((Vector2){31,6}, (Vector2){31,6}, 1);
        create_line((Vector2){32,6}, (Vector2){35,6}, 2);

        //Terra embaixo da quarta
        create_line((Vector2){31,7}, (Vector2){31,7}, 8);
        create_line((Vector2){31,8}, (Vector2){31,10}, 5);
        create_line((Vector2){32,7}, (Vector2){35,10}, 5);

        //Quinta linha
        create_line((Vector2){36,5}, (Vector2){36,5}, 1);
        create_line((Vector2){37,5}, (Vector2){38,5}, 2);

        //Terra embaixo da quinta
        create_line((Vector2){36,6}, (Vector2){36,6}, 8);
        create_line((Vector2){36,7}, (Vector2){36,10}, 5);
        create_line((Vector2){37,6}, (Vector2){38,10}, 5);

        //Sexta linha
        create_line((Vector2){39,4}, (Vector2){39,4}, 1);
        create_line((Vector2){40,4}, (Vector2){40,4}, 3);

        //Terra embaixo da sexta
        create_line((Vector2){39,5}, (Vector2){39,5}, 8);
        create_line((Vector2){39,6}, (Vector2){39,10}, 5);
        create_line((Vector2){40,5}, (Vector2){40,6}, 6);
        create_line((Vector2){40,7}, (Vector2){40,7}, 10);
        create_line((Vector2){40,8}, (Vector2){40,10}, 5);

        //Setima linha
        create_line((Vector2){41,7}, (Vector2){41,7}, 11);
        create_line((Vector2){42,7}, (Vector2){44,7}, 2);

        //Terra embaixo da setima linha
        create_line((Vector2){41,8}, (Vector2){44,10}, 5);

        //Oitava linha
        create_line((Vector2){45,6}, (Vector2){45,6}, 1);
        create_line((Vector2){46,6}, (Vector2){49,6}, 2);
        create_line((Vector2){50,6}, (Vector2){50,6}, 3);

        //Terra embaixo da oitava linha
        create_line((Vector2){45,7}, (Vector2){45,7}, 8);
        create_line((Vector2){46,7}, (Vector2){49,10}, 5);
        create_line((Vector2){45,8}, (Vector2){45,10}, 5);
        create_line((Vector2){50,7}, (Vector2){50,7}, 10);
        create_line((Vector2){50,8}, (Vector2){50,10}, 5);

        //Nona linha
        create_line((Vector2){51,7}, (Vector2){51,7}, 2);
        create_line((Vector2){52,7}, (Vector2){52,7}, 3);

        //Terra emabixo da nona linha
        create_line((Vector2){51,8}, (Vector2){51,10}, 5);
        create_line((Vector2){52,8}, (Vector2){52,9}, 6);
        create_line((Vector2){52,10}, (Vector2){52,10}, 5);

        create_plataforms(55,6);
        
        //Decima linha 
        create_line((Vector2){60,7}, (Vector2){60,7}, 1);
        create_line((Vector2){61,7}, (Vector2){64,7}, 2);

        //Terra embaixo da decima linha
        create_line((Vector2){60,8}, (Vector2){60,8}, 4);
        create_line((Vector2){61,8}, (Vector2){64,10}, 5);
        create_line((Vector2){60,9}, (Vector2){60,10}, 5);

        //Decima primeira linha
        create_line((Vector2){65,6}, (Vector2){65,6}, 1);
        create_line((Vector2){66,6}, (Vector2){66,6}, 2);
        create_line((Vector2){67,6}, (Vector2){67,6}, 3);
    
        //Terra embaixo da decima primeira
        create_line((Vector2){65,7}, (Vector2){65,7}, 8);
        create_line((Vector2){65,8}, (Vector2){65,9}, 5);
        create_line((Vector2){66,7}, (Vector2){66,9}, 5);
        create_line((Vector2){67,7}, (Vector2){67,9}, 6);

        create_plataforms(70,4);

       //Decima segunda Linha
        create_line((Vector2){75,6}, (Vector2){75,6}, 1);
        create_line((Vector2){76,6}, (Vector2){77,6}, 2);
        create_line((Vector2){78,6}, (Vector2){78,6}, 3);
        
        //Terra embaixo da decima segunda linha
        create_line((Vector2){75,7}, (Vector2){75,9}, 4);
        create_line((Vector2){76,7}, (Vector2){77,9}, 5);
        create_line((Vector2){78,7}, (Vector2){78,9}, 6);

        //Decima terceira Linha
        create_line((Vector2){81,7}, (Vector2){81,7}, 1);
        create_line((Vector2){82,7}, (Vector2){83,7}, 2);
        
        //Terra embaixo da decima terceira linha
        create_line((Vector2){81,8}, (Vector2){81,9}, 4);
        create_line((Vector2){82,8}, (Vector2){83,9}, 5);

        //Decima quarta linha
        create_line((Vector2){84,6}, (Vector2){84,6}, 1);
        create_line((Vector2){85,6}, (Vector2){100,6}, 2);
        create_line((Vector2){101,6}, (Vector2){101,6}, 3);

        //Terra embaixo da decima quarta linha
        create_line((Vector2){84,7}, (Vector2){84,7}, 8);
        create_line((Vector2){84,8}, (Vector2){84,9}, 5);
        create_line((Vector2){85,7}, (Vector2){100,9}, 5);
        create_line((Vector2){101,7}, (Vector2){101,9}, 6);
    } 
    else if (phase == 2)
    {
        // Primeira linha
        create_line((Vector2){0,7}, (Vector2){0,7}, 1);
        create_line((Vector2){1,7}, (Vector2){14,7}, 2);
        create_line((Vector2){15,7}, (Vector2){15,7}, 3);
            
        // Terra embaixo da primeira
        create_line((Vector2){0,8}, (Vector2){0,10}, 4);
        create_line((Vector2){1,8}, (Vector2){15,10}, 5);
        create_line((Vector2){15,8}, (Vector2){15,8}, 10);

        create_line((Vector2){103,2}, (Vector2){103,2}, 1);
        create_line((Vector2){104,2}, (Vector2){117,2}, 2);
        create_line((Vector2){118,2}, (Vector2){118,2}, 3);
            
        // Terra embaixo da primeira
        create_line((Vector2){103,3}, (Vector2){103,10}, 4);
        create_line((Vector2){104,3}, (Vector2){117,10}, 5);
        create_line((Vector2){118,3}, (Vector2){118,10}, 6);

    }
    else if (phase == 3)
    {
        // Primeira linha
        create_line((Vector2){0,7}, (Vector2){0,7}, 1);
        create_line((Vector2){1,7}, (Vector2){14,7}, 2);
        create_line((Vector2){15,7}, (Vector2){15,7}, 3);
            
        // Terra embaixo da primeira
        create_line((Vector2){0,8}, (Vector2){0,10}, 4);
        create_line((Vector2){1,8}, (Vector2){15,10}, 5);
        create_line((Vector2){15,8}, (Vector2){15,8}, 10);

        create_plataforms(18,6);

        // Terra flutuante
        create_line((Vector2){23,6}, (Vector2){23,6}, 1);
        create_line((Vector2){24,6}, (Vector2){37,6}, 2);
        create_line((Vector2){38,6}, (Vector2){38,6}, 3);

        // Terra embaixo
        create_line((Vector2){23,7}, (Vector2){23,7}, 12);
        create_line((Vector2){24,7}, (Vector2){37,7}, 9);
        create_line((Vector2){38,7}, (Vector2){38,7}, 13);

        // Esquerda
        create_plataforms(24, 4);

        // Meio
        create_plataforms(29, 2);

        // Direita
        create_plataforms(35, 4);

    }   
}

void create_objects(int phase)
{
    if(phase == 1)
    {
        create_line((Vector2){12, 6}, (Vector2){12, 6}, 17); 
        buildings[12][6].object = true;
    }
    else if(phase == 2)
    {

    }
    else if (phase == 3)
    {

    }
}

void create_plataforms(int pos_x, int pos_y)
{
    for(int i = 0; i < 3; i++)
    {
        create_line((Vector2){pos_x + i,pos_y}, (Vector2){pos_x + i,pos_y}, 14 + i);
    }
}



//___________________________________________________________________________________________
#endif