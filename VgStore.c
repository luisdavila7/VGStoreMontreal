/*
Luis Davila
Cod: 2030057
Final Project
Algorithms and Programming
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define VG_Type 7
#define VG_ESRB_R 6
#define VG_Platform 7
#define VG_Modes 6
#define VG_Format 2
#define MAX_LINE_LENGTH 40
#define VGAMEMAXINV 50

typedef struct VG_STORE{
	char SKU [MAX_LINE_LENGTH];
	char vgName[MAX_LINE_LENGTH];
	char vgStudio[MAX_LINE_LENGTH];
	//Declared as INT to define characteristics of the VG without the user having to type them.
	int vgType;
	int vgESRBRating;
	int vgRate;
	int vgPlatform;
	int vgModes;
	int vgFormat; // Physical format or digital format
	float vgSelling_Price;
} VG_STORE;

VG_STORE VG_inventory[50];

typedef struct SEARCHMODE{
		char SEARCH_SKU[MAX_LINE_LENGTH];
		char SEARCH_vgName[MAX_LINE_LENGTH];
		char SEARCH_vgStudio[MAX_LINE_LENGTH];
		int SEARCH_vgType;
		int SEARCH_vgESRBRating;
		int SEARCH_vgRate;
		int SEARCH_vgPlatform;
		int SEARCH_vgModes;
		int SEARCH_vgFormat;
		float SEARCH_vgSelling_Price;
} SEARCHMODE;

SEARCHMODE SEARCH_VG_inventory[50];

int k = 0, invbase_flag = 0; // inventory tracking
// Search variables
char skuTemp[MAX_LINE_LENGTH];
int locationSku;
char vgType[VG_Type][MAX_LINE_LENGTH] = {"Action","Idle","Role-playing","Simulation","Sports","Strategy/RPG","Other"};
char vgESRBRating[VG_ESRB_R][MAX_LINE_LENGTH] = {"E","E10+","T","M","A","RP"};
char vgPlatform[VG_Platform][MAX_LINE_LENGTH] = {"PS","Xbox","Nintendo Switch","PC","Mobile","Google Stadia - Streaming","Amazon Luna - Streaming"};
char vgModes[VG_Modes][MAX_LINE_LENGTH] = {"Local / Single Player","Local / Coop Mode","Local / PvP","Online / Single Player","Online / Coop Mode","Online / PvP"};
char vgFormat[VG_Format][MAX_LINE_LENGTH] = {"Physical","Digital"};

void displayMenu(){
	printf("|==================================================================|");
	printf("\n|=================| Menu for VIDEO  GAMES STORE |==================|");
	printf("\n|==================================================================|\n");
	printf("\n 1. Populate the Inventory");
	printf("\n 2. Search for a games");
	printf("\n 3. Edit an entry Game by ID (SKU)");
	printf("\n 4. Display all games in the inventory");
	printf("\n 5. Exit the system");
}

void baseInventory(){
	//SKU, Name, Estudio, Type, Rate, Platform, Modes, Format, Price
	VG_STORE Red_Dead = {"BASEINV5001", "Red Dead Redemption 2", "Rockstar", 0, 2, 95, 0, 0, 0, 45.99};
	VG_STORE Half_Life = {"BASEINV5002", "Half-Life: Alyx", "Valve", 0, 2, 95, 4, 0, 1, 49.99};		
	VG_STORE Zelda = {"BASEINV5003", "The Legend of Zelda: Breath of the Wild", "Nintendo", 0, 1, 94, 2, 0, 0, 49.99};
	VG_STORE Mario = {"BASEINV5004", "Super Mario Odyssey", "Nintendo", 6, 0, 90, 2, 2, 0, 50.49};
	VG_STORE Smash_Bros = {"BASEINV5005", "Super Smash Bros", "Nintendo", 0, 0, 90, 2, 2, 0, 49.99};
	VG_STORE LoU = {"BASEINV5006", "The Last of Us", "Sony", 1, 3, 90, 0, 0, 0, 60.99};
	VG_STORE GTA = {"BASEINV5007", "Grand Theft Auto V", "Rockstar Games", 0, 3, 90, 0, 3, 0, 50.49};
	VG_STORE GoW = {"BASEINV5008", "God of War", "Sony", 6, 2, 89, 0, 0, 0, 49.90};
	VG_STORE StarCraft = {"BASEINV5009", "StarCraft II: Wings of Liberty", "Blizzard", 5, 1, 89, 3, 5, 1, 69.49};
	VG_STORE Sekiro = {"BASEINV5010", "Sekiro: Shadows Die Twice", "Activision", 0, 4, 89, 0, 0, 0, 69.49};
	VG_inventory[k++] = Red_Dead;
	VG_inventory[k++] = Half_Life;
	VG_inventory[k++] = Zelda;
	VG_inventory[k++] = Mario;
	VG_inventory[k++] = Smash_Bros;
	VG_inventory[k++] = LoU;
	VG_inventory[k++] = GTA;
	VG_inventory[k++] = GoW;
	VG_inventory[k++] = StarCraft;
	VG_inventory[k++] = Sekiro;
}

void displayInventory(int i){
	printf("\n|==================================================================|\n");
	printf("These are the details of the game located in inventory position #%d\n", i+1);
	printf("\n1. SKU: \t\t%s", VG_inventory[i].SKU);
	printf("\n2. Name: \t\t%s", VG_inventory[i].vgName);
	printf("\n3. Studio: \t\t%s", VG_inventory[i].vgStudio);
	printf("\n4. Type: \t\t%s", vgType[VG_inventory[i].vgType]);
	printf("\n5. ESRB Rating: \t%s", vgESRBRating[VG_inventory[i].vgESRBRating]);
	printf("\n6. Metacritic Rating: \t%d", VG_inventory[i].vgRate);
	printf("\n7. Platform: \t\t%s", vgPlatform[VG_inventory[i].vgPlatform]);
	printf("\n8. Gameplay: \t\t%s", vgModes[VG_inventory[i].vgModes]);
	printf("\n9. Format of the Game: \t%s", vgFormat[VG_inventory[i].vgFormat]);
	printf("\n10. Selling Price: \t%0.2f CAD\n", VG_inventory[i].vgSelling_Price);
}

bool checkSKU(char skuTemp[MAX_LINE_LENGTH]){
	for(int i = 0; i < k; i++)
		if (strcmp(skuTemp, VG_inventory[i].SKU) == 0){
			printf("This SKU are duplicated\n");
			return true;
		}
		return false;
}

// All the features of the video game are separated to facilitate individual editing in option 3.

void videoGameName(int i){
	printf("Insert Video Game Name: ");
	fflush(stdin);
	fgets(VG_inventory[i].vgName, MAX_LINE_LENGTH, stdin);
	VG_inventory[i].vgName[strlen(VG_inventory[i].vgName)-1] = '\0';
}

void videoGameStudio(int i){
	printf("Insert Video Game Studio: ");
	fflush(stdin);
	fgets(VG_inventory[i].vgStudio, MAX_LINE_LENGTH, stdin);	
	VG_inventory[i].vgStudio[strlen(VG_inventory[i].vgStudio)-1] = '\0';
}

void videoGameGenre(int i){
	printf("\nGenre Video Game");
	printf("\n0. Action");
	printf("\n1. Idle");
	printf("\n2. Role-playing");
	printf("\n3. Simulation");
	printf("\n4. Sports");
	printf("\n5. Strategy/RPG");
	printf("\n6. Other");

	do {
		printf("\n\nSelect one option: ");
		scanf("%d", &VG_inventory[i].vgType);
		if(VG_inventory[i].vgType < 0 || VG_inventory[i].vgType > 6)
			printf("\nPlease, insert a valid option");
	} while(VG_inventory[i].vgType < 0 || VG_inventory[i].vgType > 6);
}

void videoGameESRB(int i){
	printf("\nESRB Rating");
	printf("\n0. E"); 
	printf("\n1. E10+"); 
	printf("\n2. T");  
	printf("\n3. M"); 
	printf("\n4. A"); 
	printf("\n5. RP");
	do {
		printf("\n\nSelect one option: ");
		scanf("%d", &VG_inventory[i].vgESRBRating);
		if(VG_inventory[i].vgESRBRating < 0 || VG_inventory[i].vgESRBRating > 5)
			printf("\nPlease, insert a valid option");
	} while(VG_inventory[i].vgESRBRating < 0 || VG_inventory[i].vgESRBRating > 5);
}

void videoGameMetacritic(int i){
	printf("\nInsert the Video Game -	Metacritic Rating");
	do {
		printf("\nFrom 0 to 100: ");
		scanf("%d", &VG_inventory[i].vgRate);
		if(VG_inventory[i].vgRate < 0 || VG_inventory[i].vgRate > 100)
			printf("\nPlease, insert a valid option");
	} while(VG_inventory[i].vgRate < 0 || VG_inventory[i].vgRate > 100);
}

void videoGamePlatform(int i){
	printf("\nPlatform Video Game");
	printf("\n0. PS"); 
	printf("\n1. Xbox"); 
	printf("\n2. Nintendo Switch");  
	printf("\n3. PC"); 
	printf("\n4. Mobile");
	printf("\n5. Google Stadia - Streaming");
	printf("\n6. Amazon Luna - Streaming");
	do {
		printf("\n\nSelect one option: ");
		scanf("%d", &VG_inventory[i].vgPlatform);
		if(VG_inventory[i].vgPlatform < 0 || VG_inventory[i].vgPlatform > 6)
			printf("\nPlease, insert a valid option");
	} while(VG_inventory[i].vgPlatform < 0 || VG_inventory[i].vgPlatform > 6);
}

void videoGamePlayMode(int i){
	printf("\nGame Play Mode: ");
	printf("\n0. Local / Single Player"); 
	printf("\n1. Local / Coop Mode");
	printf("\n2. Local / PvP");
	printf("\n3. Online / Single Player");
	printf("\n4. Online / Coop Mode");
	printf("\n5. Online / PvP");
	do {
		printf("\n\nSelect one option: ");
		scanf("%d", &VG_inventory[i].vgModes);
		if(VG_inventory[i].vgModes < 0 || VG_inventory[i].vgModes > 6)
			printf("\nPlease, insert a valid option");
	} while(VG_inventory[i].vgModes < 0 || VG_inventory[i].vgModes > 6);
}

void videoGameFormat(int i){
	printf("\nFormat of the Video Game");
	printf("\n0. Physical"); 
	printf("\n1. Digital");
	do {
		printf("\n\nSelect one option: ");
		scanf("%d", &VG_inventory[i].vgFormat);
		if(VG_inventory[i].vgFormat < 0 || VG_inventory[i].vgFormat > 1)
			printf("\nPlease, insert a valid option");
	} while(VG_inventory[i].vgFormat < 0 || VG_inventory[i].vgFormat > 1);
}

void videoGamePrice(int i){
	printf("\nGame selling Price");
	do {
		printf("\nPlease enter a greater than 0 CAD: ");
		scanf("%f", &VG_inventory[i].vgSelling_Price);
		if(VG_inventory[i].vgSelling_Price <= 0)
			printf("\nPlease, insert a valid option");
	} while(VG_inventory[i].vgSelling_Price <= 0);
}

void addVideoGame(int i, int addVGinv){
	do{
		printf("\nInsert SKU: ");
		fflush(stdin);
		fgets(VG_inventory[k].SKU, MAX_LINE_LENGTH, stdin);
		VG_inventory[k].SKU[strlen(VG_inventory[k].SKU)-1] = '\0';
	}while(checkSKU(VG_inventory[k].SKU));

	videoGameName(k);
	videoGameStudio(k);
	videoGameGenre(k);
	videoGameESRB(k);
	videoGameMetacritic(k);
	videoGamePlatform(k);
	videoGamePlayMode(k);
	videoGameFormat(k);
	videoGamePrice(k);

	printf("\nVideo game entered, you can see below the data that was indexed.\n");
	displayInventory(k);
	k++;
}

void populateInventory(){

	int addVGinv = 0;

	do {
		printf("\n\n|==================| 1. Populate the Inventory |===================|\n");
		printf("\nThis is the option to add a new game to the inventory.");
		printf("\nThere are %d indexed Video Games in the inventroy", k);
		printf("\n\nHow many Games do you want to add : ");
		scanf("%d", &addVGinv);

		if(addVGinv > (VGAMEMAXINV-k)) {
			printf("\n|=========================| WARNNING!!!! |=========================|");
			printf("\nThis request overpasses the maximum size of the inventory.\n");
			printf("\nThe max capacity is: %d", VGAMEMAXINV);
			printf("\nThis inventory only has %d slots free", VGAMEMAXINV-k);
		} else if(addVGinv == 0) { // If the user changes his mind, he can return to the main menu.
					printf("\nYou will return to main menu");
			}
		else {
			printf("\n|==================| Inventory information |=======================|");
			printf("\nNumber of games in current inventory: [%d]", k);
			printf("\nThe video game number [%d] will be added to the inventory.", k + 1);
			printf("\nPlease include his details.\n");
		}
	} while(addVGinv < 0 || addVGinv > (VGAMEMAXINV-k));
	
	for(int i = 1; i <= addVGinv; i++) {
		addVideoGame(i, addVGinv);
		if(i < addVGinv) {
			printf("\n|===============| To continue with the next enter. |===============|\n");
			system("pause");
		}
	}

	printf("\nYou have finished to adding games to the inventory.");
	printf("\n|========================| Back the menu |=========================|\n");
    system("pause");
}

void SEARCH_videoGameGenre(int i){
	printf("\nGenre Video Game");
	printf("\n0. Action");
	printf("\n1. Idle");
	printf("\n2. Role-playing");
	printf("\n3. Simulation");
	printf("\n4. Sports");
	printf("\n5. Strategy/RPG");
	printf("\n6. Other");

	do {
		printf("\n\nSelect one option: ");
		scanf("%d", &SEARCH_VG_inventory[i].SEARCH_vgType);
		if(SEARCH_VG_inventory[i].SEARCH_vgType < 0 || SEARCH_VG_inventory[i].SEARCH_vgType > 6)
			printf("\nPlease, insert a valid option");
	} while(SEARCH_VG_inventory[i].SEARCH_vgType < 0 || SEARCH_VG_inventory[i].SEARCH_vgType > 6);
}

void SEARCH_videoGameESRB(int i){
	printf("\nESRB Rating");
	printf("\n0. E"); 
	printf("\n1. E10+"); 
	printf("\n2. T");  
	printf("\n3. M"); 
	printf("\n4. A"); 
	printf("\n5. RP");

	do {
		printf("\n\nSelect one option: ");
		scanf("%d", &SEARCH_VG_inventory[i].SEARCH_vgESRBRating);
		if(SEARCH_VG_inventory[i].SEARCH_vgESRBRating < 0 || SEARCH_VG_inventory[i].SEARCH_vgESRBRating > 5)
			printf("\nPlease, insert a valid option");
	} while(SEARCH_VG_inventory[i].SEARCH_vgESRBRating < 0 || SEARCH_VG_inventory[i].SEARCH_vgESRBRating > 5);
}

void SEARCH_videoGameMetacritic(int i){
	printf("\nInsert the Video Game -	Metacritic Rating");
	do {
		printf("\nFrom 0 to 100: ");
		scanf("%d", &SEARCH_VG_inventory[i].SEARCH_vgRate);
		if(SEARCH_VG_inventory[i].SEARCH_vgRate < 0 || SEARCH_VG_inventory[i].SEARCH_vgRate > 100)
			printf("\nPlease, insert a valid option");
	} while(SEARCH_VG_inventory[i].SEARCH_vgRate < 0 || SEARCH_VG_inventory[i].SEARCH_vgRate > 100);
}

void SEARCH_videoGamePlatform(int i){
	printf("\nPlatform Video Game");
	printf("\n0. PS"); 
	printf("\n1. Xbox"); 
	printf("\n2. Nintendo Switch");  
	printf("\n3. PC"); 
	printf("\n4. Mobile");
	printf("\n5. Google Stadia - Streaming");
	printf("\n6. Amazon Luna - Streaming");
	do {
		printf("\n\nSelect one option: ");
		scanf("%d", &SEARCH_VG_inventory[i].SEARCH_vgPlatform);
		if(SEARCH_VG_inventory[i].SEARCH_vgPlatform < 0 || SEARCH_VG_inventory[i].SEARCH_vgPlatform > 6)
			printf("\nPlease, insert a valid option");
	} while(SEARCH_VG_inventory[i].SEARCH_vgPlatform < 0 || SEARCH_VG_inventory[i].SEARCH_vgPlatform > 6);
}

void SEARCH_videoGamePlayMode(int i){
	printf("\nGame Play Mode: ");
	printf("\n0. Local / Single Player"); 
	printf("\n1. Local / Coop Mode");
	printf("\n2. Local / PvP");
	printf("\n3. Online / Single Player");
	printf("\n4. Online / Coop Mode");
	printf("\n5. Online / PvP");
	do {
		printf("\n\nSelect one option: ");
		scanf("%d", &SEARCH_VG_inventory[i].SEARCH_vgModes);
		if(SEARCH_VG_inventory[i].SEARCH_vgModes < 0 || SEARCH_VG_inventory[i].SEARCH_vgModes > 6)
			printf("\nPlease, insert a valid option");
	} while(SEARCH_VG_inventory[i].SEARCH_vgModes < 0 || SEARCH_VG_inventory[i].SEARCH_vgModes > 6);
}

void SEARCH_videoGameFormat(int i){
	printf("\nFormat of the Video Game");
	printf("\n0. Physical"); 
	printf("\n1. Digital");
	do {
		printf("\n\nSelect one option: ");
		scanf("%d", &SEARCH_VG_inventory[i].SEARCH_vgFormat);
		if(SEARCH_VG_inventory[i].SEARCH_vgFormat < 0 || SEARCH_VG_inventory[i].SEARCH_vgFormat > 1)
			printf("\nPlease, insert a valid option");
	} while(SEARCH_VG_inventory[i].SEARCH_vgFormat < 0 || SEARCH_VG_inventory[i].SEARCH_vgFormat > 1);
}

void SEARCH_videoGamePrice(int i){
	printf("\nGame selling Price");
	do {
		printf("\nPlease enter a greater than 0 CAD: ");
		scanf("%f", &SEARCH_VG_inventory[i].SEARCH_vgSelling_Price);
		if(SEARCH_VG_inventory[i].SEARCH_vgSelling_Price <= 0){
			printf("\nPlease, insert a valid option");
		}
	} while(SEARCH_VG_inventory[i].SEARCH_vgSelling_Price <= 0);
}

void searchByFilter(){

	int option;
	int j = 0;
	int searchFlag = 0;
	
	printf("\n|=======================| 2. Search Games |========================|\n");
	printf("\nThis is the option to search a game into the inventory.");
	printf("\nThere are %d indexed Video Games in the inventroy\n", k);
	system("pause");

	printf("\nSearch Features\n");
	printf("\n1. SKU");
	printf("\n2. Name");
	printf("\n3. Studio");
	printf("\n4. Type");
	printf("\n5. ESRB Rating");
	printf("\n6. Metacritic Rating");
	printf("\n7. Platform");
	printf("\n8. Gameplay");
	printf("\n9. Format of the Game");
	printf("\n10. Selling Price");

	do {
		printf("\n\nSelect search criteria: ");
		scanf("%d", &option);
		if(option > 10 || option < 1)
		printf("\nPlease, insert a valid option");
	} while(option > 10 || option < 1);

	switch(option){

		case 1:
			printf("\nInsert SKU to search: ");
			fflush(stdin);
			fgets(SEARCH_VG_inventory[j].SEARCH_SKU, MAX_LINE_LENGTH, stdin);
			SEARCH_VG_inventory[j].SEARCH_SKU[strlen(SEARCH_VG_inventory[j].SEARCH_SKU)-1] = '\0';
			for(int i = 0; i < k; i++){
				if (strcmp(SEARCH_VG_inventory[j].SEARCH_SKU, VG_inventory[i].SKU) == 0){
					displayInventory(i);
					searchFlag++;
				}
			}
			break;
		case 2:
			printf("\nInsert Name to search: ");
			fflush(stdin);
			fgets(SEARCH_VG_inventory[j].SEARCH_vgName, MAX_LINE_LENGTH, stdin);
			SEARCH_VG_inventory[j].SEARCH_vgName[strlen(SEARCH_VG_inventory[j].SEARCH_vgName)-1] = '\0';
			for(int i = 0; i < k; i++){
				if (strcmp(SEARCH_VG_inventory[j].SEARCH_vgName, VG_inventory[i].vgName) == 0){
					displayInventory(i);
					searchFlag++;
				}					
			}
			break;
		case 3:
			printf("\nInsert Studio to search: ");
			fflush(stdin);
			fgets(SEARCH_VG_inventory[j].SEARCH_vgStudio, MAX_LINE_LENGTH, stdin);
			SEARCH_VG_inventory[j].SEARCH_vgStudio[strlen(SEARCH_VG_inventory[j].SEARCH_vgStudio)-1] = '\0';
			for(int i = 0; i < k; i++){
				if (strcmp(SEARCH_VG_inventory[j].SEARCH_vgStudio, VG_inventory[i].vgStudio) == 0){
					displayInventory(i);
					searchFlag++;
				}
			}
			break;
		case 4:
			printf("\nInsert Type to search: ");
			SEARCH_videoGameGenre(j);
			for(int i = 0; i < k; i++){
				if (SEARCH_VG_inventory[j].SEARCH_vgType == VG_inventory[i].vgType){
					displayInventory(i);
					searchFlag++;
				}
			}
			break;
  		case 5:
			printf("\nInsert ESRB Rating to search: ");
			SEARCH_videoGameESRB(j);	
			for(int i = 0; i < k; i++){
				if (SEARCH_VG_inventory[j].SEARCH_vgESRBRating == VG_inventory[i].vgESRBRating){
					displayInventory(i);
					searchFlag++;
				}
			}
			break;
		case 6:
			printf("\nInsert Metacritic to search: ");
			SEARCH_videoGameMetacritic(j);
			for(int i = 0; i < k; i++){
				if (SEARCH_VG_inventory[j].SEARCH_vgRate == VG_inventory[i].vgRate){
					displayInventory(i);
					searchFlag++;
				}
			}
			break;
		case 7:
			printf("\nInsert Platform to search: ");
			SEARCH_videoGamePlatform(j);
			for(int i = 0; i < k; i++){
				if (SEARCH_VG_inventory[j].SEARCH_vgPlatform == VG_inventory[i].vgPlatform){
					displayInventory(i);
					searchFlag++;
				}
			}
			break;
		case 8:
			printf("\nInsert Gameplay to search: ");
			SEARCH_videoGamePlayMode(j);
			for(int i = 0; i < k; i++){
				if (SEARCH_VG_inventory[j].SEARCH_vgModes == VG_inventory[i].vgModes){
					displayInventory(i);
					searchFlag++;
				}
			}
			break;
		case 9:
			printf("\nInsert Format to search: ");
			SEARCH_videoGameFormat(j);
			for(int i = 0; i < k; i++){
				if (SEARCH_VG_inventory[j].SEARCH_vgFormat == VG_inventory[i].vgFormat){
					displayInventory(i);
					searchFlag++;
				}
			}
			break;
		case 10:
			printf("\nInsert Price to search: ");
			SEARCH_videoGamePrice(j);
			for(int i = 0; i < k; i++){
				if (SEARCH_VG_inventory[j].SEARCH_vgSelling_Price == VG_inventory[i].vgSelling_Price){
					displayInventory(i);
					searchFlag++;
				}
			}
			break;
		}
		
		if(searchFlag == 0){
			printf("\nGame Not Found!!\n\n");
			printf("\nYou have finished to search games in the inventory.");
			printf("\n|========================| Back the menu |=========================|\n");
			system("pause");
		} else {
			printf("\nYou have finished to search games in the inventory.");
			printf("\n|========================| Back the menu |=========================|\n");
			system("pause");
		}
}

void displayCharacteristics(){
	
	int option;
	char editGame_ans;

	do {
		printf("\n\nSelect one option that you want modified: ");
		scanf("%d", &option);
		if(option > 10 || option < 1)
		printf("\nPlease, insert a valid option");
	} while(option > 10 || option < 1);

	switch(option){
		case 1:
			printf("\n!!!WARNING --- SKU CANNOT BE MODIFIED!!!!!");
			system("pause");
			displayInventory(locationSku);
			displayCharacteristics();
			break;
		case 2:
			videoGameName(locationSku);
			break;
		case 3:
			videoGameStudio(locationSku);
			break;
		case 4:
			videoGameGenre(locationSku);
			break;
		case 5:
			videoGameESRB(locationSku);
			break;
		case 6:	
			videoGameMetacritic(locationSku);
			break;
		case 7:
			videoGamePlatform(locationSku);
			break;
		case 8:
			videoGamePlayMode(locationSku);
			break;
		case 9:
			videoGameFormat(locationSku);
			break;
		case 10:
			videoGamePrice(locationSku);
			break;
	}
	
	printf("\nThese are the game whit the new change.");
	displayInventory(locationSku);
	do {
		printf("\nDo you want to change another characteristics? (y/n): \n");
		scanf(" %c", &editGame_ans);
		if(editGame_ans != 'y' && editGame_ans != 'Y' && editGame_ans != 'n' && editGame_ans != 'N')
			printf("\nPlease, the answer is Yes or No: ");
	} while(editGame_ans != 'y' && editGame_ans != 'Y' && editGame_ans != 'n' && editGame_ans != 'N');

	if(editGame_ans == 'y' || editGame_ans == 'Y') {
		displayInventory(locationSku);
		displayCharacteristics();
	}else {
		printf("\n|========================| Back the menu |=========================|\n");
		system("pause");
	}
}

void editVideoGame(){

	int option;
	char editGame_ans;
	int flagSearch = 0;

	printf("\n|==========| 3. Video Game Characteristics Editing Mode |==========|\n");
	printf("\nNOTE: This option modifies the characteristics of the game, \nbut does not allow modifying the SKU.");
	printf("\nInsert the SKU of the game to search: ");
	fflush(stdin);
	fgets(skuTemp, MAX_LINE_LENGTH, stdin);
	skuTemp[strlen(skuTemp)-1] = '\0';
	
	for(int i = 0; i < k; i++){
		if (strcmp(skuTemp, VG_inventory[i].SKU) == 0){
			flagSearch++;
			locationSku = i;
			break;
		}
	}
	
	if (flagSearch == 1){
		printf("\nWe will proceed to modify the characteristics of the following game:");
		displayInventory(locationSku);
		displayCharacteristics();
	}else{	
		printf("Not Found!!\n");
		do {
			printf("\nDo you want to try whit other SKU number? (y/n): \n");
			scanf(" %c", &editGame_ans);
			if(editGame_ans != 'y' && editGame_ans != 'Y' && editGame_ans != 'n' && editGame_ans != 'N')
				printf("\nPlease, the answer is Yes or No: ");
		} while(editGame_ans != 'y' && editGame_ans != 'Y' && editGame_ans != 'n' && editGame_ans != 'N');
	
		if(editGame_ans == 'y' || editGame_ans == 'Y') {
			editVideoGame();
		}else {
			printf("\n|========================| Back the menu |=========================|\n");
			system("pause");
		}
	}
}

void displayVideoGame(){
	printf("\n|================| 4. Inventory Information List |=================|");
    for(int i = 0; i < k; i++) {
		displayInventory(i);
    }
}

int main(){

	int option = 0;
	char invbase_ans;
	int addVGinv = 0;
	
    displayMenu();

	do {
		printf("\n\nSelect one option: ");
		scanf("%d", &option);

		if(option > 5 || option <= 0)
			printf("\nPlease, insert a valid option");

	} while(option > 5 || option <= 0);

	switch(option) {
		case 1:
			if(invbase_flag == 0){
				printf("\nThere is a base inventory to enter with 10 video games.\n");	
				do {
					printf("\nDo you want to add it to the inventory righ now? (y/n): ");
					scanf(" %c", &invbase_ans);
					if(invbase_ans != 'y' && invbase_ans != 'Y' && invbase_ans != 'n' && invbase_ans != 'N')
						printf("\nPlease, the answer is Yes or No: ");
				} while(invbase_ans != 'y' && invbase_ans != 'Y' && invbase_ans != 'n' && invbase_ans != 'N');
				if(invbase_ans == 'y' || invbase_ans == 'Y') {
					baseInventory();
					invbase_flag++;
				}else
					printf("\nInventory will proceed without adding base games");
			}
			populateInventory();
			main();
			break;
		case 2:
			searchByFilter();
			main();
			break;
		case 3:
			editVideoGame();
			main();
			break;
		case 4:
			displayVideoGame();
			printf("\n|========================| Back the menu |=========================|\n");
    		system("pause");
			main();
			break;
		case 5:
			printf("\nHasta la vista!!");
			printf("\nThe inventory will be reset!");
			printf("\nSee you next time!!\n");
			printf("\nThis is the Final Project for ALGORITHMS AND PROGRAMMING\n");
			printf("\nPresented by Luis Davila\n");
			printf("\nCode: 2030057\n");
			printf("\nAEC in Information Technology Programmer-Analyst\n");
			printf("\nLa Salle Collage december 2021\n");
			system("pause");
			break;
		default:
			break;
	}
	exit(EXIT_SUCCESS);
}
