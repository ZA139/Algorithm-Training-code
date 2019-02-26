#include<stdio.h>
#include<string.h>
int main(void)
{
	int i, c;
	char keybord[] = "`1234567890-=QWERTYUIOP[]\ASDFGHJKL;'ZXCVBNM,./";
	while ((c=getchar())!=EOF)
	{
		for (i = 1; keybord[i] && keybord[i] != c; i++);
		if (keybord[i])
			putchar(keybord[i -1]);
		else
			putchar(c);

	}
	return 0;
}