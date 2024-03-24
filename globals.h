#ifndef GLOBALS_H
#define GLOBALS_H

#include "structures.h"

#define MAP_SIZE_X 420
#define MAP_SIZE_Y 460
#define PLAYER_START_X MAP_SIZE_X / 2
#define PLAYER_START_Y MAP_SIZE_Y / 2
#define MIN_BOX_SIZE_X 4
#define MAX_BOX_SIZE_X 12
#define MIN_BOX_SIZE_Y 6
#define MAX_BOX_SIZE_Y 16
#define WALL_DENSITY 0.03
#define MONSTER_FREQUENCY 20 
#define CHEST_FREQUENCY 60


//Extern variables
    extern int map[MAP_SIZE_X][MAP_SIZE_Y];
    extern int playerX;
    extern int playerY;
    extern int player;
    
//GAME FUNCTIONS*******************************************************************************

Hero Displaylvluptree(Hero *hero);
Hero DisplaySpells(Hero *hero);
Hero Displaylvluptree(Hero *hero);
Hero* movePlayer(int map[MAP_SIZE_X][MAP_SIZE_Y], char direction, int *playerX, int *playerY, Hero *hero, mon mn1, char *name, int exps, int golds);           //moves player on the map
Hero DisplayStats(Hero *hero);			                                    	//displays information
Hero Fight(Hero *hero, mon mon, char * name, int exps, int golds);               //starts a fight
Hero lvlup(Hero *hero);                                                         //level up 
//MAP FUNCTIONS*******************************************************************************
void generateMap(int map[MAP_SIZE_X][MAP_SIZE_Y], int playerX, int playerY);                            //generates map
void printMap(int map[MAP_SIZE_X][MAP_SIZE_Y], int playerX, int playerY);                               //prints 2d map grid






#endif