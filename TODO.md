# push_swap : ce qu'il reste à faire (partie obligatoire)

État au 18/11/2026. Les cases cochées sont faites.

## Déjà fait

- [x] Les 11 opérations : `srcs/ops_base.c`, `ops_base_push.c`, `ops_rotate.c`, `ops_rrr.c`
- [x] Le parsing des flags (`srcs/pushswap_parse.c`) et des nombres (`srcs/parse_num.c`)
- [x] Les erreurs détectées : non-entier, `""`, `+`, `-`, dépassement d'`int`, doublons, flag inconnu ou placé après les nombres
- [x] Le passage des valeurs en index : `to_rank` (`srcs/parse_num.c`)
- [x] Les algos : `minmax_sort` (`--simple`), `range_sort` (`--medium`), `quick_sort` (`--complex`)
- [x] L'adaptatif dans `check_algo` (`srcs/run_algo.c`) : `minmax_sort` si disorder > 0,95, `range_sort` si < 0,5, sinon `quick_sort`
- [x] Les utilitaires : `srcs/utils.c` et `srcs/utils_second.c` (`is_sorted`, `pos_of_min`, `pos_of_max`, `cost`, `top_a`, `sort_three`, `push_back_max`)
- [x] `compute_disorder` (`srcs/disorder.c`)
- [x] Les petits cas : jusqu'à 5 éléments, `minmax_sort` est utilisé quel que soit le flag (3 éléments : 2 coups max, 5 éléments : 10 coups max mesurés)
- [x] La libft et ft_printf, le Makefile, `main.c`, un seul `push_swap.h` à la racine
- [x] Tous les fichiers sont dans `srcs/` (plus de dossiers `Enzo/` et `Tristan/`)
- [x] Le `.gitignore` (`obj/`, `*.o`, `*.a`, `*.out`, `/push_swap`)
- [x] Les headers 42 sont présents sur tous les `.c` et `.h`

---

## 1. Obtenir un `make` qui passe

