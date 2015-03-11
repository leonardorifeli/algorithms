#include <stdio.h>

void main(){

  int operator;
  float x;
  float y;
  float total;

  printf("Olá, seja bem-vindo. Escolha qual operação deseja efetuar: \n");

  printf("| 0 = Adição \n");
  printf("| 1 = Subtração \n");
  printf("| 2 = Multiplicação \n");
  printf("| 3 = Divisão \n");

  scanf("%d", &operator);

  printf("Digite o primeiro número (conjunto inteiro): \n");
  scanf("%f", &x);

  printf("Digite o segundo número (também no conjunto inteiro): \n");
  scanf("%f", &y);

  if(operator == 0){
    total = addition(20.5, 20.5);
    printf("total: %f", total);
    printf('\n');
  }else if(operator == 1){

  }else if(operator == 2){

  }else if(operator == 3){

  }else{
    printf("Você não digitou o número da operação. \n");
  }

  return int 0;

}

void addition(float x, float y)
{
  float total = x+y;

  return float total;
}

/*
subtraction()
{
}

int multiplication()
{
}

int division()
{
}
*/
