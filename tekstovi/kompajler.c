#include <stdio.h>
#include <stdlib.h>


int main(){

    system("gcc -o igrica.exe main.c mapa.c fight.c spells.c");
    system("pause");


/*
    scanf("%d", &key);
        printf("press r to restart, q to quit");
    int key;
        while (1){ 
    if (key == 'r'){
            system("gcc -o igrica.exe main.c mapa.c");
    } else if (key == 'q') {
    EXIT_SUCCESS;
        } else {break;}
    }*/



    return 0;
}