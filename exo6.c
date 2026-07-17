#include <stdio.h>

// Somme recursive
int somme_rec(int t[], int n) {
    if (n == 0) {
        return 0;
    }
    return t[n - 1] + somme_rec(t, n - 1);
}

// Somme iterative optimisee avec une boucle "while"
int somme_iter(int t[], int n) {
    int s = 0;
    int i = 0;
    while (i < n) {
        s += t[i];
        i++;
    }
    return s;
}

int main() {
    int t[] = {1, 2, 3, 4, 5};
    int n = 5;
    printf("Somme Rec : %d\n", somme_rec(t, n));
    printf("Somme Iter (while) : %d\n", somme_iter(t, n));
    return 0;
}