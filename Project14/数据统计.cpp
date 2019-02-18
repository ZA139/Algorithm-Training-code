#include<stdio.h>
#define INF 1000000000
int main(void)
{
	int x, n = 0, s = 0, kase = 0;
	while (scanf("%d",&n)==1&&n)
	{
		int min = INF, max = -INF;
		int s = 0;
		for (size_t i = 0; i < n; i++)
		{
			scanf("%d", &x);
			s += x;
			if (x > max)max = x;
			if (x < min)min = x;
		}
		if (kase) printf("\n");
		printf("Case %d:%d %d %.3f\n", ++kase, min, max, (double)s / n);
	}
	getchar();
	return 0;
}
