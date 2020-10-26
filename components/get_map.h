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
    PhysicsBody physicsBlock;
    bool physics;
    bool physicsCreated;
}blocks;


//_________________________________________________________________________________________

//___________________________________VARIABLES_______________________________________________

blocks buildings[320][14];

//____________________________________________________________________________________________

//___________________________________FUNCTIONS DECLARATIONS____________________________________

void CreateLine(Vector2 inicial, Vector2 final, int sprite);
void CreateMap(int phase);
void CreateFloor(int phase);
void CreateObjects(int phase);
void CreatePlatforms(int pos_x, int pos_y);

//____________________________________________________________________________________________


//___________________________________FUNCTIONS_______________________________________________

//creates a map line and divides it into blocks
void CreateLine(Vector2 inicial, Vector2 final, int sprite)
{
    //takes the final and Initial coordinates of the line
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
void CreateMap(int phase)
{
    if(phase == 1)
    {
        CreateFloor(1);
        CreateObjects(1);
             
    }
    else if(phase == 2)
    {
        CreateFloor(2);
        CreatePlatforms(18,7);
        CreatePlatforms(22,6);
        CreatePlatforms(26,5);
        CreatePlatforms(30,4);
        CreatePlatforms(35,4);
        CreatePlatforms(39,4);
        CreatePlatforms(44,4);
        CreatePlatforms(48,5);
        CreatePlatforms(53,6);
        CreatePlatforms(57,4);
        CreatePlatforms(62,3);
        CreatePlatforms(66,2);
        CreatePlatforms(71,3);
        CreatePlatforms(75,1);
        CreatePlatforms(80,0);
        CreatePlatforms(85,1);
        CreatePlatforms(89,2);
        CreatePlatforms(93,2);
        CreatePlatforms(98,2);
    }
    else if(phase == 3)
    {
        CreateFloor(3);
                
    }
    
}

void CreateFloor(int phase)
{
    if(phase == 1)
    {
        // Primeira linha
        CreateLine((Vector2){0,7}, (Vector2){0,7}, 1);
        CreateLine((Vector2){1,7}, (Vector2){14,7}, 2);
        CreateLine((Vector2){15,7}, (Vector2){15,7}, 3);
            
        // Terra embaixo da primeira
        CreateLine((Vector2){0,8}, (Vector2){0,10}, 4);
        CreateLine((Vector2){1,8}, (Vector2){15,10}, 5);
        CreateLine((Vector2){15,8}, (Vector2){15,8}, 10);
        
        // Segunda Linha
        CreateLine((Vector2){16,8}, (Vector2){16,8}, 11);
        CreateLine((Vector2){17,8}, (Vector2){24,8}, 2);
        CreateLine((Vector2){25,8}, (Vector2){25,8}, 7);
        // Terra embaixo da segunda
        CreateLine((Vector2){16,9}, (Vector2){25,10}, 5);
        
        // Terceira linha
        CreateLine((Vector2){26,7}, (Vector2){26,7}, 1);
        CreateLine((Vector2){27,7}, (Vector2){29,7}, 2);
        CreateLine((Vector2){30,7}, (Vector2){30,7}, 7);
        
        // Terra embaixo da terceira
        CreateLine((Vector2){26,8}, (Vector2){26,8}, 8);
        CreateLine((Vector2){26,9}, (Vector2){26,10}, 5);
        CreateLine((Vector2){27,8}, (Vector2){30,10}, 5);
        
        //Quarta linha
        CreateLine((Vector2){31,6}, (Vector2){31,6}, 1);
        CreateLine((Vector2){32,6}, (Vector2){35,6}, 2);

        //Terra embaixo da quarta
        CreateLine((Vector2){31,7}, (Vector2){31,7}, 8);
        CreateLine((Vector2){31,8}, (Vector2){31,10}, 5);
        CreateLine((Vector2){32,7}, (Vector2){35,10}, 5);

        //Quinta linha
        CreateLine((Vector2){36,5}, (Vector2){36,5}, 1);
        CreateLine((Vector2){37,5}, (Vector2){38,5}, 2);

        //Terra embaixo da quinta
        CreateLine((Vector2){36,6}, (Vector2){36,6}, 8);
        CreateLine((Vector2){36,7}, (Vector2){36,10}, 5);
        CreateLine((Vector2){37,6}, (Vector2){38,10}, 5);

        //Sexta linha
        CreateLine((Vector2){39,4}, (Vector2){39,4}, 1);
        CreateLine((Vector2){40,4}, (Vector2){40,4}, 3);

        //Terra embaixo da sexta
        CreateLine((Vector2){39,5}, (Vector2){39,5}, 8);
        CreateLine((Vector2){39,6}, (Vector2){39,10}, 5);
        CreateLine((Vector2){40,5}, (Vector2){40,6}, 6);
        CreateLine((Vector2){40,7}, (Vector2){40,7}, 10);
        CreateLine((Vector2){40,8}, (Vector2){40,10}, 5);

        //Setima linha
        CreateLine((Vector2){41,7}, (Vector2){41,7}, 11);
        CreateLine((Vector2){42,7}, (Vector2){44,7}, 2);

        //Terra embaixo da setima linha
        CreateLine((Vector2){41,8}, (Vector2){44,10}, 5);

        //Oitava linha
        CreateLine((Vector2){45,6}, (Vector2){45,6}, 1);
        CreateLine((Vector2){46,6}, (Vector2){49,6}, 2);
        CreateLine((Vector2){50,6}, (Vector2){50,6}, 3);

        //Terra embaixo da oitava linha
        CreateLine((Vector2){45,7}, (Vector2){45,7}, 8);
        CreateLine((Vector2){46,7}, (Vector2){49,10}, 5);
        CreateLine((Vector2){45,8}, (Vector2){45,10}, 5);
        CreateLine((Vector2){50,7}, (Vector2){50,7}, 10);
        CreateLine((Vector2){50,8}, (Vector2){50,10}, 5);

        //Nona linha
        CreateLine((Vector2){51,7}, (Vector2){51,7}, 2);
        CreateLine((Vector2){52,7}, (Vector2){52,7}, 3);

        //Terra emabixo da nona linha
        CreateLine((Vector2){51,8}, (Vector2){51,10}, 5);
        CreateLine((Vector2){52,8}, (Vector2){52,9}, 6);
        CreateLine((Vector2){52,10}, (Vector2){52,10}, 5);

        CreatePlatforms(55,6);
        
        //Decima linha 
        CreateLine((Vector2){60,7}, (Vector2){60,7}, 1);
        CreateLine((Vector2){61,7}, (Vector2){64,7}, 2);

        //Terra embaixo da decima linha
        CreateLine((Vector2){60,8}, (Vector2){60,8}, 4);
        CreateLine((Vector2){61,8}, (Vector2){64,10}, 5);
        CreateLine((Vector2){60,9}, (Vector2){60,10}, 5);

        //Decima primeira linha
        CreateLine((Vector2){65,6}, (Vector2){65,6}, 1);
        CreateLine((Vector2){66,6}, (Vector2){66,6}, 2);
        CreateLine((Vector2){67,6}, (Vector2){67,6}, 3);
    
        //Terra embaixo da decima primeira
        CreateLine((Vector2){65,7}, (Vector2){65,7}, 8);
        CreateLine((Vector2){65,8}, (Vector2){65,9}, 5);
        CreateLine((Vector2){66,7}, (Vector2){66,9}, 5);
        CreateLine((Vector2){67,7}, (Vector2){67,9}, 6);

        CreatePlatforms(70,4);

       //Decima segunda Linha
        CreateLine((Vector2){75,6}, (Vector2){75,6}, 1);
        CreateLine((Vector2){76,6}, (Vector2){77,6}, 2);
        CreateLine((Vector2){78,6}, (Vector2){78,6}, 3);
        
        //Terra embaixo da decima segunda linha
        CreateLine((Vector2){75,7}, (Vector2){75,9}, 4);
        CreateLine((Vector2){76,7}, (Vector2){77,9}, 5);
        CreateLine((Vector2){78,7}, (Vector2){78,9}, 6);

        //Decima terceira Linha
        CreateLine((Vector2){81,7}, (Vector2){81,7}, 1);
        CreateLine((Vector2){82,7}, (Vector2){83,7}, 2);
        
        //Terra embaixo da decima terceira linha
        CreateLine((Vector2){81,8}, (Vector2){81,9}, 4);
        CreateLine((Vector2){82,8}, (Vector2){83,9}, 5);

        //Decima quarta linha
        CreateLine((Vector2){84,6}, (Vector2){84,6}, 1);
        CreateLine((Vector2){85,6}, (Vector2){100,6}, 2);
        CreateLine((Vector2){101,6}, (Vector2){101,6}, 3);

        //Terra embaixo da decima quarta linha
        CreateLine((Vector2){84,7}, (Vector2){84,7}, 8);
        CreateLine((Vector2){84,8}, (Vector2){84,9}, 5);
        CreateLine((Vector2){85,7}, (Vector2){100,9}, 5);
        CreateLine((Vector2){101,7}, (Vector2){101,9}, 6);
    } 
    else if (phase == 2)
    {
        // Primeira linha
        CreateLine((Vector2){0,7}, (Vector2){0,7}, 1);
        CreateLine((Vector2){1,7}, (Vector2){14,7}, 2);
        CreateLine((Vector2){15,7}, (Vector2){15,7}, 3);
            
        // Terra embaixo da primeira
        CreateLine((Vector2){0,8}, (Vector2){0,10}, 4);
        CreateLine((Vector2){1,8}, (Vector2){15,10}, 5);
        CreateLine((Vector2){15,8}, (Vector2){15,8}, 10);

        CreateLine((Vector2){103,2}, (Vector2){103,2}, 1);
        CreateLine((Vector2){104,2}, (Vector2){117,2}, 2);
        CreateLine((Vector2){118,2}, (Vector2){118,2}, 3);
            
        // Terra embaixo da primeira
        CreateLine((Vector2){103,3}, (Vector2){103,10}, 4);
        CreateLine((Vector2){104,3}, (Vector2){117,10}, 5);
        CreateLine((Vector2){118,3}, (Vector2){118,10}, 6);

    }
    else if (phase == 3)
    {
        // Primeira linha
        CreateLine((Vector2){0,7}, (Vector2){0,7}, 1);
        CreateLine((Vector2){1,7}, (Vector2){14,7}, 2);
        CreateLine((Vector2){15,7}, (Vector2){15,7}, 3);
            
        // Terra embaixo da primeira
        CreateLine((Vector2){0,8}, (Vector2){0,10}, 4);
        CreateLine((Vector2){1,8}, (Vector2){15,10}, 5);
        CreateLine((Vector2){15,8}, (Vector2){15,8}, 10);

        CreatePlatforms(18,6);

        // Terra flutuante
        CreateLine((Vector2){23,6}, (Vector2){23,6}, 1);
        CreateLine((Vector2){24,6}, (Vector2){37,6}, 2);
        CreateLine((Vector2){38,6}, (Vector2){38,6}, 3);

        // Terra embaixo
        CreateLine((Vector2){23,7}, (Vector2){23,7}, 12);
        CreateLine((Vector2){24,7}, (Vector2){37,7}, 9);
        CreateLine((Vector2){38,7}, (Vector2){38,7}, 13);

        // Esquerda
        CreatePlatforms(24, 4);

        // Meio
        CreatePlatforms(29, 2);

        // Direita
        CreatePlatforms(35, 4);

        CreatePlatforms(41,6);

        // Terra flutuante
        CreateLine((Vector2){46,6}, (Vector2){46,6}, 1);
        CreateLine((Vector2){47,6}, (Vector2){51,6}, 2);
        CreateLine((Vector2){52,6}, (Vector2){52,6}, 3);

        // Terra embaixo
        CreateLine((Vector2){46,7}, (Vector2){46,7}, 12);
        CreateLine((Vector2){47,7}, (Vector2){51,7}, 9);
        CreateLine((Vector2){52,7}, (Vector2){52,7}, 13);

    }   
}

void CreateObjects(int phase)
{
    if(phase == 1)
    {
        // Placa: comandos
        CreateLine((Vector2){12, 6}, (Vector2){12, 6}, 17); 
        CreateLine((Vector2){19, 7}, (Vector2){19, 7}, 18); 
        CreateLine((Vector2){30, 2}, (Vector2){30, 2}, 25); 
        // Placa: 2 vidas
        CreateLine((Vector2){39, 3}, (Vector2){39, 3}, 21); 
        CreateLine((Vector2){47, 5}, (Vector2){47, 5}, 23); 
        // Placa: plataforma
        CreateLine((Vector2){50, 5}, (Vector2){50, 5}, 21); 
        CreateLine((Vector2){62, 6}, (Vector2){62, 6}, 20); 
        CreateLine((Vector2){66, 5}, (Vector2){66, 5}, 24); 
        CreateLine((Vector2){76, 5}, (Vector2){76, 5}, 19); 
        // Placa: correr na próxima fase
        CreateLine((Vector2){88, 5}, (Vector2){88, 5}, 21); 

    }
    else if(phase == 2)
    {

    }
    else if (phase == 3)
    {
        CreateLine((Vector2){12, 6}, (Vector2){12, 6}, 21);
        CreateLine((Vector2){49, 5}, (Vector2){49, 5}, 21);
    }
}

void CreatePlatforms(int pos_x, int pos_y)
{
    for(int i = 0; i < 3; i++)
    {
        CreateLine((Vector2){pos_x + i,pos_y}, (Vector2){pos_x + i,pos_y}, 14 + i);
    }
}



//___________________________________________________________________________________________
#endif