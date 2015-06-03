#include <stdio.h>

int main(){

    int count = 1;

    while(count <= 10){
        printf("Loop number: %d \n\n", count);

        count++;
    }

    count = 1;
    printf("Other repetion structure \n");

    do{
      printf("Loop number: %d \n\n", count);
      count++;
    }while(count <= 10);

    printf("Other repetion structure \n");


    for(count=1; count <= 10; count++){
      printf("Loop number: %d \n\n", count);
    }

}
