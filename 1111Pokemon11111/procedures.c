#include "pokemon.h"


void verifyType(type tp, char* fname)
{	// verify if the type object in parameter is valid

	if(fname == NULL)
	{
		printf("\n\nfname point to NULL");
		exit(1);
	}

	if(tp.name == NULL)
	{
		printf("\n\nname point to NULL in %s", fname);
		exit(1);
	}

	if(tp.nimmune > MAX_LENGTH)
	{
		printf("\n\nnimmune > MAX_LENGTH in %s", fname);
		exit(1);
	}
	if(tp.nimmune < 0)
	{
		printf("\n\nnimmune < 0 in %s", fname);
		exit(1);
	}
	if(tp.immune == NULL)
	{
		printf("\n\ntp.immune point to NULL in %s", fname);
		exit(1);
	}

	if(tp.nresist > MAX_LENGTH)
	{
		printf("\n\nnresist > MAX_LENGTH in %s", fname);
		exit(1);
	}
	if(tp.nresist < 0)
	{
		printf("\n\nnresist < 0 in %s", fname);
		exit(1);
	}
	if(tp.resist == NULL)
	{
		printf("\n\nresist point to NULL in %s", fname);
		exit(1);
	}

	if(tp.nefficient > MAX_LENGTH)
	{
		printf("\n\nnresist > MAX_LENGTH in %s", fname);
		exit(1);
	}
	if(tp.nefficient < 0)
	{
		printf("\n\nnresist < 0 in %s", fname);
		exit(1);
	}
	if(tp.efficient == NULL)
	{
		printf("\n\nresist point to NULL in %s", fname);
		exit(1);
	}

}


void verifyPType(type* tps, int n, char* fname)
{	// verify if the ptype pointer to a type is valid

	if(fname == NULL)
	{
		printf("\n\nfname point to NULL");
		exit(1);
	}
	if(n<0)
	{
		printf("\n\nn < 0 in %s", fname);
		exit(1);
	}
	if(tps== NULL)
	{
		printf("\n\ntps point to NULL in %s", fname);
		exit(1);
	}
	for (int i = 0; i<n; i++)
	{
		verifyType( *(tps+i), fname);
	}
}

void verifyEffect(effect effe, char* fname)
{	// verify if the effect object in parameter is valid

	if(fname == NULL)
	{
		printf("\n\nfname point to NULL");
		exit(1);
	}
	if(effe.name == NULL)
	{
		printf("\n\neffe.name poit to NULL in %s", fname);
		exit(1);
	}
	if(effe.tour < 0)
	{
		printf("\n\neffe.tour < 0 in %s", fname);
	}
}


void verifyPEffect(effect* effes, int n, char* fname)
{	// verify if the peffect pointer to a effect is valid

	if(fname == NULL)
	{
		printf("\n\nfname point to NULL");
		exit(1);
	}
	if(n<0)
	{
		printf("\n\nn < 0 in %s", fname);
		exit(1);
	}
	for (int i = 0; i<n; i++)
	{
		verifyEffect( *(effes+i), fname);
	}

}


void verifyAbility(ability abl, char* fname)
{	// verify if the ability object in parameter is valid

	if(fname == NULL)
	{
		printf("\n\nfname point to NULL");
		exit(1);
	}
	if(abl.name == NULL)
	{
		printf("\n\nabl.name point to NULL in %s", fname);
		exit(1);
	}
	if(abl.phy_spe == NULL)
	{
		printf("\n\nabl.phy_spe point to NULL in %s", fname);
		exit(1);
	}
	if(abl.dmg < 0)
	{
		printf("\n\nabl.dmg < 0 in %s", fname);
		exit(1);
	}
	if(abl.precision>100)
	{
		printf("\n\nabl.precision > 100 in %s", fname);
		exit(1);
	}

	if(abl.ppmax<=0)
	{
		printf("\n\nabl.ppmax <= 0 in %s",fname);
		exit(1);
	}
	if(abl.pp > abl.ppmax)
	{
		printf("\n\nabl.pp > abl.ppmax in %s",fname);
		exit(1);
	}
	if(abl.pp < 0)
	{
		printf("\n\nabl.pp < 0 in %s",fname);
		exit(1);
	}

	verifyEffect(abl.effect, fname);

	if(abl.peffect > 100)
	{
		printf("\n\nabl.peffect > 100 in %s", fname);
		exit(1);
	}
	if(abl.peffect < 0)
	{
		printf("\n\nabl.peffect < 0 in %s", fname);
		exit(1);
	}
	if(abl.type == NULL)
	{
		printf("\n\nabl.type point to NULL in %s", fname);
		exit(1);
	}
	if(abl.affectall != 1 && abl.affectall != 0)
	{
		printf("\n\nabl.affectall != 1 && != 0 in %s", fname);
		exit(1);
	}
	if(abl.spd_atk < 0)
	{
		printf("%s",abl.name);
		printf("\n\nabl.spd_atk < 0 in %s", fname);
		exit(1);
	}
	if(abl.spd_atk > 2)
	{
		printf("\n\nabl.spd_atk > 2 %s", fname);
		exit(1);
	}

}


void verifyPAbility(ability* abls, int n, char* fname)
{	// verify if the abls pointer to a ability is valid
	if(fname == NULL)
	{
		printf("\n\nfname point to NULL");
		exit(1);
	}
	if(n<0)
	{
		printf("\n\nn < 0 in %s", fname);
		exit(1);
	}
	if(abls== NULL)
	{
		printf("\n\nabls point to NULL in %s", fname);
		exit(1);
	}
	for(int i = 0; i < n; i++)
	{
		verifyAbility(*(abls+i), fname);
	}
}


void verifyPkmn(pokemon pkmn, char* fname)
{	// verify if the pokemon object in parameter is valid

	
	if(fname == NULL)
	{
		printf("\n\nfname point to NULL");
		exit(1);
	}
	if(pkmn.name == NULL)
	{
		printf("\n\npkmn.name point to NULL in %s", fname);
		exit(1);
	}
	if(pkmn.hpmax <= 0)
	{
		printf("\n%d\n", pkmn.hpmax);
		printf("\n\npkmn.hpmax <= 0 in %s", fname);
		exit(1);
	}
	if(pkmn.hp>pkmn.hpmax)
	{
		printf("\n\npkmn.hp > pkmn.hpmax in %s", fname);
		exit(1);
	}

	if(pkmn.ntype<=0)
	{
		printf("\n\npkmn.ntype <= 0 in %s", fname);
		exit(1);
	}
	if(pkmn.ntype > 2)
	{
		printf("\n\npkmn.ntype > 2 in %s",fname);
		exit(1);
	}
	
	verifyPType(pkmn.type, pkmn.ntype, fname);

	if(pkmn.capt > 100)
	{
		printf("\n\npkmn.capt > 100 in %s",fname);
		exit(1);
	}
	if(pkmn.capt < 0)
	{
		printf("\n\npkmn.capt < 0 in %s",fname);
		exit(1);
	}
	if(pkmn.atk <= 0)
	{
		printf("\n\npkmn.atk <= 0 in %s", fname);
		exit(1);
	}
	if(pkmn.atk_spe <= 0)
	{
		printf("\n\npkmn.atk_spe <= 0 in %s", fname);
		exit(1);
	}
	if(pkmn.def <= 0)
	{
		printf("\n\npkmn.def <= 0 in %s", fname);
		exit(1);
	}
	if(pkmn.def_spe <= 0)
	{
		printf("\n\npkmn.def_spe <= 0 in %s", fname);
		exit(1);
	}
	if(pkmn.speed <= 0)
	{
		printf("\n\npkmn.speed <= 0 in %s", fname);
		exit(1);
	}
	/*if(pkmn.nabi!=0 && pkmn.nabi!=1)
	{
		printf("\n\npkmn.number_next < 0 in %s", fname);
		exit(1);
	}*/

	if(pkmn.capt < 0)
	{
		printf("\n\npkmn.capt < 0 in %s",fname);
		exit(1);
	}
	verifyPAbility(pkmn.current_abilities, 4, fname);
	/*verifyPAbility(pkmn.next_abilities, 1, fname);*/

	if(pkmn.affected.name == NULL)
	{
		printf("\n\npkmn.affected point to NULL in %s", fname);
		exit(1);
	}
	
	if(pkmn.spdbar < 0)
	{
		printf("\n\npkmn.spdbar < 0");
		exit(1);
	}

}


void verifyPPkmn(pokemon* pkmn, int n, char* fname)
{	// verify if the ppkmn pointer to a pokemon is valid
	
	if(fname == NULL)
	{
		printf("\n\nfname point to NULL");
		exit(1);
	}
	if(n<0)
	{
		printf("\n\nn < 0 in %s", fname);
		exit(1);
	}
	if(pkmn== NULL)
	{
		printf("\n\npknm point to NULL in %s", fname);
		exit(1);
	}
	for(int i = 0; i < n; i++)
	{
		verifyPkmn(*(pkmn+i), fname);
	}
}


void PrintfStatus(char* sta)
{	// print the status with the color of the background
	if( !strcmp(sta, "bru") )
	{
		printf("\33[48;2;255;50;50m\33[38;2;255;255;255mbru\33[0m");
	}
	else if( !strcmp(sta, "par") )
	{
		printf("\33[48;2;225;205;55m\33[38;2;255;255;255mpar\33[0m");
	}
	else if( !strcmp(sta, "gel") )
	{
		printf("\33[48;2;55;205;205m\33[38;2;255;255;255mgel\33[0m");
	}
	else if( !strcmp(sta, "emp") )
	{
		printf("\33[48;2;205;55;205m\33[38;2;255;255;255mpoi\33[0m");
	}
	else if( !strcmp(sta, "end") )
	{
		printf("\33[48;2;175;175;175m\33[38;2;255;255;255mend\33[0m");
	}
	else if( !strcmp(sta, "con") )
	{
		printf("\33[48;2;255;175;50m\33[38;2;255;255;255mcon\33[0m");
	}
	
}

