#include <stdio.h>
#include <assert.h>

//constants
#define ARRAY_SIZE 5

//flag identifier
#define UP 0
#define DOWN 1

void swap(int array[ARRAY_SIZE], int index_1, int index_2){
  int tmp = array[index_1];
  array[index_1] = array[index_2];
  array[index_2] = tmp;
}

void sort(int array[ARRAY_SIZE], int flag){
  if(flag == 0){
    for(int i = 0; i < ARRAY_SIZE - 1; i++){
      for(int j = 0; j < (ARRAY_SIZE - 1) - i; j++){
        if(array[j] < array[j + 1]){
          swap(array, j, j + 1);
        } else {

        }
      }
    }
  } else {
    for(int i = 0; i < ARRAY_SIZE - 1; i++){
      for(int j = 0; j < (ARRAY_SIZE - 1) - i; j++){
        if(array[j] > array[j + 1]){
          swap(array, j, j + 1);
        } else {

        }
      }
    }
  }
}

int main(void){
  //initialize
  int flag = 0;
  int nums[ARRAY_SIZE] = {0};

  for(int i = 0; i < ARRAY_SIZE; i++){
    printf("%d番目の整数を入力:", i + 1);
    scanf("%d", &nums[i]);
  }
  printf("入力された配列は -> ");
  //without last index
  for(int i = 0; i < ARRAY_SIZE - 1; i++){
    printf("%d, ", nums[i]);
  }
  //last index
  printf("%dです。\n", nums[ARRAY_SIZE - 1]);

  printf("descending order -> 0, ascending order -> 1:");
  scanf("%d", &flag);
  assert(flag == 0 || flag == 1);

  sort(nums, flag);
  printf("入れ替え後の配列は -> ");
  for(int i = 0; i < ARRAY_SIZE - 1; i++){
    printf("%d, ", nums[i]);
  }
  //last index
  printf("%dです。\n", nums[ARRAY_SIZE - 1]);
}
