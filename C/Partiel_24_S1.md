# Partiel d'Algorithmique - 9 janvier 2024

Correction du partiel d'Algorithmique du Semestre 1 de 2024

## Partie 1

### Question 1-A

```c
printf("Veuillez renseigner un caractère :");
scanf("%c", &ch);
```

### Question 1-B

Il permet de renvoyer un pointeur vers la variable `ch`

### Question 2-A

```c
nbOctets = sizeof(ch);
```

### Question 2-B

```c
nbBits = log2(ch) + 1;
```

### Question 2-C

#### Code

```c
mask = 0x8000;

int i = 0;
// On vérifie que ch != 0, sinon la boucle est infinie
// A chaque itération de la boucle, on décale ch vers la droite
if(ch != 0) while(mask & (ch << i)){
    i++;
}
else i = sizeof(int);


// A la fin de la boucle, i est le nombre de bits non utilisés
// Le nombre de bits utilisés est donc le nombre total de bits de la variable
// moins le nombre de bits non utilisés
nbBits = sizeof(int) - i;
```

#### Explications

> Rappel : le bit de poids fort d'un nombre est le bit situé le plus à gauche.
>
> Dans l'exemple suivant, `X` est le bit de poids fort, et `Z` le bit de poids faible : `0bXyyyyyyyZ`

`mask & n` pour tout int n renvoie une des valeurs suivantes :

- `0b1000000000000000` (`0x8000`)
- `0b0000000000000000` (`0x0000`)

La valeur renvoyée dépend _uniquement_ du bit de poids fort de `ch`.

> Rappel 2 : l'opérateur `x << n` est l'opérateur de décalage binaire vers la gauche. Il permet de décaler tous les bits d'un nombre `x` de `n` places vers la gauche
>
> Exemples : `0b00110101 << 2` -> `0b11010100`, `0b00010110 << 1` -> `0b00101100`

`mask & (ch << i)` permet de faire la même opération que plus haut, mais avec `ch` décalé vers la gauche de `i` places.

Par conséquent, le `i` le plus petit pour lequel cette opération renvoie `0b1000000000000000` est le nombre de bits non utilisés de `ch`.

Regardons un exemple de l'exécution de la boucle du programme plus haut. On prendra `ch = 0b0001011001111000`.

Pour simplifier, on mettra la valeur `true` quand `mask & (ch << i)` vaut `0x8000` et `false` quand cela vaut `0x0000`

| i | ch << i          | mask & (ch << i) |
|---|------------------|------------------|
| 0 | 0001011001111000 |      false       |
| 1 | 0010110011110000 |      false       |
| 2 | 0101100111100000 |      false       |
| 3 | 1011001111000000 |       true       |

On voit bien que `i` est le nombre de bits non utilisés dans `ch` : il y a 3 bits non utilisés au début de `ch`, et `i == 3`

### Question 3-A

Ce if sert dans le cas particulier où `ch` n'est encodé que sur 1 seul octet

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
        *(newWord + i) = *(word + i);
        i++;
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

#### Structures - Question 1

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

#### Structures - Question 2

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
