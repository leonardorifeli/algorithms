#include <stdio.h>
#include <mach/mach.h>
#include <mach/mach_vm.h>

void main() {
    int x;
    int y;
    int operator;
    int total;

    printf("Olá, seja bem-vindo. Escolha qual operação deseja efetuar: \n");

    printf("| 0 = Adição \n");
    printf("| 1 = Subtração \n");
    printf("| 2 = Multiplicação \n");
    printf("| 3 = Divisão \n");
    printf("| 4 = Resto \n");

    scanf("%d", &operator);

    printf("Digite o primeiro número (conjunto inteiro): \n");
    scanf("%d", &x);

    printf("Digite o segundo número (conjunto inteiro): \n");
    scanf("%d", &y);

    if(!(operator >= 0 && operador <= 4)) {
        printf("The operator inserted is not supported by system.");
        exit;
    }

    if(operator == 0){
        total = additionAction(x, y);
    }else if(operator == 1){
        total = subtractionAction(x, y);
    }else if(operator == 2){
        total = multiplicationAction(x, y);
    }else if(operator == 3){
        total = divisionAction(x, y);
    }else if(operator == 4){
        total = modeAction(x, y);
    }
}

int additionAction(int x, int y)
{
    return (x)+(y);
}

int subtractionAction(int x, int y)
{
    return (x)-(y);
}

int multiplicationAction(int x, int y)
{
    return (x)*(y);
}

int divisionAction(int x, int y)
{
    if(y == 0)
        return 0;

    return (x)/(y);
}

int modeAction(int x, int y)
{
    return (x)%(y);
}
