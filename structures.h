#ifndef STRUCTURES_H
#define STRUCTURES_H


typedef struct monster{
		char mname[20];		        	//monster's name
        int mMAXHP;                     //monster's max health
		int mHP;			        	//monster's Health
		int mAT;			        	//monster's Attack
		int mspl1;	         			//monster's Spell value
		int mspl2;		        		//monster's Spell value
		int mexp;		        		//monster's exp range
		int mgold;			        	//monster's gold range
	} mon; 
	

typedef struct bossman{
		char Bname[20];
		int Bded;
        int BMAXHP;
		int BHP;
		int BAT;
		int BSPIRIT;
		int Bspl1;
		int Bspl2;	
		int Bulti;
	} BOSS; 

typedef struct{		
    	int MAXHP;			    		//Hero's max health
        int HP;                         //Hero's current health
		int MAXMANA;
	    int MANA;			        	//Hero's mana
	    int AT;				        	//Max damage during fight
	    int SPIRIT;			           	//Max healing during fight
	    int spl1; 			        	//Spell value
	    int spl2;			        	//Spell value
	    int ult;				        //Ultimate ability (has a coldown)
	    char hname[20];					//Hero's  name
	    int lvl;						//Hero's level
	    int exp;						//Hero's  Expiriance
	    int gold;						//Hero's Gold 			//ne sme u minus (double?)
	    int key;						//Number of keys 		//ne sme u minus (double?)
        int lvlpoint;                   //lvlup points
        int statspoint;                 //statspoint
		int spl1lvl;
		int spl2lvl;
		int splult;
    } Hero; 


#endif 

