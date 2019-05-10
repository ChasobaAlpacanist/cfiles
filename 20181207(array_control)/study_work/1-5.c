#include <stdio.h>
#include <assert.h>

//constants
#define ARRAY_SIZE 5

void swap(int array[ARRAY_SIZE], int index_1, int index_2){
  int tmp = array[index_1];
  array[index_1] = array[index_2];
  array[index_2] = tmp;
}

int main(void){
  //initialize
  int index_1 = 0, index_2 = 0;
  int nums[ARRAY_SIZE] = {0};

  for(int i = 0; i < ARRAY_SIZE; i++){
    printf("%d番目の整数を入力:", i + 1);
    scanf("%d", &nums[i]);
  }
  printf("入力された配列は -> ");
  for(int i = 0; i < ARRAY_SIZE - 1; i++){
    printf("%d, ", nums[i]);
  }
  printf("%dです。\n", nums[ARRAY_SIZE - 1]);

  printf("入れ替えたい2つの数字の要素番号を入力してください.(左から");
  for(int i = 0; i < ARRAY_SIZE - 1; i++){
    printf("%d ", i);
  }
  printf("%d)\n", ARRAY_SIZE - 1);

  printf("1つ目:");
  scanf("%d", &index_1);
  printf("2つ目:");
  scanf("%d", &index_2);
  assert((index_1 >= 0 && index_1 < ARRAY_SIZE) && (index_2 >= 0 && index_2 < ARRAY_SIZE));

  swap(nums, index_1, index_2);

  printf("入れ替え後の配列は -> ");
  for(int i = 0; i < ARRAY_SIZE - 1; i++){
    printf("%d, ", nums[i]);
  }
  printf("%dです。\n", nums[ARRAY_SIZE - 1]);
}
