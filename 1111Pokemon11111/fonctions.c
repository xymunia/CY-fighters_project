#include "pokemon.h"

int NumberofChar(FILE* file, char c)
{ //return the number of the c there is in the file
    	// we count the number of occurasion a character have in the file 
    	// (it permit us to count the number of object there is in a file because there is separators between every objects)

    	rewind(file);
   	int count=0;
    	int chr;
    	while(chr!=EOF) // main loop to get the number of char there is in the file
	{	
        	chr = fgetc(file);
		if(chr == c)
		{
            		count++;
       		}
	}
   	return(count);
}


char** SplitStr(char* line)
{	
	// this function is used to get an array of strings from a string
	// ex: May,June,Jully    become  an array with May in first position June in second and Jully in third
	if(line == NULL)
	{
		printf("\n\nerror in SplitStr line point to NULL");
		exit(1);
	}

	char c;
	char* s = &c;
	char** res    = &s;
    	int count     = 0;
    	char* tmp        = line;
    	char* last_comma = 0;
    	char delim[2];
    	delim[0] = ',';
    	delim[1] = 0;
	

	// Count how many elements will be extracted.
 	while (*tmp)
 	{
   	   if (',' == *tmp)
    	   {
     	       count++;
     	       last_comma = tmp;
     	   }
    	   tmp++;
   	}

	// Add space for trailing token.
	if(last_comma < (line + strlen(line) - 1))
	{
   		count ++;
	}

	// Add space for terminating null string so caller
	// knows where the list of returned strings ends. 
	count++;

	res = malloc(sizeof(char*) * count);

	if(res)
	{
		int idx  = 0;
		char* token = strtok(line, delim);
		
		while (token)
		{
			*(res + idx) = strdup(token);
			token = strtok(0, delim);
			idx++;
		
		}
		*(res + idx) = 0;
	}
	
	return(res);
}

int size_str(char** str) // return the number of different string there is in the array of strings (str is an array of strings)
{	
	if(str == NULL){
		printf("\n\nerror str in size_str point to NULL");
	}
	int count = 0;
	while(*(str+count) != NULL) {
		count++;
	}
	return(count);
}

type* SeekTypes(char** names, type* types, int ntypes)	// return an array of type from an array of strings 
{
	if(names == NULL){
		printf("\n\nerror names in SeekTypes point to NULL");
		exit(1);
	}
	if(ntypes <= 0){
		printf("\n\nerror ntypes <= 0 in SeekTypes");
		exit(1);
	}
	verifyPType(types, ntypes, "SeekTypes");

	int nnames = size_str(names);	// number of elements in the array
	type* res = malloc(nnames*sizeof(type)); // (number of strings in the array) * sizeof(type)

	for(int i = 0; i<nnames;i++)
	{

		for(int j = 0; j<ntypes; j++)
		{
			if( !strcmp(*(names+i), (types+j)->name) ){
				*(res+i)=*(types+j);
			}		
		}

	}
	return(res);
}

ability* SeekAbilities(char** names, ability* abilities, int nabilities)	// return an array of abilities from an array of strings
{
	if(names == NULL){ // names is a list of string of every ability we seek
		printf("\n\nerror names in SeekAbilities point to NULL");
		exit(1);
	}
	if(nabilities <= 0){
		printf("\n\nerror nabilities <= 0 in SeekAbilities ");
		exit(1);
	}
	verifyPAbility(abilities, nabilities, "SeekAbilities");	// the array of every possible ability

	
	int nnames = size_str(names);	// number of elements in the array
	ability* res = malloc(4*sizeof(ability)); // number of strings in the array * sizeof(

	for(int i = 0; i<nnames;i++){

		for(int j = 0; j<nabilities;j++){

			if( !strcmp(*(names+i), (abilities+j)->name)){
				*(res+i)=*(abilities+j);
			}		
		}
	}
	if(nnames<4)
	{
		for(int i = nnames; i < 4; i++)	// we need to have 4 slot of current abilities so we fill the empty slots if needed
		{
			*(res+i) = *(abilities+(nabilities-1));	// *(abilities+(nabilities-1) is the ability wich does nothing (kind of no_ability ability)
		}
	}
	return(res);
}

