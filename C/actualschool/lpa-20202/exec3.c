#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Define all constants to reuse that
#define MIN 1
#define MAX 10
#define DIVISION 10
#define MULTIPLICATION 2;

// Define used functions
int checkFirstCharacter(char character);
void validateOcurrences(char* characters, int quantityN, int quantityM);
int countOcurrences(char* characters, char character, int quantityN, int quantityM);
int checkExists(char name, char* ocurrences, int maxCharacter);
void clearBufffer();

int main() {
    setlocale(LC_ALL, "Portuguese");
    
    // Input vars
    int i, j, uniqueKey = 0, quantityM = 0, quantityN = 0;

    printf("******************************************************* \n");
    printf("*** WELCOME TO RIFELI'S DATA PROCESSOR (RU 2136681) ***\n");
    printf("******************************************************* \n\n");

    // While true to received a valid MxN quantity
    while(1 == 1) {
        printf("Please, insert the rows quantities on matrix (between 1 and 10):\n");
        scanf("%d", &quantityM);

        printf("Please, insert the columns quantities on matrix (between 1 and 10):\n");
        scanf("%d", &quantityN);

        // Validating M or N is correct (min 1 and max 10)
        if(!(quantityM >= MIN && quantityM <= MAX) || !(quantityN >= MIN && quantityN <= MAX)) {
            printf("Invalid number to rows or columns. Try again!\n");
            continue;
        }

        break;
    }

    // Creating a dynamic matrix char to save characters
    char characters[quantityM][quantityN];

    // Creating a unique char vector to save all characters (easy to work)
    char uniqueCharacters[quantityM*quantityN];

    // For loop to save all characters
    for(i=0; i < quantityN; i++) {
        for(j=0; j < quantityM; j++) {
            printf("Please, insert one character (to %d column and %d row): \n", i + 1, j + 1);

            // cleaning up keyboard buffer
            clearBufffer();
            scanf("%s", &characters[i][j]);

            // Saving character to unique vector (more easy to work)
            uniqueCharacters[uniqueKey] = characters[i][j];
            uniqueKey++;
        }
    }
    
    // Calculating ocurrences
    printf("******************************************************* \n");
    printf("CLOUD WORD:\n");
    validateOcurrences(uniqueCharacters, quantityN, quantityM);
    printf("******************************************************* \n\n");

    // Calculating with first character
    int calculation = checkFirstCharacter(uniqueCharacters[0]);
    printf("First character is: %c and the calculation result is: %d\n", uniqueCharacters[0], calculation);
    printf("******************************************************* \n");

    return 0;
}

// Function to check first character and calculating him
int checkFirstCharacter(char character) {
    // Save character with ASCII number
    int parsedCharacter = character;

    // Validating character is UPPER CASE (to division per 10)
    if(parsedCharacter >= 65 && parsedCharacter <= 90)
        return parsedCharacter / DIVISION;
    else if (parsedCharacter >= 97 && parsedCharacter <= 122) // Validating character is LOWER CASE (to multiplication per 2)
        return parsedCharacter * MULTIPLICATION;

    // If invalid character return 0
    return 0;
}

// Function to validate all characters ocurrences
void validateOcurrences(char* characters, int quantityN, int quantityM) {
    int i, ocurrenceIncrement = 0, maxCharacter = quantityM * quantityN;

    char ocurrencesCharacter[maxCharacter];
    int ocurrencesCount[maxCharacter];

    for(i=0; i < maxCharacter; i++) {
        char actualCharacter = characters[i];
        int exists = checkExists(actualCharacter, ocurrencesCharacter, maxCharacter);

        if(exists == -1) {
            int totalOcurrences = countOcurrences(characters, actualCharacter, quantityN, quantityM);
            ocurrencesCharacter[ocurrenceIncrement] = actualCharacter;
            ocurrencesCount[ocurrenceIncrement] = totalOcurrences;
            ocurrenceIncrement++;
            printf("Ocurrence: %c (total %d) \n", actualCharacter, totalOcurrences);
        }
    }
}

// Function to check counted character
int checkExists(char character, char* ocurrences, int maxCharacter) {
    int i;
    for (i = 0; i < maxCharacter; i++)
        if((int) ocurrences[i] == (int) character)
            return i;

    return -1;
}

// Function to count ocurrence
int countOcurrences(char* characters, char character, int quantityN, int quantityM) {
    int i, total = 0;
 
    for(i=0; i < quantityN * quantityM; i++) {
        if((int) characters[i] == (int) character)
            total++;
    }

    return total;
}

// Function to clear keyboard buffer
void clearBufffer() {
    int ch;
    do {
        ch = fgetc(stdin);
    } while (ch != EOF && ch != '\n');
}