void PrintfType(char* type, char* name)
{	// print name with the color of the type
	if( !strcmp(type, "normal") )
	{
		printf("\33[38;2;255;255;255m%s \33[0m", name);
	}

	else if( !strcmp(type, "feu") )
	{
		printf("\33[38;2;255;100;100m%s\33[0m", name);
	}

	else if( !strcmp(type, "eau") )
	{
		printf("\33[38;2;100;100;255m%s\33[0m", name);
	}

	else if( !strcmp(type, "plante") )
	{
		printf("\33[38;2;100;255;100m%s\33[0m", name);
	}

	else if( !strcmp(type, "electrik") )
	{
		printf("\33[38;2;255;255;100m%s\33[0m", name);
	}

	else if( !strcmp(type, "glace") )
	{
		printf("\33[38;2;100;255;255m%s\33[0m", name);
	}
	
	else if( !strcmp(type, "combat") )
	{
		printf("\33[38;2;172;100;0m%s\33[0m", name);
	}

	else if( !strcmp(type, "poison") )
	{
		printf("\33[38;2;145;75;145m%s\33[0m", name);
	}
	
	else if( !strcmp(type, "sol") )
	{
		printf("\33[38;2;210;160;0m%s\33[0m", name);
	}

	else if( !strcmp(type, "vol") )
	{
		printf("\33[38;2;0;175;175m%s\33[0m", name);
	}

	else if( !strcmp(type, "psy") )
	{
		printf("\33[38;2;255;100;255m%s\33[0m", name);
	}

	else if( !strcmp(type, "insecte") )
	{
		printf("\33[38;2;50;120;50m%s\33[0m", name);
	}

	else if( !strcmp(type, "roche") )
	{
		printf("\33[38;2;120;80;30m%s\33[0m", name);
	}
	else if( !strcmp(type, "spectre") )
	{
		printf("\33[38;2;150;100;150m%s\33[0m", name);
	}
	else if( !strcmp(type, "dragon") )
	{
		printf("\33[38;2;120;120;150m%s\33[0m", name);
	}
	else if( !strcmp(type, "tenebres") )
	{
		printf("\33[38;2;120;120;150m%s\33[0m", name);
	}
	else if( !strcmp(type, "acier") )
	{
		printf("\33[38;2;120;120;150m%s\33[0m", name);
	}
	else if( !strcmp(type, "fee") )
	{
		printf("\33[38;2;120;120;150m%s\33[0m", name);
	}


}







void start(pokemon* starters, pokemon* trainer, char* name, int* pnallies)
{	// start the game (select the name, and the starters)
	
	verifyPPkmn(starters, 3, "start");	// the pokemons you can choose as first pokemons
	
	if(name == NULL) // the name of the team/trainer/player
	{
		printf("\n\nerror, name point to NULL in start");
		exit(1);
	}
	if(pnallies == NULL) // the name of the team/trainer/player
	{
		printf("\n\nerror, pnallies point to NULL in start");
		exit(1);
	}


	int res;	// store the numer answer
	int not_valid = 1;	// to test the answers
	int good_type, gd_type; // to test the input
	pokemon* starters2 = malloc(2 * sizeof(pokemon)); // to select the second starters

	system("clear");

	
	printf("==================================================");
	printf("\n\nProfessor: Hi pokemon trainer! I'm the pokemon professor!");
	
	
	do{			// name selection
		printf("\nProfessor: What's your trainer's name?\n");
		gd_type = scanf("%s",name);
		printf("\nProfessor: Nice to meet you %s!",name);
		if(gd_type!=1)
		{
			printf("\nenter a valid value");
		}
	}while(gd_type!=1);
	
	
	printf("\nProfessor: Hey but you don't have any pokemon yet ?!");
	printf("\nProfessor: You are lucky because I have 3 pokemons on me right now !");
	printf("\nProfessor: You can take one! Come on choose one:");

	do{			// choose the first pokemon
		not_valid=0;
		printf("\n\n");
		for(int i = 0; i < 3; i++)
		{
			printf(" %d : ",i+1);
			PrintfType( (*(*(starters+i)).type).name, (*(starters+i)).name);
			printf("	");
		}
		printf("\n");
		good_type = scanf("%d",&res);
		if(good_type == 0 || (res != 1 && res!= 2 && res!= 3 && res!=4)){
			not_valid = 1;
			printf("\nThat's not an option!");
		}
	}while(not_valid);

	printf("\nProfessor: Ok! Here take %s! Take care of him!", (*(starters+res-1)).name);
	*trainer= *(starters+res-1);
	printf("\n\n *%s joined your team*\n",(*(starters+res-1)).name);		
	
	if(res == 4)
	{	// if the player choosed metamorph, make the next starters random
		res = rand()%3+1;
	}

	switch(res-1){ // make the first pokemon unavailable by doing another array
		case 0:
			*starters2 = *(starters+1);
			*(starters2+1) = *(starters+2);
			break;
		case 1:
			*starters2 = *(starters);
			*(starters2+1) = *(starters+2);
			break;
		case 2:
			*starters2 = *(starters);
			*(starters2+1) = *(starters+1);
			break;
	}
	
	res = 0;
	printf("\nProfessor: You know what? I think one pokemon is not enough. \nIt's dangerous around here you should carry at least 2");
	printf("\nProfessor: Here take another one\n\n");
	do{			// select the second pokemon
		not_valid=0;
		for(int i = 0; i < 2; i++)
		{
			printf(" %d : ",i+1);
			PrintfType( (*(*(starters2+i)).type).name, (*(starters2+i)).name);
			printf("	");
		}
		printf("\n");
		good_type = scanf("%d",&res);
		if(good_type == 0 || (res != 1 && res!= 2)){
			not_valid = 1;
			printf("\n\nPlease enter a valid value.");
		}
	}while(not_valid);

	*pnallies = 2;
	
	printf("\nProfessor: Meh! I don't like this one, he is ugly.");
	printf("\nProfessor: Here, quick, take it and hide it, it's annoying me with it's dirty face");
	*(trainer+1)= *(starters2+res-1);		// get the pokemon in the array
	printf("\n\n (the way %s stares at you is annoying, you put him quickly in his pokeball)", (*(starters2+res-1)).name);
	printf("\n\n\n *%s joined your team* ",(*(starters2+res-1)).name);
	printf("\n\n\nProfessor: Since you are only starting your journey, I recommend you travel to Route 1, there are always trainers, wild pokemons and pokemon health center");
	printf("\nProfessor: This is the perfect place for someone who wants to become a trainer at your level");
	printf("\nProfessor: I need to let you here, I have work to do, farewell %s", name);
	sleep(10);
	free(starters2);
}

void main_menu(int* pmenu, int* pplay)
{	// displaying the main menu of the game

	if(pmenu == NULL)	// the menu 
	{
		printf("\n\nerror, pmenu point to NULL in main_menu");
		exit(1);
	}
	if(*pmenu != 0)
	{
		printf("\n\nerror, *pmenu != 0 in main_menu");
		exit(1);
	}
	if(pplay == NULL) // if we are playing or not
	{
		printf("\n\nerror, pplay point to NULL in main_menu");
		exit(1);
	}
	if(*pplay != 1)
	{
		printf("\n\nerror, *pplay != 1 in main_menu");
		exit(1);
	}

	int not_valid; // to test the answers
	int good_type;
	int res; // to store the answers

	system("clear");
	printf("\n\n\n===============================================================================================");
	printf("\n\nYou are on the Rout 1 (the main menu).");		// choose the fight you want in the main menu
	do{
		not_valid = 0;
		printf("\nChoose what you want to do now");
		printf("\n\n 0: Quit the game   1: Fight another trainer   2: Fight a wild pokemon\n");
		good_type = scanf("%d",&res);
		if(good_type == 0 || (res!=0 && res != 1 && res!= 2)){
			not_valid = 1;
			printf("\n\n\nEnter 1, 2 or 0. Can't you read? or maybe those are too big numbers for you to know them?");
		}
	} while(not_valid);

	if(res == 0){ // stop the game
		*pplay = 0;
		exit(1);}
	else{	// change the menu
		*pmenu = res;}
}

void ChooseDiff(int* pdiff)
{	// choose the difficulty of the game

	if(pdiff == NULL)	//	the pointer to the difficulty, we want to change the difficulty before we start the fight
	{
		printf("\n\nerror in ChooseDiff, pdiff point to NULL");
		exit(1);
	}

	int good_type;
	int not_valid;			// to test the answers
	int res;		// to store the answers
	do{		//select the difficulty
		not_valid = 0;
		printf("\nChoose the difficulty of the fight");
		printf("\n\n 1: struggle on his allies   2: can target his allies   3: actually fight\n");
		good_type = scanf("%d",&res);
		if(good_type == 0 || (res != 1 && res!= 2 && res != 3)){
			not_valid = 1;
			printf("\nEnter 1, 2 or 3. There is no hidden difficulty, you are exhausting me.");
		}
	} while(not_valid);
	
	*pdiff = res; 	//change the difficulty
}

void StartFight(int menu, pokemon** foes, int nfoes, pokemon* allpkmns, int npkmns)
{// start the fight, print the introduction line and initialize the enemies

	if(menu!=1 && menu!=2)	// the menu, because depending of the menu we display a different first line
	{
		printf("\n\nerror in StartFight, menu !=1 && !=2");
		exit(1);
	}
	if(nfoes<=0)	// the number of pokemon an enemy have
	{
		printf("\n\nerror in StartFight, nfoes <= 0");
		exit(1);
	}
	else if(nfoes>6)	// the number of foes
	{
		printf("\n\nerror in StartFight, nfoes > 6");
		exit(1);
	}
	if(npkmns<=0)		// the number of pokemons there is in the array, so we can make a for loop to browse through it
	{
		printf("\n\nerror in StartFight, npkmns <= 0");
		exit(1);
	}
	if(foes == NULL)	// the pointer to the foes array
	{
		printf("foes point to NULL in StartFight");
		exit(1);
	}
	verifyPPkmn(allpkmns, npkmns, "StartFight"); // verify the array of the pkmns possible

	int i=0;
	int r;
	
	system("clear");
	printf("==================================================================================================================");
	*foes = malloc(nfoes * sizeof(pokemon)); // we create the array

	while(i<nfoes){ // Make the array of pokemons of the enemy randomly
		r = rand()%npkmns;
		*(*foes+i) = *(allpkmns + r);
		i++;
	}
	
	if(menu == 2){
		printf("\n\n\nPokemons are assaulting you!!!");
		printf("\n\nA wild %s and a wild %s are surrounding you\n", (**foes).name, (*(*foes+1)).name);
	}
	else if(menu == 1){
		printf("\n\n\nA wild trainer appear!");
		printf("\n\nHe throws a %s and a %s at you \n",  (**foes).name, (*(*foes+1)).name);
	}

}

