### Question 1
*Quelle est l’utilité de l’opérateur = et du constructeur par copie?*

Un constructeur par copie copie les valeurs d’un premier objet créé par le constructeur par défaut dans une nouvelle addresse mémoire aux valeurs identiques.
L’opérateur = fait environ la même chose ; il affecte la valeur d’un objet par une nouvelle valeur.

### Question 2
*Dans quel cas est-il absolument nécessaire de les implémenter?*

Il est nécessaire d’implémenter un constructeur par copie lorqu’on copie une classe ayant un attribut qui est un pointeur X qui est situé sur la même addresse mémoire. Nécessairement, on veut garder les deux valeurs différentes du pointeur X de chaque classe, mais sans constructeur par copie, la première valeur de X sera supprimée avec delete en passant à la deuxième classe.


### Question 2
*Qu’est-ce qui différencie l’opérateur = du constructeur par copie?*


L'opérateur = est appelée si on essaie d’affecter un autre objet après l’initialisation alors que le constructeur par copie est appelé lors de la création de l’objet.
Pour éviter des problèmes de compilation, il faut supprimer le premier objet (qui est déjà affecté par l’opérateur =) avant de passer au nouveau objet qu’on veut affecter par =.
