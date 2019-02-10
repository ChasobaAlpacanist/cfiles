#include <stdio.h>

int num_factorial(int num){
  int sum = 1; //define empty product
  for(int i = 1; i < num + 1; i++){
    sum *= i;
  }
  return sum;
}

int main(void){
  int num = 0;

  printf("正数を入力:");
  scanf("%d", &num);
  while(num < 1){
    printf("入力値が不正です。正の整数で入力してください。:");
    scanf("%d", &num);
  }
  printf("%dの階乗は%dです。\n", num, num_factorial(num));
}
