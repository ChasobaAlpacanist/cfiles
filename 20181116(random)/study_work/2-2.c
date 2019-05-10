#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include "janken.h"

#define MAX_MONEY 1000
#define MIN_MONEY 200

int main(void){
  int money = 500; //所持金の初期化
  while(money < MAX_MONEY && money >= MIN_MONEY){
    printf("掛け金200円を頂きます。\n");
    money -= 200;
    if(janken() == WIN){
      printf("勝ったので300円払い戻しします。\n");
      money += 300;
    } else {
      printf("負けたので掛け金は没収です。\n");
    }
    printf("現在の所持金は%d円です。\n\n", money);
  }
  printf("ゲーム終了！\n");

  return 0;
}
