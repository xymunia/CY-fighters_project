// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct {

	char* name;
	int tour;

} frr;

void start(frr* starters, frr* trainer)
{

    *trainer=*starters;
	//(**trainer).name=(*starters).name;
	//(**trainer).tour=(*starters).tour;

}

void SeekAbility(char** names)	// names is a list of string of every name we seek
{
	printf("%s",*names);
}



int main()
{

	frr* tr=malloc(3*sizeof(frr));
    tr->name = "frr" ;
    (tr+1)->name = "fr";
    (*(tr+2)).name = "f";
    (*tr).tour = 1 ;
    (*(tr+1)).tour = 2;
    (*(tr+2)).tour = 3;
    printf("%s      %d\n\n",(*tr).name, (*tr).tour);
    
    frr** ptr = &tr;
    
	frr* st=malloc(2*sizeof(frr));
    (*st).name = "wsh" ;
    (*(st+1)).name = "ws";
    (*st).tour = 10 ;
    (*(st+1)).tour = 11;
    printf("%s      %d\n\n",(*st).name, (*st).tour);
	
    start(st, tr);

	printf("%s      %d\n",(*tr).name, (*tr).tour);
	


    char* frr = "frr";
    char** pfrr = &frr;
    SeekAbility(pfrr);

}