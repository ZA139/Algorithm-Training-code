#include<stdio.h>
int main(void)
{
	int a = 0, b = 0, c = 0,counts=0,answer=0;
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (scanf("%d%d%d", &a, &b, &c) == 3)
	{
		counts++;
		int m = a * 70 + b * 21 + c * 15;
		answer = m % 105;
		if (answer >= 10 && answer <= 100)
			printf("Case %d:%d\n", counts, answer);
		else
			printf("Case %d:No answer\n", counts);
	}
	return 0;
}