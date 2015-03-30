#include <stdio.h>

float main(){

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

  printf("valor de x: %f", addition(x, y));

  return 0;

}

int addition(int x, int y)
{
  int total = x+y;

  return total;
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
