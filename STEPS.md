# Push_swap (v1.2) : résumé et plan de travail

**Le but :** écrire en C un programme `push_swap` qui reçoit une liste d'entiers et affiche la suite d'opérations la plus courte possible pour les trier, avec seulement deux piles et 11 opérations autorisées. Le projet se fait **à 2, obligatoirement**.

⚠️ Cette version est plus lourde que l'ancien push_swap. Il faut **4 algorithmes**, un **calcul de « désordre »**, des **flags de sélection** et un mode **`--bench`**.

---

## Étape 0 : Mise en place (en binôme)

1. **S'organiser à deux**
   - Les deux logins doivent apparaître dans le repo, et chacun doit être noté comme contributeur.
   - Répartissez-vous le travail. À la défense, **chacun doit pouvoir expliquer n'importe quelle partie du code**, donc relisez le code de l'autre.
2. **Structure du repo**
   - Copier sa `libft` (sources + Makefile) dans un dossier `libft/`. Le Makefile principal compile la libft avec son propre Makefile.
   - **Makefile** : règles `$(NAME)`, `all`, `clean`, `fclean`, `re`, plus `bonus` pour le checker. On compile avec `cc -Wall -Wextra -Werror`, **sans relink**.
3. **Contraintes globales**
   - Respecter la Norme, y compris pour les fichiers bonus. Une seule erreur de norme donne 0.
   - Pas de variables globales.
   - Pas de segfault, de double free, etc.
   - Aucune fuite mémoire.
   - Fonctions autorisées : `read`, `write`, `malloc`, `free`, `exit`, et un `ft_printf` codé par vous.

---

## Étape 1 : Structure de données

1. **Choisir la représentation des piles.** Le choix classique est une liste chaînée, souvent doublement chaînée, ou un tableau circulaire.
2. **Prévoir les champs utiles**, par exemple :
   - la valeur ;
   - un **index** (le rang de la valeur une fois triée), très pratique pour le radix et les chunks ;
   - la taille de chaque pile.
3. **Prévoir une structure de compteurs** pour les 11 opérations, qui servira au mode `--bench`.

---

## Étape 2 : Parsing et gestion d'erreurs

1. **Lire les arguments.** Le premier argument correspond au **sommet** de la pile a.
2. **Repérer les flags éventuels** : `--simple`, `--medium`, `--complex`, `--adaptive` (le comportement par défaut) et `--bench`. Ils peuvent se combiner, par exemple `--bench --adaptive`.
3. **Vérifications.** S'il y a une erreur, afficher `Error\n` sur **stderr** :
   - un argument qui n'est pas un entier (par exemple `one`, `""`, `+`, `-`) ;
   - un nombre qui dépasse `INT_MIN` ou `INT_MAX` ;
   - un doublon.
4. **Sans argument**, le programme n'affiche rien et rend la main.
5. Optionnel mais utile : gérer aussi un argument entre guillemets, comme `"3 2 1"`.

---

## Étape 3 : Les 11 opérations

Chaque fonction modifie les piles, **écrit l'opération suivie de `\n` sur stdout** et incrémente son compteur.

