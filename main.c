#include <stdio.h>
#include <stdlib.h>
#include <string.h>     //Pour manipuler les chaines de caracteres
#include "personne.h"
#include <ctype.h>      //Pour pouvoir utiliser la fonction toupper()
#define TAIL 20         // determine la longueur maxiamle des mots secerts
#include <time.h>       //Pour pouvoir utiliser la fonction rand()


int main()
{

//**********************************JEU LE PENDU*****************************************

FILE *fichier=NULL;   //fichier qui contient les mots secrets
char secret[TAIL];
char *lettre=NULL;
char caractere;   //caractere que l'utilisateur entrer
short int reponse=1;
int nbcoups=0;
char *inside;
int nblettre;
const MIN=1;
int MAX=compterMot(fichier);
int positionMotsecret;
srand(time(NULL));

do{
    positionMotsecret= (rand() % (MAX - MIN + 1)) + MIN;    //determine le chiffre choisi au hasard par la machine
    renvoyermot(fichier,positionMotsecret,secret);         //fonction qui rencoie le mot correspondant a la position tire au hasard
    int nbcaractere=strlen(secret);
    lettre=malloc(nbcaractere*sizeof(char)); //On alloue de l'espace memoire
    nblettre=0;
    printf("\n\n");
    printf("\n\n");
    printf("          ***********************************************************************\n");
    printf("               *****************BIENVENUE DANS LE PENDU**************\n");
    printf("          ***********************************************************************");
     printf("\n\n");
    printf("\n\nVoici le mot a deviner :");
        for(int i=0;i<nbcaractere;i++){  // On affiche le mot secret par des etoiles
        lettre[i]='*';
        printf("%c",lettre[i]);
        }
    presentation();    //fonction qui presente le menu
    nbcoups=choix();   //fonction qui detemine le nombre d'essais a faire
    while(nbcoups>=1 && nblettre<(nbcaractere-1)){
        printf("\nEntrez un caractere :");
        caractere=lirecaractere();
        inside=NULL;
        inside=strchr(secret,caractere);

        if(inside==NULL){   // Si le caractere entre n'appartient a au mot mystere
            printf("Il vous reste %d coups",(nbcoups-1));
            nbcoups--;
        }
        else{   // si le caractere entre appartient au mot mystere
            printf("Il vous reste %d coups ::",nbcoups);
            for(int j=0;j<nbcaractere;j++){
                if(secret[j]==caractere){
                    lettre[j]=secret[j];
                }
             printf("%c",lettre[j]);   // On affiche les caractere qui appartiennent au mot secret
            }
        }
        int e=0;
        while(lettre[e]!='*' && e<=nbcaractere){    // cette boucle va nous permette de voir si l'utilisateur a devine touts lettres du mot secret
            nblettre=e;
            e=e+1;
        }
     }

    if(nbcoups==0){       //Si tu as perdu
        bonhommePendu();   // fonction qui affiche un pendu
    }

    if(nblettre==nbcaractere){  // si tu as gagne
        printf("\n\n BRAVO !!! Vous avez trouve le mot mystere\n");
    }
    free(lettre);  // on desalloue l'espace memoire
   printf("\n\nVoulez vous rejouer ?? 1(Oui)/0(Non)::");    // demande a l'utilisateur s'il veut encore jouer
   scanf("%d",&reponse);
}while(reponse==1);

if(reponse!=1){   //Si l'utilisateur ne veut plus jouer
    printf("\nMerci d'avoir Jouer\n");
    free(lettre);
}

    return 0;
}
