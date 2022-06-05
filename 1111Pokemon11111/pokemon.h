#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>


#define BAR 250
#define MAX_LENGTH 100

typedef struct {
	
	char name[20]; // the name of the type
	char** immune; // Here we get the relation of the type, an abilitiy with this type will do no dmg against immune
	char tmpimmune[80];	// every tmpsomething is just here to store/get the line before formating the line into the right type to be stored in the right place
	int nimmune;
	char** resist;	// an ability with the type will do half dmg against resist
	char tmpresist[80];
	int nresist;
	char** efficient;
	char tmpefficient[80];
	int nefficient;

} type;

typedef struct {

	char name[20];	// we need to store the number of times an effect last for some effects
	int tour;

} effect;

typedef struct {

	char name[20];
	char phy_spe[5];
	int dmg;
	int precision;
	int pp; // the number of time you can use the ability
	int ppmax;
	effect effect;
	int peffect; // probability of applying the effect
	char type[20];	//only the name of the type is needed 
	int affectall;	// 1 if affect all foes 0 if only one target
	int selfdmg; // <0 if heal, >0 if self damage like the struggle ability	
	int spd_atk;	

} ability;

typedef struct {

	char* name;	// we need it to be dinamic so we can change the name of ditto/metamorph when he morph
	int hp;
	int hpmax;
	type* type;
	char tmptype[20];
	int ntype;
	int capt;
	int atk;
	int atk_spe;
	int def;
	int def_spe;
	int speed;	
	ability* current_abilities; // (always 4 of them)	
	char tmpabilities[80];

	/*ability next_abilities;	// there is only one ability per pokemon you can get after a win
	int nabi; // to keep track of where we are in the next_abilities*/
	effect affected;
	int spdbar;

} pokemon;


// here are the tests
void verifyType(type tp, char* fname);
void verifyPType(type* tps, int n, char* fname);
void verifyEffect(effect effe, char* fname);
void verifyPEffect(effect* effes, int n, char* fname);
void verifyAbility(ability abl, char* fname);
void verifyPAbility(ability* abls, int n, char* fname);
void verifyPkmn(pokemon pkmn, char* fname);
void verifyPPkmn(pokemon* pkmn, int n, char* fname);
void FreeNames(pokemon** ppokemons, int npokemons);

// Here are the function we need before we start the game
int NumberofChar(FILE* file, char c);
char** SplitStr(char* line);
int size_str(char** str);
ability* SeekAbilities(char** names, ability* abilities, int nabilities);
ability* SeekAbility(char* names, ability* abilities, int nabilities);
effect SeekEffect(char* name, effect* effects, int neffects);
type* SeekTypes(char** names, type* types, int ntypes);
pokemon SeekPokemons(char* name, pokemon* pokemons, int npokemons);
int getTypes(type** types);
int getEffect(effect** effects);
int getAbilities(ability** ablts, effect* effects, int neffects);
int getPokemons(pokemon** pkmns, ability* abilities, int nabilities, type* types, int ntypes);


// Here are all the function we need in game
pokemon** MaxVit(pokemon** list, int narray,int nbr_vit);
int NumberPokemons(pokemon* array, int nfoes);
int IsDodging(ability atk, pokemon target);
int Crit();
float TypeEffectiveness(ability atk, pokemon target);
int CalculateDmg(ability atk, pokemon target);

int StatusEffect(pokemon* pkmn, effect* effects, int neffects, int isally, pokemon* allies, int nallies, pokemon* foes, int nfoes);

int IsKo(pokemon pkmn);
int IsWin(pokemon* allies, int nallies, pokemon* foes, int nfoes);





// Here are the procedures mainly used to display things and get inputs
void start(pokemon* starters, pokemon* trainer, char* name, int* pnallies);
void main_menu(int* pmenu, int* pplay);
void ChooseDiff(int* pdiff);




// In fight

// metamorph / ditto
int IsDitto(pokemon pkmn);
void Morphing(pokemon* ppkmn, pokemon* ptarget);

// turn priority management 
void AddSpeed(pokemon** allies, int nallies, pokemon** foes, int nfoes);
void Who_Turn(pokemon* allies, int nallies, pokemon* foes, int nfoes, pokemon*** list_turn, int* pnbr_vit);

/*void NewAbilities(pokemon* allies, int nallies);*/

// attack managament
void SelectAbilities(pokemon* pkmn, pokemon* foes, int nfoes, ability* allablts, int nabilities,int* pres);
void Attack(pokemon* pkmn, ability* patk, pokemon* ptarget, pokemon* array, int narray);

// switch of pokemon management
void SwitchPokemon(pokemon* pkmn, pokemon* array, int narray, int* pres);
void SwitchEnemy(pokemon* foes, int nfoes);
void SwitchAlly(pokemon* allies, int nallies, int* pres);

// catch management
void AddPokemon(pokemon* allies, int* pnallies, pokemon* ptarget);
void Catch(pokemon* foes, pokemon* allies, int* pnallies, int* pres);

// player turn
void PrintfType(char* type, char* name);
void PrintfStatus(char* sta);
void DisplayFight(int nallies, pokemon* allies, int nfoes, pokemon* foes, pokemon** list_turn, int nbr, char* trainer);
void YourTurn(int menu , pokemon* pkmn, pokemon* allies, int* pnallies, pokemon* foes, int nfoes, ability* allablts, int nablts, int* pres, int status, pokemon** list_turn, int nbr_vit, char* trainer);

// enemy turn management
void EnemyTurn(int diff, pokemon* pkmn,pokemon* foes, int nfoes, pokemon* allies, int nallies, ability* allablts, int nabilities, int status);
void VeryEasy(pokemon* pkmn, pokemon* foes, int nfoes, pokemon* allies, int nallies, ability* allablts, int nabilities);
void Easy(pokemon* pkmn, pokemon* foes, int nfoes, pokemon* allies, int nallies, ability* allablts, int nabilities);
void Normal(pokemon* pkmn, pokemon* foes, int nfoes, pokemon* allies, int nallies, ability* allablts, int nabilities);


// fight management
void Fight(int* pmenu,int* pdiff, pokemon* allies, int* pnallies, int* pnfoes, pokemon* allpkmns, int npkmns, ability* allablts, int nablts, effect* effects, int neffects, char* trainer);
void StartFight(int menu, pokemon** foes, int nfoes, pokemon* allpkmns, int npkmns);
void MainFight(int menu, int diff, pokemon* allies, int* pnallies, pokemon* foes, int nfoes, ability* allablts, int nablts, effect* effects, int neffects, char* trainer);
void EndFight(pokemon* allies, int nallies, pokemon* foes, int* pnfoes, int* pmenu, int npkmns, pokemon* pkmns);
void Reset(pokemon* allies, int nallies, pokemon* foes, int nfoes, int npkmns, pokemon* pkmns);
