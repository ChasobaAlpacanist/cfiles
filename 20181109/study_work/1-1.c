#include <stdio.h>
#include <math.h>

double exp_calc(double num){
  double res = 1;
  double term = 1;
  int i = 0;

  double fabsnum = fabs(num);

  do{
    i++;
    term *= fabsnum / i;
    res += term;
  } while(term > 0.0000001);

  if(num >= 0){
    return res;
  } else {
    return (1.0 / res);
  }
}


int main(void){
  double index = 0;

  printf("Input the index:");
  scanf("%lf", &index);
  printf("e^%lf = %.8lf\n", index, exp_calc(index));

  return 0;
}
