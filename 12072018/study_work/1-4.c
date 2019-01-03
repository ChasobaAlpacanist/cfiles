#include <stdio.h>
#include <assert.h>

//constants
#define ARRAY_SIZE 5

//flag identifier
#define MAX 0
#define MIN 1

int search(int array[ARRAY_SIZE], int flag){
  if(flag == 0){
    int max_value = array[0];
    for (int i = 1; i < ARRAY_SIZE; i++){
      if(max_value < array[i]){
        max_value = array[i];
      }
    }
    return max_value;
  } else {
    int min_value = array[0];
    for (int i = 1; i < ARRAY_SIZE; i++){
      if(min_value > array[i]){
        min_value = array[i];
      }
    }
    return min_value;
  }
}

int main(void){
  int flag = 0;
  int nums[ARRAY_SIZE] = {0};
  for(int i = 0; i < ARRAY_SIZE; i++){
    printf("%d番目の整数を入力:", i + 1);
    scanf("%d", &nums[i]);
  }
  printf("Find max -> 0, Find min -> 1:");
  scanf("%d", &flag);

  assert(flag == 0 || flag == 1);

  if(flag == 0){
    printf("この配列の最大の整数は -> %d\n", search(nums, flag));
  } else {
    printf("この配列の最小の整数は -> %d\n", search(nums, flag));
  }

  return 0;
}
