// Memoization

#include <stdio.h>

int c1 = 1;
int c3 = 3;
int c4 = 4;

#define MAX 1000000

int t[MAX];

int notgreedy(int x) {

    if (x == 1 || x == 3 || x == 4)
        return 1;
    if (x == 2)
        return 2;

    if (t[x] != -1) {
      return t[x];
      
    } else {
         
         int a = notgreedy(x-c4);
         int b = notgreedy(x-c3);
         int c = notgreedy(x-c1);
     
         int min = a;
     
         if (b < min) {min = b;}
         if (c < min) {min = c;}

         t[x] = min + 1;
         return (min + 1);
    }
}

int main() {
    int p;

    for (int i=0; i<MAX; i++)
      {
        t[i] = -1;
      }
    
    printf("Enter int value for p: ");
    scanf("%d", &p);

    int result = notgreedy(p);

    printf("Result: %d\n", result);

    return 0;
}


