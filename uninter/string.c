#include <stdio.h>
#include <string.h>

int executeSum(int *a, int b) {
    *a = 10;
    return *a + b;
}

int main(){

    char peopleName[ ] = "RIFELI";
    int sum = 0;
    int a = 2;
    int b = 3;

    printf("THE PEOPLE NAME IS: %s \n\n", peopleName);
    printf("a value is %d \n", a);

    sum = executeSum(&a, b);
    printf("a value is %d \n", a);
    printf("sum is %d \n", sum);

    return 0;
}
