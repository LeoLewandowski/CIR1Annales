#include <iostream>

void triDichotomie(int* tab, int tabsize){
    int* tab2 = copyTab(tab, tabsize);


}

void triInterne(int* tab, int* tab2, int start, int end){
    // Si le tableau a une longueur de 1 il est trié, on arrête la fonction
    if(end - start <= 1) return;

    int mid = (start + end) / 2;

    triInterne(tab, tab2, start, mid);
    triInterne(tab, tab2, mid, end);

    mergeTabs(tab, tab2);
}

void mergeTabs(int* tab, int* tab2, int mid, int start, int end){

}

int* copyTab(int* tab, int size){
    if(tab == NULL || size <= 0) return NULL;

    int* tab2 = (int*)malloc(size * sizeof(int));

    if(tab == NULL) return NULL;

    for(int i = 0; i < size; i++) *(tab2 + i) = *(tab + i);

    return tab2;
}