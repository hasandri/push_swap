# push_swap

`push_swap` est un projet algorithmique qui consiste à trier une liste d'entiers avec un nombre minimal d'opérations.

## Objectif

Concevoir une stratégie de tri optimisée pour ordonner les valeurs dans la pile `a` en utilisant une pile auxiliaire `b` et un jeu d'instructions limité.

## Contraintes

- Deux piles uniquement : `a` et `b`
- Opérations autorisées limitées aux mouvements du sujet (swap, push, rotate, reverse rotate)
- Minimiser strictement le nombre total de coups

## Exigences de performance

L'implémentation doit viser les seuils de validation attendus au projet 42, notamment :

- Trier 500 nombres en moins de **5500 mouvements**

## Approche recommandée

- Implémenter des structures de données adaptées en C (souvent des listes chaînées)
- Définir un algorithme de tri sur mesure pour réduire le coût en opérations
- Mesurer régulièrement le nombre de mouvements générés sur des jeux de tests volumineux
