#include<stdio.h>
#include<string.h>
int main(void)
{
	int T = 0;
	scanf("%d", &T);
	while (T--&&T <= 20)
	{
		char buff[10];//��Ŀ�ж���N������Ϊ10000����������Ҫ����7��ϰ������΢����һ��
		int first = 1;//��ʼ��first�������ʽ
		int counts[11] = { 0 };//����ÿ�����ֳ��ִ����Ĵ�����
		memset(buff, 0, sizeof(buff));//ÿ��CASE����buffer����ȫ�����
		int n = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			sprintf(buff, "%d", i);
			//��Ϊsprintf����ÿ�ε����ǻ��ʼ�����鲢���������ݵģ�����Ҫ��ѭ��д��
			for (int i = 0; i < 6; i++)//��ΪN<10000,����С����������
			{
				counts[buff[i] - '0']++;//buff[i]��ASCII���ȥ'0'��Ϊbuff[i]��ʮ����ֵ
			}
		}
		for (int i = 0; i < 10; i++)
		{
			if (first)//�׸���ֱ�����������Ҫ����ո�
			{
				printf("%d", counts[i]);
				first = 0;
			}
			else
				printf(" %d", counts[i]);//ע��ô��пո�
		}
		printf("\n");
	}
	return 0;
}