ability* SeekAbility(char* names, ability* abilities, int nabilities)	// return an ability from a string
{
	if(names == NULL){ // names is a list of string of every ability we seek
		printf("\n\nerror names in SeekAbilities point to NULL");
		exit(1);
	}
	if(nabilities <= 0){
		printf("\n\nerror nabilities <= 0 in SeekAbilities ");
		exit(1);
	}
	verifyPAbility(abilities, nabilities, "SeekAbilities");	// the array of every possible ability


	ability* res = malloc(sizeof(ability)); // number of strings in the array * sizeof(

	for(int j = 0; j<nabilities;j++){

		if( !strcmp(names, (abilities+j)->name)){
			*(res)=*(abilities+j);
		}		
	}
	return(res);
}

pokemon SeekPokemons(char* name, pokemon* pokemons, int npokemons)
{	// return the pokemon which correspond to the name
	if(name == NULL){
		printf("\n\nerror names in SeekPokemons point to NULL");
		exit(1);
	}
	if(npokemons <= 0){
		printf("\n\nerror npokemons <= 0 in SeekPokemons ");
		exit(1);
	}
	verifyPPkmn(pokemons, npokemons, "SeekPokemons");


	pokemon res;

	if((name)=="NULL"){	// if there is no ability specified then it is NULL
		((res)).name = "aucun";
	}
	else{
		for(int j = 0; j<npokemons; j++){
			if((name) == (pokemons+j)->name){
				(res)=*(pokemons+j);
			}		
		}
	}

	return(res);
}

effect SeekEffect(char* name, effect* effects, int neffects)
{	// return the effect which correspond to the name
	if(name == NULL){
		printf("\n\nerror name in SeekEffect point to NULL");
		exit(1);
	}
	if(neffects <= 0){
		printf("\n\nerror neffects <= 0 in SeekEffect");
		exit(1);
	}
	verifyPEffect(effects, neffects, "SeekEffect"); // the array of every effect possible

	effect res;


	if(strcmp(name,"aucun") == 0){	// if there is no ability specified then it is NULL
		*(res.name) = 'a';
		*(res.name) = 'u';
		*(res.name) = 'c';
		*(res.name) = 'u';
		*(res.name) = 'n';	// sometimes the ability does not apply any effect
		res.tour = 0;
	}
	else
	{
		for(int j = 0; j<neffects; j++){
			if(name==(effects+j)->name){
				res=*(effects+j);
			}		
		}
	}
	
	return(res);
}

int getTypes(type** types)
{	// make the array of every types and return the number of types in the array

	if(types == NULL){	// the array is not filled yet
		printf("\n\nerror types pointing in getTypes to NULL");
		exit(1);
	}

	FILE* ftypes = NULL; // to get the file with the types
	int ntypes;	// the number of types

	char chr; // we will need this variable to travel through the file	
	int count = 0; // we need this variable to keep track of where we are in the filling of the array
	int good_type; // we verify if the type of the variable the fscanf does is the good one 


	// Getting the abilities and storing them into a list like we did with the pokemons
	ftypes = fopen("Type.txt","r");
	if (ftypes == NULL){
		printf("pas de Type.txt");
		exit(1);
	}

	// Make space for the type array
	ntypes = NumberofChar(ftypes, '#')+1;
	*types = malloc((ntypes)*sizeof(type));

	chr = 'f'; // initialize the character so we can enter the loop
	rewind(ftypes);

	while(chr!=EOF && count < ntypes) // main loop to get the TYPES
	{	

		good_type = fscanf(ftypes,"%s", (*(*types+count)).name);	//	we get every parameter we need for a type
		if(!good_type){
			printf("\n\nerror, fscanf(ftypes, str, (*(*types+count)).name); wrong type ");
			exit(1);
		}

		good_type = fscanf(ftypes,"%s", ((*(*types+count)).tmpimmune));
		if(!good_type){
			printf("\n\nerror, fscanf(ftypes,str, ((*(*types+count)).tmpimmune)); wrong type");
			exit(1);
		}
		
		good_type = fscanf(ftypes,"%s", ((*(*types+count)).tmpresist));
		if(!good_type){
			printf("\n\nerror, fscanf(ftypes, str, ((*(*types+count)).tmpresist)); wrong type");
			exit(1);
		}
		
		good_type = fscanf(ftypes,"%s", ((*(*types+count)).tmpefficient));
		if(!good_type){
			printf("\n\nerror, fscanf(ftypes, str, ((*(*types+count)).tmpefficient)); wrong type");
			exit(1);
		}

		(*(*types+count)).immune = SplitStr(((*(*types+count)).tmpimmune));
		(*(*types+count)).nimmune = size_str((*(*types+count)).immune);
	
		(*(*types+count)).resist = SplitStr(((*(*types+count)).tmpresist));
		(*(*types+count)).nresist = size_str((*(*types+count)).resist);

		(*(*types+count)).efficient = SplitStr(((*(*types+count)).tmpefficient));
		(*(*types+count)).nefficient = size_str((*(*types+count)).efficient);

		
		count++;
		chr=fgetc(ftypes);
		chr=fgetc(ftypes);
		chr=fgetc(ftypes);	// for some reason, it needs to be called 3 times to get the # chararcter

	}
	
	fclose(ftypes);	
	return(ntypes);
}

