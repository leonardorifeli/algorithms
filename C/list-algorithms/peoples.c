#include <stdio.h>
#include <string.h>

int main(){

    int count = 1;
    int repetion;
    char peopleName[10];
    float peopleAmount = 0;

    char winnerPeopleName[10];
    float winnerPeopleAmount = 0;

    float amountM;

    printf("Please, insert the value to repetion: \n");
    scanf("%d", &repetion);

    if(repetion) {
        while(count <= repetion) {
            printf("Please, insert the name: \n");
            scanf("%s", peopleName);

            printf("Please, insert the paymento of %s: \n", peopleName);
            scanf("%f", &peopleAmount);

            if(peopleAmount > winnerPeopleAmount){
                winnerPeopleAmount = peopleAmount;
                winnerPeopleName = peopleName;
            }

            count++;
        }
    }

    if(winnerPeopleAmount > 0) {
        amountM = winnerPeopleAmount/repetion;
        printf("|------------------------------------------------------\n");
        printf("| The winner people is: %s \n", winnerPeopleName);
        printf("| Total amount is: %f \n", winnerPeopleAmount);
        printf("| Totalm amount is: %f \n", amountM);
        printf("|------------------------------------------------------\n");

    }

    printf("\n \n \n FINISH! \n");

    return 0;
}
