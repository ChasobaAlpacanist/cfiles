#include <stdio.h>

//PROTOTYPES
void print_title(void);
void print_bubble_slime(void);

/* print_title
  引数：なし
  返り値：なし
  タイトルのAAを表示する関数
*/

void print_title(void){
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
}

/* print_bubble_slime
  引数：なし
  戻り値：なし
  敵のバブルスライムのAAを表示する関数
*/

void print_bubble_slime(void){
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
}
