#include <stdio.h>

int main(){

    float i;
    float value;
    float addition;

    printf("Please, insert a something value:\n");
    scanf("%f", &value);

    addition = 0;
    for(i=1;i <= value; i++){
        addition = addition+(1/i);
    }

    printf("\nTotal result: %f \n", addition);

}
