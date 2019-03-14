#include<stdio.h>
#include<string.h>
#define maxn 90
int main(void)
{
	int score = 0, total = 0, i,T;
	scanf("%d", &T);
	while (T--)
	{
		char s[maxn] = { 0 };
		scanf("%s", s);
		int n = strlen(s);
		for (i = 0; i < n; i++)
		{
			if (s[i] != 'X'&&s[i] != 'O')
				break;
			else
			{
				if (s[i] == 'O')
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