void AddSpeed(pokemon** allies, int nallies, pokemon** foes, int nfoes)
{// Add the speed in the speed bar of every pokemon in fight

	if(nallies<=0)	// the number of pokemon the player have
	{
		printf("\n\nerror in AddSpeed, nallies <= 0");
		exit(1);
	}
	else if(nallies>6)	// the number of allies
	{
		printf("\n\nerror in AddSpeed, nallies > 6");
		exit(1);
	}
	if(nfoes<=0)	// the number of pokemon an enemy have
	{
		printf("\n\nerror in AddSpeed, nfoes <= 0");
		exit(1);
	}
	else if(nfoes>6)	// the number of foes
	{
		printf("\n\nerror in AddSpeed, nfoes > 6");
		exit(1);
	}
	if(allies == NULL)	// we need to have a pointer to array to change the variable in the array
	{
		printf("\n\nerror, allies point to NULL in AddSpeed");
		exit(1);
	}
	if(foes == NULL)
	{
		printf("\n\nerror, foes point to NULL in AddSpeed");
		exit(1);
	}
	verifyPPkmn(*allies, nallies, "AddSpeed"); // verify the array of the pokemon of the ally
	verifyPPkmn(*foes, nfoes, "AddSpeed"); // verify the array of the pokemon of the enemy

	if(nallies>2)	// if the number of pokemon is higher than 2, limit the number to 2
	{
		nallies = 2;	// because we addspeed to only the pokemon playing
	}
	if(nfoes>2)	// if the number of pokemon is higher than 2, limit the number to 2
	{
		nfoes = 2;	// because we addspeed to only the pokemon playing
	}


	sleep(2);
	for(int i = 0; i<nallies; i++)
	{
		if( !(IsKo(*(*allies+i))) )	// if the pokemon is not ko
		{

			if( !strcmp((*(*allies+i)).affected.name, "paralysie") )	// if the pokemon is affected by paralyze, his turn comes slower
			{
				(*(*allies+i)).spdbar = (*(*allies+i)).spdbar + ( ((*(*allies+i)).speed) *4 / 5) ;
			}

			else
			{
				(*(*allies+i)).spdbar = (*(*allies+i)).spdbar + (*(*allies+i)).speed;
			}
		}	
	}

	for(int i = 0; i<nfoes; i++)
	{
		if( !(IsKo(*(*foes+i))) )	// if the pokemon is not ko
			if( !strcmp((*(*foes+i)).affected.name, "paralysie") )	// if the pokemon is affected by paralyze, his turn comes slower
			{
				(*(*foes+i)).spdbar = (*(*foes+i)).spdbar + ( ((*(*foes+i)).speed) *4 / 5) ;
			}

			else
			{
				(*(*foes+i)).spdbar = (*(*foes+i)).spdbar + (*(*foes+i)).speed;
			}
	}

}

void Who_Turn(pokemon* allies, int nallies, pokemon* foes, int nfoes, pokemon*** list_turn, int* pnbr_vit)
{	// make the list_turn, the array of who play in the right order (in this turn)

	// we verify every parameter 
	if(nallies<=0)	// the number of pokemon the player possess
	{
		printf("\n\nerror in Who_Turn, nallies <= 0");
		exit(1);
	}
	else if(nallies>6)	// every trainer is limited to 6 pokemon 
	{
		printf("\n\nerror in Who_Turn, nallies > 6");
		exit(1);
	}

	if(nfoes<=0)	// the number of pokemon the enemy possess
	{
		printf("\n\nerror in Who_Turn, nfoes <= 0");
		exit(1);
	}
	else if(nfoes>6)	// every trainer is limited to 6 pokemon 
	{
		printf("\n\nerror in Who_Turn, nfoes > 6");
		exit(1);
	}

	verifyPPkmn(allies, nallies, "Who_Turn"); // verify the array of the pokemon of the ally
	verifyPPkmn(foes, nfoes, "Who_Turn"); // verify the array of the pokemon of the enemy

	if(list_turn == NULL)	// the array of the address of the pokemon, so we know which pokemon is playing this loop (sorted by speedbar in decreasing order)
	{	// in this function, list_turn is a pointer to the array of address
		printf("\n\nerror in Who_Turn, list_turn point to NULL");
		exit(1);
	}
	if(*list_turn == NULL)	// the array of the address of the pokemon, so we know which pokemon is playing this loop (sorted by speedbar in decreasing order)
	{	// is empty in the start of the function
		printf("\n\nerror in Who_Turn, *list_turn point to NULL");
		exit(1);
	}
	if(pnbr_vit == NULL)	// pointer to the number of pokemon playing this turn (because we need it outside the function)
	{
		printf("\n\nerror in Who_Turn, pnbr_vit point to NULL");
		exit(1);
	}


	int i,na,nb;
	pokemon a;
	pokemon* pa= &a;
	pokemon** list_turn_ally = &pa; // arrays of address if pokemons who can play on this turn (ally side)
	pokemon f;
	pokemon* pf = &f;
	pokemon** list_turn_foe = &pf;	// (enemy side)
	int nbr_vit_ally, nbr_vit_foe, nbr_vit; // number of ally and foe who fulfill their bar of speed
	int count = 0;

	nbr_vit_ally = 0;	// first we count the number of pokemon which need to play their turn, in order to allocate the memory for the list
	nbr_vit_foe = 0;

	if(nallies > 2)	// we count only the pokemons in fight, so we set the length to 2 as max
	{
		nallies = 2;
	}
	if(nfoes > 2)
	{
		nfoes = 2;
	}

	for(i = 0; i<nallies; i++)
	{
		if( (*(allies+i)).spdbar >= BAR && IsKo(*(allies+i)) == 0)
		{
			nbr_vit_ally++;	// count the number of allies above the BAR value and able to fight
		}
	}

	for(i = 0; i<nfoes; i++)
	{
		if( (*(foes+i)).spdbar >= BAR && IsKo(*(foes+i)) == 0)	
		{
			nbr_vit_foe++; // count the number of enemies above the BAR value and able to fight
		}
	}

	*pnbr_vit = nbr_vit_ally + nbr_vit_foe; // count the number of pokemons fighting above the BAR value
	if(*pnbr_vit != 0)
	{ // if there is someone who can play on this turn
		
		*list_turn = malloc( (*pnbr_vit) * sizeof(pokemon*) );

		list_turn_ally = MaxVit(&allies, nallies, nbr_vit_ally);	// and we make the lists, in descending order
		list_turn_foe = MaxVit(&foes, nfoes, nbr_vit_foe);		// this function doesn't take in count the pokemons which are ko

		na = 0;
		nb = 0;	
		
		while(count != *pnbr_vit) // now we compare the 2 arrays and make an array sorted by the order of who is playing
		{
			if((na<nbr_vit_ally) && ((**(list_turn_ally+na)).spdbar >= (**(list_turn_foe+nb)).spdbar))
			{
				*(*list_turn+count) = *(list_turn_ally+na);
				/*(**(*list_turn+count)).name = malloc( (strlen((**(list_turn_ally+na)).name) + 1) * sizeof(char));
				strcpy( (**(*list_turn+count)).name, (**(list_turn_ally+na)).name );*/
				na++;
			}
			else
			{
				*(*list_turn+count) = *(list_turn_foe+nb);
				/*(**(*list_turn+count)).name = malloc( (strlen((**(list_turn_foe+nb)).name) + 1) * sizeof(char));
				strcpy( (**(*list_turn+count)).name, (**(list_turn_foe+nb)).name );*/
				nb++;
			}
			count++;
			
		}
		
		/*FreeNames(list_turn_foe, nbr_vit_foe);		
		FreeNames(list_turn_ally, nbr_vit_ally);
		free(list_turn_ally);
		free(list_turn_foe);*/
	}
}

void Morphing(pokemon* ppkmn, pokemon* ptarget)
{// the ability the metamorph use, he become a perfect copy of the target
	verifyPPkmn(ppkmn, 1, "Morphing");	// the pointer to the pokemon using the ability
	verifyPPkmn(ptarget, 1, "Morphing");	// the pointer to the target (because i'm too lazy to change it to a non pointer)
	*ppkmn = *ptarget;
	(*ppkmn).name = "(metamorph) ";

	strcat((*ppkmn).name, (*ptarget).name);
}

void Attack(pokemon* pkmn, ability* patk, pokemon* ptarget, pokemon* array, int narray)	
{// do everything an attack imply, (the damage, selfdamge, targets, the pp decrease...)

	if(pkmn == NULL){	// the pointer to the pokemon doing the attack
		printf("\n\nerror in Attack pkmn point to NULL");
		exit(1);
	}
	verifyPkmn(*pkmn, "Attack");	// verify the pokemon struct of the pokemon doig the attack

	if(patk == NULL){	// the pointer to the ability used
		printf("\n\nerror in Attack patk point to NULL");
		exit(1);
	}
	verifyAbility(*patk, "Attack");		// verify the ability struct of the attack

	if(ptarget == NULL){	// the pointer to the target
		printf("\n\nerror in Attack ptarget point to NULL");
		exit(1);
	}

	verifyPkmn(*ptarget, "Attack");		// verify the pokemon struct of the getting attacked

	if(narray <= 0){	// the number of pokemon in the array
		printf("\n\nerror narray in NumberPokemons is <=0");
		exit(1);
	}
	else if(narray > 6){	
		printf("\n\nerror narray in NumberPokemons is >6");
		exit(1);
	}

	verifyPPkmn(array, narray, "Attack");	// the array of the enemies of pkmn (if the  ability affect all we need to have the whole array)

	

	int dmg;	// damage to inflict
	int n;		// number of enemy (from pkmn point of view) currently in the fight
	int r;
	int hpmax; // apparently, we need to store the hpmax in a variable
	printf("\n\n%s use %s", pkmn->name, patk->name); // the feedback of the ability used on who

	if((*patk).name != "struggle"){
			(*patk).pp--; 
	// the ability is used one time so we remove one use on it (if it's not the default attack) (pp stands for power points, it's the number of time an ability can be used)
	}

	if(patk->name == "morphing")	// if the pokemon is a ditto (metamorph), he can use morphing but it's not treated the same way as another attack
	{
		Morphing(pkmn, ptarget);	// so we use the function
	}

	else
	{
		if(patk->effect.name != "aucun")
		{
			r = rand()%101;
			if(r<= patk->peffect)
			{
				ptarget->affected = patk->effect;
			}

		}

		if((*patk).spd_atk == 1)	// we implemented attack that set the speed bar to a certain value instead of priority atk like quick attack (vive-attaque)
		{
			(*pkmn).spdbar == BAR/4;
		}
		else if((*patk).spd_atk == 2)
		{
			(*pkmn).spdbar == BAR/2;	
		}

		if((*patk).affectall)	//	inflict damage to every foes	
		{
			n = NumberPokemons(array, narray); // get the number of pokemons currently fighting, so if there is only one left, it doesn't attack 2
			for(int i = 0; i<n; i++)	// the active foes are always on the fist 2 positions of the foes array
			{
				dmg = CalculateDmg(*patk, *(array+i));

				if(dmg>4)	// display the damage and the situation of the targets and inflicts the damage (if the there is damage)
				{
					(*(array+i)).hp = (*(array+i)).hp - dmg;
					printf("\n\n%s took %d damage", (*(array+i)).name, dmg);
					if( IsKo( *(array+i)) == 0)
					{ 
						printf("\n%s : %d / %d", (*(array+i)).name, (*(array+i)).hp, (*(array+i)).hpmax);
					}
					else if( IsKo( *(array+i)) == 1)
					{ 
						printf("\n%s is K.O.", (*(array+i)).name);
					}
				}
			}
		}
		else	// inflict damage only to the target
		{		
			dmg = CalculateDmg(*patk, *ptarget);
			(*ptarget).hp = (*ptarget).hp - dmg;

			if(dmg>0) // display the damage and the situation of the target
			{
				printf("\n\n%s took %d damage", (*ptarget).name, dmg);
				if( IsKo(*ptarget) == 0)
				{ 
					printf("\n%s	HP : %d / %d", (*ptarget).name, (*ptarget).hp, (*ptarget).hpmax);
				}
				else if( IsKo(*ptarget) == 1)
				{ 
					printf("\n%s is K.O.", (*ptarget).name);
				}
			}
		}
		

		hpmax = (*pkmn).hpmax;
		(*pkmn).hp = (*pkmn).hp - (hpmax * (*patk).selfdmg / 100);	// apply the self dmg of the abilty (most of the time there is none)
		(*pkmn).hpmax = hpmax;	// for some reason we need to do this because it change the value of hpmax otherwise

		if( (*patk).selfdmg > 0 ) // if the pokemon took dmg of the attack
		{
			printf("\n\n%s is hit with recoil!", (*pkmn).name);	// that is the real line in pokemon
		}
		else if((*patk).selfdmg < 0) // if the pokemon healed
		{
			printf("\n\n%s healed!", (*pkmn).name);
		}
		if( (*pkmn).hp > (*pkmn).hpmax)	
		{	// the pokemon health points shouldn't go higher than the max so if it does, we fix it to the max
			(*pkmn).hp = (*pkmn).hpmax;
		}
	}

}

