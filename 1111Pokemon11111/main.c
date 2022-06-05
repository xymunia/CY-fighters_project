#include "pokemon.h"



int main()
{

	// Before we start the game we need to get the data
	ability a;
	ability* abilities = &a; // this will be the list of every abilities available
	ability** pabilities = &abilities;
	int nabilities; // represent the numeber of abilities there is in the array

	pokemon p;
	pokemon* pokemons = &p; // this will be the list of every pokemon available
	pokemon** ppokemons = &pokemons;
	int npokemons;	// represent number of pokemons there is in the array

	int ntypes;
	type t;
	type* types = &t;
	type** ptypes = &types;
	

	effect e;
	effect* effects = &e;
	effect** peffects = &effects;
	int neffects;



	// In game variables
	char trainer[50];	// the name the player enter
	pokemon* pkmn_player = malloc(6*sizeof(pokemon));	// a list of the pokemons the player possess
	pokemon* starters = malloc(4*sizeof(pokemon));	// the list of possible starters

	int nallies;
	int* pnallies = &nallies;

	int play = 1;	// boolean for the main loop of the gameplay
	int* pplay = &play;	// we need to be able to stop from a function (so we need to access the play variable from a function)
	int menu = 0; // to know where we are 0 = first menu, 1 = fight wild pkmn, 2 = fight trainer
	int* pmenu = &menu;	// we need to be able to change the menu from a function
	int diff = 0; // the difficulty for the enemy function  1: spam the default ability (struggle) 2: random target (foes and allies) 3: target the pokemon of the player with the lowest hp
	int* pdiff = &diff; 

	int n_enemies = 3; // the number of pokemons a enemy trainer have when starting the fight(can't be more than 6 and can't be less than 2);
	int* pn_enemies = &n_enemies;
	int wild_foes = 2;
	int* pwild = &wild_foes;

	srand(time(NULL));

	ntypes = getTypes(ptypes);	// get the data of every types
	neffects = getEffect(peffects);		// get the data of every effects/status
	nabilities = getAbilities(pabilities, effects, neffects);	// get the data of every abilities in the abilities array (and return the length of the array)
	npokemons =  getPokemons(ppokemons, abilities, nabilities, types, ntypes);		// get the data of every pokemons in the pokemons array (and return the length of the array)		

	
	// Now that we have every data we need stored, we can start the game

	// Choose your starter pokemon and your name (the trainer name is the team's name)
	*starters = *pokemons;
	*(starters+1) = *(pokemons+1);
	*(starters+2) = *(pokemons+2);
	*(starters+3) = *(pokemons+16); // this is where is metamorph (little easter egg)
	start(starters, pkmn_player, trainer, pnallies);	// here we  get the firsts pokemons and the name of the trainer (and number of pokemons)
	free(starters);


	while(play){ //	Here goes the main loop
		
		if(menu == 0){	// main menu
			main_menu(pmenu,pplay);
		}
		else if(menu == 1){ // fight against a wild pokemon (2v2, capture allowed, only 2 foes)
			
			Fight(pmenu, pdiff, pkmn_player, pnallies, pn_enemies, pokemons, npokemons, abilities, nabilities, effects, neffects, trainer);
			
		}
		else if(menu == 2){ // fight against a trainer (2v2, can't capture the pokemon, 2 to 6 foes)

			Fight(pmenu, pdiff, pkmn_player, pnallies, pwild, pokemons, npokemons, abilities, nabilities, effects, neffects, trainer);
			
		}

	}

	FreeNames(ppokemons, npokemons);
	free(pokemons);
	free(effects);
	free(types);
	free(abilities);
	free(pokemons);
	free(pkmn_player);

}



/*
list of every bug we found out in the code:

-sometimes, the foes will just play without the player having a single turn (we don't know why)

-Morphing doesn't really work 

- some test doesn't work
*/



