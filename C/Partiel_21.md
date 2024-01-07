# Partiel d'Algorithmique - 6 janvier 2021

Correction du Partiel d'Algorithmique de C du 6 janvier 2021

Ecrit par Léo Lewandowski

[Sujet disponible ici](./sujets/Partiel_21.pdf)

## Partie I

### I - Exercice 1

```c
int est_premier(int n) {
    for (int i = 2; i < sqrt(n) + 1; i++) {
        /* Si i divise n, alors n n'est pas premier et on retourne faux */
        if (n % i == 0) return 0;
    }
    /* Sinon n est premier et on retourne vrai */
    return 1;
}
```

La limite à partir de laquelle on peut arrêter de chercher est l'entier directement supérieur à la racine carrée de n

### I - Exercice 2

```c
int premier_suivant(int n) {
    int i = 0;
    /* On augmente i jusqu'à trouver un nombre qui soit premier */
    while (!est_premier(n + i)) {
        i++;
    }
    return n + i;
}
```

### I - Exercice 3

```c
void decomposition(int n) {
    /* Plus petit terme premier diviseur de n. Pour chercher les facteurs premier de n, on divise d'abord par 2, puis 3, etc. C'est pareil pour petit_terme, il commence à 2 puis augmente dès qu'il n'est plus diviseur de n */
    int petit_terme = 2;
    printf_s("%d = ", n);
    while (!est_premier(n)) {
        /* Si petit_terme divise n, alors n est égal au quotient de la division, et on imprime un terme en plus */
        if (n % petit_terme == 0) {
            printf_s("%d x ", petit_terme);
            n /= petit_terme;
        }
        /* Sinon, petit_terme devient le facteur premier suivant (excluant lui-même, d'où le +1)*/
        else petit_terme = premier_suivant(petit_terme + 1);
    }
    printf_s(" %d\n", n);
}
```

## Partie II

### II - Question 1

Cette fonction compte le nombre d'entiers pairs et impairs dans le tableau donné jusqu'à l'index donné, et renvoie `1` s'il y a plus de pairs que d'impairs, ou sinon `0`

### II - Question 2

On va jusqu'au 8eme élément du tableau, on trouve donc `5` pairs et `3` impairs, on a donc `compte1 == 5` et `compte2 == 3`.

### II - Question 3

La fonction retourne une variable de type int de valeur `1`

### II - Question 4

Il faut que plus de la moitié du tableau soit composé de nombres pairs, donc que la fonction renvoie `(compte1 > tailleTab / 2)`. On retire donc `compte2` ainsi que le `else` dans la boucle.

### II - Question 5

```c
void separation_pairs(int t1[], int t2[], int t3[], int taille) {
    int currentPair = 0, currentImpair = 0;
    for(int i = 0; i < taille; i++) {
        if(t1[i] % 2 == 0){
            t2[currentPair] = t1[i];
            currentPair++;
        } else {
            t2[currentImpair] = t1[i];
            currentImpair++;
        }
    }
}
```

### II - Question 6

```c
void applique_modif(int tab[], int taille) {
    for(int i = 0; i < taille; i++) if(tab[i] < 0) modif(tab + i);
}
```

### II - Question 7

- `e`, `f`, `h`
- `c`, `d`
- `a`
- `b`
- `g`

### II - Question 8

Interprétons le programme dans l'ordre :

- On définit `x = 10`
- On définit `adx = &x`, donc `adx` pointe vers `x`
- On définit `y = x`, donc `y = 10`
- `y++` donc on augmente `y` de 1 : `y = 11`
- `*adx += 2` équivaut à `x += 2` donc on augmente `x` de 2 : `x = 12`
- On imprime ensuite : `12,12,11`
