#include <stdio.h>

int main(){

    float array[10];
    float addition;
    int count;
    int i;


    count = 0;
    for(i=0; i < 10; i++){
        printf("Please, insert a value: ");
        scanf("%f", &array[i]);

        if(array[i] >= 0){
            addition = addition+array[i];
        }else if(array[i]){
            count = count+1;
        }
    }

    printf("\nThe quantity of negative number is: %d", count);
    printf("\nThe sum of positive number is: %2.f\n", addition);

}
