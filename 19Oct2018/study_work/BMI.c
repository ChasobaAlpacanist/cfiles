#include <stdio.h>

int main(void){
  double weight = 0, height = 0;
  double stdBMI = 21.5;

  printf("身長を入力[m]:");
  scanf("%lf", &height);
  printf("体重を入力[kg]:");
  scanf("%lf", &weight);

  double bmi = weight / (height * height);
  double std_weight = height * height * stdBMI;
  double obesity_rate = ((bmi / stdBMI) - 1.0) * 100;
  int int_bmi = (int)bmi;
  int int_std_weight = (int)std_weight;
  int int_obesity_rate = (int)obesity_rate;

  printf("あなたのBMIは%dです。\n", int_bmi);
  printf("小数点2桁では%.2lfです。\n\n", bmi);

  printf("あなたの標準体重は%dです。\n", int_std_weight);
  printf("小数点2桁では%.2lfです。\n\n", std_weight);

  printf("あなたの肥満度は%d%%です。\n", int_obesity_rate);
  printf("小数点2桁では%.2lf%%です。\n", obesity_rate);
}
