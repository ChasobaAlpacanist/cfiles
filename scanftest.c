#include <stdio.h>

int main(void){
  float x;
  printf("Please input your data:");
  scanf("%f", &x);
  printf("Your input data is:%f\n", x);
  printf("%fの二乗は%.3f\n", x, x*x);

  return 0;
}
