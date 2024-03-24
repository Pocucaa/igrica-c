#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>

#include "structures.h"
#include "globals.h"

typedef struct {
	char spellname[30];
	int manacost;
	int instance1;
	int instance2;

} spells;

//SPELL FUNCTIONS
Hero Roguespell1 (Hero *hero, spells Splz);
int Roguespell2 (Hero *hero, spells Splz);
int Roguespellult (Hero *hero, spells Splz);
int Magespell1 (Hero *hero, spells Splz);
int Magespell2 (Hero *hero, spells Splz);
int Magespellult (Hero *hero, spells Splz);
int Warriorspell1 (Hero *hero, spells Splz);
int Warriorspell2 (Hero *hero, spells Splz);
int Warriorspellult (Hero *hero, spells Splz);




spells Splz = {"", 1, 1 ,1};


// spells Roguespell1 = {"", 1, 1 ,1};
// spells Roguespell2 = {"", 1, 1 ,1};
// spells Roguespellult = {"", 1, 1 ,1};
// spells Magespell1 = {"", 1, 1 ,1};
// spells Magespell2 = {"", 1, 1 ,1};
// spells Magespellult = {"", 1, 1 ,1};
// spells Warriorspell1 = {"", 1, 1 ,1};
// spells Warriorspell2 = {"", 1, 1 ,1};
// spells Warriorspellult = {"", 1, 1 ,1};









Hero DisplaySpells(Hero *hero) {

	int dak;					//action

	system("cls");
	printf("============================================\n");
	printf("============================================\n");

	printf("Spells:\n\n");
	printf("Spell 1:\n\n");     //Dodati txt file da cita spell description
	printf("Spell 2:\n\n");     //Dodati txt file da cita spell description
	printf("Ultimate:\n\n");     //Dodati txt file da cita spell description
	printf("===========================================\n");
	printf("===========================================\n");

	
	printf("What would you like to do?\n\n");
    printf("1 --> Use Spell 1\n\n");
    printf("2 --> Use Spell 2\n\n");
    printf("3 --> Use Ultimate\n\n");
    printf("4 --> Back\n\n");
	scanf(" %d", &dak);

		switch (dak) {
		
			case 1:

			system("cls");  	
			if (player == 1) {	//warrior
			Warriorspell1(hero, Splz);
			} else if (player == 2) {	//mage
			Magespell1(hero, Splz);
			} else if (player == 3) {	//rogue
			Roguespell1(hero, Splz);
			}

			break;
			
			case 2:

			system("cls"); 
			if (player == 1) {	//warrior
			Warriorspell2(hero, Splz);
			} else if (player == 2) {	//mage
			Magespell2(hero, Splz);
			} else if (player == 3) {	//rogue
			Roguespell2(hero, Splz);
			}

			break;
			
			case 3:

			system("cls"); 
			if (player == 1) {	//warrior
			Warriorspellult(hero, Splz);
			} else if (player == 2) {	//mage
			Magespellult(hero, Splz);
			} else if (player == 3) {	//rogue
			Roguespellult(hero, Splz);

			break;
			
			case 4:
			system("cls");
			break;

			default:
			printf("Try again!\n\n");
			break;
			
		}

	return *hero;
}
}

/*typedef struct {
	char spellname[30];
	int manacost;
	int instance1;
	int instance2;

} spells;
*/




int Damagefunction (int damage1) {
	int damage2;
	damage1 = damage2;

	return damage2;
}
/*----------------------------------------------------------------------------------------------------------*/ //ROGUE
Hero Roguespell1 (Hero *hero, spells Splz) {
    // deal 120% + 12 + rogue promenjiva sa levelom
    //fast strike? ime bitno
    int damage;
	Splz.manacost = 10;
	if (hero->MANA >= Splz.manacost) {

		hero->MANA = hero->MANA - Splz.manacost;
	
    	damage = (hero->AT * 1.2) + 12 + (hero->spl1lvl * 5); 
	} else {
		damage = hero->AT; //preforms an attack, change that!
	}
	Damagefunction(damage);

    return *hero;
}
/*--------------------------------------------------------------------*/
int Roguespell2 (Hero *hero, spells Splz) {
printf("Ne radi hehe :3");
}
/*--------------------------------------------------------------------*/
int Roguespellult (Hero *hero, spells Splz) {
printf("Ne radi hehe :3");   
}
/*----------------------------------------------------------------------------------------------------------*/ //MAGE
int Magespell1 (Hero *hero, spells Splz) {
printf("Ne radi hehe :3");
}
/*--------------------------------------------------------------------*/
int Magespell2 (Hero *hero, spells Splz) {
printf("Ne radi hehe :3");
}
/*--------------------------------------------------------------------*/
int Magespellult (Hero *hero, spells Splz) {
printf("Ne radi hehe :3");    
}
/*----------------------------------------------------------------------------------------------------------*/ //WARRIOR
int Warriorspell1 (Hero *hero, spells Splz) {
printf("Ne radi hehe :3");
}
/*--------------------------------------------------------------------*/
int Warriorspell2 (Hero *hero, spells Splz) {
printf("Ne radi hehe :3");
}
/*--------------------------------------------------------------------*/
int Warriorspellult (Hero *hero, spells Splz) {
printf("Ne radi hehe :3");   
}
/*----------------------------------------------------------------------------------------------------------*/

//int RogueSpell1(Hero *hero, spells Splz);