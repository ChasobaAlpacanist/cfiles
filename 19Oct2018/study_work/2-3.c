#include <stdio.h>

int main(void){
  double cel_deg = 0.0;

  printf("摂氏温度を入力：");
  scanf("%lf", &cel_deg);

  double fah_deg = ((cel_deg * 9) / 5) + 32;
  printf("摂氏%.2lf度は華氏%.2lf度となる。\n", cel_deg, fah_deg);

  return 0;
}
