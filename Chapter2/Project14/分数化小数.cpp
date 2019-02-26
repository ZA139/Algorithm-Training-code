#include<stdio.h>
int main(void)
{
	int a, b, c,counts=0;
	while (scanf("%d%d%d", &a, &b, &c) == 3)
	{
		if (a > 1e6 || b > 1e6 || c > 100 || c < 0)
			break;
		if (a == 0 && b == a && c == a)
			break;
		counts++;
		double d = a / b;
		int integer = d;
		printf("Case %d:%d.", counts, integer);
		a %= b;
		/*if (a== 0)
		{
			
			for (size_t i = 0; i < c; i++)
			{

				printf("0");
			}
			printf("\n");
		}
		else
		{*/
			for (size_t i = 1; i < c; i++)
			{
				
				a *= 10;
				printf("%d", a/b);
				a %= b;
			}
			a *= 10;
			if (((a / b) * 10) / 10 > 5)
				printf("%d\n", (a / b) + 1);
			else
			{
				printf("%d\n", a / b);
			}

		//}
	}
	getchar();
	getchar();
	return 0;
}
