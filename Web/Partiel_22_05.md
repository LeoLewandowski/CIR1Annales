# Partiel de Web - 5 Mai 2022

## Exercice 1

### Question 1

Lequel des fichiers suivants peut être utilisé pour modifier les `configurations PHP` ?

- php.ini✅
- config.ini❌
- isset.ini❌
- httpd_php.conf❌

### Question 2

Dans quel tableau de données retrouve-t-on les cookies du visiteur ?

- `$SETCOOKIE`❌
- `$COOKIES`❌
- `$HTTP_COOKIES`❌
- `$_COOKIE`✅

### Question 3

Laquelle des fonctions suivantes connecte une base de données MySql en `utilisant PHP` ?

- `mysqli_connect()`✅
- `mysqli_query()`❌
- `mysqli_close()`❌

### Question 4

Comment préciser quel script sera lancé par le bouton « submit » d’un formulaire ?

- `<form type=”page.php”`❌
- `<form action=”page.php”`✅
- `<form script=”page.php”`❌
- `<form submit=”page.php”`❌

### Question 5

Lequel des éléments suivants est utilisé pour créer un cookie ?

- `setcookie()`✅
- `$_COOKIE`❌
- `isset()`❌

### Question 6

Laquelle des fonctions suivantes trie un tableau dans l’ordre décroissant ?

- `rsort()`✅
- `shuffle()`❌
- `reset()`❌
- `sort()`❌

### Question 7

PHP est-il sensible à la casse ?❌

- Vrai✅
- Faux❌

### Question 8

Comment retrouver le nom original d’une donnée de type « FILE » d’un formulaire ?

- `$FILE[‘…][‘tmp_name’]`❌
- `$FILE[‘...’][‘name’]`✅
- `$FILE[‘…][‘original]`❌
- `$FILE[‘…’][‘type’]`❌

### Question 9

laquelle des fonctions suivantes crée une session permettant d’utiliser les variables de session ?

- `session_set()`❌
- `session_start()`✅
- `setcookie()`❌
- `session_destroy()`❌

### Question 10

Laquelle des fonctions suivantes vérifie si une valeur spécifique existe dans un tableau ?

- `krsort()`❌
- `key()`❌
- `in_array()`✅
- `extract()`❌

## Exercice 2

```php
$tab = ['a' => 5, 'b' => 10, 'c' => 2, 'd' => 4];

    function listeDeroulante(array $tableau) {
        echo "<select name='MaListe'>";
        foreach($tableau as $cle => $val) echo "<option value='$cle'>$val</option>";
        echo "</select>";
    }

    listeDeroulante($tab);
```

## Exercice 3

Compléter les pages : `accueil.php`, `connexion.php` et `deconnexion.php` selon les consignes suivantes :

- Les champs login et password du formulaire doivent être remplis par les valeurs des cookies
nommés « login » et « password » s’ils existent, sinon les champs doivent être vides.
- Les cookies sont créés lors de la première connexion d’un utilisateur.
- Le formulaire de connexion ne doit être affiché que si aucun utilisateur n’est authentifié
sinon un bouton de déconnexion doit être affichée, le script de traitement du formulaire de
déconnexion doit être dans la page « `deconnexion.php` »
- Lors de l’authentification réussite d’un utilisateur, une variable de session nommée « auth »
est créée, cette variable contient le login de l’utilisateur.
- Un utilisateur n’est authentifié que s’il a saisi le bon login et password.
- La liste des utilisateurs est dans une table de la base de données. Cette table est nommée
« utilisateur » et contient 6 colonnes : « id », « nom », « prenom », « email », « login » et
« password »

### Accueil.php

Dans la balise `<body>` :

```php
if (empty($_SESSION['auth'])) {

        echo '<form method="post" action="connexion.php">
            <label>Login: </label>
            <input type="text" name="login" value="' . (isset($_COOKIE['login']) ? $_COOKIE['login'] : '') . '">
            <label>Password: </label>
            <input type="password" name="password" value="' . (isset($_COOKIE['password']) ? $_COOKIE['password'] : '') . '">
            <input type="submit" name="Envoyer" Value="Envoyer" />
        </form>';
} else echo '<a href="deconnexion.php">Déconnexion</a>';
```

> Rappel : Opérateur ternaire
>
> `a ? b : c`
>
> Basiquement un `if` compacté : Si a est vrai renvoie b, sinon renvoie c

### Connexion.php

```php
session_start();
if (isset($_POST['Envoyer'])) {
    setcookie('login', $_POST['login'] ?? '');
    setcookie('password', $_POST['password'] ?? '');
}

require_once ("connexionBD.php");
$requete = $connexion->prepare("SELECT nom, prenom FROM utilisateur WHERE login = ?");
$resultat = $requete->execute([$_COOKIE['login']]);
if ($resultat == FALSE) {
    echo "<p>Erreur:" . mysqli_error($connexion) . "</p>";
    die();
} else {
    $nbreLignes = $requete->num_rows;

    if ($nbreLignes != 1) {
        if ($nbreLignes > 1)
            echo "<p>Erreur : Trop d'utilisateurs avec le même login</p>";
        else
            echo "<p>Erreur : Aucun utilisateur avec ce login</p>";
    } else {
        $ligne = $requete->get_result()->fetch_assoc();

        if ($_COOKIE['password'] != $ligne['password'])
            echo '<p>Erreur : Le mot de passe ne correspond pas</p>';
        else {
            $_SESSION['auth'] = $_COOKIE['login'];
        }
    }
    $connexion->close();
    $connexion = null;
    header('location: accueil.php');
}
```

> Rappel opérateur null-coalescing
>
> `a ?? b`
>
> Si a est `null`, renvoie b. Sinon, renvoie a
> IMPORTANT : `false` n'est pas `null`, de même que les tableaux et chaînes de caractères vides, ou `0`

### Deconnexion.php

```php
session_start();
session_unset();
session_destroy();
header('location: accueil.php');
```
