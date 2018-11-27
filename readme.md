# Besoin de faire :

- le main prend en parametre les fichiers du programme 
	- int main(char ac, char **av)
- fonction qui utilise le compilateur(system() ou exec() et fork())
    - void compiletamere(char**av);
- fonction qui recupere la sortie d'erreur (read(2,buffer,taille buffer))
	- char * compileStderr()
- fonction qui ouvre le/les fichiers du programme (open())
	- int *openProg(char **av)
- fonction qui decoupe les information du compilateur pour les utilisé
    - int **parseError(char *buff)
- fonction qui place un offset a l'endroi de l'erreur/les erreurs (fonction lseek())
	- off_t placeOffset(int **a) //on vera plus tard
- fonction qui va placer un commentaire à l'endroit de l'erreur. (write())
    - void commenterror(off_t x,int *fd)
- Type d'erreur pris en compte :
    - error
    - note
    - 

- commencer à analyser la sortie du compilateur 
	- la fonction dans laquelle il y a l'erreur
	- l'erreur/warning
	- note

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