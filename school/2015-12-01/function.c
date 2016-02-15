#include <stdio.h>

int addition(int x, int y)
{
    return (x+y);
}

int sub(int x, int y)
{
    return (x-y);
}

int main()
{
    int x;
    int y;
    int option;
    int total;

    printf("Your options");
    printf("\n* 1 = Addition;");
    printf("\n* 2 = Subtraction;");

    printf("\nPlease, select an option:");
    scanf("%d", &option);

    printf("Please, insert the primary number:");
    scanf("%d", &x);

    printf("\nPlease, insert the secundary number:");
    scanf("%d", &y);

    if(option == 1){
        total = addition(x, y);
        printf("The addition is: %d\n", total);
    }else if (option == 2){
        total = sub(x, y);
        printf("The sub is: %d\n", total);
    }else{
        printf("You selected the invalid option!");
    }

}
