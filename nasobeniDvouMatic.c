#include <stdio.h>
#include <stdlib.h>

int vynasob_matice(int **a, int r_a, int s_a, int **b, int r_b, int s_b, int ***vysledek, int *r_vysledek, int *s_vysledek){


    return 1;
}

void uvolni_matici(int **matice, int radky){
    for (int i = 0; i < radky; i++){
        free(matice[i]);
    }
    free(matice);
}

int main(void){

    int r_a, r_b, s_a, s_b;

    printf("Zadej rozmery matice A (radky sloupce):\n");
    if (scanf("%d %d", &r_a, &s_a) != 2 || r_a <= 0 || s_a <= 0){
        printf("Nespravny vstup.\n");
        return 1;
    }

    int **a = malloc(sizeof(*a) * r_a);
    if (a == NULL){
        printf("Nespravny vstup.\n");
        return 1;
    }
    for (int i = 0; i < r_a; i++){
        a[i] = malloc(sizeof(*a[i]) * s_a);
        if (a[i] == NULL){
            uvolni_matici(a, i);
            printf("Nespravny vstup.\n");
            return 1;
        }
    }

    printf("Zadej rozmery matice B (radky sloupce):\n");
    if (scanf("%d %d", &r_b, &s_b) != 2 || r_b <= 0 || s_b <= 0 || s_a != s_b){
        uvolni_matici(a, r_a);
        printf("Nespravny vstup.\n");
        return 1;
    }

    int **b = malloc(sizeof(*b) * r_b);
    if (b == NULL){
        uvolni_matici(a, r_a);
        printf("Nespravny vstup.\n");
        return 1;
    }
    for (int i = 0; i < r_b; i++){
        b[i] = malloc(sizeof(*b[i]) * s_b);
        if (b[i] == NULL){
            uvolni_matici(b, i);
            uvolni_matici(a, r_a);
            printf("Nespravny vstup.\n");
            return 1;
        }
    }






    return 0;
}