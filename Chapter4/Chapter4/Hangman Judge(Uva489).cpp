#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define maxn 100
int left, chance;
char s1[maxn],s2[maxn];
int win, lose;
void guess(char ch)
{
	int bad = 1;
	int n = strlen(s1);
	for (int i = 0; i < n; i++)
			if (s1[i] == ch){left--;s1[i] = ' '; bad = 0;}
		if (bad&&isalpha(ch))
			--chance;
		//printf("%d\n", chance);
		if (!chance&&isalpha(ch))
			lose = 1;
		if (!left)
			win = 1;
}
int main(void)
{
	//freopen("Input(Uva489).txt", "r", stdin);
	//freopen("output(Uva227).txt", "w", stdout);
	int rnd;
	while (scanf("%d",&rnd)==1 && rnd!=-1)
	{
		if (scanf("%s%s", s1, s2) != 2)
			break;
		printf("Round %d\n", rnd);
		win = 0;
		lose = 0;
		left = strlen(s1);
		chance = 7;
		for (int i = 0; i < strlen(s2); i++)
		{
			guess(s2[i]);
			if (win || lose)
				break;
		}
		//printf("%d\n%d\n", win, lose);
		if (win)
			printf("You win.\n");
		else if (lose)
			printf("You lose.\n");
		else
			printf("You chickened out.\n");
	}
	return 0;
}