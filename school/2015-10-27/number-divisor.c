#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number[10];
    int i, j;
    int count = 0;

    for (i = 0; i < 9; i++){
        printf("%d - Please, insert the integer value: ", i);
        scanf("%d", &number[i]);

        for (j = 1; j <= number[i]; j++) {
            if (number[i] % j == 0) {
                count++;
            }
        }

        if (count == 2){
            printf("Result: is prime, position: %d", i);
        }else{
            printf("Result: is dont prime");
        }

        count = 0;

        printf("\n-----------------------------------------\n");

    }
}
