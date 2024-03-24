#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>

#include "structures.h"
#include "globals.h"


Hero DisplayStats(Hero *hero){

	int dak;					//action
	system("cls");
	printf("============================================\n");
	printf("============================================\n");
	printf("Stats:\n\n");
	printf("HP:%d/%d\n\n",hero->MAXHP, hero->HP);
	printf("MANA:%d\n\n",hero->MANA);
	printf("ATTACK DAMAGE:%d\n\n",hero->AT);
	printf("SPIRIT:%d\n\n\n\n",hero->SPIRIT);
	printf("Keys:%d\n\n",hero->key);
	printf("Gold:%d\n\n",hero->gold);
	printf("LEVEL:%d\n\n",hero->lvl);
	printf("EXP:%d\n\n",hero->exp);
	printf("lvlUp points:%d\n\n",hero->lvlpoint);
	printf("Stats points:%d\n\n",hero->statspoint);
	printf("===========================================\n");
	printf("===========================================\n");

	
	printf("What would you like to do?\n\n");
	printf("1                            --> Items   \n\n");
	printf("2                            --> Spells  \n\n");
	printf("3                            --> Upgrade (can't in battle!) \n\n");
	printf("4                            --> Back    \n\n");
	scanf(" %d", &dak);

		switch (dak) {
		
			case 1:
			system("cls");  	//items
			break;
			
			case 2:
			DisplaySpells(hero); 	//display spells 1 je za roguspl1 	
			break;

			case 3:
			Displaylvluptree(hero);	
			break;

			case 4:
			system("cls");  	//clears screen, vraca nazad
			break;		
		}


	return *hero;
}

Hero Fight(Hero *hero, mon mon, char * name, int exps, int golds){

int ak;						//action
int atak;					//changing variable of hero's attack
int medit;					//changing variable of monster's attack
int matak;					//changing variable of monster's attack
int rexp;					//gained exp
int rgold;					//gained gold
int turn = 1;               //turn counter
int damage;

while (hero->HP > 0 && mon.mHP > 0) {

    if (hero->HP > hero->MAXHP) {
            hero->HP = hero->MAXHP;
        }
//---------------------------------------------------------------------------------------
		system("cls");  	//clears screen
        printf("             TURN:%d               \n\n", turn);
		printf("===================================\n\n");
		printf("%s Health:%d/%d\n\n", mon.mname, mon.mMAXHP, mon.mHP);
		printf("%s Attack:%d\n\n", mon.mname, mon.mAT);
		printf("===================================\n\n");
		
		printf("===================================\n\n");
		printf("%s:\n\n", hero->hname);
		printf("%s Health:%d/%d\n\n", hero->hname,hero->MAXHP, hero->HP);
		printf("%s Attack:%d\n\n", hero->hname, hero->AT);
		printf("===================================\n\n");
		
		
	    printf("What would you like to do:\n\n");
		printf("1 --> Attack\n\n");
		printf("2 --> Meditate\n\n");
		printf("3 --> Spells\n\n");
		printf("4 --> Checks Stats.\n\n");
        printf("5 --> Use item\n\n");
		scanf(" %d", &ak);

        if (ak == 3) {
		damage = hero->AT;
		DisplaySpells(hero);
        }


		while (ak == 4) {

		DisplayStats(hero);				                	//srediti da ne gubi potes kada igras i da ne mora 2 fajt printa
		system("cls");  	//clears screen
        printf("             TURN:%d               \n\n", turn);
		printf("===================================\n\n");
		printf("%s Health:%d/%d\n\n", mon.mname, mon.mMAXHP, mon.mHP);
		printf("%s Attack:%d\n\n", mon.mname, mon.mAT);
		printf("===================================\n\n");
		
		printf("===================================\n\n");
		printf("%s:\n\n", hero->hname);
		printf("%s Health:%d/%d\n\n", hero->hname,hero->MAXHP, hero->HP);
		printf("%s Attack:%d\n\n",hero->hname, hero->AT);
		printf("===================================\n\n");
		
	    printf("What would you like to do:\n\n");
		printf("1 --> Attack\n\n");
		printf("2 --> Meditate\n\n");
		printf("3 --> Use item\n\n");
		printf("4 --> Checks Stats.\n\n");
        scanf(" %d", &ak);
        }
//---------------------------------------------------------------------------------------
		system("cls");  	//clears screen
			if (ak == 1) {
    atak = (rand() % hero->AT) + 1;
    mon.mHP -= atak;
    printf("You attacked %s, dealing %d damage.\n\n", mon.mname, atak);
} else if (ak == 2) {
    medit = (rand() % hero->SPIRIT) + 1;
    hero->HP += medit;
    printf("%s has regained %d HP!\n", hero->hname, medit);
} else {
    printf("Invalid input.\n");
    fflush(stdin);  // Clear the input buffer
    continue;       // Skip the rest of the loop and try again
}
system("pause");
system("cls");  	//clears screen
//---------------------------------------
matak = (rand() % mon.mAT) + 1;
hero->HP -= matak;
printf("%s attacks!\n", mon.mname);
printf("%s deals %d damage.\n\n", mon.mname, matak);

system("pause");

turn++;
}

system("cls");  	//clears screen
printf("%s has been defeated, you gain some exp.\n\n", mon.mname);	//exp?
system("pause");

/*-----------------------------------------------------------------------*/	

				system("cls");  	//clears screen
				rexp = (rand() % mon.mexp) + exps;			            //random broj izmedju 1 i monster exp + exps
				hero->exp = hero->exp + rexp;			            	//dodaje exp igracu
				printf("Gained %d EXP!\n\n", rexp);		            	//display
					
				rgold = (rand() % mon.mgold) + golds;		            //random broj izmedju 1 i monster gold + golds
				hero->gold = hero->gold + rgold;			        	//dodaje gold igracu
				printf("Gained %d GOLD!\n\n", rgold);		            //display
				system("pause");
				

				lvlup(hero);							//Svaki put kada se dobije exp pozovi lvlup funkciju

/*-----------------------------------------------------------------------*/	
system("cls");  	//clears screen

turn = 1;
return *hero;

}

								//treba da se namesti recimo lvl 2 preko 20 exp ali da se ne pozove svaki put , 20 lvla?
