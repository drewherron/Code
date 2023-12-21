#include <stdio.h>
#include <stdlib.h>

int main()
{
    int k = 0;
    int a = 0, b = 0;

    printf("Integer: ");
    scanf("%d", &k);

    for (int i = 2; i < ((k/2) +1); i++)
    {
        if (k % i == 0)
        {
            a = i;
            b = (k / i);
            break;
        }
    }
    if (a + b == 0)
    {
        printf("%d is a prime number.\n", k);
    }
    else
    {
        printf("%d, %d\n", a, b);
    }
    return 0;
}
