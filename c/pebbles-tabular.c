#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 4
#define WIDTH 5

#ifndef max
#define max(a,b)            (((a) > (b)) ? (a) : (b))
#endif

int field[HEIGHT][WIDTH];

int table[HEIGHT+1][WIDTH+1];

int main()
{
    int result = 0;

    // Random pebbles
    srand(time(NULL));
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            field[i][j] = rand() % 2;
        }
    }
    // Fill buffer column
    for (int i = 0; i < HEIGHT; i++)
    {
        table[i][0] = 0;
    }
    // Fill buffer row
    for (int i = 0; i < WIDTH; i++)
    {
        table[0][i] = 0;
    }
    // Pebbles to table
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            table[i+1][j+1] = field[i][j];
        }
    }
    // Calculate table
    for (int i = 1; i <= HEIGHT; i++)
    {
        for (int j = 1; j <= WIDTH; j++)
        {
            table[i][j] = field[i-1][j-1] + max(table[i-1][j], table[i][j-1]);
        }
    }

    printf("\nField:\n");

    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            printf("%d ", field[i][j]);
        }
        printf("\n");
    }
    printf("\nTabulation:\n");
    for (int i = 1; i <= HEIGHT; i++)
    {
        for (int j = 1; j <= WIDTH; j++)
        {
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }

    printf("\nMax pebbles:\t%d\n", table[HEIGHT][WIDTH]);

    //printf("Using path:\t");
    //for (int i = 0; i < (HEIGHT + WIDTH - 2); i++)
    //{
    //    printf("%c ", arrows[i]);
    //}
    //printf("\n\n");
    return 0;
}
