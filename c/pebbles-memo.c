#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 4
#define WIDTH 5

#ifndef max
#define max(a,b)            (((a) > (b)) ? (a) : (b))
#endif

int field[HEIGHT][WIDTH];

int memo[HEIGHT][WIDTH];

char arrows[HEIGHT + WIDTH - 2] = {'x'};

int ask(int y, int x)
{
    if (memo[y][x] != -1)
    {
        return memo[y][x];
    } else {
        if (y == 0 && x == 0)
        {
            return field[y][x];
        }

        //OR
        //if (x < 0 || y < 0)
        //    return 0;

        int a = -1;
        int b = -1;

        if (x > 0)
            a = ask(y, x-1);
        if (y > 0)
            b = ask(y-1, x);

        memo[y][x] = field[y][x] + max(a, b);
        return memo[y][x];
    }
}

int main()
{

    int result = 0;

    srand(time(NULL));

    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            field[i][j] = rand() % 2;
        }
    }

    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            memo[i][j] = -1;
        }
    }

    result = ask(HEIGHT-1, WIDTH-1);

    printf("\nField:\n");

    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            printf("%d ", field[i][j]);
        }
        printf("\n");
    }
    printf("\nMemo table:\n");
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            memo[i][j] == -1 ? printf("1 ") : printf("%d ", memo[i][j]);
        }
        printf("\n");
    }

    printf("\nMax pebbles:\t%d\n", result);

    //printf("Using path:\t");
    //for (int i = 0; i < (HEIGHT + WIDTH - 2); i++)
    //{
    //    printf("%c ", arrows[i]);
    //}
    //printf("\n\n");
    return 0;
}
