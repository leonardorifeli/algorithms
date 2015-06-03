#include <stdio.h>

int main(){

    int total = 1;
    int par = 0;
    int count = 1;
    int plus = 0;

    while(count <= 100){

        plus = plus + par;
        par = par + 2;

        printf("Count: %d | Amount par: %d \n", total, par);
        total++;
        count++;

        printf("Plus: %d \n\n", plus);


    }

    printf("------------------------- \n | Plus: %d \n ------------------------- \n", plus);

}