int getEffect(effect** effects)
{	// make the array of every effects and return the number of affect in the array
	
	if(effects == NULL){	// the array is not filled yet
		printf("\n\nerror effects pointing in getEffect to NULL");
		exit(1);
	}

	FILE* feffects; // to get the file with the effects
	int neffects;	// the number of effects

	int chr; // we will need this variable to travel through the file	
	int count = 0; // we need this variable to keep track of where we are in the filling of the array
	int good_type; // we verify if the type is the good one 

	// Getting the abilities and storing them into a list like we did with the pokemons
	feffects = fopen("effect.txt","r");
	if (feffects == NULL){
		printf("pas de effect.txt");
		exit(1);
	}

	// Make space for the effects array
	neffects = NumberofChar(feffects, '#')+1;
	*effects = malloc((neffects)*sizeof(effect));


	rewind(feffects);

	while(chr!=EOF && count<neffects) // main loop to get the EFFECTS
	{	

		good_type = fscanf(feffects,"%s", (*(*effects+count)).name);	//	we get every parameter we need for an effect
		if(!good_type){
			printf("\n\nerror, fscanf(feffects, str, (*(effects+count)).name); wrong type");
			exit(1);
		}
		(*(*effects+count)).tour = 0;
		count++;
		
		chr=fgetc(feffects);
		chr=fgetc(feffects);
		chr=fgetc(feffects);	// for some reason, it needs to be called 3 times to get the # chararcter
	}
	fclose(feffects);
	return(neffects);
	
}

