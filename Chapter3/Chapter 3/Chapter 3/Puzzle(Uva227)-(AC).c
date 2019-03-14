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
	while (gets(a[0])) {//ע������ǵ�һ�У�
		//����
		if (a[0][0] == 'Z') break;//�жϵ��ǵ�һ����ĸ
		if (t) {
			puts("");
		}
		int m = 0, n = 0;
		for (int i = 0; i <= 4; ++i) {
			if (i) {//���ǵ�һ��
				gets(a[i]);
			}
			for (int j = 0; j <= 4; ++j) {
				if (a[i][j] == ' ' || a[i][j] == 0) {//ע�� ǰ�ĸ�λ���Ƿ��пգ�������λ�ã��ַ���β��Ϊ�ղ���ʾ������||ǰ��ĳ�����������ģ�
					a[i][j] = ' ';
					m = i; n = j;//���յ�λ�ü�����
				}
			}
		}

		//�ƶ�
		bool ok = true;
		for (;;) {
			char c = getchar();
			if (c == '0') {
				break;
			}
			bool q = isspace(c);//isspace(c)��������c�Ƿ�Ϊ�հ��ַ�����Ϊ�棬��Ϊ��
			for (int i = 0; i < 4 && ok; ++i) {
				if (c == s[i]) {//cΪR��L��A��B�е�һ��
					q = true;
					int x = m + dir[i][0], y = n + dir[i][1];//���µ�λ������������ɲ���д��ô�ࣩ
					if (x < 0 || x > 4 || y < 0 || y > 4) {
						ok = false;
						break;
					}
					a[m][n] = a[x][y];//���ƶ�λ���ϵ���ĸ���յ�λ��
					a[x][y] = ' ';//����λ��Ϊ��
					m = x, n = y;//���¼��µ�λ��
				}
			}
			if (!q) {// q ��Ϊ���ж��Ƿ��ǿհ��ַ���ʱ��
				ok = false;
			}
		}

		//���
		printf("Puzzle #%d:\n", ++t);
		if (ok) {
			for (int i = 0; i <= 4; ++i) {
				for (int j = 0; j <= 4; ++j) {
					if (j) {
						printf(" ");//��ո��õģ������ĸ��û�ո�
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