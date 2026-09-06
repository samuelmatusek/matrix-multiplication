#include <stdio.h>
#include <stdlib.h>

int vynasob_matice(int **a, int r_a, int s_a, int **b, int r_b, int s_b, int ***vysledek, int *r_vysledek, int *s_vysledek){

    if (a == NULL || b == NULL || r_a == NULL || s_a == NULL || r_b == NULL || s_b == NULL || vysledek == NULL || r_vysledek == NULL || s_vysledek == NULL)
        return 1;

    *r_vysledek = r_a;
    *s_vysledek = s_b;

    *vysledek = malloc(sizeof(**vysledek) * r_a);
    if (*vysledek == NULL)
        return 1;
    for (int i = 0; i < *r_vysledek; i++){
        (*vysledek)[i] = malloc(**vysledek[i] * *s_vysledek);
        if((*vysledek)[i] == NULL){
            uvolni_matici(*vysledek, r_vysledek);
            return 1;
        }
    }


    return 1;
}

void uvolni_matici(int **matice, int radky){

    for (int i = 0; i < radky; i++){
        free(matice[i]);
    }
    free(matice);
}

int main(void){

    int r_a, r_b, s_a, s_b, r_vysledek, s_vysledek, **vysledek;

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
    printf("Zadejte prvky matice A:\n");
    for (int i = 0; i < r_a; i++){
        for (int j = 0; j < s_a; j++){
            if (scanf("%d", &a[i][j]) != 1){
                uvolni_matici(a, r_a);
                printf("Nespravny vstup.\n");
                return 1;
            }
        }
    }

    printf("Zadej rozmery matice B (radky sloupce):\n");
    if (scanf("%d %d", &r_b, &s_b) != 2 || r_b <= 0 || s_b <= 0 || s_a != r_b){
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
    printf("Zadejte prvky matice B:\n");
    for (int i = 0; i < r_b; i++){
        for (int j = 0; j < s_b; j++){
            if (scanf("%d", &b[i][j]) != 1){
                uvolni_matici(a, r_a);
                uvolni_matici(b, r_b);
                printf("Nespravny vstup.\n");
                return 1;
            }
        }
    }

    if(vynasob_matice(a, r_a, s_a, b, r_b, s_b, vysledek, r_vysledek, s_vysledek)){

    }
    else {
        printf("Nespravny vstup.\n");
        uvolni_matici(a, r_a);
        uvolni_matici(b, r_b);
    }

    return 0;
}