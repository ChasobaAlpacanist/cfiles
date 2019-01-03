#include <stdio.h>
#include <math.h>

double square(double num){
  return num * num;
}

int main(void){
  double a = 0.0, b = 0.0, c = 0.0, d = 0.0, e = 0.0;

  printf("1つ目の値を入力：");
  scanf("%lf", &a);
  printf("2つ目の値を入力：");
  scanf("%lf", &b);
  printf("3つ目の値を入力：");
  scanf("%lf", &c);
  printf("4つ目の値を入力：");
  scanf("%lf", &d);
  printf("5つ目の値を入力：");
  scanf("%lf", &e);

  double mean = (a + b + c + d + e) / 5;
  double std_dev = sqrt((square(a - mean) + square(b - mean)
                        + square(c - mean) + square(d - mean) + square(e - mean)) / 5);

  printf("5つの数字%lf,%lf,%lf,%lf,%lfに対して\n", a, b, c, d, e);
  printf("平均は%lf\n", mean);
  printf("標準偏差は%lf\n", std_dev);

  return 0;
}
