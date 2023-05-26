#include <stdio.h>
#include <stdlib.h>

int main()
{
    int prices[] = {1, 3, 5, 6, 9, 10, 17, 18, 20, 25};
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
    if (r < 0 || r > n)
    {
        printf("\nInvalid input!\n\n");
        return 1;
    }

    // Print prices for reference
    printf("Prices: ");
    for (int i = 0; i < n; i++)
        printf("%d ", prices[i]);

    // Print the optimal value
    printf("\nMaximum sale price: %d\n", price_table[r]);

    // Print the cuts
    printf("With cuts: ");
    while (r > 0)
    {
        printf("%d ", cuts[r]);
        r = r - cuts[r];
    }
    printf("\n");

    return 0;
}
