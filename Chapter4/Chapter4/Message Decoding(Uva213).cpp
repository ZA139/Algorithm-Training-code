#include<stdio.h>
#include<string.h>
int readchar() {//��ȡ�ǻ����ַ�
	for (;;) {
		char ch = getchar();
		if (ch != '\n'&&ch != '\r')
			return ch;
	}
}
int readint(int c) {//����ǰcλ�Ķ����ƶ�Ӧ��ʮ��������
	int temp = 0;
	while(c--)
	temp = temp * 2 + readchar() - '0';
	return temp;
}
int code[8][1 << 8];//�����λ�����λ����Ԫ�飬�����볤�ȣ��Ҳ��Ӧ�Ķ�����ֵ
int readcodes() {//��ȡ����ͷ
	memset(code, 0, sizeof(code));
	code[1][0] = readchar();
	for (int len = 2; len < 8; len++)
	{
		for (int i = 0; i < (1 << len) - 1;i++)
		{
		int ch = getchar();
		if (ch == EOF) return 0;
		if (ch == '\n' || ch == '\r') return 1;
		code[len][i] = ch;//ǰΪ���Ⱥ�Ϊ�����ƶ�Ӧ��ʮ����ֵ�����ų�111�ĳ���
        }
	}
	return 1;
}
int main(void)
{
	while (readcodes())//��ȡ���޷���ȡ�������ͷ
	{
		for (;;)
		{
			int len = readint(3);
			if (len == 0)break;//С�ڽ�������Ϊ000����������
			for (;;) {
				int v = readint(len);
				if (v == (1 << len) - 1) break;//111С�ڽ���
				putchar(code[len][v]);//vΪ��ǰ�����Ʊ����Ӧ��ʮ���Ʊ���
			}
		}
		putchar('\n');
	}
	return 0;
}