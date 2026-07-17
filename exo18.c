#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

const char *expr;

int eval_nombre() {
    int res = 0;
    while (isdigit(*expr)) {
        res = res * 10 + (*expr - '0');
        expr++;
    }
    return res;
}

int eval_facteur() {
    if (*expr == '(') {
        expr++; // Ignorer '('
        int res = eval_nombre(); // Simplifie pour cet exemple
        if (*expr == ')') expr++; // Ignorer ')'
        return res;
    }
    return eval_nombre();
}

int eval_terme() {
    int gauche = eval_facteur();
    while (*expr == '*') {
        expr++; // Passer '*'
        int droite = eval_facteur();
        gauche *= droite;
    }
    return gauche;
}

int eval_expression() {
    int gauche = eval_terme();
    while (*expr == '+') {
        expr++; // Passer '+'
        int droite = eval_terme();
        gauche += droite;
    }
    return gauche;
}

int main() {
    expr = "3+5*2"; // Priorite de la multiplication respectee : 3 + (5 * 2) = 13
    printf("Evaluation de '3+5*2' = %d\n", eval_expression());
    return 0;
}