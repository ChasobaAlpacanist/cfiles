#include <stdio.h>
#include <assert.h>

void print_binary(int num){
  if(num >= 2){
    print_binary(num / 2);
    printf("%d", num % 2);
  } else {
    switch(num){
      case 1:
        printf("1");
        break;
      default:
        printf("0");
        break;
    }
  }
}

int main(void){
  int num = 0;

  printf("Input the natural number:");
  scanf("%d", &num);
  assert(num >= 0);

  printf("The binary scale of %d is ", num);
  print_binary(num);
  printf("\n");

  return 0;
}
