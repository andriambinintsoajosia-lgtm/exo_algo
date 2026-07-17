#include <stdio.h>

// Version recursive
int pgcd_rec(int a, int b) {
    if (b == 0) {
        return a;
    }
    return pgcd_rec(b, a % b);
}

// Version iterative
int pgcd_iter(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int a = 48, b = 18;
    printf("PGCD Rec de (%d, %d) = %d\n", a, b, pgcd_rec(a, b));
    printf("PGCD Iter de (%d, %d) = %d\n", a, b, pgcd_iter(a, b));
    return 0;
}