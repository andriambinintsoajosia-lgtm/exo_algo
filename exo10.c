#include <stdio.h>

double moyenne_rec_interne(int t[], int n) {
    if (n == 0) {
        return 0.0;
    }
    return t[n - 1] + moyenne_rec_interne(t, n - 1);
}

double moyenne_rec(int t[], int n) {
    if (n == 0) return 0.0;
    return moyenne_rec_interne(t, n) / n;
}

int main() {
    int t[] = {10, 20, 30, 40};
    int n = 4;
    printf("Moyenne Rec : %.2f\n", moyenne_rec(t, n)); // Affiche 25.00
    return 0;
}