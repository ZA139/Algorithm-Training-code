#include<stdio.h>
#include<string.h>
int readchar() {//读取非换行字符
	for (;;) {
		char ch = getchar();
		if (ch != '\n'&&ch != '\r')
			return ch;
	}
}
int readint(int c) {//返回前c位的二进制对应的十进制数字
	int temp = 0;
	while(c--)
	temp = temp * 2 + readchar() - '0';
	return temp;
}
int code[8][1 << 8];//最高七位，存八位，二元组，左侧编码长度，右侧对应的二进制值
int readcodes() {//读取编码头
	memset(code, 0, sizeof(code));
	code[1][0] = readchar();
	for (int len = 2; len < 8; len++)
	{
		for (int i = 0; i < (1 << len) - 1;i++)
		{
		int ch = getchar();
		if (ch == EOF) return 0;
		if (ch == '\n' || ch == '\r') return 1;
		code[len][i] = ch;//前为长度后为二进制对应的十进制值，且排除111的出现
        }
	}
	return 1;
}
int main(void)
{
	while (readcodes())//读取到无法读取更多编码头
	{
		for (;;)
		{
			int len = readint(3);
			if (len == 0)break;//小节结束后若为000，则编码结束
			for (;;) {
				int v = readint(len);
				if (v == (1 << len) - 1) break;//111小节结束
				putchar(code[len][v]);//v为当前二进制编码对应的十进制编码
			}
		}
		putchar('\n');
	}
	return 0;
}