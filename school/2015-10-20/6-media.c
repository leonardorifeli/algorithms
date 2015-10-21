#include <stdio.h>
#include <stdlib.h>

int main(){

    int option;
    float n1, n2, n3, p1, p2, p3, media;

    printf("---------------------------------\n");
    printf("Please, choose an option:\n");
    printf("* 1 = Arithmetic Average;\n");
    printf("* 2 = Weighted Average;\n");
    printf("* 0 = Exit\n");
    printf("---------------------------------\n");

    scanf("%d", &option);


    if(option == 0) {
        printf("\nEXIT \n \n");
        exit(0);
    }

    if((option != 1) && (option != 2)) {
        printf("\nOption not found \n");
        exit(0);
    }

    switch(option) {

        case 1:
        printf("Please, insert the value of primary note:\n");
        scanf("%f", &n1);

        printf("Please, insert the value of secondary note:\n");
        scanf("%f", &n2);

        media = ((n1+n2)/2);

        printf("The arithmetic average of notes is: %.2f\n", media);

        break;

        case 2:

        printf("Please, insert the value of primary note:  \n");
        scanf("%f", &n1);

        printf("Please, insert the value of weight for primary note:  \n");
        scanf("%f", &p1);

        printf("Please, insert the value of secondary note: \n");
        scanf("%f", &n2);

        printf("Please, insert the value of weight for secondary note: \n");
        scanf("%f", &p2);

        printf("Please, insert the value of third note:\n");
        scanf("%f", &n3);

        printf("Please, insert the value of weight for third note:\n");
        scanf("%f", &p3);

        media = ((n1*p1+n2*p2+n3*p3) / (p1+p2+p3));

        printf("The weighted average of notes is: %.2f \n", media);

        break;
    }
}
