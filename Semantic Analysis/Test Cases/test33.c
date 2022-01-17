//Simple for loop 
#include <stdio.h>
int main()
{
    int num, count, sum = 0;

    printf("Enter your number ");
    scanf("%d", &num);


    for(count = 1; count <= num; ++count)
    {
        sum += count;
    }

    printf("Sum = %d", sum);
}