Hero lvlup(Hero *hero) {			//dodati counter za exp potreban za sledeci level, i dodati da uvek to kaze

    int counter = 2;
	
            if (hero->exp >= 20 && counter == 2) {		//lvl 2
			system("cls");
            printf("\n   YOU LEVELED UP TO LVL 2!!!   \n\n");
			system("pause");
                counter++;
                hero->lvl = 2;
				
            }
            else if (hero->exp >= 40 && counter == 3) {	//lvl 3
			system("cls");
            printf("\n  YOU LEVELED UP TO LVL 3!!!   \n\n");
			system("pause");
                counter++;
                hero->lvl = 3;
            }
            else if (hero->exp >= 70 && counter == 4) {	//lvl 4
			system("cls");
            printf("\n   YOU LEVELED UP TO LVL 4!!!   \n\n");
			system("pause");
                counter++;
                hero->lvl = 4;
            }
            else if (hero->exp >= 100 && counter == 5) {	//lvl 5
			system("cls");
            printf("\n   YOU LEVELED UP TO LVL 5!!!   \n\n");
			system("pause");
                counter++;
                hero->lvl = 5;
            }
            else if (hero->exp >= 140 && counter == 6) {	//lvl 6
			system("cls");
            printf("\n   YOU LEVELED UP TO LVL 6!!!   \n\n");
			system("pause");
                counter++;
            	hero->lvl = 6;
            }
            else {
                printf("You have %d EXP for level %d!!\n\n", hero->exp, counter);
                system("pause");
            }

        return *hero;
}


