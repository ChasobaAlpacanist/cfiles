#include <stdio.h>

int main(void){
  int num = 1;

  while(num > 0){
    printf("整数を入力：");
    scanf("%d", &num);

    if(num < 0){
      break;
    } else {
      if(num % 2 == 1){
        printf("Odd\n");
      } else {
        printf("Even\n");
      }
    }
  }
  return 0;
}
