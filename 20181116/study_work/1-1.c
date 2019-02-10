#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double rand_generate(void){
  srand((unsigned)time(NULL));
  double rand_num = rand() % 10001; //rand num from 0 to 10000
  rand_num = (rand_num / 100000) - 0.05; //rand num from -0.05 to 0.05
  return rand_num;
}

int main(void){
  printf("Random number -> %.2lf\n", rand_generate());
  
  return 0;
}
