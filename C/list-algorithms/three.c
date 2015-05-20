#include <stdio.h>

int main(){

    int a;
    int result;

    printf("Please, insert the unique value: \n");
    scanf("%d", &a);

    if(((a)%2) == 0){
        printf("The number is divisible per 2 \n");
    }else{
        printf("the number is dosen`t divisible per 2 \n");
    }

}
