#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Define sortStores function
void sort(int numbers[4], int totalNumbers);

int main() {
    // Set Portuguese with locale
    setlocale(LC_ALL, "Portuguese");
    
    int numbers[4], i, totalNumbers = 5;

    for(i=0;i < totalNumbers; i++) {
        printf("Please, insert %d number:\n", i + 1);
        scanf("%d", &numbers[i]);
    }

    sort(numbers, totalNumbers);

    printf("\n\n** Thanks! Ordered number list is:\n");
    for(i=0;i < totalNumbers; i++) {
        printf("# %d\n", numbers[i]);
    }
    
    return 0;
}

// Sort stores by int number
void sort(int numbers[4], int totalNumbers) {
    // Data to use on for
    int i, j, temporaryNumber;

    // Parse stores and order price ASC
    for (i = 0; i < totalNumbers - 1; i++) {
        for (j = 0; j < (totalNumbers - 1-i); j++) {
            if (numbers[j] > numbers[j + 1]) {
                temporaryNumber = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temporaryNumber;
            }
        }
    }
}
