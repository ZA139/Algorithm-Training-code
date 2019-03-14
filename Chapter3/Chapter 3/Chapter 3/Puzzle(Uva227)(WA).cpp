#include <stdio.h>
#include <string.h>
#define LOCAL
	typedef struct {
		int r;
		int c;
	} Point;

	int main() {
    #ifdef LOCAL
		freopen("input(Uva227).txt", "r", stdin);
		freopen("output(Uva227).txt", "w", stdout);
    #endif // LOCAL

		const int maxn = 5;
		char puzzle[maxn][maxn] = { 0 };
		int kase = 0;
		int first = 1;
		for (;;) {

			//  1.先读取一个字符,看是不是Z,不是Z得看看是不是空字符
			char ch;
			ch = getchar();
			if (ch == 'Z') break;
			else {
				puzzle[0][0] = ch;
				first == 1 ? first = 0 : printf("\n");
			}

			Point empty;
			if (ch == ' ') { empty.r = 0, empty.c = 0; }

			//  2.读取Puzzle初始化布局
			for (int i = 1; i < 25; ) {
				ch = getchar();
				if (ch == ' ') {
					puzzle[empty.r = i / 5][empty.c = i % 5] = ch;
					i++;
				}
				if (ch != ' ' && ch != '\n' && ch != '\t' && ch != '\r') {
					puzzle[i / 5][i % 5] = ch;
					i++;
				}
			}

			//  3.执行指令
			int configuration = 1;
			while ((ch = getchar()) != '0') {

				if (ch == '\n' || ch == ' ' || !configuration) continue;
				int row = empty.r, col = empty.c;
				if (configuration) {
					switch (ch) {

					case 'A':
						if (row - 1 >= 0) {
							puzzle[row][col] = puzzle[row - 1][col];
							puzzle[row - 1][col] = ' ';
							empty.r = row - 1;
							empty.c = col;
						}
						else {
							configuration = 0;
						}
						break;
					case 'B':
						if (row + 1 < maxn) {
							puzzle[row][col] = puzzle[row + 1][col];
							puzzle[row + 1][col] = ' ';
							empty.r = row + 1;
							empty.c = col;
						}
						else {
							configuration = 0;
						}
						break;
					case 'R':
						if (col + 1 < maxn) {
							puzzle[row][col] = puzzle[row][col + 1];
							puzzle[row][col + 1] = ' ';
							empty.r = row;
							empty.c = col + 1;
						}
						else {
							configuration = 0;
						}
						break;
					case 'L':
						if (col - 1 >= 0) {
							puzzle[row][col] = puzzle[row][col - 1];
							puzzle[row][col - 1] = ' ';
							empty.r = row;
							empty.c = col - 1;
						}
						else {
							configuration = 0;
						}
						break;
					default:
						configuration = 0;
						break;

					}
				}

			}
			//  4.吃掉回车
			ch = getchar();

			//  5.输出
			if (!configuration) {
				printf("Puzzle #%d:\nThis puzzle has no final configuration.\n", ++kase);
			}
			else {
				printf("Puzzle #%d:\n", ++kase);
				for (int row = 0; row < maxn; row++) {

					for (int col = 0; col < maxn; col++) {

						printf(col == maxn - 1 ? "%c" : "%c ", puzzle[row][col]);

					}
					printf("\n");
				}
			}

		}

		return 0;
	}//题解来自http://www.cppblog.com/sixleaves/archive/2015/02/06/209753.aspx