#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>

#include "structures.h"
#include "globals.h"


int player;

//STARTING FUNCTIONS***************************************************************************

void EnterStart();							                                    //press enter to start	
void ChangeColor();							                                        //Choosing color
//char ChoosingName(char yn, char * name);		                                //choosing name		//zakuca
Hero ChoosingCharacter(char yn, Hero *hr, int player);				        	            //choosing Hero (Hero umesto void)

//*********************************************************************************************


int main(){

	int game;						//if 0, game ends
	char yn;							//Yes or No
	char ak;							//Action
	int crlvl;						//Current Level
	int exps;						//exp addon depending on stage
	int golds;						//gold addon depending on stage
	//srand(time(0));				//generates random number from time
    srand(time(NULL));				//raspitati se


int playerY = PLAYER_START_Y;
int playerX = PLAYER_START_X;


Hero hero = {0, 0, 0, 0, 0, 0, 0, 0, 0, "", 0, 0, 0, 0, 0, 0, 1, 1, 1};


//cudovista :O
mon mn1 = {"Angery Gnome!", 25, 25, 4, 0, 0, 15, 12};
mon mn2 = {"Skeleton Warrior!", 28, 28, 7, 0, 0, 24, 22};	//dodati raspon exp i golda 
mon mn3 = {"Slime!", 35, 35, 3, 0, 0, 12, 9};
mon mn4 = {"Skeleton Mage!", 45, 45, 3, 10, 0, 48, 33}; //fireball

//chestovi
int chest1;

//itemi



//osobine karaktera:
char name[20];						//Player name






/*------------------------------------------------------------------------------------------------------------------------*/
system("cls");  	//clears screen		
printf("Welcome to the DUNGEON EXPLORER by Veljko, Press ENTER key to continue.\n"); 
/*------------------------------------------------------------------------------------------------------------------------*/	
EnterStart();
/*-----------------------------------------------------------------------------------------------------------*/			
ChangeColor();
/*----------------------------------------------------------------------------------------------------------*/
yn=0;		

do {
		printf("What would you like to be called?\n\n");
		scanf(" %s",&name);	
		printf("\n\n");
		printf("Your name is %s?\n(2=Yes, 1=No)\n\n",name);
		scanf(" %d", &yn);
	} while (yn == 1);

system("cls");  	//clears screen			
//ChoosingName(yn, name);		//zakuca
/*---------------------------------------------------------------------------------------------------------*/
//dodati text i srediti text	************

printf("Welcome %s,\n\n", name);

	FILE *pf = fopen("tekstovi/Introduction.txt", "r");

        char buffer[255];
        if (pf == NULL) {
            printf("Can't find the file!");
			exit(EXIT_FAILURE);
        } else {
                while (fgets(buffer, 255, pf) != NULL) {
                printf("%s", buffer);
                }
            }
        fclose(pf);

system("pause");
system("cls");  	//clears screen	
/*------------------------------------------------------------------------------------------------------------------------*/		
hero = ChoosingCharacter(yn, &hero, player);
/*------------------------------------------------------------------------------------------------------------------------*/
system("cls");  	//clears screen
crlvl=1;
game=1;
hero.gold=0;
hero.key=0;
hero.lvl=1;
hero.exp=0;
exps=3;
golds=10;

generateMap(map, playerX, playerY);
map[playerX][playerY] = 2;
printMap(map, playerX, playerY);

char direction;
// namestiti da umres kad hp padne ispod 1 i kad je game 0      ***************
while (game == 1) {//----------------------------------------------------------------------------START IGRE!!!!!!!!!!!!!!!!!!!!!!!!!!!

		if (hero.HP <= 0) {
		game = 0;
			}
        
        if (hero.HP > hero.MAXHP) {
            hero.HP = hero.MAXHP;
        }

        printf("Enter the direction to move (w/a/s/d), e for stats, r for restart q to quit: ");
        scanf(" %c", &direction);
        if (direction == 'q') {
            system("cls");
            exit(1);
        } else if (direction == 'e') {
            DisplayStats(&hero);
        } else if (direction == 'r') {
			system("igrica.exe");
        }
        movePlayer(map, direction, &playerX, &playerY, &hero, mn1, name, exps, golds); 				//&hero, mn1, name, exps, golds);

		//moveNPC(map, playerX, playerY, &hero, mn1, name, exps, golds)

        printMap(map, playerX, playerY);
        printf("\n");
    
    

}
//game0!!!!!!!!!!!!!!!!!END


//exit(EXIT_FAILURE);
//namestiti da kada hp < 0, umres!
system("cls");
printf("YOU HAVE LOST X)!!!\n");
system("pause");

	return 0;	
}