void SelectAbilities(pokemon* pkmn, pokemon* foes, int nfoes, ability* allablts, int nabilities, int* pres)
{	// Let the player choose an ability and a target

	if(pkmn == NULL){	// the pointer to the pokemon attacking	
		printf("\n\nerror in SelectAbilities pkmn point to NULL");
		exit(1);
	}
	verifyPkmn(*pkmn, "SelectAbilities");
	if(nfoes <= 0){
		printf("\n\nerror nfoes in SelectAbilities is <= 0");
		exit(1);
	}
	if(nfoes > 6){
		printf("\n\nerror nfoes in SelectAbilities is > 6");
		exit(1);
	}
	verifyPPkmn(foes, nfoes, "SelectAbilities");
	if(nabilities <= 0){	// the pointer to the pokemon attacking
		printf("\n\nerror in SelectAbilities nabilities <= 0");
		exit(1);
	}
	verifyPAbility(allablts, nabilities, "SelectAbilities");
	if(pres == NULL){
		printf("\n\nerror in SelectAbilities pres point to NULL");
		exit(1);
	}if(*pres > 4 && *pres < 0)
	{
		printf("\n\nerror in SelectAbilities *pres > 4 && *pres < 0");
		exit(1);
	}


	int not_valid;
	int good_type;

	ability atk; // if the player choose struggle (the default attack) we need to store it somewhere
	ability* patk; // pointer to the ability in the pokemon moveset
	char* pstruggle = "struggle"; // the string struggle because seekabiliy take a char* as an argument
	pokemon* ptarget; // pointer to the target
	ability* pk_ab = (*pkmn).current_abilities;

	do{	// Select your ability
		not_valid = 0;

		printf("\n0: Back\n");	// display the abilities
		for(int i = 0; i < 4; i++)
		{
			if( strcmp((*(pk_ab+i)).name, "aucune") )	// if the ability is not none, display it
			{
				printf("%d:   ",i+1);
				PrintfType( (*(pk_ab+i)).type, (*(pk_ab+i)).name);
				printf("	PP: %d/%d	Type: ", (*(pk_ab+i)).pp, (*(pk_ab+i)).ppmax);
				PrintfType((*(pk_ab+i)).type, (*(pk_ab+i)).type);	
				// print the name of the abilities
	
				if( (*(pk_ab+i)).affectall == 1)
				{
					printf("	Affect every opponents");
				}	
			}	
			printf("\n");	
		}
		printf("5:   struggle\n\n");


		good_type = scanf("%d", pres);
		if(*pres != 5)
		{
			if(good_type == 0 || (*pres != 0 && *pres != 1 && *pres!= 2 && *pres != 3 && *pres != 4) || ((*(((*pkmn).current_abilities)+(*pres) -1)).name == "aucune") )
			{	
			// select the ability
			not_valid = 1;
			printf("\n You are in a fight.... COME ON enter a valid value");
			}
		}
		if(*pres != 0)
		{
			if(*pres!=5)	// we verify if the ability is valid
			{
				if((*(((*pkmn).current_abilities)+(*pres) -1)).pp==0) 
				{
					not_valid = 0;
					printf("\n This ability is out of pp, choose another one");
				}
				else if(!strcmp((*(pk_ab+(*pres-1))).name, "aucune") )
				{
					not_valid = 0;
					printf("\n This slot of ability is empty, pls choose another one");
				}
			}
		}
	} while(not_valid);

	if(*pres!=0)
	{
		if(*pres == 5)	// if the player choosed the default ability select it
		{
			patk = &atk;
			*patk = *(SeekAbility(pstruggle , allablts, nabilities));		
		}
		else
		{
			patk =  ((*pkmn).current_abilities+(*pres) -1);
		}
		if(!((*patk).affectall)){
			do{	// Then the player select the target if the ability doesn't affect everybody
				not_valid = 0;
				printf("\n0: Back   ");
				for(int i = 0; i < 2; i++)
				{
					printf("%d: ", i+1);
					PrintfType( (*(*(foes+1)).type).name,  (*(foes+1)).name);
					printf("	  ");
					
				}
				printf("\n\n");
				good_type = scanf("%d", pres);
				if(good_type == 0 || (*pres!=0 &&*pres != 1 && *pres!= 2)){	// Select the target
					not_valid = 1;
					printf("\n You are in a fight.... COME ON enter a valid value\n\n");
				}
				else if(IsKo(*(foes+(*pres)-1)) )
				{
					not_valid = 1;
					printf("\n You want to kill him? He is already ko... You are the good guy? Remember?\n\n");
				}
			} while(not_valid);
			if(*pres!=0){
				ptarget = (foes+(*pres)-1);
			}
		}

	}

	if(*pres != 0){
		Attack(pkmn, patk, ptarget, foes, nfoes);
	}
}


void SelectPokemon(pokemon* pkmn, pokemon* array, int narray, int* pres)
{// Let the player choose the pokemon he is switching with the current playing

	if(pkmn == NULL){	// the pointer to the pokemon whis is being swicthed
		printf("\n\nerror in SelectPokemon pkmn point to NULL");
		exit(1);
	}
	verifyPkmn(*pkmn, "SelectPokemon");
	if(narray <= 0){	// the length of the array
		printf("\n\nerror narray in SelectPokemon is <0");
		exit(1);
	}
	if(narray > 6){
		printf("\n\nerror narray in SelectPokemon is <0");
		exit(1);
	}
	verifyPPkmn(array, narray, "SelectPokemon");	// verify the array the player can select
	if(pres == NULL){	// the pointer to the inputs of the player (if it's 0 we need to loop again outside the function)
		printf("\n\nerror in SelectPokemon pres point to NULL");
		exit(1);
	}
	if(*pres > narray && *pres < 0)
	{
		printf("\n\nerror in SelectPokemon *pres > narray && *pres < 0");
		exit(1);
	}


	int not_valid;
	int good_type=0;
	int i;
	int* idxs = calloc(narray+1, sizeof(int)); // that way we have an array of idxs which are valid since 0 is a valid value
	int right = 0;

	do{	// Select the pokemon you are switching with
		not_valid = 0;
		printf("\n You want to switch %s with: \n\n", (*pkmn).name);
		printf("0: Back  ");
		
		for(i = 2; i<narray; i++){	// i = 2 because you can't switch with the current pokemons
			if( !(IsKo(*(array+i))) ){	// if the pokemon is not dead make it an option
				printf("%d : %s		", i+1, (array+i)->name);
				*(idxs+i) = i+1;
			}
		}
		printf("\n\n");
		good_type = scanf("%d", pres);

		if(*pres != 0)
		{
			for(i = 0; i<narray; i++)
			{
				if(good_type == 1 && *pres == *(idxs+i)){		// verify if the input is a valid number
					right = 1;
				}
			}
			if(good_type == 0 || right == 0)
			{
					not_valid = 1;
					printf("\n -_- You are in a fight.... COME ON enter a valid value!");
			}
		}
	} while(not_valid);
	free(idxs);

}

void SwitchPokemon(pokemon* pkmn, pokemon* array, int narray, int* pres)
{ // Switch the pokemon selected with the one current playing
	if(pkmn == NULL){	// the pointer to the pokemon whis is being swicthed
		printf("\n\nerror in SwitchPokemon pkmn point to NULL");
		exit(1);
	}
	verifyPkmn(*pkmn, "SwitchPokemon");
	if(narray <= 0){	// the length of the array
		printf("\n\nerror narray in SwitchPokemon is <0");
		exit(1);
	}
	if(narray > 6){
		printf("\n\nerror narray in SwitchPokemon is <0");
		exit(1);
	}
	verifyPPkmn(array, narray, "SwitchPokemon");	// verify the array of the team where the pkmn belongs to
	if(pres == NULL){	// the pointer to the inputs of the player (if it's 0 we need to loop again outside the function)
		printf("\n\nerror in SwitchPokemon pres point to NULL");
		exit(1);
	}
	if(*pres > narray && *pres < 0)
	{
		printf("\n\nerror in SwitchPokemon *pres > narray && *pres < 0");
		exit(1);
	}

	pokemon tmp;
	pokemon* new_current = (array+(*pres)-1);

	printf("\n\n%s is replaced by %s", (*pkmn).name, (*new_current).name);

	if(*pres > 0){
		tmp = *pkmn;	// switching the pokemons
		*pkmn = *new_current;
		*new_current = tmp;
	}
}

void SwitchEnemy(pokemon* foes, int nfoes)
{	// switch the pokemon which are ko and in fight with the ones which are not ko and not in fight

	if(nfoes <= 0){	// the length of the array
		printf("\n\nerror nfoes in SwitchEnemy is <0");
		exit(1);
	}
	if(nfoes > 6){
		printf("\n\nerror nfoes in SwitchEnemy is <0");
		exit(1);
	}
	verifyPPkmn(foes, nfoes, "SwitchEnemy");

	for(int i =0; i<nfoes; i++)	// reset the spdbar of the pokemons which are ko
	{
		if( IsKo(*(foes+i)) )
		{
			(*(foes+i)).spdbar = 0;
		}
	}

	int a = 2;
	int* pa = &a;

	if( IsKo(*foes) && nfoes>2 )	// switch pokemon 1 of enemmy if is ko
	{
		printf("\n\n%s is K.O.", (*foes).name);
		while( IsKo(*(foes + a)) && a<nfoes )	// we increment a until we found a pokemon able to fight (or we don't)
		{
			a++;
		}

		if(a<nfoes){	// if there is a pokemon able to fight switch
			a++;		// we increment a because it need to fit the SwitchPokemon calculus
			SwitchPokemon(foes, foes, nfoes, pa);}
	}

	a=2;
	if( IsKo(*(foes+1)) && nfoes>2 ) // switch pokemon 2 of enemmy if is ko
	{
		printf("\n\n%s is K.O.", (*(foes+1)).name);
		while( IsKo(*(foes + a)) && a<nfoes )	// we increment a until we found a pokemon able to fight (or we don't)
		{
			a++;
		}

		if(a<nfoes){	// if there is a pokemon able to fight switch
			a++;		// we increment a because it need to fit the SwitchPokemon calculus
			SwitchPokemon( (foes+1) , foes, nfoes, pa);}
	}

}