int getAbilities(ability** abilities, effect* effects, int neffects)
{	// make the array of every abilities and return the number of abilities in the array
	if(abilities == NULL){	// the array is not filled yet
		printf("\n\nerror abilities list pointing to NULL in getAbilities");
		exit(1);
	}
	if(neffects <= 0){
		printf("\n\nerror neffects <= 0 in getAbilities");
		exit(1);
	}

	verifyPEffect(effects, neffects, "getAbilities"); // the array of every effect possible

	FILE* fabilities; // to get the file with the abilities
	int nabilities;	// the number of abilities

	char chr; // we will need this variable to travel through the files	
	int count = 0; // we need this variable to keep track of where we are in the filling of the lists
	int good_type; // we verify if the type is the good one 


	// Getting the abilities and storing them into a list like we did with the pokemons
	fabilities = fopen("capa.txt","r");
	if (fabilities == NULL){
		printf("pas de capa.txt");
		exit(1);
	}

	// Make space for the abilities list
	nabilities = NumberofChar(fabilities, '#')+1;
	*abilities = malloc((nabilities)*sizeof(ability));
	
	rewind(fabilities);

	while(chr!=EOF && count < nabilities) // main loop to get the ABILITIES
	{			

		good_type = fscanf(fabilities,"%s", (*(*abilities+count)).name);	//	we get every parameter we need for an ability
		if(!good_type){
			printf("\n\nerror, fscanf(fabilities, str, (*(*abilities+count)).name) wrong type");
			exit(1);
		}
		good_type = fscanf(fabilities,"%s", (*(*abilities+count)).phy_spe);
		if(!good_type){
			printf("\n\nerror, fscanf(fabilities,str, (*(*abilities+count)).phy_spe); wrong type");
			exit(1);
		}
		
		good_type = fscanf(fabilities,"%d", &(*(*abilities+count)).dmg);
		if(!good_type){
			printf("\n\nerror, fscanf(fabilities, int, (*(*abilities+count)).dmg); wrong type");
			exit(1);
		}
		
		good_type = fscanf(fabilities,"%d", &(*(*abilities+count)).precision);
		if(!good_type){
			printf("\n\nerror, fscanf(fabilities,int, (*(*abilities+count)).precision); wrong type");
			exit(1);
		}
		good_type = fscanf(fabilities,"%d", &(*(*abilities+count)).pp);
		(*(*abilities+count)).pp = (*(*abilities+count)).pp / 5;
		if(!good_type){
			printf("\n\nerror, fscanf(fabilities,int, (*(*abilities+count)).pp); wrong type");
			exit(1);
		}
		good_type = fscanf(fabilities,"%d", &(*(*abilities+count)).ppmax);
		(*(*abilities+count)).ppmax = (*(*abilities+count)).ppmax / 5;
		if(!good_type){
			printf("\n\nerror,  fscanf(fabilities, int, (*(*abilities+count)).ppmax); wrong type");
			exit(1);
		}
		good_type = fscanf(fabilities,"%s", (*(*abilities+count)).effect.name);
		if(!good_type){
			printf("\n\nerror, fscanf(fabilities, str, (*(*abilities+count)).effect.name); wrong type");
			exit(1);
		}
		
		good_type = fscanf(fabilities,"%d", &(*(*abilities+count)).peffect);
		if(!good_type){
			printf("\n\nerror, fscanf(fabilities, str, (*(*abilities+count)).peffect); wrong type");
			exit(1);
		}
		
		good_type = fscanf(fabilities,"%s", (*(*abilities+count)).type);
		if(!good_type){
			printf("\n\nerror, fscanf(fabilities, str, (*(*abilities+count)).type); wrong type");
			exit(1);
		}
		
		good_type = fscanf(fabilities,"%d", &(*(*abilities+count)).affectall);
		if(!good_type){
			printf("\n\nerror, fscanf(fabilities, int, (*(*abilities+count)).affectall); wrong type");
			exit(1);
		}
		
		good_type = fscanf(fabilities,"%d", &(*(*abilities+count)).selfdmg);
		if(!good_type){
			printf("\n\nerror, fscanf(fabilities, int, (*(*abilities+count)).selfdmg); wrong type");
			exit(1);
		}
		
		good_type = fscanf(fabilities,"%d", &(*(*abilities+count)).spd_atk);
		if(!good_type){
			printf("\n\nerror, fscanf(fabilities, int, (*(*abilities+count)).spd_atk); wrong type");
			exit(1);
		}
		(*(*abilities+count)).effect.tour = 0;
		chr=fgetc(fabilities);
		chr=fgetc(fabilities);
		chr=fgetc(fabilities);
		count++;

	}
	fclose(fabilities);
	return(nabilities);
}

