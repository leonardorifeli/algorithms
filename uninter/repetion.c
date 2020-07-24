#include <stdio.h>

int main(){

    int calc = 10;
    int totalTo = 10;

    int i = 1;
    int j = 1;
    int result;

    for(i=1;i <= calc;i++) {

        printf("----------------------------------------- \n");
        printf("| Calculing the tab of the %d number \n \n", i);

        for(j=1; j <= totalTo;j++){
            result = (i*j);
            printf("| %d x %d = %d \n", i, j, result);
        }

        printf(" \n\n ");
    }

}
