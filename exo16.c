#include <stdio.h>
#include <stdbool.h>

bool absentSurLigne(int k, int grille[9][9], int i) {
    for (int col = 0; col < 9; col++) {
        if (grille[i][col] == k) return false;
    }
    return true;
}

bool absentSurColonne(int k, int grille[9][9], int j) {
    for (int ligne = 0; ligne < 9; ligne++) {
        if (grille[ligne][j] == k) return false;
    }
    return true;
}

bool absentSurBloc(int k, int grille[9][9], int i, int j) {
    int bi = i - i % 3, bj = j - j % 3;
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            if (grille[bi + r][bj + c] == k) return false;
        }
    }
    return true;
}

// Resolution par Backtracking
bool estValide(int grille[9][9], int position) {
    if (position == 9 * 9) {
        return true; // Fin de la grille atteinte
    }

    int i = position / 9, j = position % 9;
    
    if (grille[i][j] != 0) {
        return estValide(grille, position + 1);
    }

    for (int k = 1; k <= 9; k++) {
        if (absentSurLigne(k, grille, i) && 
            absentSurColonne(k, grille, j) && 
            absentSurBloc(k, grille, i, j)) {
            
            grille[i][j] = k; // Choix temporaire

            if (estValide(grille, position + 1)) {
                return true;
            }
            
            grille[i][j] = 0; // Backtracking (reinitialisation au bon endroit)
        }
    }
    return false; // Echec pour ce chemin
}

void afficherGrille(int grille[9][9]) {
    for (int i = 0; i < 9; i++) {
        if (i % 3 == 0 && i != 0) printf("------+------+------\n");
        for (int j = 0; j < 9; j++) {
            if (j % 3 == 0 && j != 0) printf("|");
            printf("%d ", grille[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int grille[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    printf("Grille initiale :\n");
    afficherGrille(grille);
    printf("\n");

    if (estValide(grille, 0)) {
        printf("Grille resolue avec succes :\n");
        afficherGrille(grille);
    } else {
        printf("Pas de solution.\n");
    }

    return 0;
}