int getPokemons(pokemon** pokemons, ability* abilities, int nabilities, type* types, int ntypes)
{	// make the array of every types and return the number of types in the array
	if(pokemons == NULL){ // the array is empty so no verifyppkmn
		printf("\n\nerror pokemons list pointing to NULL");
		exit(1);
	}
	if(nabilities <= 0){
		printf("\n\nerror nabilities <= 0 in getPokemons");
		exit(1);
	}
	if(ntypes <= 0){
		printf("\n\nerror ntypes <= 0 in getPokemons");
		exit(1);
	}
	
	verifyPAbility(abilities, nabilities, "getPokemons");	// the array of every possible ability
	verifyPType(types, ntypes, "getPokemons");
	

	FILE* fpokemons; // to get the file with the pokemons
	int npokemons;	// the number of pokmemons

	int chr; // we will need this variable to travel through the files	
	int count = 0; // we need this variable to keep track of where we are in the filling of the lists
	int good_type; // we verify if the type is the good one;
	char na;
	char n[21];
	char (*name)[21] = &n; // where we store the name in the first place
	name = malloc(npokemons * sizeof(char[21]));
	
	// Getting the pokemon and storing them into a list like we did with the pokemons
	fpokemons = fopen("Pokedex.txt","r");
	if (fpokemons == NULL){
		printf("pas de Pokedex.txt");
		exit(1);
	}

	// Make space for the pokemons list
	npokemons = NumberofChar(fpokemons, '#')+1;
	*pokemons = malloc((npokemons)*sizeof(pokemon));

	rewind(fpokemons);

	while(chr!=EOF && count < npokemons) // main loop to get the POKEMONS
	{

		good_type = fscanf(fpokemons,"%s", name[count]);	//	we get every parameter we need for a pokemon
		if(!good_type){
			printf("\n\nerror, fscanf(fpokemons, str, name; wrong type");
			exit(1);
		}
		good_type = fscanf(fpokemons,"%d", &((*(*pokemons+count)).hp));
		if(!good_type){
			printf("\n\nerror, fscanf(fpokemons, int, &((*(*pokemons+count)).hp)); wrong type\n");
			exit(1);
		}

		good_type = fscanf(fpokemons,"%d", &((*(*pokemons+count)).hpmax));
		if(!good_type){
			printf("\n\nerror, fscanf(fpokemons, int, &((*(*pokemons+count)).hpmax)); wrong type\n");
			exit(1);
		}
			
		good_type = fscanf(fpokemons,"%s", (*(*pokemons+count)).tmptype);	// we need to make it a list of strings
		if(!good_type){
			printf("\n\nerror, fscanf(fpokemons, str, (*(*pokemons+count)).tmptype); wrong type");
			exit(1);
		}

		good_type = fscanf(fpokemons,"%d", &(*(*pokemons+count)).ntype);
		if(!good_type){
			printf("\n\nerror, fscanf(fpokemons, int, &(*(*pokemons+count)).ntype); wrong type");
			exit(1);
		}
			
		
		good_type = fscanf(fpokemons,"%d", &(*(*pokemons+count)).capt);
		if(!good_type){
			printf("\n\nerror, fscanf(fpokemons, int, &((*(*pokemons+count)).capt)); wrong type");
			exit(1);
		}
		
		good_type = fscanf(fpokemons,"%d", &((*(*pokemons+count)).atk));
		if(!good_type){
			printf("\n\nerror, fscanf(fpokemons, int, &((*(*pokemons+count)).atk)); wrong type");
			exit(1);
		}
		
		good_type = fscanf(fpokemons,"%d", &((*(*pokemons+count)).atk_spe));
		if(!good_type){
			printf("\n\nerror,  fscanf(fpokemons, int, &((*(*pokemons+count)).atk_spe)); wrong type");
			exit(1);
		}
		
		good_type = fscanf(fpokemons,"%d", &((*(*pokemons+count)).def));
		if(!good_type){
			printf("\n\nerror, fscanf(fpokemons, int, &((*(*pokemons+count)).def)); wrong type");
			exit(1);
		}
		
		good_type = fscanf(fpokemons,"%d", &((*(*pokemons+count)).def_spe));
		if(!good_type){
			printf("\n\nerror, fscanf(fpokemons, int, &((*(*pokemons+count)).def_spe)); wrong type");
			exit(1);
		}

		good_type = fscanf(fpokemons,"%d", &((*(*pokemons+count)).speed));
		if(!good_type){
			printf("\n\nerror, fscanf(fpokemons, int, &((*(*pokemons+count)).speed));; wrong type");
			exit(1);
		}

		good_type = fscanf(fpokemons,"%s", (*(*pokemons+count)).tmpabilities);	// we need to make it a list of strings
		if(!good_type){
			printf("\n\nerror, fscanf(fpokemons, str, (*(*pokemons+count)).tmpabilities); wrong type");
			exit(1);
		}

		/*good_type = fscanf(fpokemons,"%s", &(*(pokemons+count)).next_abilities);	// we need to make it a list of strings
		if(!good_type){
			printf("\n\nerror, fscanf(fpokemons, str, &(*(pokemons+count)).next_abilities); wrong type");
			exit(1);
		}*/
		
		if(name[count] != "Metamortph")
		{
			(*(*pokemons+count)).name = malloc( (strlen(name[count])+1) * sizeof(char));
		}
		else	// the array needs to be at least 12 character long for the morphing ability to be used
		{
			(*(*pokemons+count)).name = malloc( 12 * sizeof(char));
		}

		(*(*pokemons+count)).name = name[count];
		
		(*(*pokemons+count)).type = SeekTypes(SplitStr((*(*pokemons+count)).tmptype), types, ntypes);
		
		(*(*pokemons+count)).current_abilities = SeekAbilities(SplitStr((*(*pokemons+count)).tmpabilities), abilities, nabilities);

		/*(*(*pokemons+count)).nabi = 0;*/
		(*(*pokemons+count)).spdbar = 0;
		count++;
		chr=fgetc(fpokemons);
		chr=fgetc(fpokemons);
		chr=fgetc(fpokemons);


	}
	fclose(fpokemons);
	return(npokemons);
}