//
//										<----------------  FUNKCIJE  ------------------->
//												
//
/*------------------------------------------------------------------------------------------------------------------------*/
void EnterStart(){
	char ch; 
	while(1)   //checks if the enter is pressed and starts the game!			1 means true
	{
		ch=fgetc(stdin);
		if(ch==0x0A)
		{
			break;
		}
		else
		{
			printf("%c is pressed. You must press ENTER to start.\n",ch);
		}
		ch=getchar();

	}
}
/*------------------------------------------------------------------------------------------------------------------------*/
void ChangeColor(){

char color;									//Dodati jos boja?
char yn;					//color check
do{
system("cls");  	//clears screen	
printf("What color would you like the text to be?           (press 9 to skip...)\n\n");
printf("Brighter colors:\n\n");

printf("White --> 1\n\n");
printf("Yellow --> 2\n\n");
printf("Aqua --> 3\n\n");
printf("Green --> 4\n\n");

printf("Darker colors:\n\n");

printf("Darker Yellow --> 5\n\n");
printf("Darker Blue --> 6\n\n");
printf("Grey --> 7\n\n");

printf("And if ur rlly sick here is light red:\n\n");
printf("Red --> 8\n\n");

while (1) {
        color = getchar();
        if (color >= '1' && color <= '9' && getchar() == '\n') {
            color = color - '0';  // Convert character to integer
            break;  // Valid input, exit the loop
        } else {
            // Invalid input, clear the input buffer
            while (color != '\n' && color != EOF) {
                color = getchar();
            }
            printf("Invalid input. Please enter a single digit!\n\n\n ");
    }
}
		if (color == 1) {
				system("color 7");	
		} else if (color == 2) {
				system("color E");			
		} else if (color == 3) {
				system("color B");		
		} else if (color == 4) {
				system("color a");		
		} else if (color == 5) {
				system("color 6");			
		} else if (color == 6) {
				system("color 1");		
		} else if (color == 7) {
				system("color 8");		
        } else if (color == 8) {
				system("color C");		
		} else if (color == 9) {
				break;
		} else {
			printf("Invalid input.\n");
		}	

		while (1) {

        system("cls");  	//clears screen			
		printf("Is this the color you would like?\n(2=Yes, 1=No)\n\n");
		printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n");
		printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n\n");
		printf("000000000000000000000000000000000000000000000000\n\n");
		printf("===============================================)\n\n");
        yn = getchar();
        if (yn >= '1' && yn <= '2' && getchar() == '\n') {
            yn = yn - '0';  // Convert character to integer
            break;  // Valid input, exit the loop
        } else {
            // Invalid input, clear the input buffer
            while (yn != '\n' && yn != EOF) {
                yn = getchar();
            }
            printf("Invalid input. Please enter a single digit!\n\n\n ");
    }
}

} while (yn == 1);
system("cls");  	//clears screen	
}

/*------------------------------------------------------------------------------------------------------------------------*/
/*char ChoosingName(char yn, char* name){	//Zakuca
		
return *name;
}
/*------------------------------------------------------------------------------------------------------------------------*/


Hero ChoosingCharacter(char yn, Hero *hero, int player){

FILE *pf = fopen("tekstovi/CharacterStats.txt", "r");

        char buffer[255];
        if (pf == NULL) {
            printf("Can't find the file!");
			exit(EXIT_FAILURE);
        } else {
                while(fgets(buffer, 255, pf) != NULL){
                printf("%s", buffer);
                }
            }
        fclose(pf);

system("pause");
system("cls"); 

FILE *pf1 = fopen("tekstovi/CharacterDes.txt", "r");

        if (pf == NULL ){
            printf("Can't find the file!");
			exit(EXIT_FAILURE);
        }
        else {
                while(fgets(buffer, 255, pf) != NULL){
                printf("%s", buffer);
                }
            }
        fclose(pf);

system("pause");

yn=0;
do {
       while (1) {
system("cls"); 
printf("Choose your character:\n\n");	
printf("Warrior --> 1\n\n");
printf("Mage --> 2\n\n");
printf("Rogue --> 3\n\n");
        player = getchar();
        if (player >= '1' && player <= '3' && getchar() == '\n') {
            player = player - '0';  // Convert character to integer
            break;  // Valid input, exit the loop
        } else {
            // Invalid input, clear the input buffer
            while (player != '\n' && player != EOF) {
                player = getchar();
            }
            printf("Invalid input. Please enter a single digit!\n\n\n ");
     }
}

  while (1) {
    system("cls");
printf("Is this class your final choice?\n(2=Yes, 1=No)\n\n");

        yn = getchar();
        if (yn >= '1' && yn <= '2' && getchar() == '\n') {
            yn = yn - '0';  // Convert character to integer
            break;  // Valid input, exit the loop
        } else {
            // Invalid input, clear the input buffer
            while (yn != '\n' && yn != EOF) {
                yn = getchar();
            }
            printf("Invalid input. Please enter a single digit!\n\n\n ");
    }
}

}while (yn == 1);

switch (player) {
			case 1:	
			hero->MAXHP = 45; hero->HP = 45; hero->AT = 7; hero->MAXMANA = 10; hero->MANA = 10; strcpy(hero->hname, "Warrior"); hero->SPIRIT = 5;		//RAGE More damage on 50% and lower hp	
			hero->spl1 = 0; hero->spl2 = 0; hero->ult = 0; 																
			break;
			
			case 2:
			hero->MAXHP = 25; hero->HP = 25; hero->AT = 5; hero->MAXMANA = 30; hero->MANA = 30; strcpy(hero->hname, "Mage"); hero->SPIRIT = 6;			//WISENESS regenerates bonus mana 	
			hero->spl1 = 0; hero->spl2 = 0; hero->ult = 0; 																		
			break;
			
			case 3: 
			hero->MAXHP = 30; hero->HP = 35; hero->AT = 10; hero->MAXMANA = 15; hero->MANA = 15; strcpy(hero->hname, "Rogue"); hero->SPIRIT = 4;			//Can critical strike
			break;
			hero->spl1 = 0; hero->spl2 = 0; hero->ult = 0; 
			default:
			printf("Try again!\n\n");
			break;		
		}	
		
return *hero;
}
/*------------------------------------------------------------------------------------------------------------------------*/
