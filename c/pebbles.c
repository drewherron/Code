#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 4
#define WIDTH 5

#ifndef max
#define max(a,b)            (((a) > (b)) ? (a) : (b))
#endif

int field[HEIGHT][WIDTH];

char arrows[HEIGHT + WIDTH - 2] = {'x'};

int ask(int y, int x)
{
    if (y == 0 && x == 0)
    {
        return field[y][x];
    }

    int a = -1;
    int b = -1;
    
    if (x > 0)
        a = ask(y, x-1);
    if (y > 0)
        b = ask(y-1, x);
   
    return field[y][x] + max(a, b);
}

int main() {

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
            printf("%d ", field[i][j]);
        }
        printf("\n");
    }

    result = ask(HEIGHT-1, WIDTH-1);

    printf("Max pebbles:\t%d\n", result);

    printf("Using path:\t");
    for (int i = 0; i < (HEIGHT + WIDTH - 2); i++)
    {
        printf("%c ", arrows[i]);
    }
    printf("\n\n");
    return 0;
}
