#include <stdio.h>
#include <gconio.h>
//_getch()はgetch(), system('cls')はclrscr()を代わりに使った。

int main(void){
  int hp = 0, strength = 0, defence= 0;

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
  while(hp < 1 || hp > 20){
    printf("入力値が不正です。1~20で入力してください");
    scanf("%d", &hp);
  }

  printf("ちから:");
  scanf("%d", &strength);
  while(strength < 1 || strength > 10){
    printf("入力値が不正です。1~10で入力してください");
    scanf("%d", &strength);
  }

  printf("まもり:");
  scanf(" %d", &defence);
  while(defence < 1 || defence > 10){
    printf("入力値が不正です。1~10で入力してください");
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
  printf("仮に今の状態でスライムと戦う場合以下のようになると考えられます。\n");
  getch();
  int damage = power - 2.0/6;
  printf("スライムに攻撃を与えると%d回で倒れるでしょう。\n", (int)(8.0/damage + 0.999));
  getch();
  float damaged = 3 - guard/6;
  printf("スライムから攻撃を受けると%d回耐えられるでしょう。\n", (int)(hp/damaged - 0.001));

  return 0;
}
