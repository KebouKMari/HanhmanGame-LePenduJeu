#include "personne.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define TAIL 20


char lirecaractere(){
    char carac=0;
    carac=getchar();
    carac=toupper(carac);
    while(getchar()!='\n');

    return carac;
}

void bonhommePendu(){
    printf("\n");
    printf("HOHO!! PENDU :(\n\n");
    printf("  ______________________________________________\n");
    printf("||______________________________________________\n");
    printf("||                        |\n");
    printf("||                        |\n");
    printf("||                        |\n");
    printf("||                        |\n");
    printf("||                        |\n");
    printf("||                      ______\n");
    printf("||                     /      \ \n");
    printf("||                    |  -  -  | \n");
    printf("||                     \______/  \n");
    printf("||                         |    \n");
    printf("||                         |    \n");
    printf("||                         |    \n");
    printf("||                         |    \n");

   }

presentation(){

printf("\n\n");
printf("\n\n");
printf("              *********Choix du niveau*****\n\n");
printf("              1. FACILE\n");
printf("              2. MOYEN\n");
printf("              3. DIFFICILE\n\n");
}

int choix(){
printf("              Choissisez votre niveau ::");
int choice;
scanf("%d",&choice);
switch(choice){
case 1:
    return 15;
    break;
case 2:
    return 10;
    break;
case 3:
    return 5;
    break;
default:
    printf("Faites les choix entre les numeros ci - dessus");
    return -1;
    break;
}

}

int compterMot(FILE *file){
    int compte=0; char chaine[TAIL];
file=fopen("livre.txt","r");
if(file==NULL){
    printf("\nOuverture echoue ");
}
else{
    rewind(file);
   while(fgets(chaine,TAIL,file)!=NULL){
        compte++;
   }
    fclose(file);
    return compte;
}
}

void renvoyermot(FILE *file,int position, char mot[]){
    int compteur=0;
    file=fopen("livre.txt","r");
    rewind(file);
    while(fgets(mot,TAIL,file)!=NULL){
        if(compteur==position){
            fgets(mot,TAIL,file);
            fclose(file);
            break;
        }
        compteur++;
    }
}














