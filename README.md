
# DINER DES PHILOSOPHES

Il s’agit d’un problème devenu emblématique, initialement formulé par le hollandais Dijkstra en 1965, mais transposé sous la présente forme par le britannique Hoare.

Cinq philosophes muets dinent autour d’une table ronde. Devant chaque philosophe se trouve une assiette de spaghettis et cinq fourchettes sont réparties aux cotés des philosophes, comme l’illustre la figure ci-dessus. Chaque philosophe doit impérativement penser et manger, en alternance. Toutefois, pour pouvoir manger, un philosophe doit utiliser les deux fourchettes proches de lui (la gauche et la droite) et chaque fourchette ne peut être tenue que par un seul philosophe à la fois. Un philosophe peut prendre les fourchettes à des moments différents, selon leur disponibilité, mais ne peut manger que s’il tient les deux. Un philosophe ne sait pas quand les autres souhaitent manger ou penser. On suppose que les assiettes sont remplies de spaghettis au fur et à mesure que les convives les vident et ce indéfiniment. Enfin, les philospohes ont un apétit et une capacité d’absorbtion sans limite.

Le problème est d’imaginer un comportement adoptable par chaque philosophe et qui permette d’assurer qu’aucun d’entre eux ne soit jamais bloqué et puisse indéfiniment alterner ses périodes de réflexion et celles de restauration.


## Travail
Il s’agit de concevoir une solution au problème tel qu’énoncé ci-dessus. L’utilisation de la bibliothèque Qt et de ses classes permetant de gérer le multithreading est imposé, mais il n’est pas demandé de réaliser un affichage graphique.

Une esquisse de modèle est à respecter, le reste de l’implémentation est laissé libre. Le programme doit se structurer autour des classes Philosophe et Fourchette.
## Authors

- [AYITE Yawo](https://github.com/yawoayite)

