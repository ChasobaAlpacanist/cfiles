#include <stdio.h>

int main(void){
  //型指定子の宣言・代入・演算・表示
  int int1 = 0;
  int int2 = 5;
  char char1;
  float float1 = 0.0;
  float float2 = 2.027;
  double double1 = 0.0;
  double double2 = 3.937;

  int1 = 10;
  char1 = 'A';
  float1 = 12.5;
  double1 = 50.825;

  printf("int1の値は%d\n", int1);
  printf("char1の値は%c\n", char1);
  printf("float1の値は%f\n", float1);
  printf("double1の値は%lf\n\n", double1);

  int intsum = 0;
  float floatdif = 0.0;
  double doublepro = 0.0;

  intsum = int1 + int2;
  floatdif = float1 - float2;
  doublepro = double1 * double2;

  printf("%d + %d = %d\n", int1, int2, intsum);
  printf("char1の値は%c\n", char1);
  printf("%f - %f = %f\n", float1, float2, floatdif);
  printf("%lf * %lf = %lf\n\n", double1, double2, doublepro);

  int int3 = 0;
  //int doubleの計算をintで行う。doubleの小数点以下のデータは損失
  int2 = int1 + double1;

  double double3 = 0.0;
  //int doubleの計算をdoubleで行う。intはdoubleに暗黙的キャスト
  double3 = int1 + double2;
  //intのdoubleへの明示的キャスト
  double3 = (double)int1 + double2;

  return 0;
}
