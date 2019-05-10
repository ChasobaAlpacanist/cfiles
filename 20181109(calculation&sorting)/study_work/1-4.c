#include <stdio.h>
#include <math.h>

int main(void){
  double dt[10] = {0};
  double sum = 0;
  double mean = 0;
  double std_devi = 0;
  double cv = 0;


  for(int i = 0; i < 10; i++){
    printf("dt[%d] = ?:", i);
    scanf("%lf", &dt[i]);
  }

  //Calculating mean
  for(int i = 0; i < 10; i++){
    sum += dt[i];
  }

  mean = sum / 10;

  //Calculating variance
  double variance = 0;
  for(int i = 0; i < 10; i++){
    variance += (dt[i] - mean) * (dt[i] - mean);
  }
  variance /= 10;

  std_devi = sqrt(variance);
  cv = std_devi / mean;

  printf("The mean of this data is %lf.\n", mean);
  printf("The SD is %lf.\n", std_devi);
  printf("The CV is %lf.\n", cv);

  return 0;
}
