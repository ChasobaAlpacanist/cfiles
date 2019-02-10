#include <stdio.h>

#define ARRAY_SIZE 10

int search(int array[ARRAY_SIZE]){
  int max_value = array[0];
  for (int i = 1; i < ARRAY_SIZE; i++){
    if(max_value < array[i]){
      max_value = array[i];
    }
  }
  return max_value;
}

int main(void){
  int nums[ARRAY_SIZE] = {12, 39, 13, 139, 13, 64, 71, 82, 219, 1};
  printf("配列の要素は -> ");
  for(int i = 0; i < ARRAY_SIZE; i++){
    printf("%d ", nums[i]);
  }
  printf("の10個です。\n");
  printf("この配列の最大の整数は -> %d\n", search(nums));

  return 0;
}