void SwitchAlly(pokemon* allies, int nallies, int* pres)
{	// The only difference with SwitchEnemy is that we let the player choose who to switch with (so we don't pass pa in Switchpokemon but pres)

	
	if(nallies <= 0){	// the length of the array
		printf("\n\nerror nallies in SwitchAlly is <=0");
		exit(1);
	}
	if(nallies > 6){
		printf("\n\nerror nallies in SwitchAlly is >6");
		exit(1);
	}
	verifyPPkmn(allies, nallies, "SwitchAlly");
	if(pres == NULL){	// the pointer to the inputs of the player (if it's 0 we need to loop again outside the function)
		printf("\n\nerror in SwitchAlly pres point to NULL");
		exit(1);
	}

	int a = 2;

	for(int i =0; i<nallies; i++)	// reset the spdbar of the pokemons which are ko
	{
		if( IsKo(*(allies+i)) == 1 )
		{
			(*(allies+i)).spdbar = 0;
		}
	}

	if( IsKo(*allies) == 1 && nallies>2 )	// verify if the 1st pokemon in fight is KO and if there is other pokemons which are able to fight
	{
		printf("\n\n%s is K.O", (*allies).name);
		while( IsKo(*(allies + a)) == 1 && a<nallies )	// we increment a until we found a pokemon able to fight (unless there is none)
		{
			a++;
		}

		if(a<nallies){	// if there is a pokemon able to fight make the player select who to switch with
			do{
				SelectPokemon( allies, allies, nallies, pres);
				if(*pres == 0)
				{
					printf("\n\nChoose a pokemon........");
				}
			} while(*pres == 0); // the player can't go back in the turn menu it doesn't make any sense otherwise
			SwitchPokemon( allies, allies, nallies, pres);
		}
	}

	a=2;

	if( IsKo(*(allies+1)) == 1 && nallies>2)	// verify if the 2nd pokemon in fight is KO and if there is other pokemons which are able to fight
	{
		printf("\n\n%s is K.O", (*(allies+1)).name);
		while( IsKo(*(allies + a)) == 1 && a<nallies )	// we increment a until we found a pokemon able to fight (unless there is none)
		{
			a++;
		}

		if(a<nallies){	// if there is a pokemon able to fight make the player select who to switch with
			do{
				SelectPokemon( (allies+1), allies, nallies, pres);
				if(*pres == 0)
				{
					printf("\n\nChoose a pokemon........");
				}
			} while(*pres == 0); // the player can't go back in the turn menu it doesn't make any sense otherwise
			SwitchPokemon( (allies+1), allies, nallies, pres);
		}
	}
}




void AddPokemon(pokemon* allies, int* pnallies, pokemon* ptarget)
{	// add the pokemon in the allies array
	if(pnallies == NULL){	// the pointer to the number of allies
		printf("\n\nerror in AddPokemon pnallies point to NULL");
		exit(1);
	}
	if(*pnallies > 6 || *pnallies <= 0){	// the pointer to the number of allies
		printf("\n\nerror in AddPokemon *pnallies > 6 || *pnallies <= 0");
		exit(1);
	}
	verifyPPkmn(allies, *pnallies, "AddPokemon");

	if(*pnallies<6)	// add the pokemon if the team is not full
	{
		printf("\n\n%s is now part of your team!!", (*ptarget).name);
		*(allies+(*pnallies)) = *ptarget;
		(*ptarget).hp = 0;
		printf("hpmax de %s : %d", (*ptarget).name, (*ptarget).hpmax);
		(*pnallies)++;
	}
	else
	{
		printf("\n\nBut you can't carry more pokemons...");

		printf("\n\nYou throw the %s in the trash can", (*ptarget).name);
	}
}

void Catch(pokemon* foes, pokemon* allies, int* pnallies, int* pres)
{	// try to catch the pokemon if the team is not full already
	
	verifyPPkmn(foes, 2, "Catch");
	if(allies == NULL){	// the array of the team where the pkmn belongs to
		printf("\n\nerror in Catch allies point to NULL");
		exit(1);
	}
	if(pnallies == NULL){	// the pointer to the number of allies
		printf("\n\nerror in Catch pnallies point to NULL");
		exit(1);
	}
	if(*pnallies > 6 || *pnallies <= 0){	// the pointer to the number of allies
		printf("\n\nerror in Catch *pnallies > 6 || *pnallies <= 0");
		exit(1);
	}
	verifyPPkmn(allies, *pnallies, "Catch");
	if(pres == NULL){	// the pointer to the inputs of the player (if it's 0 we need to loop again outside the function)
		printf("\n\nerror in Catch pres point to NULL");
		exit(1);
	}

	int not_valid;
	int good_type=0;
	int r;
	pokemon* ptarget;

	if(*pnallies<6)	// you can't catch a pokemon if your team is already full
	{

		do{	// Select your target
			not_valid = 0;
			printf("\nWho do you want to throw your ball to?");
			printf("\n0: Back   ");
			for(int i = 0; i < 2; i++)
			{
				printf("%d: ", i+1);
				PrintfType( (*(*(foes+1)).type).name,  (*(foes+1)).name);
				printf("			");
				
			}
			printf("\n\n");	
			good_type = scanf("%d", pres);
			if(good_type == 0 || (*pres!=0 && *pres != 1 && *pres!= 2))
			{
				not_valid = 1;
				printf("\n -_- You are in a fight.... COME ON enter a valid value!");
			}
		} while(not_valid);
		if(*pres != 0)
		{
			ptarget = foes + *pres -1;

			r = rand() % 101;
			printf("You throw used a pokeball on %s!", (*ptarget).name);
			sleep(1);
			if(r<=(*ptarget).capt)
			{
				printf("\n\nGotcha!");
				AddPokemon(allies, pnallies, ptarget);
				 
			}
			else
			{
				printf("\n\n%s escaped!", (*ptarget).name);
			}
		}
	}
}

void DisplayFight(int nallies, pokemon* allies, int nfoes, pokemon* foes, pokemon** list_turn, int nbr, char* trainer)
{	// display the situation of the fight for the player

	if(nallies <= 0){	// the length of the array
		printf("\n\nerror nallies in DisplayFight is <=0");
		exit(1);
	}
	if(nallies > 6){
		printf("\n\nerror nallies in DisplayFight is >6");
		exit(1);
	}
	verifyPPkmn(allies, nallies, "DisplayFight");
	if(nfoes <= 0){	// the length of the array
		printf("\n\nerror nfoes in DisplayFight is <0");
		exit(1);
	}
	if(nfoes > 6){
		printf("\n\nerror nfoes in DisplayFight is <0");
		exit(1);
	}
	verifyPPkmn(foes, nfoes, "DisplayFight");
	if(nbr < 0){	// the length of the array
		printf("\n\nerror nbr in DisplayFight is <0");
		exit(1);
	}

	char* sta = malloc(4*sizeof(char));	
	pokemon pkmn;
	if(nfoes>2)
	{
		nfoes = 2;
	}
	if(nallies>2)	// we want to display only the pokemons in fight
	{
		nallies = 2;
	}
	

	if(nbr>0)
	{
		printf("\n\n\nThe next pokemons playing this turn are :");
		for(int i = 0; i<nbr-1; i++)
		{
			printf(" %s,", (**(list_turn+i)).name);
		}
		printf(" %s\n\n", (**(list_turn+(nbr-1))).name);
	}	
	
	printf("_________________________________________________________________________________________________________________________________________________________________________");
	printf("\n¤Enemies : ");
	pkmn = *foes;
	printf("		");
	PrintfType((*pkmn.type).name, pkmn.name);
	if(pkmn.hp > 0)
	{
		printf("  PV : %d/%d", pkmn.hp, pkmn.hpmax);
	}
	else
	{
		printf("  KO!   ");
	}
	printf("  	BAR : %d/%d", pkmn.spdbar, BAR);
	printf("\n");
	for(int i = 1; i < nfoes; i++)	// display the foes
	{
		pkmn = *(foes+i);
		printf("		");
		PrintfType((*pkmn.type).name, pkmn.name);
		if(pkmn.hp > 0)
		{
			printf("  PV : %d/%d", pkmn.hp, pkmn.hpmax);
			printf("  	BAR : %d/%d", pkmn.spdbar, BAR);
		}
		else
		{
			printf("  KO!   ");
		}
		if(pkmn.affected.name != "aucun")
		{
			*sta =  pkmn.affected.name[0];
			*(sta+1) = pkmn.affected.name[1];
			*(sta+2) = pkmn.affected.name[2];
			*(sta+3) = '\0';
			printf(" 	");
			PrintfStatus(sta);
		}
		printf("\n");
	}

	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n¤(You) %s 's pokemons : ", trainer);
	pkmn = *allies;
	printf("	");
	PrintfType((*pkmn.type).name, pkmn.name);
	if(pkmn.hp > 0)
	{
		printf("  PV : %d/%d", pkmn.hp, pkmn.hpmax);
		printf("  	BAR : %d/%d", pkmn.spdbar, BAR);
	}
	else
	{
		printf("  KO!   ");
	}
	printf("\n");
	for(int i = 1; i < nallies; i++)	// display the allies
	{
		pkmn = *(allies+i);
		printf("	");
		PrintfType((*pkmn.type).name, pkmn.name);
		if(pkmn.hp > 0)
		{
			printf("  PV : %d/%d", pkmn.hp, pkmn.hpmax);
		}
		else
		{
			printf("  KO!   ");
		}
		printf("  	BAR : %d/%d", pkmn.spdbar, BAR);
		if(pkmn.affected.name != "aucun")
		{
			*sta =  pkmn.affected.name[0];
			*(sta+1) = pkmn.affected.name[1];
			*(sta+2) = pkmn.affected.name[2];
			printf(" 	%s", sta);
		}
		printf("\n");
	}
	printf("_________________________________________________________________________________________________________________________________________________________________________\n");
	free(sta);
}	


