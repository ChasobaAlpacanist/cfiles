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
  //int + double -> int
  int2 = int1 + double1;
  printf("%d + %f = %d\n", int1, double1, int2);

  double double3 = 0.0;
  //int + double -> double
  double3 = int1 + double2;
  printf("%d + %f = %f\n", int1, double2, double3);

  char char2 = 0;
  //char + int -> char
  char2 = char1 + 128;
  printf("%d + %d = %d\n", 128, char1, char2);
  printf("%d + %d = %c\n", 128, char1, char2);

  //char + double -> char
  char2 = double1 + char1;
  printf("%f + %d = %d\n", double1, char1, char2);
  //char + double -> double
  double3 = double1 + char1;
  printf("%f + %d = %f\n", double1, char1, double3);

  unsigned int bit1 = 0x56;
  unsigned int bit2 = 0x6f;

  printf("16進数%xは10進数で%d\n", bit1, bit1);
  printf("16進数%xは10進数で%d\n", bit2, bit2);

  printf("%x << 1 = %x\n", bit1, bit1 << 1); //10進数における2倍に対応
  printf("%x >> 1 = %x\n", bit1, bit1 >> 1); //10進数における1/2倍に対応
  printf("%x >> 1 = %x\n", bit2, bit2 >> 1); //余りはデータ損失となる

  //2進数ではbit1が01010110,bit2が01101111となる
  printf("%x | %x = %x\n", bit1, bit2, bit1 | bit2); //論理和
  //01010110 | 01101111 = 01111111 -> 0x7f

  printf("%x & %x = %x\n", bit1, bit2, bit1 & bit2); //論理積
  //01010110 & 01101111 = 01000110 -> 0x46

  return 0;
}
