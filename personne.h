#ifndef  DEF_PERSONNE.H
#define  DEF_PERSONNE.H
#include <stdio.h>
#define TAIL 20


char lirecaractere();
void bonhommePendu();
void presentation();
int  choix();
int  compterMot(FILE *file);
void renvoyermot(FILE *file,int position, char *mot);


#endif   //  Pour eviter les inclusions infinies;
