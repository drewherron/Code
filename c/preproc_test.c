#include <stdio.h>

#define mkstr(s) # s

#define concat(a,b) a ## b

int main()
{
    printf("STDC: %d\n",__STDC__);
    printf("On date %s\n",__DATE__);
    printf("At time %s\n",__TIME__);
    printf("On line %d\n", __LINE__);
    printf("In file %s\n", __FILE__);

    printf(mkstr(Making a string\n));
    printf("%d\n", concat(1, 0));

    return 0;
}
