# Besoin de faire :

si tu regardes sa et que je suis pas la, la structure errt est remplie donc tu peux t'amuser a faire une focntion de correction et tester, je ferais le tableau de fonctions plus tard.

y'a aussi le makefile a faire.

ah oui errt c'est devenu une liste chainé mais pour l'instant tu ten ballec vu que y'a pas de tableau de fonctions.

le find_err n'est pas fait mais tu n'en as pas besoin, fait en sorte que l'erreur que tu veux tester soit la premiere (ou la seul) et du coup tu n'auras pas besoin de naviguer dans la liste chainer pour trouver la bonne structure (ce cera la premiere).

dans le main rajoute directement t'as fonction avec errors en parametre. Si tu as mis ton erreurs et premier alors la premiere struct de errors contiendra les info sur ton erreur.



- Parseur :
1 : nom fichier
2 : ligne
3 : position ligne
4 : error/warning/note

si c'est une erreur : il te montre ou est l'erreur -> suivi d'un note
si c'est un warning : 

on creer des fonctions de gestion d'erreur
un tableau de fonction qui les contients
le parseur va definir la valeur de fct_err par rapport a la position de la fonction souhaiter dans le tableau pour pouvoir appeler la bonne fonction.