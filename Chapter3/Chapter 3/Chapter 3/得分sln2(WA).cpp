#include<stdio.h>
#include<string.h>
int main(void)
{
	int score = 0, total = 0,  T,c;
	scanf("%d", &T);
	getchar();
	while (T--)
	{
		while ((c=getchar())!=EOF)
		{
			if (c != 'X'&&c!= 'O')
				break;
			else
			{
				if (c == 'O')
				{
					total += ++score;
				}
				else
				{
					score = 0;
				}
			}
		}
		printf("%d\n", total);
		total = 0;
		score = 0;
	}
	return 0;
}