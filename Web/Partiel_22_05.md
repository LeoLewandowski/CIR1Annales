# Partiel de Web - 5 Mai 2022

<style>
    ul {
        list-style-type: '❌';
    }
    ul ul li {
        list-style-type: '✅';
    }
</style>

## Exercice 1
Question 1 :
Lequel des fichiers suivants peut être utilisé pour modifier les configurations PHP ?

  - php.ini
- config.ini
- isset.ini
- httpd_php.conf

### Question 2

Dans quel tableau de données retrouve-t-on les cookies du visiteur ?

- `$SETCOOKIE`
- `$COOKIES`
- `$HTTP_COOKIES`
  - `$_COOKIE`

### Question 3

Laquelle des fonctions suivantes connecte une base de données MySql en utilisant PHP ?

- `mysqli_connect()`
- `mysqli_query()`
- `mysqli_close()`

### Question 4

Comment préciser quel script sera lancé par le bouton « submit » d’un formulaire ?

- `<form type=”page.php”`
- `<form action=”page.php”`
- `<form script=”page.php”`
- `<form submit=”page.php”`

### Question 5

Lequel des éléments suivants est utilisé pour créer un cookie ?

- `setcookie()`
- `$_COOKIE`
- `isset()`

### Question 6

Laquelle des fonctions suivantes trie un tableau dans l’ordre décroissant ?

- `rsort()`
- `shuffle()`
- `reset()`
- `sort()`

### Question 7

PHP est-il sensible à la casse ?

- Vrai
- Faux

### Question 8

Comment retrouver le nom original d’une donnée de type « FILE » d’un formulaire ?

- `$FILE[‘…][‘tmp_name’]`
- `$FILE[‘...’][‘name’]`
- `$FILE[‘…][‘original]`
- `$FILE[‘…’][‘type’]`

### Question 9

laquelle des fonctions suivantes crée une session permettant d’utiliser les variables de session ?

- Session_set()
- Session_start()
- Setcookie()
- Session_destroy()

### Question 10

Laquelle des fonctions suivantes vérifie si une valeur spécifique existe dans un tableau ?

- krsort()
- key()
- in_array()
- extract()

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
