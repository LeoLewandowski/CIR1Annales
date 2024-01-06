# Partiel d'Algorithmique - 6 janvier 2022

## Exercice 1

Enoncé :

![Enoncé exo 1](./images/Partiel_22/exo1_enonce.png)

L'opérateur modulo (`a % b`) renvoie le reste de la division euclidienne de `a` par `b`

Première itération, `i = 0`, `j = 0 % 3 = 0` :

- Switch case `0` : on imprime `10` fois tut
- Pas de break -> on passe au case `1` : on imprime encore `2` fois tut (total `12`)
- Break -> on sort du switch
- On imprime une fois de plus tut : total = `13`

Seconde itération, `i = 1`, `j = 1 % 3 = 1` :

- Switch case `1` : 2 fois tut, total = `15`
- Break -> on sort du switch
- On imprime une fois de plus tut : total = `16`

Troisième itération, `i = 2`, `j = 2 % 3 = 0` :

- Switch case `default` : 1 fois tut, total = `17`
- On imprime une fois de plus tut : total = `18`

Quatrième itération, `i = 3`, `j = 3 % 3 = 0` :

- Switch case `0` : on imprime `10` fois tut, total = `28`
- Pas de break -> on passe au case `1` : on imprime encore `2` fois tut (total `30`)
- Break -> on sort du switch
- On imprime une fois de plus tut : total = `31`

Total final : `31`

## Exercice 2

### Question 1

> Rappel : `.` permet d'accéder à un élément d'une structure donnée directement, `->` permet d'accédent à un élément d'une structure dont on a le pointeur : `pointeur->valeur` est la même chose que `(*pointeur).valeur`

```c
objet.valeur

pointeur->valeur
(*pointeur).valeur
```

1) `.`
2) `.`
3) `.`
4) `.`
5) `.`
6) `.`
7) `->`
8) `->`
9) `->`
10) `*`
11) `&`
12) `->`
13) `->`
14) vide
15) vide
16) `&`
17) `*`

Code final si vous voulez tester :

```c
typedef struct de {
    int nbFace; // nombre de faces du dé
    int faceSelect; // face active du dé (entre 1 et nbFace inclus)
    char id[8]; // identifiant du dé
}dice;

// renvoie 0 si la face sélectionnée n'est pas une face possible pour ce dé
int verifie(dice d) {
    int valide = 0;
    if (d.faceSelect <= d.nbFace && d.faceSelect > 0) {
        valide = 1;
    }
    return valide;
}

// affiche les caractéristiques du dé à l'écran
void affiche(dice d) {
    printf("Le dé %s de %d faces est actuellement sur la face %d.\n",
        d.id, d.nbFace, d.faceSelect);
}

// lance un dé : modifie la face sélectionnée
void tirage(dice* d) {
    printf("On lance le dé %s\n", d->id);
    d->faceSelect = (1 + rand() % d->nbFace);
    affiche(*d);
}

int main() {
    dice D20 = { 20,25,"d20" };
    dice* copie = &D20;
    copie->id[3] = 'z';
    copie->id[5] = 't';
    affiche(D20);
    if (verifie(D20)) { printf("Ce dé est valide.\n"); }
    else { printf("Ce dé n'est pas valide.\n"); }
    tirage(&D20);
    affiche(*copie);
}
```

### Question 2

Sortie :

```console
Le dé d20z de 20 faces est actuellement sur la face 25.
Ce dé n'est pas valide.
On lance le dé d20z
Le dé d20z de 20 faces est actuellement sur la face 2.
Le dé d20z de 20 faces est actuellement sur la face 2.
```

## Exercice 3
