#include <stdio.h>
#include <assert.h>

int square_sum(int num){
  int sum = 0;
  while(num > 0){
    sum += num * num;
    num--;
  }

  return sum;
}


int main(void){
  int number = 0;
  printf("Input the natural number:");
  scanf("%d", &number);
  assert(number > 0);

  printf("Sum of squares is %d.\n", square_sum(number));

  return 0;
}
