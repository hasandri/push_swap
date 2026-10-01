*This activity has been created as part of the 42 curriculum by hasandri, fetraand.*


# **push_swap**

# DESCRIPTION

Push_swap est un projet de l'école 42 dont l'objectif est de trier une pile de données avec un ensemble d'instructions limité, en utilisant le moins de mouvements possible.

Le projet push_swap est un défi qui réside dans l'optimisation algorithmique. On reçois une liste de nombres entiers (la pile A) et on dois les trier par ordre croissant en utilisant une pile auxiliaire (B) et une série d'opérations spécifiques (rotations, échanges, poussées).

Ce projet permet de développer :

- la logique algorithmique
- l’optimisation du nombre d’opérations
- la gestion des structures de données (stacks)
- le parsing et la gestion des erreurs

Le but principal n’est pas seulement de trier, mais de trier avec le moins d’opérations possible.

## Exigence de performance

Pour répondre aux attentes du projet, l’algorithme doit viser un seuil strict sur les gros jeux de données :

- Trier 500 nombres en moins de **5500 mouvements**

---

# INSTRUCTION

## Installation
```bash
git clone git@vogsphere.42antananarivo.mg:vogsphere/intra-uuid-865484eb-ca86-4174-ad71-c0be281b30d8-7396825-fetraand push_swap

cd push_swap
```

## Compilation
```bash
make
```

## Execution
```bash
./push_swap [option] <liste d'entiers>
ou
./push_swap <liste d'entiers> [option]

exemple 1:
./push_swap --bench 1 3 2 4

- Output:

```bash
pb
sa
pa
[bench] disorder: 16.67%
[bench] strategy: Simple / O(n²)
[bench] total_ops: 3
[bench] sa: 1   sb: 0   ss: 0   pa: 1   pb: 1
[bench] ra: 0   rb: 0   rr: 0   rra: 0  rrb: 0  rrr: 0