void YourTurn(int menu , pokemon* pkmn, pokemon* allies, int* pnallies, pokemon* foes, int nfoes, ability* allablts, int nablts, int* pres, int status, pokemon** list_turn, int nbr_vit, char* trainer)
{	// let the player choose what he want to do in when 1 of his pokemon is playing

	// we verify every parameter 
	if(menu!=1 && menu!=2)	// the menu, because depending of the menu we wan catch or not pokemon
	{
		printf("\n\nerror in YourTurn, menu !=1 && !=2");
		exit(1);
	}
	if(pkmn == NULL)	// the pokemon playing the turn
	{
		printf("\n\nerror in YourTurn, pkmn point to NULL");
		exit(1);
	}
	verifyPkmn(*pkmn, "YourTurn");
	
	if(pnallies == NULL)	// the pointer to the number of pokemons the player possess, because we need to increase it if he catch a new pokemon
	{
		printf("\n\nerror in YourTurn, pnallies point to NULL");
		exit(1);
	}
	if(*pnallies <= 0)	// the pointer to the number of pokemons the player possess, because we need to increase it if he catch a new pokemon
	{
		printf("\n\nerror in YourTurn, *pnallies <= 0");
		exit(1);
	}
	if(*pnallies > 6)	// the pointer to the number of pokemons the player possess, because we need to increase it if he catch a new pokemon
	{
		printf("\n\nerror in YourTurn, *pnallies > 6");
		exit(1);
	}

	verifyPPkmn(allies, *pnallies, "YourTurn"); // the array of every pokemon the player possess

	if(nfoes<=0)	// the number of pokemon the enemy possess
	{
		printf("\n\nerror in YourTurn, nfoes <= 0");
		exit(1);
	}
	else if(nfoes>6)	// every trainer is limited to 6 pokemon 
	{
		printf("\n\nerror in YourTurn, nfoes > 6");
		exit(1);
	}
	verifyPPkmn(foes, nfoes, "YourTurn");	// the array of every enemy pokemon

	if(nablts<=0)	// the number of abilities so we can travel through abilities if needed
	{
		printf("\n\nerror in YourTurn, nablts <= 0");
		exit(1);
	}
	verifyPAbility(allablts, nablts, "YourTurn");	// the array of every possible ability

	if(pres == NULL){
		printf("\n\nerror in YourTurn pres point to NULL");
		exit(1);
	}
	if(status!=1 && status!=2 && status!=0 && status!=-1){
		printf("\n\nerror in YourTurn, status isn't valid.");
		printf("\n %s  status %d  hp %d hpmax %d ", (*pkmn).name, status, (*pkmn).hp, (*pkmn).hpmax);
		exit(1);
	}
	if(list_turn == NULL){
		printf("\n\nerror in YourTurn, list_turn point to NULL");
		exit(1);
	}
	if(nbr_vit<0){
		printf("\n\nerror in YourTurn, nbr_vit < 0");
		exit(1);
	}


	int not_valid;
	int good_type=0;
	
	DisplayFight(*pnallies, allies, nfoes, foes, list_turn, nbr_vit, trainer);			// we display the state of the fight to the player

	if(status == 0)	// no particular effect on the turn
	{

		do{	// Select your actions
			printf("\n the pokemon playing is %s\n", (*pkmn).name);
			not_valid = 0;
			printf("\n1: Abilities	  2: Switch pokemon	   3: Throw a pokeball\n\n");	// ability, Switch pokemon, throw a ball
			good_type = scanf("%d", pres);
			if(menu == 2)
			{
				if(good_type == 0 || (*pres != 1 && *pres!= 2 && *pres != 3))
				{
					not_valid = 1;
					printf("\n -_- You are in a fight.... COME ON enter a valid value!");
				}
			}
			else{
				if(*pres == 3)
				{
					not_valid = 1;
					printf("\nYou can't catch a pokemon of a trainer, you are supposed to be the good guy remember?");
				}
				else if(good_type == 0 || (*pres != 1 && *pres!= 2)){
					not_valid = 1;
					printf("\n -_- You are in a fight.... COME ON enter a valid value!");
				}
			}
		} while(not_valid);

		if(*pres == 1)	// if the player choosed the abilities, let him choose the ability	and the target
		{

			SelectAbilities(pkmn, foes, nfoes, allablts, nablts, pres);
		}

		else if(*pres == 2) // if the player choosed the switch pokemon option, let him choose the pokemon which will switch
		{
			SelectPokemon(pkmn, allies, *pnallies, pres);
			if(*pres!=0)
			{
				SwitchPokemon(pkmn, allies, *pnallies, pres);
			}
		}


		else if(*pres == 3)	// throw a pokeball
		{
			if(menu == 2 && *pnallies < 6)
			{
				
					Catch(foes, allies, pnallies, pres);
			}
			else if(*pnallies >= 6)
			{
				printf("\nYou can't have more than 6 pokemons");
				*pres = 0;
			}
			else
			{
				printf("\nYou can't catch a pokemon of a trainer, you are supposed to be the good guy remember?");
				*pres = 0;
			}

		}

	}


	else if(status == 2)	// if the pokemon is confused
	{
		printf("\n\n%s is confused...", (*pkmn).name);
		VeryEasy(pkmn ,allies, *pnallies, foes, nfoes, allablts, nablts);
	}

}

void VeryEasy(pokemon* pkmn, pokemon* foes, int nfoes, pokemon* allies, int nallies, ability* allablts, int nabilities)
{	// the easiest difficulty, the enemy alwayse use the worst ability and can target everibody

	// we verify every parameter 
	if(pkmn == NULL)	// the pokemon playing the turn
	{
		printf("\n\nerror in VeryEasy, pkmn point to NULL");
		exit(1);
	}
	if(nfoes<=0)	// the number of pokemon the enemy possess
	{
		printf("\n\nerror in VeryEasy, nfoes <= 0");
		exit(1);
	}
	else if(nfoes>6)	// every trainer is limited to 6 pokemon 
	{
		printf("\n\nerror in VeryEasy, nfoes > 6");
		exit(1);
	}
	if(nallies<=0)	// the number of pokemon the player possess
	{
		printf("\n\nerror in VeryEasy, nallies <= 0");
		exit(1);
	}
	else if(nallies>6)	// every trainer is limited to 6 pokemon 
	{
		printf("\n\nerror in VeryEasy, nallies > 6");
		exit(1);
	}

	if(nabilities<=0)	// the number of abilities so we can travel through abilities if needed
	{
		printf("\n\nerror in VeryEasy, nabilities <= 0");
		exit(1);
	}
	verifyPkmn(*pkmn, "VeryEasy");
	verifyPPkmn(allies, nallies, "VeryEasy"); // the array of every pokemon the player possess
	verifyPPkmn(foes, nfoes, "VeryEasy"); // the array of every pokemon the player possess
	verifyPAbility(allablts, nabilities, "VeryEasy");	// the array of every possible ability

	// use struggle on a random target (can be himself), is used for the confusion status
	int side = rand()%2;
	int who = rand()%2;
	
	//ability
	pokemon* ptarget;	// random struggle (so the enemy only use the default ability)
	char* str = "struggle";	// the default attack
	ability* strug = SeekAbility(str, allablts, nabilities);

	//target
	if(side == 0){		// the pokemon can choose to target a dead pokemon because the enemies in this game are dumb (and sometimes the player too)
		ptarget = foes+who;}
	else{
		ptarget = allies+who;}

	Attack(pkmn, strug, ptarget, allies, nallies);

}

void Easy(pokemon* pkmn, pokemon* foes, int nfoes, pokemon* allies, int nallies, ability* allablts, int nabilities)
{	// the easy difficulty, the enemy choose an ability (other than struggle) but can target his allies

	// we verify every parameter 
	if(pkmn == NULL)	// the pokemon playing the turn
	{
		printf("\n\nerror in Easy, pkmn point to NULL");
		exit(1);
	}
	if(nfoes<=0)	// the number of pokemon the enemy possess
	{
		printf("\n\nerror in Easy, nfoes <= 0");
		exit(1);
	}
	else if(nfoes>6)	// every trainer is limited to 6 pokemon 
	{
		printf("\n\nerror in Easy, nfoes > 6");
		exit(1);
	}
	if(nallies<=0)	// the number of pokemon the player possess
	{
		printf("\n\nerror in Easy, nallies <= 0");
		exit(1);
	}
	else if(nallies>6)	// every trainer is limited to 6 pokemon 
	{
		printf("\n\nerror in Easy, nallies > 6");
		exit(1);
	}
	if(nabilities<=0)	// the number of abilities so we can travel through abilities if needed
	{
		printf("\n\nerror in Easy, nabilities <= 0");
		exit(1);
	}
	verifyPkmn(*pkmn, "Easy");
	verifyPPkmn(allies, nallies, "Easy"); // the array of every pokemon the player possess
	verifyPPkmn(foes, nfoes, "Easy"); // the array of every pokemon the player possess
	verifyPAbility(allablts, nabilities, "Easy");	// the array of every possible ability

	int side = rand()%2;
	int who = rand()%2;
	int rablt;	// random number ability
	char* str = "struggle"; // default attack
	int isoutpp = 0;
	pokemon* ptarget;	// select a random ability and a random target
	ability* patk;

	for(int i = 0; i<4;i++)	// we verify if the pokemon is not out of pp (and if there is an ability at i)
	{
		if( ( (*((*pkmn).current_abilities + i)).name == "aucune") || ((*((*pkmn).current_abilities + i)).pp == 0))
		{
			isoutpp++;
		}

	}

	// ability
	if(isoutpp != 4)	// if the pokemon is not out of pp in all abilities
	{
		do{	 // if (the pokemon use the default ability) or (doesn't have an ability in x, it can't use the xth ability (0<x<=4)) or  (if it 's out of pp)
			rablt = rand()%5;	// choose a random ability

		}while( ( (*((*pkmn).current_abilities + rablt)).name == "aucune") || ( (*((*pkmn).current_abilities + rablt)).pp == 0));
	}
	else	// if the pokemon is out of pp, let him use the default ability
	{
		rablt = 5;
	}

	// target
	if(side == 0){		//		the pokemon can choose to target a dead pokemon because the enemies in this game are dumb (and sometimes the player too)
		ptarget = foes+who;}
	else{
		ptarget = allies+who;}

	if(rablt == 5)	// if selected struggle
	{
		patk = SeekAbility(str, allablts, nabilities);
	}
	else	// if selected an ability
	{
		patk = (*pkmn).current_abilities+rablt;
	}

	Attack(pkmn, patk, ptarget, allies, nallies);
	
}


