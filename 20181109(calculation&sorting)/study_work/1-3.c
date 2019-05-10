#include <stdio.h>

void put_comma(int num){
  if(num < 1000){
    printf("%d", num);
  } else {
    put_comma(num / 1000);
    printf(",%03d", num % 1000);
  }
  return 0;
}

int main(void){
  int number = 0;
  printf("Input the number:");
  scanf("%d", &number);

  printf("Complete putting comma -> ");
  put_comma(number);
  printf("\n");

  return 0;
}
