#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Create a default struct to music type/properties
struct Music {
  char name[20];
  char artist[20];
  float duration;
  struct Music *next;
} *Data;

// Define all functions
int displayMenu();
void addMusic();
void listMusic();

int main() {
  setlocale(LC_ALL, "Portuguese");

  // Setup menu vars
  int menuOption, clean;
  Data = NULL;

  // Creating while loop to work with option menu.
  while(1) {
    // Call menu function
    menuOption = displayMenu();

    // Validating invalid option menu
    if(menuOption < 1 || menuOption > 3) {
      printf("Invalid Option.\n\n");
      continue;
    }

    // Check option is to exit
    if(menuOption == 3) {
      printf("Thanks! Bye.\n");
      break;
    }

    // Check option is to list musics
    if(menuOption == 2) {
      listMusic();
      continue;
    }

    // Call func to add music
    addMusic();
  }
}

// Fuction to display menu option
int displayMenu() {
  int menuOption, clean;
  
  printf("\nWELCOME TO RIFELI'S MUSIC STORE (RU 2136681). Our menu: \n");
  printf("***************************** \n");
  printf("[ 1 ] Add music \n");
  printf("[ 2 ] List musics \n");
  printf("[ 3 ] Exit \n");
  printf("***************************** \n");

  // Read menu choice
  scanf("%d", &menuOption);

  // Clean keyboard
  while ((clean = getchar()) != '\n' && clean != EOF) {}

  return menuOption;
}

// Function to add music
void addMusic() {
  int clean;
  
  // Create a new music
  struct Music *newMusic;
	newMusic = (struct Music *)malloc(sizeof(struct Music));
	
  printf("Inserting new music \n");
  
  // Get all music data
  printf("- Music name: \n");
  fgets(newMusic->name, 20, stdin);
  
  printf("- Artist name: \n");
  fgets(newMusic->artist, 20, stdin);
  
  printf("- Duration music: \n");
  scanf("%f", &newMusic->duration);
  while ((clean = getchar()) != '\n' && clean != EOF) {}

  // Check music is empty
	if (Data == NULL) {
    Data = newMusic;
		Data->next = NULL;
    return;
	}

  // Music already exits and adding on next music
	newMusic->next = Data;
  Data = newMusic;
}

// Function to show music
void listMusic() {
  // Create a music list with data
  struct Music *musicList;
	musicList = (struct Music *)malloc(sizeof(struct Music));
  musicList = Data;

  printf("Listing musics \n");

  // Checking music list is empty
  if (Data == NULL) {
    printf("The music list is empty.\n");
    return;
  }

  // Loop to show all music data
  while (musicList != NULL) {
		printf("- Music name: %s", musicList->name);
    printf("- Artist name: %s", musicList->artist);
    printf("- Duration: %.2f\n" , musicList->duration);
		musicList = musicList->next;
    printf("***************************** \n");
	}
}