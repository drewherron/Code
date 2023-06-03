#include <stdio.h>

#define MAX 100

int val_table[MAX][MAX];

void init_table()
{
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || j == i)
                val_table[i][j] = 1;
            else
                val_table[i][j] = val_table[i-1][j-1] + val_table[i-1][j];
        }
    }
}

int main()
{
    int N, K;
    init_table();
    printf("Enter N: ");
    scanf("%d", &N);
    printf("Enter K: ");
    scanf("%d", &K);

    if (N > MAX || K > MAX)
    {
        printf("Values must be less than or equal to %d\n", MAX);
        return 1;
    }

    if(N < K)
    {
        printf("N must be greater than or equal to K\n");
        return 1;
    }

    printf("%d\n", val_table[N][K]);

    return 0;
}

