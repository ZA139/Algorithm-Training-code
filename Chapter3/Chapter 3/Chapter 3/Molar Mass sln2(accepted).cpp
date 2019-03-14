#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define maxn 90
int main(void)
{
	char element[maxn];
	int T = 0;
	int now = 0;
	double mass = 0.0;
	double element_mass[8] = { 12.010,1.008,16.000,14.010 };
	scanf("%d", &T);

	while (T--)
	{	
		scanf("%s", element);
	    int n = strlen(element);
		for (size_t i = 0; i < n; i++)
		{
			if ('A' < element[i] && element[i] < 'Z')
			{
				switch (element[i])
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
			else if (isdigit(element[i]))
			{
				if (47<element[i + 1]&&element[i+1]<57)
				{
					mass += ((element[i] - 48) * element_mass[now])*10;
					mass += (element[i + 1]-49)*element_mass[now];
					i ++;
				}
				else
				mass += (element[i]-49) * element_mass[now];
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