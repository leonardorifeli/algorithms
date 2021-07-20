#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Create a default struct to Student type/properties
struct Student {
  char *name;
  char *email;
  int registerCode;
};

// Define a const with max student
#define STUDENT_COUNT 11

// create a list of student with hashTable
struct Student hashTable[STUDENT_COUNT]; 

// Define build function
void buildHashTable();
void build(char name[50], char email[50], int registerCode);
void searchStudent(int studentRegisterCode);
int createHashIndex(int registerCode);
int displayMenu();

int main() {
  setlocale(LC_ALL, "Portuguese");

  // Setup vars
  int menuOption, clean, studentRegisterCode;

  // build hash table with -1 value
  buildHashTable();

  // build students
  build("Leandro", "leandro@gmail.com", 30234181);
  build("Moacir", "moacir@gmail.com", 42356681);
  build("Alcides", "alcides@gmail.com", 34158689);
  build("João", "joao@gmail.com", 15953688);
  build("José", "jose@gmail.com", 96366784);
  build("Leonardo Rifeli", "leonardorifeli@gmail.com", 2136681); //me
  build("Marlei", "marlei@gmail.com", 5336691);
  build("Thuany", "thuany@gmail.com", 4636689);
  build("Vitória", "vitoria@gmail.com", 7936683);
  build("Valentina", "valentina@gmail.com", 1736684);

  while(1) {
    // show menu
    menuOption = displayMenu();

    // Validating invalid option menu
    if(menuOption < 1 || menuOption > 2) {
      printf("Invalid Option.\n\n");
      continue;
    }

    // Check option is to exit
    if(menuOption == 2) {
      printf("Thanks! Bye.\n");
      break;
    }

    // Getting RU (register code) to find student
    printf("Please, key the Student's RU (register code): \n");
    scanf("%d", &studentRegisterCode);

    // clean keyboard
    while ((clean = getchar()) != '\n' && clean != EOF) {}

    // Try to match the student
    searchStudent(studentRegisterCode);
  }
}

// function to match saved student with register code
void searchStudent(int studentRegisterCode) {
  int index = createHashIndex(studentRegisterCode);

  // check has student
  while(hashTable[index].registerCode != -1) {
    // check the student is the register code
    if(hashTable[index].registerCode == studentRegisterCode) {
      printf("Student founded:\n");
      printf("- Name: %s\n", hashTable[index].name);
      printf("- Email: %s\n", hashTable[index].email);
      printf("- Register code: %d\n\n ", hashTable[index].registerCode);
      return;
    }

    // increment index to find
    index = createHashIndex(++index);
  }

  printf("Student not found\n");
}

// Fuction to display menu option
int displayMenu() {
  int menuOption, clean;
  
  printf("\nWELCOME TO RIFELI'S MUSIC STORE (RU 2136681). Our menu: \n");
  printf("***************************** \n");
  printf("[ 1 ] Search Student \n");
  printf("[ 2 ] Exit \n");
  printf("***************************** \n");

  // Read menu choice
  scanf("%d", &menuOption);

  // Clean keyboard
  while ((clean = getchar()) != '\n' && clean != EOF) {}

  return menuOption;
}

// build hash table with register code equal -1
void buildHashTable() {
  int i;
  for(i = 0; i < STUDENT_COUNT; i++) {
    hashTable[i].registerCode = -1;
  }
}

// build student
void build(char name[50], char email[50], int registerCode) {
  int mainIndex = createHashIndex(registerCode);
  while(hashTable[mainIndex].registerCode != -1) {
    mainIndex = createHashIndex(mainIndex + 1);
  }

  struct Student newStudent;
  newStudent.name = name;
  newStudent.email = email;
  newStudent.registerCode = registerCode;

  hashTable[mainIndex] = newStudent;
}

// create hash with mod by register code & student count
int createHashIndex(int registerCode) {
  return registerCode % STUDENT_COUNT;
}