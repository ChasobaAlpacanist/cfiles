#include <stdio.h>
#include <stdlib.h>
#include <gconio.h>
#include <time.h>
//_getch()はgetch(), system('cls')はclrscr()を代わりに使った。

//スライムの攻撃の関数
int slime_damage(int a, int slime_hp, int slime_power, int guard){
  if(slime_hp > 1){
    printf("スライムのこうげき！\n");
    getch();
    double power_coefficient = 0.9 + (float)(rand() % 1001) * 0.0002;
    int attack = (int)(power_coefficient * slime_power - (double)guard / 6);
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

int main(void){
  int hp = 0, strength = 0, defence= 0;
  int slime_hp = 15, slime_power = 3, slime_guard = 4, command = 0;

  printf("*************************************************************************\n\n\n");
  printf("          *         ***             *         *      \n");
  printf("          **            *            *         *      \n");
  printf("        **                     **********      *     \n");
  printf("       **          ******           *          *  ** \n");
  printf("      *               **          ***          ***   \n");
  printf("      **              *          *  *         *      \n");
  printf("      **            ***         *  *       **       \n");
  printf("        **          *  *          ***       *        \n");
  printf("          **        *   *            *       **       \n");
  printf("          **      *    ****       **         ********\n\n\n");
  printf("*************************************************************************\n");
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
  scanf("%d", &hp);
  while(hp < 1){
    printf("入力値が不正です。1~で入力してください");
    scanf("%d", &hp);
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
    scanf("%d", &hp);
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
  int power = 2 * 1.1 + strength;
  printf("こうげきりょく:%d\n", power);
  getch();
  int guard = 2 + defence;
  printf("ぼうぎょりょく:%d\n", guard);
  getch();
  printf("HP:%d\n", hp);
  getch();
  printf("ではがんばってください。");
  getch();
  clrscr();

  //戦闘シーン
  printf("                            ｒ'￣i\n");
  printf("      　 , - ､　　　　　　　　ﾞ‐- '\n");
  printf("      　{　　 }　　　　　　　　　　　　r'⌒',\n");
  printf("      　`‐-‐'　　　　　 r'⌒',　　　　　!、_丿\n");
  printf("        　　◯　　　　　　ヽ-‐'　　   ＿＿＿\n");
  printf("      　　　　　　 ｒ'⌒',　　 ,,r-‐'　　　　　`''ヽ､　　○\n");
  printf("      　　　　　  　` ‐-' 　／　　　　　　　　　　 ＼\n");
  printf("      　　　　　 　, ､ ,,／ r‐､（･） （･）＿　　　　　'─--､,,\n");
  printf("      　　    ,,r-─（＿）　　ヽ、`── '　 ノ　　　　i⌒)　　 `,\n");
  printf("      　   （　　　　　　　　　　`'‐──‐'´　　　　　￣　　,r‐\n");
  printf("      　   　￣つ　　　　'⌒'　　　　　　　　　　　,r─‐‐''\n");
  printf("      　   　 (´　　　　　　　　　　.........,r──'\n");
  printf("      　   　　￣￣ﾞ'───--------‐'\n");
  printf("*****************************************************************************\n");

  printf("バブルスライムがあらわれた！\n");
  getch();

  while(slime_hp > 1 && hp > 1){
    printf("勇者はどうする！（HP:%d）\n", hp);
    printf("1.こうげき\n2.ぼうぎょ\n3.まほう\n4.にげる\n");
    scanf("%d", &command);
    switch(command){
      case 1:
        printf("勇者のこうげき！\n");
        getch();
        srand((unsigned int)time(NULL)); //乱数の初期化
        double power_coefficient = 0.9 + (float)(rand() % 1001) * 0.0002;
        int attack = (int)(power_coefficient * power - (double)slime_guard / 6);
        printf("%dのダメージを与えた！\n", attack);
        getch();
        slime_hp -= attack;
        hp -= slime_damage(0, slime_hp, slime_power, guard);
        break;

      case 2:
        printf("勇者は身を守っている。\n");
        getch();
        hp -= slime_damage(1, slime_hp, slime_power, guard);
        break;

      case 3:
        printf("しかし何もおこならなかった！\n");
        getch();
        hp -= slime_damage(0, slime_hp, slime_power, guard);
        break;

      case 4:
        printf("しかし回り込まれてしまった！\n");
        hp -= slime_damage(0, slime_hp, slime_power, guard);
        break;
    }
  }

  if(hp < 1){
    printf("勇者は倒れてしまった！\n");
  } else {
    printf("やった！スライムを倒した！\n");
  }
  return 0;
}
