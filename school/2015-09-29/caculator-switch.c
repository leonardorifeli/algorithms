#include <stdio.h>
#include <stdlib.h>

int main(){

    int numberPrimary;
    int numberSecondary;
    int option;
    float result;

    printf("\n---------------------------------\n");
    printf("Please, choose an option of operation: \n");
    printf("* 1 = Addition \n");
    printf("* 2 = Subtraction \n");
    printf("* 3 = Multiplication \n");
    printf("* 4 = Division \n");
    printf("* 5 = MOD \n");
    printf("* 6 = Exit \n");
    scanf("%d", &option);

    if(option == 6){
        printf("-----BYE----- \n");
        exit(0);
    }

    printf("Please, insert the number primary: ");
    scanf("%d", &numberPrimary);

    printf("\nPlease, insert the number secondary: ");
    scanf("%d", &numberSecondary);

    switch (option){
        case 1:
            result = ((numberPrimary)+(numberSecondary));
            printf("Result addition is: %.2f \n", result);
            break;
        case 2:
            result = ((numberPrimary)-(numberSecondary));
            printf("Result subtraction is: %.2f \n", result);
            break;
        case 3:
            result = ((numberPrimary)*(numberSecondary));
            printf("Result multiplication is: %.2f \n", result);
            break;
        case 4:
            result = ((numberPrimary)/(numberSecondary));
            printf("Result division is: %.2f \n", result);
            break;
        case 5:
            result = (numberPrimary%numberSecondary);
            printf("Result the mod is: %.2f \n", result);
            break;
    }

    printf("\n---------------------------------\n");

}