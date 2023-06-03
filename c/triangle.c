//
//#include <stdio.h>
//
//#ifndef min
//#define min(a,b)            (((a) < (b)) ? (a) : (b))
//#endif
//
//#define N 10  // Maximum number of rows in the triangle
//
//// Time complexity = O(n^2)
//// Because it's (n(n-1))/2 which is basically n^2/2 so, n^2.
//
//int min_sum(int triangle[N][N], int num_rows)
//{
//    int val_table[N][N];
//
//    // Initialize the bottom row of val_table with the bottom row of the triangle
//    for (int i = 0; i < num_rows; i++)
//    {
//        val_table[num_rows-1][i] = triangle[num_rows-1][i];
//    }
//
//    // Start from the second last row and go up to the top
//    for (int i = num_rows-2; i >= 0; i--)
//    {
//        for (int j = 0; j <= i; j++)
//        {
//            val_table[i][j] = triangle[i][j] + min(val_table[i+1][j], val_table[i+1][j+1]);
//        }
//    }
//
//    // The minimum path sum from the top to the bottom of the triangle
//    // is now stored at the top of dp
//    return val_table[0][0];
//}
//
//int main()
//{
//    int triangle[N][N] =
//    {
//        {2},
//        {5, 4},
//        {1, 4, 7},
//        {8, 6, 9, 6}
//    };
//
//    int num_rows = 4;
//
//    int min_path_sum = min_sum(triangle, num_rows);
//
//    printf("Minimum path sum: %d\n", min_path_sum);
//
//    return 0;
//}

#include <stdio.h>

#ifndef min
#define min(a,b)            (((a) < (b)) ? (a) : (b))
#endif

#define N 10 // Max triangle rows

int main()
{
    int triangle[N][N] =
    {
        {2},
        {5, 4},
        {1, 4, 7},
        {8, 6, 9, 6}
    };

    int num_rows = 4;
    int val_table[N][N];

    // Initialize the bottom row of val_table with the bottom row of the triangle
    for (int i = 0; i < num_rows; i++)
    {
        val_table[num_rows-1][i] = triangle[num_rows-1][i];
    }

    // Start from the second last row and go up to the top
    for (int i = num_rows-2; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            val_table[i][j] = triangle[i][j] + min(val_table[i+1][j], val_table[i+1][j+1]);
        }
    }

    // The minimum path sum from the top to the bottom of the triangle
    // is now stored at the top of dp
    int min_path_sum = val_table[0][0];

    printf("Minimum path sum: %d\n", min_path_sum);

    return 0;
}
