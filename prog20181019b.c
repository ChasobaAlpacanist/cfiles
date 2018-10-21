#include <stdio.h>

int main(void){
  int num;
  num = 10;
  float num2 = 0.0;
  float ans = num + num2;

  printf("%d(int) + %f(float) = %.3f(float)\n", num, num2, ans);

  double num3 = 1.25;
  printf("%d(int) + %f(double) = %f(double)\n", num, num3, num + num3);
  printf("明示的キャスト\n");
  printf("%d(int) + %f(double) = %f(double)\n", num, num3, (double)num + num3);

  int num4 = 256;
  printf("%dの10進数は%d\n", num4, num4);
  printf("%dの8進数は%o\n", num4, num4);
  printf("%dの16進数は%x\n", num4, num4);

  double ans2, ans3 = 0.0;
  ans2 = num2 * num3 + num4;
  printf("%.3f * %.3f + %d = %.3f\n", num2, num3, num4, ans2);

  ans3 = num2 * (num3 + num4);
  printf("%.3f * (%.3f + %d) = %.3f\n", num2, num3, num4, ans3);

  int bit = 100;
  int bit2 = 2;
  int ans4 = 0;
  ans4 = bit >> bit2;
  printf("%d >> %d = %d(2^-2倍)\n", bit, bit2, ans4);

  ans4 = bit << bit2;
  printf("%d << %d = %d(2^2倍)\n", bit, bit2, ans4);

  return 0;
}
