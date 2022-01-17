//with error - dangling else problem
#include<stdio.h>
#define x 3
int main()
{
	int a=4;
	if(a<15)
		printf("15");
	else
	{
		if(a<12)
			printf("CS251");
		else
			printf("CS252");
		else
			printf("CS253");
	}
}