pokemon** MaxVit(pokemon** list, int narray, int nbr_vit) // function to make the list of who play in the right order (in one array)
{
	if(list == NULL){	// pointer to the allies/foes array
		printf("\n\nerror, list in MaxVit point to NULL");
		exit(1);
	}
	if(narray <= 0)
	{
		printf("\n\n error, narray <= 0 in MaxVit");
		exit(1);
	}
	if(narray >6)
	{
		printf("\n\n error, narray > 6 in MaxVit");
		exit(1);
	}
	if(nbr_vit<0){
		printf("\n\nerror, nbr_vit in MaxVit is <0");
		exit(1);
	}
	verifyPPkmn(*list, narray, "MaxVit");


	pokemon** res = malloc(nbr_vit * sizeof(pokemon*));
	pokemon* tmp;
	int j;
	int i =0;
	int count = 0;
	int max;

	while(i<narray && count<nbr_vit)
	{ // we make the arrays of every pokemon which have a speedbar equal or greater than BAR (and reset it to 0) (and are not ko)
		
		if( (*(*list+i)).spdbar >= BAR && IsKo( (*(*list+i)) ) == 0)
		{
			*(res+count) = (*list+i);

			/*(**(res+count)).name = malloc( (strlen((*((*list)+i)).name) + 1) * sizeof(char));
			strcpy((**(res+count)).name, (*((*list)+i)).name);*/

			(*(*list+i)).spdbar = 0;	// we reset the speed bar, (so having a value above BAR is just about who play first, no addition to the next one)
			count++;
		}	
		i++;
	}	

	for(i = 0; i < nbr_vit; ++i) // now we sort the arrays in descending order
	{
		max = i;
		for(j = i + 1; j < nbr_vit; ++j) 
		{
			/*if( (**(res+i)).spdbar < (**(res+j)).spdbar ) 
			{
				tmp = *(res+i);
				*(res+i) = *(res+j);
				*(res+j) = tmp;
			}*/

			if( (**(res+max)).spdbar < (**(res+j)).spdbar )
			{
				max = j;
			}
		}
		if(max != i)
		{
			tmp = *(res+i);
			*(res+i) = *(res+max);
			*(res+max) = tmp;
		}
		
	}
	return(res);
}


int IsKo(pokemon pkmn)	// return 1 if the pkmn is ko, 0 if not
{
	//verifyPkmn(pkmn, "IsKo");
	int res;
	if(pkmn.hp <= 0){
		res = 1;
	}
	else{
		res = 0;
	}
	return(res);
}

int IsWin(pokemon* allies, int nallies, pokemon* foes, int nfoes) // return 1 if win, 0 if nothing, -1 if lost
{
	
	if(nallies <= 0){
		printf("\n\nerror, in IsWin nallies <=0");
		exit(1);
	}
	if(nallies > 6){
		printf("\n\nerror, in IsWin nallies >6");
		exit(1);
	}
	if(nfoes < 0){
		printf("\n\nerror, in IsWin nfoes <0");
		exit(1);
	}
	if(nfoes > 6){
		printf("\n\nerror, in IsWin nfoes >6");
		exit(1);
	}

	//verifyPPkmn(allies, nallies, "IsWin"); // the array of every pokemon the player possess
	//verifyPPkmn(foes, nfoes, "IsWin"); // the array of every pokemon the player possess


	int res = 1;
	for(int i = 0; i < nfoes; i++)	// we search if there is a pokemon left in the enemy team
	{
		if( !(IsKo(*(foes+i))) )
		{
			res = 0;
		}
	}


	if(res==0)
	{	// we search if there is a pokemon left in the ally team if he doesn't win
		res = -1;
		for(int i = 0; i < nfoes; i++)
		{
			if( !(IsKo(*(foes+i))) )
			{
				res = 0;
			}
		}
	}

	return(res);
}




int IsDodging(ability atk , pokemon target) // return 1 if the target dodge, 0 if he doesn't		p(hit) = precision move x (1  - evade of the target)
{

	verifyAbility(atk, "IsDodging");
	verifyPkmn(target, "IsDodging");


	int r;
	int p;

	r = rand()%101;	// make a random value
	p = (atk).precision * (target).speed;	// calculate the probability of a hit (not dodge)

	if(r <= p) // the attack hit the target
	{
		return(0);
	}
	printf("\n");
	PrintfType((*target.type).name, target.name);
	printf(" dodged the attack!");
	return(1);	// the target dodge
}

int Critical()	// return if the damage multiplier of the critic hit if there is one
{
	int r;
	r = rand()%100;
	if( r <= 7)	// if the hit is critical
	{
		printf("\n Critical Hit!");
		return(2); // double the dmg
	}
	return(1); // else, change nothing to the damage
}


