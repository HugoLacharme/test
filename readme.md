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

