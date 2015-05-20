#include <stdio.h>

int main(){

    int a;
    int b;
    int c;
    int result;

    printf("Please, insert the primary value: \n");
    scanf("%d", &a);

    printf("Please, insert the secundary value. \n");
    scanf("%d", &b);

    printf("Please, insert the tercery value. \n");
    scanf("%d", &c);

    if((a > b) && (a > c))
        printf("The primary value is the big value. \n");
    }else if((b > a) && (b > c)){
        printf("The secundary value is the big value. \n");
    }else if((c > a) && (c > b)){
        printf("The tercery value is the big value. \n");
    }else {
        printf("Something value is the big value. \n");
    }

}
