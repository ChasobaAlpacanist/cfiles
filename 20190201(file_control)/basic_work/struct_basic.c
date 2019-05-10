#include <stdio.h>

//Constant
#define STR_MAX 256

//typedef Struct
typedef struct player{
  char name[STR_MAX]; //名前
  int level; //レベル
  int power; //ちから
  double g_rate; //成長率
} player_t; // <-セミコロン

//prototype
void print_all(player_t dt);

int main(void){
  struct player p_1;
  struct player p_2 = {"Chaso", 1, 100, 0.25};

  player_t p_3 = {"Chaso", 2, 200, 0.5};

  print_all(p_1);
  printf("\n");
  print_all(p_2);
  printf("\n");
  print_all(p_3);
}

void print_all(player_t dt){
  printf("名前は%s\n", dt.name);
  printf("レベルは%d\n", dt.level);
  printf("ちからは%d\n", dt.power);
  printf("成長率は%.3lf\n", dt.g_rate);
}