### 1.1 Corriger le commentaire du chat
- **Fichier :** `srcs/pushswap_parse.c`, ligne 69 (et suivantes).
- **Problème :** la ligne `//	/ > 💙 <\` se termine par `\`. En C, ça prolonge le commentaire sur la ligne suivante, et avec `-Werror` ça donne l'erreur `commentaire multi-lignes`.
- **Correction :** supprimer le dessin, ou retirer le `\` en fin de ligne.

### 1.2 Ajouter un compteur par opération (pour `--bench`)
- **Dans `t_ps`**, ajouter `int cnt[11];`, dans l'ordre `sa sb ss pa pb ra rb rr rra rrb rrr`.
- **L'initialiser à 0** dans `init_stacks` (`main.c`), par exemple avec `ft_bzero(ps->cnt, sizeof(ps->cnt))`.
- **Compter chaque opération :** changer `put_op(t_ps *ps, const char *s)` en `put_op(t_ps *ps, const char *s, int id)`, qui fait `ps->cnt[id]++`. Chaque fonction d'opération passe son indice (`sa` → 0, …, `rrr` → 10).

### 1.3 Écrire `print_bench` (nouveau fichier, par exemple `srcs/bench.c`)
Elle est déjà déclarée dans `push_swap.h` et appelée dans `main.c`, mais n'existe pas encore : c'est ce qui bloque l'édition de liens.
- **Prototype :** `void print_bench(t_ps *ps, int mode, double disorder);`
- **Tout s'écrit sur stderr (fd 2)**, avec `ft_putstr_fd` et `ft_putnbr_fd` (`ft_printf` écrit sur stdout).
- **À afficher**, dans le format de l'exemple du sujet :
  1. **Le désordre** en pourcentage avec 2 décimales, par exemple `49.93%`. On calcule `x = (int)(disorder * 10000 + 0.5)`, puis on affiche `x / 100`, un `.`, et `x % 100` **sur 2 chiffres** (`5.07`, pas `5.7`).
  2. **La stratégie et sa complexité**, d'après `mode % 10` :

     | Mode | Affichage |
     |---|---|
     | 1 (adaptive) | `Adaptive / ` + la complexité de l'algo choisi selon `disorder` (mêmes seuils que `run_algo`) |
     | 2 (complex) | `Complex / O(n log n)` |
     | 3 (medium) | `Medium / O(n√n)` |
     | 4 (simple) | `Simple / O(n²)` |

  3. **Le total** des opérations (`ps->ops`).
  4. **Le nombre de chaque opération** : `sa sb ss pa pb ra rb rr rra rrb rrr`.
- Les opérations restent sur stdout : `./push_swap --bench $ARG 2>bench.txt | ./checker_linux $ARG` doit marcher.

### 1.4 Mettre à jour le Makefile
- Ajouter `srcs/bench.c` dans `SRCS`.
- Lancer `make` deux fois : la seconde fois, **rien ne doit être recompilé** (pas de relink).
- Vérifier `make clean`, `make fclean` et `make re`.

---

## 2. Vérifier que tout fonctionne

Le `checker_linux` du sujet se place à la racine du repo, **sans le commit**.

### 2.1 Résultats mesurés le 18/11 (copie avec le commentaire corrigé, 30 tirages)

| Test | Coups max | Moyenne | Tri correct |
|---|---|---|---|
| 3 nombres | 2 | 1 | OK |
| 5 nombres | 10 | 8 | OK |
| 100 nombres (défaut) | 729 | 636 | OK |
| 500 nombres (défaut) | 5250 | 5148 | OK |
| 100, `--simple` | 1266 | 1163 | OK |
| 100, `--medium` | 610 | 578 | OK |
| 100, `--complex` | 716 | 697 | OK |
| 500, `--complex` | 5273 | 5231 | OK |

Seuils du sujet : 100 → < 700 excellent, 500 → < 5500 excellent.
- [ ] **100 nombres en mode par défaut** : on dépasse parfois 700 (max 729). Piste : régler les pivots de `quick_sort`, ou passer à `range_sort` sur une plus grande plage de désordre (`--medium` fait ~580 sur 100).
- [ ] **Refaire la mesure** avec `checker_linux` une fois le `make` réparé, sur des entrées presque triées et triées à l'envers, pour chaque flag.

### 2.2 Gestion d'erreurs
Déjà OK sur : `one`, `""`, `1 2 2`, `2147483648`, `+ 1`, `1 --simple`, `--foo 1 2`.
- [ ] Vérifier aussi `-2147483649`, `- 1`, et que rien ne sort sur stdout dans ces cas.

### 2.3 Cas sans sortie
Déjà OK sur : `./push_swap` et `./push_swap 1 2 3`.
- [ ] Vérifier `./push_swap --bench` et `./push_swap 42`.

### 2.4 Fuites et plantages
```sh
valgrind --leak-check=full --show-leak-kinds=all ./push_swap $ARG > /dev/null
valgrind --leak-check=full ./push_swap 1 2 2       # chemin d'erreur
valgrind --leak-check=full ./push_swap             # sans argument
```
- [ ] 0 octet perdu et 0 erreur dans tous les cas.

---

## 3. Norme

Résultat de `norminette main.c push_swap.h srcs/` au 18/11 :
- [ ] **`min_max.c`** : ajouter une ligne vide avant les fonctions des lignes 36 et 50.
- [ ] **`range.c`** : ajouter une ligne vide avant la fonction de la ligne 30.
- [ ] **`parse_num.c`** : double espace ligne 102 (`while (i <  n)`).
- [ ] **`pushswap_parse.c`** :
  - ligne 15 : tabulation au lieu d'espace avant le nom de `flag_cmp` ;
  - ligne 17 : tabulation au lieu d'espace dans `int i;` ;
  - ligne 42 : double espace (`*count  % 10`) ;
  - ligne 47 : ligne vide avant la fonction.
- [ ] **Relancer `norminette *.c *.h srcs/ libft/ ft_printf/`** après l'ajout de `bench.c` : il faut 0 erreur. Une seule erreur donne 0.

---

## 4. README.md

Le README actuel est encore celui de get_next_line et doit être entièrement réécrit, en anglais de préférence.
- [ ] **Première ligne, en italique :** `*This project has been created as part of the 42 curriculum by ebayle, trmorand.*`
- [ ] **Description :** le but du projet et une vue d'ensemble.
- [ ] **Instructions :** compiler (`make`), lancer, la liste des flags, et un exemple avec `checker_linux`.
- [ ] **Algorithms**, une explication détaillée pour chacun :
  - **simple (min/max) :** pourquoi il est en O(n²) ;
  - **medium (range / chunks) :** pourquoi il est en O(n√n), et le choix de la taille des plages ;
  - **complex (quicksort sur 2 piles) :** pourquoi il est en O(n log n) ;
  - **adaptive :** pourquoi les seuils 0,5 et 0,95, la technique utilisée dans chaque régime, et les bornes en temps et en mémoire.
- [ ] **La métrique de désordre :** sa définition (proportion de paires inversées) et la façon de la calculer.
- [ ] **Contributions :** qui a fait quoi, par exemple les opérations et les algos pour Enzo, le parsing, les flags et le dispatch pour Tristan.
- [ ] **Resources :** les références, et **comment l'IA a été utilisée** (pour quelles tâches et sur quelles parties).

---

## 5. Avant le rendu

- [ ] **Aucun fichier inutile** dans le repo : pas de `.o`, pas de binaire, pas de `checker_linux`.
- [ ] **Les deux logins doivent apparaître** dans les commits.
- [ ] **Faire un `git clone` du repo dans un dossier vide**, puis `make`, puis les tests. Seul ce qui est dans le repo compte.
- [ ] **Préparer la défense :**
  - chacun doit pouvoir expliquer **tout** le code, y compris celui de l'autre ;
  - s'entraîner à faire une petite modification en direct, par exemple changer un affichage.
