#include <stdio.h>
#include <stdlib.h>

#ifndef max
#define max(a,b)            (((a) > (b)) ? (a) : (b))
#endif

//int cut_rod(int price[], int n)
//{
//    int *val = (int*) malloc((n+1)*sizeof(int));
//    val[0] = 0;
//
//    for (int i = 1; i<=n; i++)
//    {
//        int max_val = -1;
//
//        for (int j = 0; j < i; j++)
//        {
//            max_val = max(max_val, price[j] + val[i-j-1]);
//        }
//        val[i] = max_val;
//    }
//    return val[n];
//}

int main() {
    int price_list[] = {1, 3, 4, 6, 9, 14, 17, 20, 23, 25};
//    int r = sizeof(arr)/sizeof(arr[0]);
    int r, max_val = 0;
    int cuts[price_list];

    // Make table
    int list_len = 10;
    int table[list_len];
    for (int i = 0; i <= list_len; i++)
    {
        table[i] = 0;
    }

    for (int i = 1; i <=list_len; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            max_val = max(table[i], price_list[j] + table[j-i]);
        }
        table[i] = max_val;

    }

    

    printf("Enter length of rod (max 10): ");
    scanf("%d", &r);

    printf("Max price:\t%\n", table[r]);

    
    return 0;
}


//    printf("Max price:\t%\n", cut_rod(price_list, r));
