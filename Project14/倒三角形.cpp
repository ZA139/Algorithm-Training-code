#include<stdio.h>
int main(void)
{int n, i, j, k,line=1;
	while (scanf("%d", &n) == 1)
	{
		int m = n;
		for (i = 0; i < n; i++)
		{
			for (j = 1; j < line; j++)
				printf(" ");
			line++;
			for (k = 0; k < (2 * m - 1); k++)
				printf("#");
			printf("\n");
			m--;
		}
	}
	getchar();
	getchar();
	return 0;
}