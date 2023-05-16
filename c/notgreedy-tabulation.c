// Tabulation

#include <stdio.h>

int c1 = 1;
int c3 = 3;
int c4 = 4;

#define MAX 1000000

int t[MAX];

int notgreedy(int x) {
  for (int i = 5; i <= MAX; i++) {
    int a = t[i-c1];
    int b = t[i-c3];
    int c = t[i-c4];

    int min = a;

    if (b < min) {min = b;}
    if (c < min) {min = c;}

    t[i] = 1 + min;
  }
    return t[x];
}

int main() {
    int p;

    t[0] = 0;
    t[1] = 1;
    t[2] = 2;
    t[3] = 1;
    t[4] = 1;
    
    printf("Enter int value for p: ");
    scanf("%d", &p);

    int result = notgreedy(p);

    printf("Result: %d\n", result);

    return 0;
}


