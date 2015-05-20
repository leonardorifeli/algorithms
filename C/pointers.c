#include <stdio.h>

int main(){

  int a = 255;
  int b = &a;

  printf("%d \n", b);
  b = b + 1;
  printf("%d \n", b);
  b = b + 4;
  printf("%d \n", b);

  return 0;

}
