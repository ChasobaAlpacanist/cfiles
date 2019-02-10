#include <stdio.h>

//constants
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
  int nums[ARRAY_SIZE] = {0};
  for(int i = 0; i < ARRAY_SIZE; i++){
    printf("%d番目の整数を入力:", i + 1);
    scanf("%d", &nums[i]);
  }
  printf("最大の整数は -> %d\n", search(nums));

  return 0;
}
