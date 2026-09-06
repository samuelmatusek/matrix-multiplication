#include <stdio.h>
#include <stdlib.h>

int vynasob_matice(int **a, int r_a, int s_a, int **b, int r_b, int s_b, int ***vysledek, int *r_vysledek, int *s_vysledek){


    return 1;
}

void uvolni_matici(int **matice, int radky){
    
}

int main(void){

    int r_a, r_b, s_a, s_b;

    printf("Zadej rozmery matice A (radky sloupce):\n");
    if (scanf("%d %d", &r_a, &s_a) != 2 || r_a <= 0 || s_a <= 0){
        printf("Nespravny vstup.\n");
        return 1;
    }








    return 0;
}