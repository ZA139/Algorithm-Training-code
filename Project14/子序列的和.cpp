#include<stdio.h>
int main(void)
{
	int n, m,counts=0;double sum = 0;
	while (scanf("%d%d", &n, &m) == 2 && n < m&&m < 1e6&&n!=0&&m!=0)
	{
		
		for (; n <= m; n++)
		{
			sum +=1.0 /n/n ;//��1/��n*n����n�ر��ʱ��n*n�����
		}
		counts++;
		printf("Case %d: %.5lf", counts, sum);
	}
	getchar();
	getchar();
	return 0;
}