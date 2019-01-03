#include <stdio.h>

void sort(int nums[], int array_size){
  for(int i = 0; i < array_size - 1; i++){
    for(int j = i + 1; j < array_size; j++){
      if(nums[i] < nums[j]){
        int tmp = nums[j];
        nums[j] = nums[i];
        nums[i] = tmp;
      }
    }
  }
}

int main(void){
  int array_size = 3;
  int num_array[3] = {0};
  for(int i = 0; i < array_size; i++){
    printf("%dつ目の番号は?:", i + 1);
    scanf("%d", &num_array[i]);
  }
  sort(num_array, array_size);

  printf("%d %d %d\n", num_array[0], num_array[1], num_array[2]);

  return 0;
}
