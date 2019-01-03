#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

//DEFINITIONS

#define SLIME_HP 15
#define SLIME_GUARD 4
#define SLIME_POWER 3

#define NOGUARD 0
#define GUARD 1

#define ATTACK 1
#define DEFENCE 2
#define MAGIC 3
#define RUN 4

//PROTOTYPES
int slime_damage(int a, int slime_hp, int yuusya_guard);
void yuusya_damage(int yuusya_power, int yuusya_hp, int slime_hp, int yuusya_guard, int command);
void battle(int yuusya_hp, int yuusya_power, int yuusya_guard, int slime_hp);

/* slime_damage
  引数：a -> 勇者が防御しているかを数字に変換。
       yuusya_guard -> 勇者の防御力を表す。
  返り値：スライムが与えたダメージを返す。
  注意：aは 0or1
*/

int slime_damage(int a, int slime_hp, int yuusya_guard){
  if(slime_hp > 1){
    printf("スライムのこうげき！\n");
    getch();
    srand((unsigned int)time(NULL));
    double power_coefficient = 0.9 + (float)(rand() % 1001) * 0.0002;
    int attack = (int)(power_coefficient * SLIME_POWER - (double)yuusya_guard / 6);
    switch(a){
      case 0: //非防御時
        printf("%dのダメージを受けた！\n", attack);
        getch();
        return attack;
      case 1: //防御時
        attack = attack / 2;
        printf("%dのダメージを受けた！\n", attack);
        getch();
        return attack;
    }
  } else {

  }
  return 0;
}

/* yuusya_damage
  引数：yuusya_power -> 勇者の攻撃力
       yuusya_hp -> 勇者のHP
       yuusya_guard -> 勇者の防御力
       slime_hp -> スライムのHP
       command -> 勇者の行動
  返り値：なし
  勇者がダメージを与え、スライムの反撃が来るまでの一連の流れを表す。
  注意：1 <= command <= 4
*/

void yuusya_damage(int yuusya_power, int yuusya_hp, int slime_hp, int yuusya_guard, int command){
  printf("勇者はどうする！（HP:%d）\n", yuusya_hp);
  printf("1.こうげき\n2.ぼうぎょ\n3.まほう\n4.にげる\n");
  scanf("%d", &command);
  switch(command){
    case ATTACK:
      printf("勇者のこうげき！\n");
      getch();
      srand((unsigned int)time(NULL)); //乱数の初期化
      double power_coefficient = 0.9 + (float)(rand() % 1001) * 0.0002;
      int attack = (int)(power_coefficient * yuusya_power - (double)SLIME_GUARD / 6);
      printf("%dのダメージを与えた！\n", attack);
      getch();
      slime_hp -= attack;
      yuusya_hp -= slime_damage(NOGUARD, slime_hp, yuusya_guard);
      break;

    case DEFENCE:
      printf("勇者は身を守っている。\n");
      getch();
      yuusya_hp -= slime_damage(GUARD, slime_hp, yuusya_guard);
      break;

    case MAGIC:
      printf("しかし何もおこならなかった！\n");
      getch();
      yuusya_hp -= slime_damage(NOGUARD, slime_hp, yuusya_guard);
      break;

    case RUN:
      printf("しかし回り込まれてしまった！\n");
      yuusya_hp -= slime_damage(NOGUARD, slime_hp, yuusya_guard);
      break;
  }
}

/* battle
  引数：yuusya_hp -> 勇者のHP
       yuusya_power -> 勇者の攻撃力
       yuusya_guard -> 勇者の守備力
       slime_hp -> スライムのHP
  返り値：なし
  勇者とスライムの勝敗がつくまでの戦いの流れを表す。
*/

void battle(int yuusya_hp, int yuusya_power, int yuusya_guard, int slime_hp){
  while(slime_hp >= 1 && yuusya_hp >= 1){
    int command = 0;
    printf("勇者はどうする！（HP:%d）\n", yuusya_hp);
    printf("1.こうげき\n2.ぼうぎょ\n3.まほう\n4.にげる\n");
    scanf("%d", &command);
    assert(command >= 1 && command <= 4);
    yuusya_damage(yuusya_power, yuusya_hp, slime_hp, yuusya_guard, command);
  }
  if(yuusya_hp < 1){
    printf("勇者は倒れてしまった！\n");
  } else {
    printf("やった！スライムを倒した！\n");
  }
}
