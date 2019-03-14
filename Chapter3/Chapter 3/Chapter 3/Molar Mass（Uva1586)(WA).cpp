#include<stdio.h>
#define maxn 90
int main(void)
{
	int element ='\0',T=0;
	int now = 0;
	double mass = 0.0;
	double element_mass[8] = { 12.010,1.008,16.000,14.010 };
	scanf("%d", &T);
	getchar();
	while (T--) 
	{
		while ((element = getchar()) != '\n')
		{
			if ('A'<element&&element<'Z')
			{
				switch (element)
				{
				case'C':
					now = 0;
					break;
				case'H':
					now = 1;
					break;
				case'O':
					now = 2;
					break;
				case'N':
					now = 3;
					break;
				}
				mass += element_mass[now];
			}
			else if ('1'<element&&element<='99')
			{
				mass += element-49 * element_mass[now];
			}
			else
			{
				return 1;
			}
		}
		printf("%.3lf\n", mass);
		mass = 0;
	}
	return 0;
}