int StatusEffect(pokemon* pkmn, effect* effects, int neffects, int isally, pokemon* allies, int nallies, pokemon* foes, int nfoes)
{	/*return 1 if the turn is skipped, 
	2 if the pokemon is confuse and
	0 if nothing happen more thant what is managed in the function
	-1 if there is a winner*/

	if(pkmn == NULL){
		printf("\n\nerror pkmn in StatusEffect point to NULL");
		exit(1);
	}
	if(neffects <= 0){
		printf("\n\nerror neffects <=0 in StatusEffect");
		exit(1);
	}
	if(nallies<=0)	// the number of pokemon an enemy have
	{
		printf("\n\nerror in StatusEffect, nallies <= 0");
		exit(1);
	}
	else if(nallies>6)	// the number of foes
	{
		printf("\n\nerror in StatusEffect, nallies > 6");
		exit(1);
	}
	if(nfoes<=0)	// the number of pokemon an enemy have
	{
		printf("\n\nerror in StatusEffect, nfoes <= 0");
		exit(1);
	}
	else if(nfoes>6)	// the number of foes
	{
		printf("\n\nerror in StatusEffect, nfoes > 6");
		exit(1);
	}
	if(isally != 0 && isally != 1)
	{
		printf("\n\nerror, isally != 0 && != 1 in StatusEffect");
	}
	verifyPkmn(*pkmn, "StatusEffect");
	verifyPPkmn(allies, nallies, "StatusEffect"); // the array of every pokemon the player possess
	verifyPPkmn(foes, nfoes, "StatusEffect"); // the array of every pokemon the player possess
	verifyPEffect(effects, neffects, "StatusEffect"); // the array of every effect possible


	int res;
	int* pres = &res;
	int stat = 0;
	int r;
	effect curr_sttus;
	curr_sttus = (*pkmn).affected; // current status of the pokemon

	if(!strcmp(curr_sttus.name, "brulure") )	// if the pokemon is burned
	{	// deals constant damage to the pokemon affected
		(*pkmn).hp = (*pkmn).hp - ((*pkmn).hpmax/ 8);
		printf("\n\n");
		PrintfType((*(*pkmn).type).name,(*pkmn).name);
		printf(" is burning !");
	}

	else if(!strcmp(curr_sttus.name, "gel"))	// skip the turn 
	{
		r = rand()%10;
		if(r!= 0)	// 10% to get out of freeze
		{
			printf("\n\n");
			PrintfType((*(*pkmn).type).name,(*pkmn).name);
			printf(" is frozen solid ! He can't move!");
			stat = 1;
		}
		else
		{
			printf("\n\n");
			PrintfType((*(*pkmn).type).name,(*pkmn).name);
			printf(" is not frozen anymore !");
		}

	}

	else if(!strcmp(curr_sttus.name, "paralysie") )	// slow the speedbar and can skip turn 
	{	// can't get out of paralysis
		// the speedbar proggressing slower is in the addspeed function
		r = rand()%4;
		if(r==0)
		{
			printf("\n\n");
			PrintfType((*(*pkmn).type).name,(*pkmn).name);
			printf(" is paralyzed !");
			stat = 1;
		}
	}

	else if(!strcmp(curr_sttus.name, "empoisonnement") )
	{	// deals damage that constantly increase, can't get out of poison
		((*pkmn).affected).tour++;
		(*pkmn).hp = (*pkmn).hp - ((*pkmn).hpmax/ 16) - (curr_sttus.tour * ((*pkmn).hpmax/ 16));
		printf("\n\n");
		PrintfType((*(*pkmn).type).name,(*pkmn).name);
		printf(" is poisoned !");
	}

	else if(!strcmp(curr_sttus.name, "endormi") )
	{	// sleep skip the turn but can last 7 turns
		((*pkmn).affected).tour++;
		r = rand()%7;
		if(curr_sttus.tour < r)
		{
			printf("\n\n");
			PrintfType((*(*pkmn).type).name,(*pkmn).name);
			printf(" is fast asleep !");
			stat = 1;
		}
	}

	else if(!strcmp(curr_sttus.name, "confus"))
	{	// confusion make attack random target and can last 4 turns
		((*pkmn).affected).tour++;
		r = rand()%4;
		if(curr_sttus.tour < r)
		{
			printf("\n\n");
			PrintfType((*(*pkmn).type).name,(*pkmn).name);
			printf(" is confused !");
			stat = 1;
		}
	}

	if(isally == 1) // verify if ally is ko, switch in this case
	{
		SwitchAlly(allies, nallies, pres);	// switch ally if ko
	}
	else	// verify for the enemy, and switch
	{
		SwitchEnemy(foes, nfoes);
	}

	if((IsWin(allies, nallies, foes, nfoes)) == -1 || (IsWin(allies, nallies, foes, nfoes)) == 1)
	{
		stat = -1;
	}

	return(stat);
}