Hero Displaylvluptree(Hero *hero){
	int ak;
	system("cls");
	printf("===========================================\n");
	printf("===========================================\n");
	printf("Upgrade Spells                   --> 1\n");
	printf("Upgrade Stats                    --> 2\n");
	printf("Back                             --> 3\n");
	scanf("%d", &ak);
	printf("===========================================\n");
	printf("===========================================\n");

while (1){
	if (ak == 1) {
/*-----------------------------------------------------------------------*/	
	system("cls");
	printf("===========================================\n");
	printf("===========================================\n");
	printf("Avaliable lvlUp points:%d\n\n",hero->lvlpoint);
	printf("===========================================\n");
	printf("Spell 1 points:                %d\n\n",hero->spl1lvl);
	printf("Spell 2 points:                %d\n\n",hero->spl2lvl);
	printf("Ultimate points:               %d\n\n",hero->splult);
	printf("===========================================\n");
	printf("===========================================\n");
	printf("Upgrade Spell 1                --> 1\n");
	printf("Upgrade Spell 2                --> 2\n");
	printf("Upgrade Ultimate               --> 3\n");
	printf("Back                           --> 4\n");
	scanf("%d", &ak);
	printf("===========================================\n");
	printf("===========================================\n");

	while (1){

	if (ak == 1) {
	
	if (hero->lvlpoint > 0) {
		hero->lvlpoint = hero->lvlpoint - 1;
		hero->spl1lvl = hero->spl1lvl + 1;
	}

	} else if (ak == 2) {

	if (hero->lvlpoint > 0) {
		hero->lvlpoint = hero->lvlpoint - 1;
		hero->spl2lvl = hero->spl2lvl + 1;
	}

	} else if (ak == 3) {

	if (hero->lvlpoint > 5) {	//dodati uslov da si odredjeni level
		hero->lvlpoint = hero->lvlpoint - 1;
		hero->splult = hero->splult + 1;
	} else {
	system("cls");
	break;
	}

	} else if (ak == 4) {
	system("cls");
	break;
	} else {
    printf("Invalid input.\n");
    fflush(stdin);  // Clear the input buffer
	scanf("%d", &ak);
	}
	}
/*-----------------------------------------------------------------------*/
} else if (ak == 2) {

/*-----------------------------------------------------------------------*/	
	system("cls");
	printf("===========================================\n");
	printf("===========================================\n");
	printf("Avaliable Stats points:%d\n\n",hero->statspoint);
	printf("===========================================\n");
	printf("Stats:\n\n");
	printf("MAXHP:             			   %d\n\n",hero->MAXHP);
	printf("MAXMANA:             		   %d\n\n",hero->MAXMANA);
	printf("ATTACK DAMAGE:                 %d\n\n",hero->AT);
	printf("SPIRIT:               	       %d\n\n\n\n",hero->SPIRIT);
	printf("===========================================\n");
	printf("===========================================\n");
	printf("Upgrade MAXHP                  +3 --> 1\n");
	printf("Upgrade MAXMANA                +2 --> 2\n");
	printf("Upgrade ATTACK DAMAGE          +1 --> 3\n");
	printf("Upgrade SPIRIT                 +1 --> 4\n");	
	printf("Back                              --> 5\n");
	scanf("%d", &ak);
	printf("===========================================\n");
	printf("===========================================\n");



	if (ak == 1) {
	
	if (hero->statspoint > 0) {
		hero->statspoint = hero->statspoint - 1;
		hero->MAXHP = hero->MAXHP + 3;
	}

	} else if (ak == 2) {

	if (hero->lvlpoint > 0) {	
		hero->statspoint = hero->statspoint - 1;
		hero->MAXMANA = hero->MAXMANA + 2;
	}
	} else if (ak == 3) {

	if (hero->lvlpoint > 0) {	//dodati uslov da si odredjeni level
		hero->statspoint = hero->statspoint - 1;
		hero->AT = hero->AT + 1;
	}
	} else if (ak == 4) {

	if (hero->lvlpoint > 0) {	//dodati uslov da si odredjeni level
		hero->statspoint = hero->statspoint - 1;
		hero->SPIRIT = hero->SPIRIT + 1;
	}
	} else if (ak == 5) {
	system("cls");
	break;
	} else {
    printf("Invalid input.\n");
    fflush(stdin);  // Clear the input buffer
	scanf("%d", &ak);
}
/*-----------------------------------------------------------------------*/	
} else if (ak == 3) {
	system("cls");
	break;
	} else {
    printf("Invalid input.\n");
    fflush(stdin);  // Clear the input buffer
	scanf("%d", &ak);
}
}


}
//-----------------------------------------------------------------------------------------------FUNKCIJE MAPE---------------------------

