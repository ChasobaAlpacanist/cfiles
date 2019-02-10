#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <gconio.h>
#include "ascii_arts.h"
#include "battle_command.h"
//_getch()はgetch(), system('cls')はclrscr()を代わりに使った。
int main(void){
  int yuusya_hp = 0, strength = 0, defence= 0;
  int slime_hp = SLIME_HP;

  print_title();
  //waiting for key input
  getch();
  clrscr();

  printf("ようこそ。\n");
  getch();
  printf("あなたは選ばれし勇者さんらしいです。\n");
  getch();
  printf("ステータスを入力してください。\n");
  getch();

  printf("たいりょく:");
  scanf("%d", &yuusya_hp);
  while(yuusya_hp < 1){
    printf("入力値が不正です。1~で入力してください");
    scanf("%d", &yuusya_hp);
  }

  printf("ちから:");
  scanf("%d", &strength);
  while(strength < 1){
    printf("入力値が不正です。1~で入力してください");
    scanf("%d", &strength);
  }

  printf("まもり:");
  scanf(" %d", &defence);
  while(defence < 1){
    printf("入力値が不正です。1~で入力してください");
    scanf("%d", &yuusya_hp);
  }

  printf("ご入力ありがとうございます。装備は床に置いてあります。\n");
  getch();
  getch();
  printf("ひのきのぼうを手に入れた。\n");
  getch();
  printf("布の服を手に入れた。\n");
  getch();
  printf("今のステータスを申し上げます。\n");
  getch();
  int yuusya_power = 2 * 1.1 + strength;
  printf("こうげきりょく:%d\n", yuusya_power);
  getch();
  int yuusya_guard = 2 + defence;
  printf("ぼうぎょりょく:%d\n", yuusya_guard);
  getch();
  printf("HP:%d\n", yuusya_hp);
  getch();
  printf("ではがんばってください。");
  getch();
  clrscr();

  //戦闘シーン
  print_bubble_slime();
  getch();

  battle(yuusya_hp, yuusya_power, yuusya_guard, slime_hp);
  return 0;
}
