# Partiel d'Algorithmique - 9 janvier 2024

Correction du partiel d'Algorithmique du Semestre 1 de 2024

## Partie 1

## Partie 2

### Question A

> Rappel : `*(tab + i)` équivaut à `tab[i]`

```c
char* cloneStr(char* word) {
    char* newWord = calloc(1, sizeof(word));
    int i = 0;
    // Tant que *(word + i) évalue en tant que `true`, on copie les caractères
    // Le caractère de fin de string évalue à `false`, la boucle s'arrêtera donc à ce caractère
    while( *(word + i) ) {
        *(newWord + i) = *(word + i)
    }
    return newWord;
}
```

### Question B

1. La fonction `free` permet de libérer la mémoire occupée par une variable
2. Le pointeur `copie` a la valeur de pointeur `NULL`
3. Oui, on peut utiliser cet espace mémoire - qui a été libéré - pour d'autres variables. Cependant, les données associées à `copie` ont été supprimées pour libérer la mémoire, et ne sont donc plus accessibles

## Partie 3

### Dessin

1. Cette fonction affiche `nb` lignes
2. La fonction affiche `nb` lignes composées chacune de `nb + 2` caractères (+2 car on compte les `#` de début et de fin de ligne), elle affiche donc en tout `nb(nb + 2) = nb² + 2nb` caractères
3. Pour `nb = 1` :

   ```none
   #$#
   ```

   Pour `nb = 4` :

   ```none
    #$--$#
    #-$$-#
    #-$$-#
    #$--$#
   ```

   Pour `nb = 5` :

   ```none
    #$---$#
    #-$-$-#
    #--$--#
    #-$-$-#
    #$---$#
   ```

### Structures

#### Question 1

```c
typedef struct {
    poisson fishes[30];
    int nbFish;
    float volume; // Vous pouvez remplacer float par double ou int par exemple
    short quality;
    // Vous pouvez aussi utiliser un int, un long ou autre
    // type d'entier pour la qualité de l'eau
    // Techniquement un char peut marcher aussi, car la valeur
    // de la qualité est comprise entre 0 et 100
} aquarium;
```

#### Question 2

```c
void qualityCheck(aquarium aq) {
    if(aq.quality >= 80) printf("La qualité de l'eau est bonne");
    else if(aq.quality >= 45) printf("La qualité de l'eau est moyenne");
    else printf("La qualité de l'eau est mauvaise");
}
```

#### Question 3

Il y a 2 moyens de répondre à cette question :

- En utilisant un pointeur pour modifier la propriété de l'aquarium
- En renvoyan l'aquarium après modification, sans utiliser de pointeur

Version avec pointeur :

```c
void filtrer(aquarium* aqPtr) {
    if(aqPtr->quality < 85 && aqPtr->quality >= 75) aqPtr->quality = 85;
    else if(aqPtr->quality < 75) aqPtr->quality += 10;
    // Pas besoin de else ; si aucune des deux ifs n'est valide, alors
    // cela veut direque la qualité de l'eau est supérieur à 85
    // et donc on ne la modifie pas
}
```

Version sans pointeur :

```c
aquarium filtrer(aquarium aq) {
    if(aq.quality < 85 && aq.quality >= 75) aq.quality = 85;
    else if(aq.quality < 75) aq.quality += 10;
    return aq;
}
```

#### Question 4

```c
int fatFishes(aquarium aq, double threshold) {
    int count = 0;
    for(int i = 0; i < aq.nbFish; i++){
        if(aq.fishes[i].poids > threshold) count++;
    }
    return count;
}
```
