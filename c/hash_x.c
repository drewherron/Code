#include <stdio.h>

/*
Trying to find (an interesting) way to print this:
##########
##      ##
# #    # #
#  #  #  #
#   ##   #
#   ##   #
#  #  #  #
# #    # #
##      ##
##########
*/
int print_line(int, int);

int main(int argc, char *argv[])
{
    for (int i = 10; i > 0; i--)
        printf("#");
    printf("\n");
    print_line(0, 6);
    for (int i = 10; i > 0; i--)
        printf("#");
    printf("\n");

    return 0;
}

int print_line(int a, int b)
{
    if (a > 3)
        return 0;

    printf("#%*s", a, "");
    printf("#%*s", b, "");
    printf("#%*s#\n", a, "");

    print_line(a + 1, b - 2);

    printf("#%*s", a, "");
    printf("#%*s", b, "");
    printf("#%*s#\n", a, "");

    return 0;
}