float TypeEffectiveness(ability atk, pokemon target)
{	// return the effectiveness of the type of the attack
	
	verifyAbility(atk, "TypeEffectiveness");
	verifyPkmn(target, "TypeEffectiveness");

	type current_type;
	int i,j;
	float res = 1;
	for(i = 0; i < target.ntype ; i++)
	{
		current_type = *(target.type + i);
		
		for(j = 0; j < current_type.nimmune; j++)
		{
			if( !strcmp(*((current_type.immune)+j), atk.type) )
			{// if immune
				
				res = res * 0;
			}
		}

		for(j = 0; j < current_type.nresist; j++)
		{
			if( !strcmp(*((current_type.resist)+j), atk.type) )
			{// if not very effective
				
				res = res * 0.5;
			}
		}

		for(j = 0; j < current_type.nefficient; j++)
		{
			if( !strcmp(*((current_type.efficient)+j), atk.type) )
			{// if effective
				res = res * 2;
			}
		}
	}

	if(res==0)
	{
		printf("\nIt doesn't affect ");
		PrintfType((*target.type).name, target.name);
	}
	else if(res <= 0.5)
	{
		printf("\nIt's not very effective...");
	}
	else if(res >= 2)
	{
		printf("\nIt's super effective!");
	} 

	return(res);
}

int CalculateDmg(ability atk, pokemon target)
{	// return the damage of the attack (with everything like the critical, effectiveness...)

	verifyAbility(atk, "CalculateDmg");
	verifyPkmn(target, "CalculateDmg");

	int dmg;	// dmg calculus			(((22	+ 2) * dmg of ability * atk of pkmn attacking / def of foes) / 50 + 2) * critical * type dmg

	if(IsDodging(atk, target))
	{
		dmg = 0; // the target dodge so there is no dmg
	}
	else
	{	
		if(atk.dmg = 0)
		{
			dmg = 0;
		}
		else if(!strcmp(atk.phy_spe, "spe"))	// calculate the dmg if the atk is special and not physical
		{
			dmg = (24 * (atk).dmg * target.atk_spe / target.def_spe) / 50 + 2;
		}
		else	// calculate the dmg if the atk is physical and not special
		{
			dmg = (24 * (atk).dmg * target.atk / target.def) / 50 + 2;
		}
		dmg = dmg * Critical();	// add the critical multiplier if there is one
		dmg = dmg * TypeEffectiveness(atk, target);
	}
	return dmg;
}


int NumberPokemons(pokemon* array, int narray) // this function return the number of pokemon currently fighting in the array
{

	if(narray < 0){
		printf("\n\nerror naray in NumberPokemons is <0");
		exit(1);
	}
	else if(narray>6)	// the number of foes
	{
		printf("\n\nerror in NumberPokemons, narray > 6");
		exit(1);
	}

	verifyPPkmn(array, narray, "NumberPokemons");



	int count = 0;
	for(int i = 0; i < narray; i++)
	{
		if( !(IsKo(*(array+i))) ) {	// count the number of pokemon which is alive
			count = count + 1;}
	}

	if(count == 1)
	{
		return(1);	// return 1 if only one pokemon is alive 
	}
	return(2);
}


int IsDitto(pokemon pkmn)
{	// return 1 if the pokemon was a ditto morphed, else return 0
	verifyPkmn(pkmn, "IsDitto");
	char subbuff[10];
	if(strlen(pkmn.name)>10)	// we verify if the name is long enough
	{
		memcpy( subbuff, &(pkmn.name[1]), 9 );	// when metamorph is morphed, his name is like this: (metamorph)morphed_pkmn_name
		if(subbuff == NULL)	// I've read we need to test the return value because it's not already in the function
		{
			printf("error, IsDitto memcpy return a pointer to NULL");
			exit(1);
		}
		subbuff[10] = '\0';		// so we copy the name in a substring and verify if the (metamorph) is here or not
		if(!strcmp(subbuff, "Metamorph") )
		{
			return(1);
		}
	}
	return(0);
}
