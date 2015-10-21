#include <stdio.h>

int main(){

    int total;
    int newTotal;
    int i;
    float media;

    total = 13;
    newTotal = 0;

    for(i=1; i <= 60; i++){
        newTotal = total+newTotal;
        total = total+1;
    }

    printf("total: %d \n \n", newTotal);

    media = newTotal / 60;

    printf("media: %.2f \n \n", media);

}
