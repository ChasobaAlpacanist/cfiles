#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int dice(void){
  srand((unsigned)time(NULL));
  return (rand() % 6) + 1;
}

int main(void){
  printf("ダイスの結果は -> %d\n", dice());

  return 0;
}