void Normal(pokemon* pkmn, pokemon* foes, int nfoes, pokemon* allies, int nallies, ability* allablts, int nabilities)
{	// the normal difficulty, the enemy choose an ability (other than struggle) and target the player
	// we verify every parameter 
	if(pkmn == NULL)	// the pokemon playing the turn
	{
		printf("\n\nerror in Normal, pkmn point to NULL");
		exit(1);
	}
	if(nfoes<=0)	// the number of pokemon the enemy possess
	{
		printf("\n\nerror in Normal, nfoes <= 0");
		exit(1);
	}
	else if(nfoes>6)	// every trainer is limited to 6 pokemon 
	{
		printf("\n\nerror in Normal, nfoes > 6");
		exit(1);
	}
	if(nallies<=0)	// the number of pokemon the player possess
	{
		printf("\n\nerror in Normal, nallies <= 0");
		exit(1);
	}
	else if(nallies>6)	// every trainer is limited to 6 pokemon 
	{
		printf("\n\nerror in Normal, nallies > 6");
		exit(1);
	}
	if(nabilities<=0)	// the number of abilities so we can travel through abilities if needed
	{
		printf("\n\nerror in Normal, nabilities <= 0");
		exit(1);
	}

	verifyPkmn(*pkmn, "Normal");
	verifyPPkmn(allies, nallies, "Normal"); // the array of every pokemon the player possess
	verifyPPkmn(foes, nfoes, "Normal"); // the array of every pokemon the player possess
	verifyPAbility(allablts, nabilities, "Normal");	// the array of every possible ability

	int rablt;
	char* str = "struggle"; // default attack
	int isoutpp = 0;
	pokemon* ptarget;	// select a random ability and the pokemon of the player with the less health points
	ability* patk;


	for(int i = 0; i<4;i++)	// we verify if the pokemon is not out of pp
	{
		if(((*((*pkmn).current_abilities + i)).name == "aucune") || ((*((*pkmn).current_abilities + i)).pp == 0))
		{
			isoutpp++;
		}
	}

	// ability
	if(isoutpp != 4)	// if the pokemon is not out of pp in all abilities
	{
		do{	 // if (the pokemon use the default ability) or (doesn't have an ability in x, it can't use the xth ability (0<x<=4)) or  (if it 's out of pp)
			rablt = rand()%5;

		}while(( (*((*pkmn).current_abilities + rablt)).name == "aucune") || ( (*((*pkmn).current_abilities + rablt)).pp == 0));
	}
	else	// if the pokemon is out of pp, let him use the default ability
	{
		rablt = 5;
	}

	if(rablt == 5)	// if selected struggle
	{
		patk = SeekAbility(str, allablts, nabilities);
	}
	else	// if selected an ability
	{
		patk = (*pkmn).current_abilities+rablt;
	}

	// target
	if(IsKo(*allies))	// if there is only one pokemon left, target him
	{
		ptarget = allies+1;
	}
	else if(IsKo(*(allies+1)) )
	{
		ptarget = allies;
	}
	else
	{						// else, we compare the hp of the 2 pokemons and target the one with the less health points
		if( (*allies).hp <= (*(allies+1)).hp)
		{
			ptarget = allies;
		}
		else{
			ptarget = allies+1;
		}
	}

	// attack
	Attack(pkmn, patk, ptarget, allies, nallies);
	
}

void EnemyTurn(int diff, pokemon* pkmn,pokemon* foes, int nfoes, pokemon* allies, int nallies, ability* allablts, int nabilities, int status)
{
	/*the difficulty variable for the enemy function works like this:
	1: always use the default ability (struggle) (which is really bad)
	2: random target (foes and allies) 
	3: target the pokemon of the player with the lowest health pool*/


	// we verify every parameter 
	if(pkmn == NULL)	// the pokemon playing the turn
	{
		printf("\n\nerror in EnemyTurn, pkmn point to NULL");
		exit(1);
	}
	if(nfoes<=0)	// the number of pokemon the enemy possess
	{
		printf("\n\nerror in EnemyTurn, nfoes <= 0");
		exit(1);
	}
	else if(nfoes>6)	// every trainer is limited to 6 pokemon 
	{
		printf("\n\nerror in EnemyTurn, nfoes > 6");
		exit(1);
	}
	if(nallies<=0)	// the number of pokemon the player possess
	{
		printf("\n\nerror in EnemyTurn, nallies <= 0");
		exit(1);
	}
	else if(nallies>6)	// every trainer is limited to 6 pokemon 
	{
		printf("\n\nerror in EnemyTurn, nallies > 6");
		exit(1);
	}
	if(nabilities<=0)	// the number of abilities so we can travel through abilities if needed
	{
		printf("\n\nerror in EnemyTurn, nabilities <= 0");
		exit(1);
	}
	verifyPkmn(*pkmn, "EnemyTurn");
	verifyPPkmn(allies, nallies, "EnemyTurn"); // the array of every pokemon the player possess
	verifyPPkmn(foes, nfoes, "EnemyTurn"); // the array of every pokemon the player possess
	verifyPAbility(allablts, nabilities, "EnemyTurn");	// the array of every possible ability

	if(nallies > 2)
	{
		nallies = 2;
	}
	if(nfoes > 2)
	{
		nfoes = 2;
	}


	if(status == 2)	// if the pokemon is confused
	{
		VeryEasy(pkmn ,foes, nfoes, allies, nallies, allablts, nabilities);
	}
	else
	{	
		switch(diff)
		{
			case 1:
				VeryEasy(pkmn ,foes, nfoes, allies, nallies, allablts, nabilities);
				break;
			case 2:
				Easy(pkmn ,foes, nfoes, allies, nallies, allablts, nabilities);
				break;
			case 3:
				Normal(pkmn ,foes, nfoes, allies, nallies, allablts, nabilities);
				break;
		}
	}
}

void MainFight(int menu, int diff, pokemon* allies, int* pnallies, pokemon* foes, int nfoes, ability* allablts, int nablts, effect* effects, int neffects, char* trainer)
{	// manage the whole fight (who is playing and what they do)

	// we verify every parameter 
	if(menu!=1 && menu!=2)	// the menu, because depending of the menu we wan catch or not pokemon
	{
		printf("\n\nerror in MainFight, menu !=1 && !=2");
		exit(1);
	}
	if(diff!=1 && diff!=2 && diff!=3)	// the difficulty, because we need to know how the enemy act
	{
		printf("\n\nerror in MainFight, diff !=1 && !=2 && !=3");
		exit(1);
	}


	if(pnallies == NULL)	// the pointer to the number of pokemons the player possess, because we need to increase it if he catch a new pokemon
	{
		printf("\n\nerror in MainFight, pnallies point to NULL");
		exit(1);
	}
	if(foes == NULL)	// the array of every pokemon the enemy possess
	{
		printf("\n\nerror in MainFight, foes point to NULL");
		exit(1);
	}
	if(nfoes<=0)	// the number of pokemon the enemy possess
	{
		printf("\n\nerror in MainFight, nfoes <= 0");
		exit(1);
	}
	else if(nfoes>6)	// every trainer is limited to 6 pokemon 
	{
		printf("\n\nerror in MainFight, nfoes > 6");
		exit(1);
	}
	if(allablts == NULL)	// the array of every possible abilities, so we can get the struggle ability
	{
		printf("\n\nerror in MainFight, allablts point to NULL");
		exit(1);
	}
	if(nablts<=0)	// the number of abilities so we can travel through abilities if needed
	{
		printf("\n\nerror in MainFight, nablts <= 0");
		exit(1);
	}
	if(effects == NULL) //  every status, so we can use the StatusEffect function
	{
		printf("\n\nerror in MainFight, effects point to NULL");
		exit(1);
	}
	if(neffects<=0)	// number of possible status, for the same purpose
	{
		printf("\n\nerror in MainFight, neffects <= 0");
		exit(1);
	}

	verifyPPkmn(allies, *pnallies, "MainFight"); // the array of every pokemon the player possess
	verifyPPkmn(foes, nfoes, "MainFight"); // the array of every pokemon the player possess
	verifyPAbility(allablts, nablts, "MainFight");	// the array of every possible ability

	int res;
	int* pres = &res; // to store the inputs of the player
	int i, j;

	int nallies = *pnallies;
	int status = 0;
	int firstloop;
	int win = (IsWin(allies, nallies, foes, nfoes));

	int nbr_vit;
	int* pnbr_vit = &nbr_vit;
	
	pokemon l;
	pokemon* list = &l;
	pokemon** list_turn = &list;
	pokemon*** plist_turn = &list_turn; //pointer to the array of pokemons who should play this turn
	
	AddSpeed(&allies, nallies, &foes, nfoes);


	while( win == 0 )	// main loop
	{

		nbr_vit = 0;
		Who_Turn(allies, nallies, foes, nfoes, plist_turn, pnbr_vit);	// we get the list of who should play in the correct order (if there is someone who play on this turn)
		//(and if it works...)
		DisplayFight(*pnallies, allies, nfoes, foes, list_turn, nbr_vit, trainer);
		sleep(5);		
		
		if(nbr_vit > 0)
		{
			i = 0;
			while(i < nbr_vit && win == 0)	//	Does every turn in the priority
			{	
				j = 0;	// verify if the pokemon playing is an ally
				while(j < nallies && win == 0)	// (those while loops are just for loop with 2 condition and idk if I can do it otherwise)
				{

					firstloop == 1;
					if( (IsKo(*(allies+j))) == 0 ) // if the pokemon is not ko
					{
						if(*(list_turn+i) == (allies+j))	// if the pokemon playing is in the ally team
						{
							do{ // if the player choose to get back in the turn menu (somewhere in a function), it loops again 
								printf("\n\n%s is playing", (*(allies+j)).name);

								if(firstloop == 1 && !(IsWin(allies, nallies, foes, nfoes)))	
								// we don't want the player to get affected by the status multiple times in one turn just because he went back in the selection
								{
									status = StatusEffect((allies+j), effects, neffects, 1, allies, nallies, foes, nfoes);		
									// apply the effect the pokemon is affected	
									firstloop = 0;
								}
								if(status != -1 && status != 1)	
								// if there is already a winner we want nothing more to happen (and if the turn is skipped by the status)
								{
									// Player turn
									YourTurn(menu, (allies+j), allies, pnallies, foes, nfoes, allablts, nablts, pres, status, list_turn, nbr_vit, trainer);
									
									if(*pres != 0)
									{
										// Switch enemy pokemon if one is ko (or both)
										SwitchEnemy(foes, nfoes);

										// Switch ally pokemon if one is ko (or both)
										SwitchAlly(allies, nallies, pres);	// it is possible with the self damage to get ko by yourself

									}
								}
							
							} while(*pres == 0);
						}
					}
					j++;
				}




				j = 0;	// verify if the pokemon playing is a foe
				while(j < nfoes && win == 0)
				{
					if( (IsKo(*(foes+j))) == 0 ) // if the pokemon is not ko
					{
						if( *(list_turn+i) == (foes+j) )	// if the pokemon playing is in the enemy team
						{
							printf("\n\n%s is playing", (*(foes+j)).name);
							status = StatusEffect((foes+j), effects, neffects, 0, allies, nallies, foes, nfoes);		
							// apply the effect the pokemon is affected

							if(status != -1 && status != 1)	// if there is already a winner we want nothing more to happen
							{
								// Enemy turn
								EnemyTurn(diff, (foes+j), foes, nfoes, allies, nallies, allablts, nablts, status);

								// Switch ally pokemon if one is ko (or both)
								SwitchAlly(allies, nallies, pres);

								// Switch enemy pokemon if one is ko (or both)
								SwitchEnemy(foes, nfoes); // it is possible with the self damage
							}
						}
					}
					j++;
				}
				win = IsWin(allies, nallies, foes, nfoes);	// stop the fight if it is over
				if(!win)
				{
					printf("\nWaiting for the pokemons to decide who play this turn.....\n");
				}
				i++;
			}
			if(nbr_vit > 0)
			{
				free(list_turn); // don't free the array if there was no malloc
			}

		}
	
		// We add the speed value of every pokemon in their bar	
		AddSpeed(&allies, nallies, &foes, nfoes);	
	}

}

