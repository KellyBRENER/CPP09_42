Consignes de l'exercice :
//créer un programme qui prend une séquence d'entiers positif en argument
//utiliser l'algorithme de tri "merge-insert" pour trier les nombres
//c'est à dire l'algorithme ford-johnson
//utiliser au moins deux conteneurs différents pour comparer le temps d'exécution de chacun
// gérer au moins 3000 entiers différents
//implémenter l'algorithme pour chaque conteneur
/*
résultats :
1ere ligne : texte explicite + séquences d'entiers positifs non triés
2eme ligne : texte explicite + séquence d'entiers triés
3eme ligne : texte explicite + temps utilisé par l'algo + conteneur utilisé
4eme ligne : idem pour le 2ème conteneur

pour tester le programme :
> ./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
permet de générer 3000 entiers pouvant aller de 1 à 100 000
*/
//on va séparer les nombres en paires de nombres
//on va trier chaque paire
//merger 2 paires
//comparer les plus petits nombres de chaque paire pour déplacer le + petit dans le conteneur final
//continuer à comparer les plus petits de chaque conteneur pour les déplacer au fur et à mesure dans le conteneur final jusqu'à ce qu'il n'y ai plus de nombre dans les deux conteneurs
//puis comparer 2 paires merges avec 2 paires merges selon le même procédé
//à chaque fois, on part des deux plus petits de chaque liste et on place le + petit dans une nouvelle liste
//puis on prends à nouveau les 2 plus petits et on sort le + petit des deux etc...
