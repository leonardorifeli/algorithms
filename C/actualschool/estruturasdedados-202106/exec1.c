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


int displayMenu();
void addMusic();
void listMusic();

int main() {
  setlocale(LC_ALL, "Portuguese");

  int menuOption, clean;
  Data = NULL;

  while(1) {
    menuOption = displayMenu();

    if(menuOption < 1 || menuOption > 3) {
      printf("Invalid Option.\n\n");
      continue;
    }

    if(menuOption == 3) {
      printf("Thanks! Bye.\n");
      break;
    }

    if(menuOption == 2) {
      listMusic();
      continue;
    }

    addMusic();
  }
  

}

int displayMenu() {
  int menuOption, clean;
  
  printf("\nWELCOME TO RIFELI'S MUSIC STORE (RU 2136681). Our menu: \n");
  printf("***************************** \n");
  printf("[ 1 ] Add music \n");
  printf("[ 2 ] List musics \n");
  printf("[ 3 ] Exit \n");
  printf("***************************** \n");

  scanf("%d", &menuOption);
  while ((clean = getchar()) != '\n' && clean != EOF) {}

  return menuOption;
}

void addMusic() {
  int clean;
  
  struct Music *newMusic;
	newMusic = (struct Music *)malloc(sizeof(struct Music));
	
  printf("Inserting new music \n");
  
  printf("- Music name: \n");
  fgets(newMusic->name, 20, stdin);
  
  printf("- Artist name: \n");
  fgets(newMusic->artist, 20, stdin);
  
  printf("- Duration music: \n");
  scanf("%f", &newMusic->duration);
  while ((clean = getchar()) != '\n' && clean != EOF) {}

	if (Data == NULL) {
    Data = newMusic;
		Data->next = NULL;
    return;
	}

	newMusic->next = Data;
  Data = newMusic;
}

void listMusic() {
  struct Music *musicList;
	musicList = (struct Music *)malloc(sizeof(struct Music));
  musicList = Data;

  printf("Listing musics \n");

  if (Data == NULL) {
    printf("The music list is empty.\n");
    return;
  }

  while (musicList != NULL) {
		printf("- Music name: %s", musicList->name);
    printf("- Artist name: %s", musicList->artist);
    printf("- Duration: %.2f\n" , musicList->duration);
		musicList = musicList->next;
    printf("***************************** \n");
	}
}

// Função para montar um produto com suas propriedades
// struct Product build(int item, char name[20], int code, float price) {
//   struct Product product;
//   product.item = item;
//   product.name = name;
//   product.code = code;
//   product.price = price;
//   return product;
// }