exemple 2:
./push_swap [pas d'option] 1 3 2 4 : Utilisation automatique de l'algo adaptive

exemple 3:
./push_swap --simple --complex --medium --bench 4 67 3 87 23

- Output
```bash
ra
ra
pb
ra
ra
pb
rra
pa
pa
[bench] disorder: 40.00%
[bench] strategy: Medium / O(n√n)
[bench] total_ops: 9
[bench] sa: 0   sb: 0   ss: 0   pa: 2   pb: 2
[bench] ra: 4   rb: 0   rr: 0   rra: 1  rrb: 0  rrr: 0

Remarques:
On peut placer les options à n'importe quelles positions (devant, derrière, au milieu)
```

## Options disponibles
- `--simple`	: algorithme simple O(n²) (selection sort)
- `--medium`	: algorithme moyen O(n√n) (chunk)
- `--complex`	: algorithme complexe O(n log n) (radix)
- `--adaptive` : choix automatique de l’algorithme
- `--bench` : affiche les statistiques

---

# ALGORITHME 
 Le programme utilise plusieurs stratégies selon la taille et le désordre des données:
 
## Simple - O(n²) (Selection Sort)
Facile à implémenter, très peu d'opérations sur petits datasets, utilisé pour:
- petits inputs (n <= 3)
- données presque triées

## Medium - O(n√n) (Chunk)
Réduit le nombre d'opérations, bon compromis entre performance et complexité:
- division des données en groupes (chunks)
- traitement progressif

## Complexe - O(n log n) (Radix Sort)
Très performant pour grandes données, stable et prévisible
-  tri basé sur les bits
-  indexation des valeurs

## Adaptif
Optimise le nombre total d'opérations et s'adapte à chaue cas.
Le programme choisit automatiuement:
- n <= 3 : simple
- faible désordre : simple
- désordre moyen : chunk
- fort désordre : radix

## Mode benchmark

- `--bench` : Affiche des statistiques de performance détaillées après le tri.

La sortie du benchmark inclut :

- **Désordre** — Le désordre calculé de l’entrée*(pourcentage avec 2 décimales)*
- **Stratégie** — Le nom de l’algorithme utilisé et sa classe de complexité théorique
- **Total operations** — Le nombre total d’opérations effectuées
- **Détails des operations** — Le nombre de chaque opération individuelle :

  |Operation| Description 					|
  |---------|-------------------------------|
  | `sa`	| swap a 						|
  | `sb`	| swap b 						|
  | `ss`	| sa et sb en meme temps	|
  | `pa`	| push vers a						|
  | `pb`	| push  vers b 						|
  | `ra`	| rotate a 						|
  | `rb`	| rotate b 						|
  | `rr`	| ra and rb en meme temps	|
  | `rra`	| reverse rotate a 				|
  | `rrb`	| reverse rotate b 				|
  | `rrr`	| rra and rrb en meme temps	|

## Commande make

- Compile
```bash
make
```
- Suprime les .o
```bash
make clean
```
- Suprime tout
```bash
make fclean
```
- Recompile
```bash
make re
```

---

# ERREUR

Le programme affiche ‘Error’ dans les cas suivants:
- Arguments non numériques
- Doublons
- Dépassement de INT_MAX / INT_MIN
- Entrée vide ou invalide

## Exemple
- Input
```bash
./push_swap 1 3 deux
./push_swap "   " "1 2 5"
./push_swap 3 1 3
./push_swap 5 1 2147483648
```
- Output
```bash
Error
```
---

# RESSOURCES

## References

- [Sorting Algorithms](https://www.youtube.com/watch?v=bRPHvWgc6YM/)
- [Radix Sort](https://en.wikipedia.org/wiki/Radix_sort)
- [Further explanation of push_swap](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)

## Utilisation d'IA (chatGPT, DeepSeek)
- Compréhension des algo de tri
- Optimisation des stratégies
- Structure du README

---

# CONTRIBUTION
- *hasandri*:
  - Operation
  - Parsing
  
- *fetrand*:
  - Algorithm
  - Makefile

- Groupe :
  - Algo_benchmark
  - Main
  - Gestion des erreurs

---

# JUSTIFICATION DE L' ALGORITHME

## Pourquoi ?

Le choix d’utiliser plusieurs algorithmes repose sur une contrainte essentielle du projet push_swap :
minimiser le nombre d’opérations, et non simplement trier.

Un seul algorithme ne peut pas être optimal pour tous les cas, car la performance dépend fortement de :

  - la taille des données (n)
  - le niveau de désordre initial

C’est pourquoi une approche multi-stratégie a été adoptée.

## Algorithme simple — O(n²) (Selection Sort)

Cet algorithme parcourt la pile pour identifier systématiquement le plus petit élément et le déplacer vers la pile auxiliaire.

Justification :

  - Sur de petites tailles (n <= 5), les algorithmes complexes introduisent un surcoût inutile.  
  - La selection sort nécessite peu d’opérations concrètes dans push_swap
  - Il est très efficace lorsque les données sont déjà partiellement triées

Dans ce contexte, la complexité théorique O(n²) est négligeable face au coût réel en opérations

## Algorithme medium — O(n√n) (Chunk)

L’approche par chunks permet de mieux contrôler les déplacements entre les piles A et B.

Justification :

  - Réduit les rotations inutiles
  - Permet de traiter les données par blocs cohérents
  - Diminue significativement le nombre total d’opérations comparé à un algo quadratique

C’est un compromis efficace entre simplicité et performance pour des tailles moyennes

## Algorithme complexe — O(n log n) (Radix Sort)

Le radix sort est utilisé pour les grands volumes de données.

Justification :

  - Complexité stable et prévisible
  - Très peu de comparaisons (basé sur les bits)
  - Compatible avec les contraintes de push_swap (push + rotate)

C’est l’algorithme le plus fiable et performant pour les grands datasets, même très désordonnés

## Stratégie adaptative

Une stratégie unique serait inefficace dans certains cas.
Le mode adaptatif permet de choisir dynamiquement la meilleure approche.

Justification :

  - Analyse du niveau de désordre
  - Adaptation en fonction de la taille des données
  - Optimisation automatique sans intervention de l’utilisateur

Cela permet d’obtenir un nombre d’opérations proche de l’optimal dans tous les cas

## Conclusion

Chaque algorithme a été choisi pour un rôle précis :

Selection sort → optimal pour petits inputs
Chunk → équilibre performance / complexité
Radix sort → optimal pour grands volumes
Adaptatif → maximise l’efficacité globale

L’objectif final est atteint :
réduire au maximum le nombre d’opérations en s’adaptant intelligemment aux données.