/*
void NewAbilities(pokemon* allies, int nallies)
{	// we had the idea of making abilities that the pokemons could gain the player won

	if(allies == NULL)	// the array of every pokemon the enemy possess
	{
		printf("\n\nerror in NewAbilities, allies point to NULL");
		exit(1);
	}
	if(nallies<=0)	// the number of pokemon the enemy possess
	{
		printf("\n\nerror in NewAbilities, nallies <= 0");
		exit(1);
	}
	else if(nallies>6)	// every trainer is limited to 6 pokemon 
	{
		printf("\n\nerror in NewAbilities, nallies > 6");
		exit(1);
	}
	int r, not_valid, good_type, res, count;
	pokemon ally;

	for(int i = 0; i<nallies; i++)
	{
		r = rand()%2;
		if(r==1)
		{
			ally = (*(allies+i));
			count = (*(allies+i)).nabi;
			if( count!=0 )	///////////////////////////// si plusieurs next abilities, verifier que nabi < number_next
			{
				do{
					not_valid=0;
					printf("\n\n\n%s can learn %s!", ally.name, (*(ally.next_abilities+count)).name);
					printf("\nSelect an ability to change:");
					printf("\n\n 0:no thx   1: %s   2:%s   3: %s   4: %s \n", (*(ally.current_abilities)).name, (*(ally.current_abilities+1)).name, (*(ally.current_abilities+2)).name, (*(ally.current_abilities+3)).name);
					good_type = scanf("%d",&res);
					if(good_type == 0 || (res != 0 && res != 1 && res != 2 && res != 3 && res != 4))
					{
						not_valid = 1;
						printf("\n\n%s learned %s and forgot every other abilities!\n\n\n\n\nok that was a joke, enter a valid value", ally.name, (*(ally.next_abilities+count)).name);
					}
				} while(not_valid);
				(*(allies+i)).nabi++;
			}

			if(res!=0)
			{
				*((*(allies+i)).current_abilities + res -1) = (*((*(allies+i)).next_abilities+count));
			}
		}
	}
}
*/

void EndFight(pokemon* allies, int nallies, pokemon* foes, int* pnfoes, int* pmenu, int npkmns, pokemon* pkmns)
{	// put end to the fight, reset everything and add foes if needed

	// we verify every parameter 
	if(nallies<=0)	// the number of pokemons the player have
	{
		printf("\n\nerror in EndFight, nallies <= 0");
		exit(1);
	}
	else if(nallies>6)
	{
		printf("\n\nerror in EndFight, nallies > 6");
		exit(1);
	}
	if(pnfoes == NULL)	// the pointer to the number of pokemons the enemy possess, because we want to increase it if the player win
	{
		printf("\n\nerror in EndFight, pnfoes point to NULL");
		exit(1);
	}
	if(*pnfoes > 6 || *pnfoes <= 0){	// the pointer to the number of foes
		printf("\n\nerror in EndFight *pnfoes > 6 || *pnfoes <= 0");
		exit(1);
	}

	if(pmenu == NULL)	// the pointer to the menu variable, so we can go back in the main menu when the fight is over
	{
		printf("\n\nerror in EndFight, pmenu point to NULL");
		exit(1);
	}
	if(npkmns <= 0)
	{
		printf("\n\nerror in EndFight, npkmns <= 0");
		exit(1);
	}
	verifyPPkmn(allies, nallies, "EndFight");
	verifyPPkmn(foes, *pnfoes, "EndFight");
	verifyPPkmn(pkmns, npkmns, "EndFight");






	if((*pnfoes<6) && (IsWin(allies, nallies, foes, *pnfoes) == 1) && (*pmenu == 2))	
	{
		(*pnfoes)++; // increase the number of pokemons a enemy trainer possess if the player win (and the enemy doesn't have already 6 pokemon)
	}

	if(IsWin(allies, nallies, foes, *pnfoes) == 1)
	{
		printf("You win!");
		/*NewAbilities(allies, nallies);*/
		Reset(allies, nallies, foes, *pnfoes,  npkmns, pkmns);
	}
	else if(IsWin(allies, nallies, foes, *pnfoes) == -1)
	{
		printf("You lose!");
		Reset(allies, nallies, foes, *pnfoes, npkmns, pkmns);
	}
	*pmenu = 0;

}

void Reset(pokemon* allies, int nallies, pokemon* foes, int nfoes, int npkmns, pokemon* pkmns)
{	// reset the pokemons like they were fully healed
	// we verify every parameter 
	if(nallies<=0)	// the number of pokemons the player have
	{
		printf("\n\nerror in Reset, nallies <= 0");
		exit(1);
	}
	else if(nallies>6)
	{
		printf("\n\nerror in Reset, nallies > 6");
		exit(1);
	}
	if(nfoes<=0)	// the number of pokemons the enemy have
	{
		printf("\n\nerror in Reset, nfoes <= 0");
		exit(1);
	}
	else if(nfoes>6)
	{
		printf("\n\nerror in Reset, nfoes > 6");
		exit(1);
	}
	if(npkmns <= 0)
	{
		printf("\n\nerror in Reset, npkmns <= 0");
		exit(1);
	}
	verifyPPkmn(allies, nallies, "Reset");
	verifyPPkmn(foes, nfoes, "Reset");
	verifyPPkmn(pkmns, npkmns, "Reset");

	effect clean;
	*(clean.name) = 'a';	// doesn't work otherwise
	*(clean.name) = 'u';
	*(clean.name) = 'c';
	*(clean.name) = 'u';
	*(clean.name) = 'n';
	clean.tour = 0;
	
	for(int i = 0; i<nallies; i++)
	{


		if(IsDitto(*(allies+i))) // if the pokemon is a metamorph (ditto) morphed, reset him
		{
			*(allies+i) = SeekPokemons("metamorph", pkmns, npkmns);	
		}


		(*(allies+i)).hp = (*(allies+i)).hpmax;	// reset the hp

		for(int j = 0; j<4; j++)	// reset the pp of every ability the pokemon possess
		{
			if(   (*((*(allies+i)).current_abilities+j)).name	!= "NULL")
			{
				(*((*(allies+i)).current_abilities+j)).pp = (*((*(allies+i)).current_abilities+j)).ppmax;
			}
		}

		(*(allies+i)).affected = clean ;
		(*(allies+i)).spdbar = 0;	// reset the speed bar progress

	}

}


void Fight(int* pmenu, int* pdiff, pokemon* allies, int* pnallies, int* pnfoes, pokemon* allpkmns, int npkmns, ability* allablts, int nablts, effect* effects, int neffects, char* trainer)
{	// the main function of the fight, managing the start to the end

	// we verify every parameter 
	if(pmenu == NULL)	// the pointer to the menu variable, so we can go back in the main menu when the fight is over
	{
		printf("\n\nerror in Fight, pmenu point to NULL");
		exit(1);
	}
	if(*pmenu != 1 && *pmenu != 2)
	{
		printf("\n\nerror in Fight, pmenu != 1 && !=2");
		exit(1);
	}
	
	if(pdiff == NULL)	//	the pointer to the difficulty, we want to change the difficulty before we start the fight
	{
		printf("\n\nerror in Fight, pdiff point to NULL");
		exit(1);
	}

	if(pnallies == NULL)	// the pointer to the number of pokemons the player possess, because we need to increase it if he catch a new pokemon
	{
		printf("\n\nerror in Fight, pnallies point to NULL");
		exit(1);
	}
	if(*pnallies > 6 || *pnallies <= 0){	// the pointer to the number of allies
		printf("\n\nerror in Fight *pnallies > 6 || *pnallies <= 0");
		exit(1);
	}
	if(pnfoes == NULL)	// the pointer to the number of pokemons the enemy possess, because we want to increase it if the player win
	{
		printf("\n\nerror in Fight, pnfoes point to NULL");
		exit(1);
	}
	if(*pnfoes > 6 || *pnfoes <= 0){	// the pointer to the number of foes
		printf("\n\nerror in Fight *pnfoes > 6 || *pnfoes <= 0");
		exit(1);
	}
	if(npkmns<=0)		// the number of pokemons there is in the array, so we can make a for loop to browse through it
	{
		printf("\n\nerror in Fight, npkmns <= 0");
		exit(1);
	}
	if(nablts<=0)	// the number of abilities so we can travel through abilities if needed
	{
		printf("\n\nerror in Fight, nablts <= 0");
		exit(1);
	}
	if(neffects<=0)	// number of possible status, for the same purpose
	{
		printf("\n\nerror in Fight, neffects <= 0");
		exit(1);
	}
	
	verifyPPkmn(allies, *pnallies, "Fight"); // the array of every pokemon the player possess
	verifyPAbility(allablts, nablts, "Fight");	// the array of every possible ability
	verifyPPkmn(allpkmns, npkmns, "Fight");	// the array of every pokemon possible
	verifyPEffect(effects, neffects, "Fight"); // the array of every effect possible

	pokemon foe;
	pokemon* foes = &foe; // we create the array
	pokemon** pfoes = &foes;
	
	ChooseDiff(pdiff); // Choose the difficulty

	StartFight(*pmenu, pfoes, *pnfoes, allpkmns, npkmns); // Display the firsts line and make the enemies with random pokemons


	MainFight(*pmenu, *pdiff,allies, pnallies, foes, *pnfoes, allablts, nablts, effects, neffects, trainer); // Where the main part of the fight take place


	EndFight(allies, *pnallies, foes, pnfoes, pmenu, npkmns, allpkmns);

	free(foes);


}


void FreeNames(pokemon** ppokemons, int npokemons)
{	// to free the names of the pokemons which were allocated
	if(ppokemons == NULL)
	{
		printf("\n\nerror in FreeNames, ppokemons point to NULL");
		exit(1);
	}
	if(npokemons<=0)	// number of possible pokemons to free the names
	{
		printf("\n\nerror in FreeNames, npokemons <= 0");
		exit(1);
	}
	verifyPPkmn(*ppokemons, npokemons, "FreeNames");

	for(int i = 0; i < npokemons; i++)
	{
		free((*((*ppokemons)+i)).name);
	}
	
}








