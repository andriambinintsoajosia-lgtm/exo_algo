#include <stdio.h>

// Version recursive utilisant un operateur ternaire
int max_rec(int t[], int n) {
    if (n == 1) {
        return t[0];
    }
    int m = max_rec(t, n - 1);
    
    /* EXPLICATION DE L'OPERATEUR TERNAIRE :
       La syntaxe (Condition) ? Expression1 : Expression2
       evalue la Condition. Si elle est vraie, renvoie Expression1. Sinon, renvoie Expression2.
       Ici : si le dernier element du sous-tableau est superieur au maximum du reste 'm',
       on retourne t[n - 1], sinon on retourne 'm'. */
    return (t[n - 1] > m) ? t[n - 1] : m;
}

// Version iterative avec "while"
int max_iter(int t[], int n) {
    int max = t[0];
    int i = 1;
    while (i < n) {
        if (t[i] > max) {
            max = t[i];
        }
        i++;
    }
    return max;
}

int main() {
    int t[] = {12, 5, 18, 2, 9};
    int n = 5;
    printf("Max Rec : %d\n", max_rec(t, n));
    printf("Max Iter (while) : %d\n", max_iter(t, n));
    return 0;
}