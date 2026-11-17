# push_swap : ce qu'il reste à faire (partie obligatoire)

État au 17/11/2026. Les cases cochées sont faites.

## Déjà fait

- [x] Les 11 opérations : `Enzo/ops_base.c`, `ops_base_push.c`, `ops_rotate.c`, `ops_rrr.c`
- [x] Le parsing des flags (`Tristan/pushswap_parse.c`) et des nombres (`Tristan/parse_num.c`)
- [x] Les erreurs détectées : non-entier, `""`, `+`, `-`, dépassement d'`int`, doublons
- [x] Le passage des valeurs en index : `to_rank` (`Tristan/parse_num.c`)
- [x] Les algos :
  - `minmax_sort` pour `--simple` ;
  - `range_sort` pour `--medium` ;
  - `quick_sort` pour `--complex`.
- [x] L'adaptatif dans `check_algo` (`Tristan/run_algo.c`), avec les seuils 0,2 et 0,5
- [x] La libft et ft_printf : une seule libft, sans `.git` imbriqué
- [x] Le Makefile
- [x] `main.c`
- [x] Un seul `push_swap.h`, à la racine

---

## 1. Obtenir un premier `make` qui passe

### 1.1 Corriger le commentaire du chat
- **Fichier :** `Tristan/pushswap_parse.c`, lignes 55 et 57.
- **Problème :** ces lignes `//` se terminent par `\`. En C, ça prolonge le commentaire sur la ligne suivante, et avec `-Werror` ça donne l'erreur `commentaire multi-lignes`.
- **Correction :** retirer le `\` ou ajouter un caractère après.

### 1.2 Supprimer `Enzo/algo.c`
Ce fichier est obsolète : il gérait les anciens flags `--minmax`, `--range` et `--quick`, que le parsing de Tristan remplace. Il ne compile plus, et il est déjà exclu du Makefile.

### 1.3 Écrire les fonctions utilitaires (un nouveau fichier, par exemple `Enzo/utils.c`)
Elles sont déjà déclarées dans `push_swap.h`. Attention, la Norme limite à 5 fonctions par fichier, donc il faudra 2 fichiers.

| Fonction | Ce qu'elle fait | Utilisée par |
|---|---|---|
| `int is_sorted(t_stack *s)` | Renvoie 1 si `v[0] < v[1] < … < v[size-1]`, sinon 0 | `minmax_sort` |
| `int pos_of_min(t_stack *s)` | Renvoie l'indice du plus petit élément | `minmax_sort` |
| `int pos_of_max(t_stack *s)` | Renvoie l'indice du plus grand élément | `minmax_sort`, `push_back_max` |
| `int cost(int pos, int size)` | Renvoie le nombre de coups pour amener `pos` au sommet, soit `min(pos, size - pos)` | `minmax_sort` |
| `void top_a(t_ps *ps, int pos)` | Amène `a.v[pos]` au sommet : `ra` × `pos` si `pos <= size / 2`, sinon `rra` × `size - pos` | `minmax_sort` |
| `void sort_three(t_ps *ps)` | Trie a quand elle contient **3 éléments ou moins**, en 2 opérations au maximum | `minmax_sort` |
| `void push_back_max(t_ps *ps)` | Tant que b n'est pas vide : amène le max de b au sommet (`rb` ou `rrb`, au plus court), puis `pa` | `range_sort` |

**Points d'attention :**
- `sort_three` doit aussi gérer 2 éléments (un simple `sa` si besoin) et 1 élément (ne rien faire). `minmax_sort` l'appelle dès que `a.size <= 3`, donc aussi avec 2 éléments.
- Les 5 cas de `sort_three` avec 3 éléments, en index (0 = le plus petit) :

  | Pile a | Opérations |
  |---|---|
  | `1 0 2` | `sa` |
  | `2 1 0` | `sa` + `rra` |
  | `2 0 1` | `ra` |
  | `0 2 1` | `sa` + `ra` |
  | `1 2 0` | `rra` |

- `push_back_max` doit avoir sa propre version de `pos_of_max` et de rotation pour b, car `top_a` ne travaille que sur a.

### 1.4 Écrire `compute_disorder` (nouveau fichier, par exemple `Tristan/disorder.c`)
- **Prototype :** `double compute_disorder(t_stack *a);`
- **Calcul :**
  1. compter les paires `i < j` où `a->v[i] > a->v[j]` (les « inversions ») ;
  2. diviser par le nombre total de paires, `n * (n - 1) / 2`.
- **Types :** faire le calcul en `double` ou en `long`. Avec 500 nombres il y a 124 750 paires : un `int` suffit, mais autant être prudent.
- **Si `size < 2`**, renvoyer `0.0`, pour éviter une division par zéro.
- **Résultat attendu :** 0 pour une pile triée, 1 pour une pile triée à l'envers.
- **Dans le `main`**, elle est appelée **avant** le premier mouvement. `disorder == 0` veut dire que la pile est déjà triée, et dans ce cas on n'affiche aucune opération.

### 1.5 Ajouter un compteur par opération (pour `--bench`)
- **Dans `t_ps`**, ajouter `int cnt[11];`, dans l'ordre `sa sb ss pa pb ra rb rr rra rrb rrr`.
- **L'initialiser à 0** dans `init_stacks` (`main.c`), par exemple avec `ft_bzero(ps->cnt, sizeof(ps->cnt))`.
- **Compter chaque opération.** Le plus simple : changer `put_op(t_ps *ps, const char *s)` en `put_op(t_ps *ps, const char *s, int id)`, qui fait `ps->cnt[id]++`. Chaque fonction d'opération passe alors son indice, par exemple `sa` passe 0 et `rrr` passe 10.
- **Le total** reste `ps->ops`. On peut aussi le recalculer en faisant la somme de `cnt`.

### 1.6 Écrire `print_bench` (nouveau fichier, par exemple `Tristan/bench.c`)
- **Prototype :** `void print_bench(t_ps *ps, int mode, double disorder);`
- **Quand :** elle n'est appelée que si `mode >= 10`, c'est-à-dire si `--bench` est présent.
- **Tout s'écrit sur stderr (fd 2)**, avec `ft_putstr_fd` et `ft_putnbr_fd`. `ft_printf` écrit uniquement sur stdout.
- **À afficher**, dans le format de l'exemple du sujet :
  1. **Le désordre** en pourcentage avec 2 décimales, par exemple `49.93%`.
     - On calcule `x = (int)(disorder * 10000 + 0.5)`, puis on affiche `x / 100`, un `.`, et `x % 100` **sur 2 chiffres** (5,07 % doit s'écrire `5.07`, pas `5.7`).
  2. **La stratégie et sa complexité**, d'après `mode % 10` :

     | Mode | Affichage |
     |---|---|
     | 1 (adaptive) | `Adaptive / ` suivi de la complexité de l'algo choisi, selon `disorder` |
     | 2 (complex) | `Complex / O(n log n)` |
     | 3 (medium) | `Medium / O(n√n)` |
     | 4 (simple) | `Simple / O(n²)` |

  3. **Le total** des opérations.
  4. **Le nombre de chaque opération** : `sa sb ss pa pb ra rb rr rra rrb rrr`.
- Les opérations elles-mêmes restent sur stdout. On doit pouvoir faire `./push_swap --bench $ARG 2>bench.txt | ./checker_linux $ARG`.

### 1.7 Mettre à jour le Makefile
- Ajouter dans `SRCS` les nouveaux fichiers : utilitaires, `disorder.c` et `bench.c`.
- Lancer `make`, puis `make` une seconde fois : la seconde fois, **rien ne doit être recompilé** (pas de relink).
- Vérifier aussi `make clean`, `make fclean` et `make re`.

### 1.8 Ajouter un `.gitignore`
```
obj/
*.o
*.a
push_swap
```

---

## 2. Les petits cas (2, 3 et 5 éléments)

Ça rapporte beaucoup de points à l'évaluation.
- **2 éléments :** `sa` si besoin, soit 1 opération au maximum.
- **3 éléments :** `sort_three`, 2 opérations au maximum.
- **5 éléments :** environ 12 opérations au maximum. La méthode :
  1. faire `pb` sur les 2 plus petits, en prenant à chaque fois le chemin le plus court ;
  2. `sort_three` ;
  3. `pa` deux fois (vérifier que b est dans le bon ordre avant).
- **4 éléments :** même principe que 5, avec un seul `pb`.
- **Où le brancher :** dans `check_algo`, avant de choisir l'algo. Si `a.size <= 5`, on appelle `small_sort`, quel que soit le flag.

---

## 3. Vérifier que tout fonctionne

Le `checker_linux` fourni par le sujet doit être placé à la racine du repo, mais **sans le commit**.

### 3.1 Gestion d'erreurs
Chacune de ces commandes doit afficher `Error` sur stderr, et rien sur stdout :
```sh
./push_swap one
./push_swap ""
./push_swap 1 2 2
./push_swap 2147483648
./push_swap -2147483649
./push_swap + 1
./push_swap - 1
./push_swap 1 --simple      # flag après les nombres
./push_swap --foo 1 2       # flag inconnu
```

### 3.2 Cas sans sortie
Ces commandes ne doivent rien afficher :
```sh
./push_swap
./push_swap --bench
./push_swap 1 2 3 4 5
./push_swap 42
```

### 3.3 Exactitude et nombre de coups
```sh
ARG=$(shuf -i 0-9999 -n 100 | tr '\n' ' ')
./push_swap $ARG | ./checker_linux $ARG     # doit afficher OK
./push_swap $ARG | wc -l                     # nombre de coups
```
- Faire tourner ça **en boucle**, sur des dizaines de tirages, pour 3, 5, 100 et 500 nombres.
- Tester **chaque flag** (`--simple`, `--medium`, `--complex` et `--adaptive`) :
  - sur des entrées aléatoires ;
  - sur des entrées presque triées (désordre inférieur à 0,2) ;
  - sur des entrées triées à l'envers.
- Les flags doivent marcher **quelle que soit la taille** de l'entrée.

### 3.4 Seuils à atteindre (en mode par défaut)
| Taille | Minimum | Bon | Excellent |
|---|---|---|---|
| 100 | < 2000 | < 1500 | < 700 |
| 500 | < 12000 | < 8000 | < 5500 |

Si `quick_sort` est trop haut sur 500 nombres, deux pistes :
- passer à un algorithme de coût, où l'on calcule le coût de chaque élément et où l'on combine `rr` et `rrr` ;
- régler les pivots.

### 3.5 Fuites et plantages
```sh
valgrind --leak-check=full --show-leak-kinds=all ./push_swap $ARG > /dev/null
valgrind --leak-check=full ./push_swap 1 2 2       # chemin d'erreur
valgrind --leak-check=full ./push_swap             # sans argument
```
Résultat attendu : 0 octet perdu et 0 erreur dans tous les cas.

---

## 4. Norme

- [ ] **Remettre les headers 42** sur tous les `.c` et `.h` : ils ont été retirés, et les fichiers de `Tristan/` n'en ont jamais eu.
- [ ] **Ajouter une ligne vide entre chaque fonction**, notamment dans `min_max.c`, `quick_sort.c`, `range.c` et `pushswap_parse.c`.
- [ ] **Corriger tabulations et espaces** dans `pushswap_parse.c` :
  - `static int flag_cmp` et `int i;` doivent avoir une tabulation, pas un espace ;
  - `*count  % 10` contient un double espace.
- [ ] **Corriger le double espace** de `while (i <  n)` dans `parse_num.c`.
- [ ] **Respecter les limites** : 5 fonctions maximum par fichier, 25 lignes par fonction, 4 paramètres et 5 variables au maximum.
- [ ] **Lancer `norminette *.c *.h Enzo/ Tristan/ libft/ ft_printf/`** : il faut 0 erreur. Une seule erreur donne 0.

---

## 5. README.md

Le README actuel est celui de get_next_line et doit être entièrement réécrit, en anglais de préférence.
- [ ] **Première ligne, en italique :** `*This project has been created as part of the 42 curriculum by ebayle, trmorand.*`
- [ ] **Description :** le but du projet et une vue d'ensemble.
- [ ] **Instructions :** compiler (`make`), lancer, la liste des flags, et un exemple avec `checker_linux`.
- [ ] **Algorithms**, une explication détaillée pour chacun :
  - **simple (min/max) :** pourquoi il est en O(n²) ;
  - **medium (range / chunks) :** pourquoi il est en O(n√n), et pourquoi une plage de 15 pour 100 nombres et de 30 pour 500 ;
  - **complex (quicksort sur 2 piles) :** pourquoi il est en O(n log n) ;
  - **adaptive :** pourquoi les seuils 0,2 et 0,5, la technique utilisée dans chaque régime, et les bornes en temps et en mémoire.
- [ ] **La métrique de désordre :** sa définition et la façon de la calculer.
- [ ] **Contributions :** qui a fait quoi, par exemple les opérations et les algos pour Enzo, le parsing, les flags et le dispatch pour Tristan.
- [ ] **Resources :** les références, et **comment l'IA a été utilisée** (pour quelles tâches et sur quelles parties).

---

## 6. Avant le rendu

- [ ] **Avoir un seul `push_swap.h`** et aucun fichier inutile dans le repo : pas de `algo.c`, pas de `.o`, pas de binaire, pas de `checker_linux`.
- [ ] **Les deux logins doivent apparaître** dans les commits.
- [ ] **Faire un `git clone` du repo dans un dossier vide**, puis `make`, puis les tests. Seul ce qui est dans le repo compte.
- [ ] **Préparer la défense :**
  - chacun doit pouvoir expliquer **tout** le code, y compris celui de l'autre ;
  - s'entraîner à faire une petite modification en direct, par exemple changer un affichage.
