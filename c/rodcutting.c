#include <stdio.h>
#include <stdlib.h>

#ifndef max
#define max(a,b)            (((a) > (b)) ? (a) : (b))
#endif

void main()
{
    int prices[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = sizeof(prices)/sizeof(prices[0]);
    int price_table[n+1], cuts[n+1];
    int i, j, r;

    // Initialize the price_table array
    for (i = 0; i <= n; i++)
        price_table[i] = 0;

    // Build up price_table[] and cuts[]
    for (i = 1; i <= n; i++)
    {
        int max_val = -1;

        for (j = 1; j <= i; j++)
        {
            if (max_val < prices[j-1] + price_table[i-j])
            {
                max_val = prices[j-1] + price_table[i-j];
                cuts[i] = j;
            }
        }
        price_table[i] = max_val;
    }
    // Get length from user
    printf("Length of rod: ");
    scanf("%d", &r);

    // Print the optimal value
    printf("Maximum obtainable value is %d\n", price_table[r]);

    // Print the cuts
    printf("Cuts: ");
    while (r > 0) {
        printf("%d ", cuts[r]);
        r = r - cuts[r];
    }
    printf("\n");
}