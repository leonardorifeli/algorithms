#include <stdio.h>

int main(){

    int a;
    int b;

    printf("Hello! You can insert the primary value, please: \n");

    scanf("%d", &a);

    printf("Insert now the secundary value, please: \n");

    scanf("%d", &b);

    if(a < b){
        printf("The primary value is small. \n");
    }

    if(b < a){
        printf("The secundary value is small. \n");
    }

    if(a == b){
        printf("The valus is equals. \n");
    }

}
