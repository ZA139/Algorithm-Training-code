#include<stdio.h>
#include<string.h>
#define maxn 1010
int a[maxn];
int main(void)
{
	int n, i, j,k,first=1;
	memset(a, 0, sizeof(a));
	//while (scanf("%d%d", &n, &k) == 2)
	scanf("%d%d", &n, &k);
		for (i = 1; i<=k; i++)
		{
			for (j = 1; j <= n; j++)
			{
				if (j%i == 0)
					a[j] = !a[j];
			}
		}
		for (i = 1; i <= n; i++)
		{
			//printf("%d:%d\n", i, a[i]);
			if (a[i])
			{
				if (first)
					first = 0;
				else
					printf(" ");
				printf("%d", i);
			}
		}
		getchar();
		getchar();
	return 0;
}