| Op | Effet |
|---|---|
| `sa` / `sb` / `ss` | Échange les 2 premiers éléments (de a, de b, des deux) |
| `pa` / `pb` | Prend le sommet de b et le pose sur a (ou l'inverse) |
| `ra` / `rb` / `rr` | Rotation : le premier élément devient le dernier |
| `rra` / `rrb` / `rrr` | Rotation inverse : le dernier élément devient le premier |

Chaque opération ne fait rien s'il n'y a pas assez d'éléments.

Astuce : écrivez une version « silencieuse » des opérations. Elle vous resservira pour le checker en bonus.

---

## Étape 4 : Métrique de désordre (obligatoire)

1. Implémenter `compute_disorder`. On compte les paires (i, j) avec i < j et `a[i] > a[j]`, puis on divise par le nombre total de paires.
   - On obtient 0 si la pile est triée et 1 si elle est dans l'ordre inverse.
2. On la calcule **avant le moindre mouvement**.
3. Pensez aux cas limites : avec 0 ou 1 élément, il y a zéro paire, donc attention à la division par zéro.
4. Si la pile est déjà triée, on n'affiche aucune opération.

---

## Étape 5 : Les 4 stratégies

La complexité annoncée se mesure **en nombre d'opérations push_swap générées**, et non en complexité théorique sur un tableau.

### 5.1 Algorithme simple, en O(n²) : `--simple`
- Pistes : insertion, sélection, bulle, ou extraction du min/max.
- L'approche la plus simple : chercher le minimum, le faire remonter au sommet par le chemin le plus court (`ra` ou `rra`), faire `pb`, recommencer, puis tout ramener avec `pa`.

### 5.2 Algorithme moyen, en O(n√n) : `--medium`
- Pistes : tri par **chunks** (√n morceaux), par blocs, bucket sort avec √n seaux, ou découpage par plages de valeurs.
- Le classique : découper les index en chunks, pousser chaque chunk vers b, puis ramener les éléments dans a du plus grand au plus petit.

### 5.3 Algorithme complexe, en O(n log n) : `--complex`
- Pistes : **radix** (LSD ou MSD), tri fusion sur 2 piles, quicksort avec partition, heap sort, ou arbre indexé binaire.
- Le **radix binaire sur les index** est le plus simple à coder. Attention : il donne environ 6 700 opérations pour 500 nombres, ce qui valide le minimum mais pas le seuil « bon ».

### 5.4 Algorithme adaptatif, de votre conception : `--adaptive` (par défaut)
Il choisit sa méthode selon le désordre et doit respecter ces complexités :

| Désordre | Complexité exigée |
|---|---|
| < 0,2 | O(n²) |
| entre 0,2 (inclus) et 0,5 (exclu) | O(n√n) |
| ≥ 0,5 | O(n log n) |

- Vous êtes libres de la technique utilisée dans chaque régime.
- Les flags doivent fonctionner **pour toutes les entrées valides**, quelles que soient la taille et le désordre.

### 5.5 Petits cas (fortement conseillé)
- Prévoir un tri dédié pour 2, 3 et 5 éléments : au maximum 2 ou 3 opérations pour 3 nombres, et environ 12 pour 5. Ça fait gagner beaucoup en évaluation.

---

## Étape 6 : Atteindre les seuils de performance

| Taille | Minimum pour valider | Bon | Excellent |
|---|---|---|---|
| 100 nombres aléatoires | < 2000 | < 1500 | < 700 |
| 500 nombres aléatoires | < 12000 | < 8000 | < 5500 |

- La vérification se fait avec le `checker_linux` fourni.
- Le bonus n'est évalué que si **tous** les benchmarks obligatoires sont validés.
- Pour viser « excellent », on optimise souvent avec un **algorithme de coût** (style « Turk ») : avant chaque déplacement, on calcule le nombre de rotations nécessaire et on combine `rr` et `rrr`.

---

## Étape 7 : Mode `--bench`

Il n'est actif que si le flag est présent. Après le tri, on affiche **sur stderr** :
1. le désordre en pourcentage avec 2 décimales (par exemple `49.93%`) ;
2. le nom de la stratégie et sa classe de complexité (par exemple `Adaptive / O(n√n)`) ;
3. le nombre total d'opérations ;
4. le nombre de chaque opération : `sa sb ss pa pb ra rb rr rra rrb rrr`.

Les opérations elles-mêmes restent sur stdout, ce qui permet de faire `push_swap --bench ... 2> bench.txt | ./checker_linux ...`.

---

## Étape 8 : Le README.md

1. **Première ligne en italique :** *This project has been created as part of the 42 curriculum by login1, login2.*
2. Une section **Description** : le but et une vue d'ensemble.
3. Une section **Instructions** : compilation et exécution.
4. Une section **Resources** : des références, plus **comment l'IA a été utilisée** (pour quelles tâches et sur quelles parties).
5. **Spécifique à ce projet :**
   - une explication et une justification détaillées des algorithmes choisis ;
   - pour l'adaptatif : pourquoi ces seuils, quelles techniques dans chaque régime, et un argument de complexité (bornes supérieures en temps et en espace, dans le modèle push_swap) ;
   - **la contribution de chacun des deux** membres du binôme.
6. Rédigé en anglais de préférence, sinon en français.

---

## Étape 9 : Bonus, le programme `checker`

Il se compile avec `make bonus`, dans des fichiers `_bonus.c` et `_bonus.h`.
1. Il prend la pile a en arguments. Sans argument, il n'affiche rien.
2. Il lit les instructions sur stdin, une par ligne, puis les exécute (un `get_next_line` est utile ici).
3. Il affiche `OK\n` si a est triée **et** b est vide, sinon `KO\n`.
4. Il affiche `Error\n` sur stderr pour un argument invalide, un doublon, un dépassement d'entier, ou une instruction inconnue ou mal formatée.

---

## Étape 10 : Tests et préparation de la défense

1. **Tests à faire :**
   - les erreurs : `one`, `""`, les doublons, `2147483648`, `-2147483649` ;
   - une liste déjà triée, qui ne doit afficher aucune sortie ;
   - 1, 2, 3 et 5 éléments ;
   - 100 et 500 nombres aléatoires, en boucle sur des dizaines de tirages (`shuf -i 0-9999 -n 500`) ;
   - chaque flag forcé sur chaque type d'entrée ;
   - les fuites avec `valgrind`.
2. **Norminette** sur tous les fichiers.
3. **Défense :**
   - Les deux doivent être présents et capables d'expliquer tout le code.
   - On peut vous demander une **petite modification en direct** du projet, par exemple changer un affichage ou adapter une structure.
4. **Rendu :** vérifier les noms de fichiers dans le repo Git. Seul ce qui est dans le repo compte.

---

**Ordre de travail conseillé :** 1 → 2 → 3 → 4 → algorithme simple et petits cas → radix (complexe) → chunks (moyen) → adaptatif → `--bench` → optimisation pour les seuils → README → checker.
