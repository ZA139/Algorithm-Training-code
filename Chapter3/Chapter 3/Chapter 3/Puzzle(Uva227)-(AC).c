#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include <ctype.h>
#define maxn 5

const int dir[4][2] = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };
const char s[] = "ABRL";
char a[maxn][maxn];

int main() {
	int t = 0;
	while (gets(a[0])) {//注意读的是第一行！
		//读入
		if (a[0][0] == 'Z') break;//判断的是第一个字母
		if (t) {
			puts("");
		}
		int m = 0, n = 0;
		for (int i = 0; i <= 4; ++i) {
			if (i) {//不是第一行
				gets(a[i]);
			}
			for (int j = 0; j <= 4; ++j) {
				if (a[i][j] == ' ' || a[i][j] == 0) {//注意 前四个位置是否有空，或第五个位置（字符串尾）为空不显示！且若||前面的成立不读后面的！
					a[i][j] = ' ';
					m = i; n = j;//将空的位置记下来
				}
			}
		}

		//移动
		bool ok = true;
		for (;;) {
			char c = getchar();
			if (c == '0') {
				break;
			}
			bool q = isspace(c);//isspace(c)：检查参数c是否为空白字符，是为真，否为假
			for (int i = 0; i < 4 && ok; ++i) {
				if (c == s[i]) {//c为R，L，A，B中的一个
					q = true;
					int x = m + dir[i][0], y = n + dir[i][1];//将新的位置算出（方法巧不用写那么多）
					if (x < 0 || x > 4 || y < 0 || y > 4) {
						ok = false;
						break;
					}
					a[m][n] = a[x][y];//将移动位置上的字母给空的位置
					a[x][y] = ' ';//将新位置为空
					m = x, n = y;//重新记新的位置
				}
			}
			if (!q) {// q 是为了判断是否是空白字符的时候
				ok = false;
			}
		}

		//输出
		printf("Puzzle #%d:\n", ++t);
		if (ok) {
			for (int i = 0; i <= 4; ++i) {
				for (int j = 0; j <= 4; ++j) {
					if (j) {
						printf(" ");//输空格用的，最后字母后没空格
					}
					printf("%c", a[i][j]);
				}
				printf("\n");
			}
		}
		else {
			printf("This puzzle has no final configuration.\n");
		}
	}
	return 0;
}