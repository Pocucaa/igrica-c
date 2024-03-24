#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>

#include "structures.h"
#include "globals.h"


int map[MAP_SIZE_X][MAP_SIZE_Y];  // Define the map variable
int playerX;                      // Define other global variables if necessary
int playerY;





void generateMap(int map[MAP_SIZE_X][MAP_SIZE_Y], int playerX, int playerY) {
    
	//Kreiranje zidova mapa
    for (int i = 0; i < MAP_SIZE_X; i++) {
        for (int j = 0; j < MAP_SIZE_Y; j++) {
            if (i == 0 || i == MAP_SIZE_X - 1 || j == 0 || j == MAP_SIZE_Y - 1) {
                map[i][j] = 0; // Kreiranje zida oko mape
            } else {
                map[i][j] = (rand() / (double)RAND_MAX) < WALL_DENSITY ? 0 : 1;		//dodavanje random zidova
            }
        }
    }

    // Kreiranje random blokova zidova
    for (int i = 1; i < MAP_SIZE_X - 1; i += (rand() % 10) + 5) {
        for (int j = 1; j < MAP_SIZE_Y - 1; j += (rand() % 20) + 5) {
            int boxSizeX = (rand() % (MAX_BOX_SIZE_X - MIN_BOX_SIZE_X + 1)) + MIN_BOX_SIZE_X;
            int boxSizeY = (rand() % (MAX_BOX_SIZE_Y - MIN_BOX_SIZE_Y + 1)) + MIN_BOX_SIZE_Y;
            for (int k = i; k < i + boxSizeX && k < MAP_SIZE_X - 1; k++) {
                for (int l = j; l < j + boxSizeY && l < MAP_SIZE_Y - 1; l++) {
                    map[k][l] = 0;
                }
            }
        }
    }

    // Pokusaj kreiranja 2x2 hodnika koji povezuju zidove
    for (int i = 2; i < MAP_SIZE_X - 2; i++) {
        for (int j = 2; j < MAP_SIZE_Y - 2; j++) {
            if (map[i][j] == 0) {
                if (map[i + 1][j] == 0 && map[i][j + 1] == 0 && map[i + 1][j + 1] == 1) {
                    map[i][j + 1] = 1;
                } else if (map[i + 1][j] == 1 && map[i][j + 1] == 0 && map[i + 1][j + 1] == 0) {
                    map[i + 1][j] = 1;
                }
            }
        }
    }

    // Kreiranje prostora oko igraca koji je prazan                                                               
    for (int i = playerX - 4; i < playerX + 4; i++) {
        for (int j = playerY - 6; j < playerY + 6; j++) {
            if (i >= 0 && i < MAP_SIZE_X && j >= 0 && j < MAP_SIZE_Y) {
                map[i][j] = 1;
            }
        }
    }


	// Kreiranje random cudovista
	for (int i = 1; i < MAP_SIZE_X; i += (rand() % MONSTER_FREQUENCY) + 5) { 
		for (int j = 1; j < MAP_SIZE_Y; j += (rand() % MONSTER_FREQUENCY) + 20) { 
			if (map[i][j] == 1) {
					map[i][j] = 3;
			}
		}
	}

// Kreiranje HP UPA
	for (int i = 1; i < MAP_SIZE_X; i += (rand() % CHEST_FREQUENCY) + 7) { 
		for (int j = 1; j < MAP_SIZE_Y; j += (rand() % CHEST_FREQUENCY) + 13) { 
			if (map[i][j] == 1) {
					map[i][j] = 4;
			}
		}
	}

// Kreiranje random cesta 
	for (int i = 1; i < MAP_SIZE_X; i += (rand() % CHEST_FREQUENCY) + 13) { 
		for (int j = 1; j < MAP_SIZE_Y; j += (rand() % CHEST_FREQUENCY) + 19) { 
			if (map[i][j] == 1) {
					map[i][j] = 5;
			}
		}
	}


}



void printMap(int map[MAP_SIZE_X][MAP_SIZE_Y], int playerX, int playerY) {
    system("cls"); 

    int startX = playerX - 10;
    int startY = playerY - 30;

    for (int i = startX; i < startX + 20; i++) {
        for (int j = startY; j < startY + 60; j++) {
            if (i >= 0 && i < MAP_SIZE_X && j >= 0 && j < MAP_SIZE_Y) {
                if (map[i][j] == 0) {
                    printf("#");                    //zid
                } else if (map[i][j] == 1) {
                    printf(" ");                    //put
                } else if (map[i][j] == 2) {
                    printf("H");                    //heroj
                } else if (map[i][j] == 3) {
                    printf("M");                    //cudoviste
                } else if (map[i][j] == 4) {
                    printf("+");                    //cudoviste
                } else if (map[i][j] == 5) {
                    printf("@");                    //cudoviste
                } else {
                printf("0"); // zids
           		 }
        }

        }
		printf("\n");
	}
}


Hero* movePlayer(int map[MAP_SIZE_X][MAP_SIZE_Y], char direction, int *playerX, int *playerY, Hero *hero, mon mn1, char *name, int exps, int golds){

    int newX = *playerX;
    int newY = *playerY;

    switch (direction) {
        case 'w':
            newX--;
            break;
        case 'a':
            newY--;
            break;
        case 's':
            newX++;
            break;
        case 'd':
            newY++;
            break;
        default:
            printf("Invalid direction!\n");
    	}


    if (newX >= 0 && newX < MAP_SIZE_X && newY >= 0 && newY < MAP_SIZE_Y && map[newX][newY] == 1) {
        map[*playerX][*playerY] = 1;
        map[newX][newY] = 2;
        *playerX = newX;
        *playerY = newY;
    } else if (newX >= 0 && newX < MAP_SIZE_X && newY >= 0 && newY < MAP_SIZE_Y && map[newX][newY] == 3) {	
		system("cls");	
        
        Fight(hero, mn1, name, exps, golds); 

		map[*playerX][*playerY] = 1;
        map[newX][newY] = 1;
	} else if (newX >= 0 && newX < MAP_SIZE_X && newY >= 0 && newY < MAP_SIZE_Y && map[newX][newY] == 4) {	
		system("cls");	
		printf("HP UP!\n");
		printf("+ 10HP!\n\n");
		system("pause");
    int keychanse; 
    keychanse = (rand() % 10) + 1;


    if (keychanse == 7){
        system("cls");
        printf("Wow, you also found a key!\n");
        system("pause");
        hero->key += 1;
    }

		hero->HP += 10;
		map[*playerX][*playerY] = 1;
        map[newX][newY] = 1;

	} else if (newX >= 0 && newX < MAP_SIZE_X && newY >= 0 && newY < MAP_SIZE_Y && map[newX][newY] == 5) {	
		system("cls");	
		printf("YOU FOUND A CHEST!\n\n");
        system("pause");
		map[*playerX][*playerY] = 1;
        map[newX][newY] = 1;
    } else {
        printf("Invalid move!\n");
    }

	return hero;
}