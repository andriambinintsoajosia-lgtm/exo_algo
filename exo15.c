#include <stdio.h>

void echanger(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void permuter(int t[], int debut, int fin) {
    if (debut == fin) {
        for (int i = 0; i <= fin; i++) {
            printf("%d ", t[i]);
        }
        printf("\n");
        return;
    }
    for (int i = debut; i <= fin; i++) {
        echanger(&t[debut], &t[i]);      // Fixer l'element
        permuter(t, debut + 1, fin);    // Permuter le reste
        echanger(&t[debut], &t[i]);      // Backtrack (restaurer)
    }
}

int main() {
    int t[] = {1, 2, 3};
    int n = 3;
    printf("Permutations de [1, 2, 3] :\n");
    permuter(t, 0, n - 1);
    return 0;
}