#include<stdio.h>
#include<string.h>
int main(void)
{
	int count = 0;
	char s[20], buf[99];
	scanf("%s", s);
	for (int abc = 111; abc <= 999; abc++)
	{
		for (int de = 11; de <= 99; de++)
		{
			int x = abc * (de % 10), y = abc * (de / 10), z = abc * de;
			sprintf(buf, "%d%d%d%d%d", abc, de, x, y, z);
			int right = 1;
			for (int i = 0; i < strlen(buf); i++)
			{
				if (strchr(s, buf[i]) == NULL)
					right = 0;
			}
			if (right)
			{
				printf("<%d>\n", ++count);
				printf("..%d\nX..%d\n-----\n.%d\n%d.\n----\n%d\n\n", abc, de, x, y, z);
			}
		}
	}
	printf("The number of solutions = %d\n", count);
	getchar();
	getchar();
	return 0;
}