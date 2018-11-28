#include <stdio.h>

double stdBMI(int a){
  double m_StdBMI = 22.0, f_StdBMI = 21.0, u_StdBMI = 21.5;
  switch(a){
    case 1:
      return m_StdBMI;
    case 2:
      return f_StdBMI;
    default:
      return u_StdBMI;
  }
}

int main(void){
  int sex = 0;
  double weight = 0, height = 0, bmi = 0, stdWeight = 0, obesityRate = 0; //definition

  //input
  printf("性別を入力:\n");
  printf("1,男性\n2,女性\nそれ以外の数字,男女共用\n");
  scanf("%d", &sex);
  printf("身長を入力[m]:");
  scanf("%lf", &height);
  printf("体重を入力[kg]:");
  scanf("%lf", &weight);

  bmi = weight / (height * height);
  stdWeight = stdBMI(sex) * (height * height);
  obesityRate = (weight / stdWeight - 1) * 100;

  printf("あなたの標準体重は%.2lf[kg]です。\n", stdWeight);
  printf("あなたのBMIは%.2lfです。\n", bmi);
  printf("あなたの肥満度は%.2lf%%です。" , obesityRate);
  if(obesityRate < -10){
    printf("痩せすぎです。\n");
  } else {
    if(obesityRate > 10){
      printf("太りすぎです。\n");
    } else {
      printf("標準です。\n");
    }
  }
  return 0;
}
