#include <stdio.h>

void sort(int nums[], int array_size){
  int tmp_nums[3] = {0};
  int max = 0, tmp = 0, min = 0;
  tmp_nums[0] = (nums[0] > nums[1]) ? nums[0] : nums[1];
  tmp_nums[1] = (nums[0] > nums[1]) ? nums[1] : nums[0];

  max = (tmp_nums[0] > nums[2]) ? tmp_nums[0] : nums[2];
  tmp = (tmp_nums[0] > nums[2]) ? nums[2] : tmp_nums[0];
  tmp_nums[0] = max; //Found max value
  tmp_nums[2] = tmp;

  min = (tmp_nums[1] < tmp_nums[2]) ? tmp_nums[1] : tmp_nums[2]; //Found min value
  tmp = (tmp_nums[1] < tmp_nums[2]) ? tmp_nums[2] : tmp_nums[1];
  tmp_nums[1] = tmp;
  tmp_nums[2] = min;

  //sorting
  nums[0] = tmp_nums[0];
  nums[1] = tmp_nums[1];
  nums[2] = tmp_nums[2];
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
