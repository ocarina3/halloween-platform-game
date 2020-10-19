#ifndef GET_MAP_H
#define GET_MAP_H


#include "raylib.h"

#define buildings_width         50
#define buildings_height        50

//___________________________________STRUCTS_______________________________________________

typedef struct
{
    Rectangle block;
    bool draw;
    int sprite;
}blocks;

//_________________________________________________________________________________________

//___________________________________VARIABLES_______________________________________________

blocks buildings[320][14];

//____________________________________________________________________________________________

//___________________________________FUNCTIONS_______________________________________________

//creates a map line and divides it into blocks
void create_line(Vector2 inicial, Vector2 final, int sprite)
{
    //takes the final and initial coordinates of the line
    Vector2 num_blocks = {((final.x - inicial.x)+ 1),((final.y - inicial.y) + 1)};
    
    //create the blocks
    for (int i = 0; i < (int)num_blocks.x; i++)
    {
        for(int j = 0; j < (int)num_blocks.y; j++)
        {
            buildings[(int)inicial.x + i][(int)inicial.y + j].draw = true;
            buildings[(int)inicial.x + i][(int)inicial.y + j].sprite = sprite;
        }
    }
}

//create the lines of the map
void create_map()
{

    // Primeira linha
    create_line((Vector2){0,7}, (Vector2){0,7}, 1);
    create_line((Vector2){1,7}, (Vector2){14,7}, 2);
    create_line((Vector2){15,7}, (Vector2){15,7}, 3);
        
    // Terra embaixo da primeira linha
    // Esquerda
    create_line((Vector2){0,8}, (Vector2){0,10}, 4);
    // Meio 
    create_line((Vector2){1,8}, (Vector2){15,10}, 5);
    // Dobra
    create_line((Vector2){15,8}, (Vector2){15,8}, 10);
    
    // Segunda Linha
    create_line((Vector2){16,8}, (Vector2){16,8}, 11);
    create_line((Vector2){17,8}, (Vector2){24,8}, 2);
    create_line((Vector2){25,8}, (Vector2){25,8}, 7);
    // Terra emvbaixo do segundo (meio)
    create_line((Vector2){16,9}, (Vector2){25,10}, 5);
    
    // Terceira linha
    create_line((Vector2){26,7}, (Vector2){26,7}, 1);
    create_line((Vector2){27,7}, (Vector2){29,7}, 2);
    create_line((Vector2){30,7}, (Vector2){30,7}, 7);
    
    // Terra embaixo
    create_line((Vector2){26,8}, (Vector2){26,8}, 8);
    create_line((Vector2){26,9}, (Vector2){26,10}, 5);
    create_line((Vector2){27,8}, (Vector2){30,10}, 5);
    
    //  
    create_line((Vector2){31,6}, (Vector2){35,6}, 2);
    create_line((Vector2){36,5}, (Vector2){38,5}, 2);
    create_line((Vector2){39,4}, (Vector2){40,4}, 2);
    create_line((Vector2){41,7}, (Vector2){44,7}, 2);
    create_line((Vector2){45,6}, (Vector2){50,6}, 2);
    create_line((Vector2){51,7}, (Vector2){52,7}, 2);
    // Plataforma
    create_line((Vector2){55,6}, (Vector2){55,6}, 14);
    create_line((Vector2){56,6}, (Vector2){56,6}, 15);
    create_line((Vector2){57,6}, (Vector2){57,6}, 16);
    // 
    create_line((Vector2){60,7}, (Vector2){64,7}, 2);
    create_line((Vector2){65,6}, (Vector2){67,6}, 2);
    // Plataforma
    create_line((Vector2){70,4}, (Vector2){70,4}, 14);
    create_line((Vector2){71,4}, (Vector2){71,4}, 15);
    create_line((Vector2){72,4}, (Vector2){72,4}, 16);
    // Linha
    create_line((Vector2){75,6}, (Vector2){78,6}, 2);
    create_line((Vector2){81,7}, (Vector2){83,7}, 2);
    create_line((Vector2){84,6}, (Vector2){96,6}, 2);
}

//___________________________________________________________________________________________
#endif