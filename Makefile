#Variables
CC=gcc
CCFLAG=-Wall
EXEC=Correcteur
SRC	=	$(ROOT_DIR)/comment.c\
		$(ROOT_DIR)/compile.c\
		$(ROOT_DIR)/corrector.c\
		$(ROOT_DIR)/find_errors.c\
		$(ROOT_DIR)/free.c\
		$(ROOT_DIR)/openf.c\
		$(ROOT_DIR)/parseur_util.c\
		$(ROOT_DIR)/parseur.c\
		$(ROOT_DIR)/utils.c\
		$(ROOT_DIR)/fct_corr/$(wildcard *.c)\
OBJ= $(SRC:.c=.o)

All: $(EXEC)

#Génération d'executables
Correcteur: $(OBJ)
	@$(CC) -o $@ $^ $(CCFLAG) 
	@echo $@ "generated"

corrector.o: corrector.h

#Génération des .o
%.o: %.c 
	@$(CC) -o $@ -c $< $(CCFLAG) 
	@echo $@ "generated"

#Clean and Cleanall
.PHONY: clean cleanall

clean: 
	@rm -rf *.o
	@echo ".o supprimer"

cleanall: clean
	@rm -rf $(EXEC)
	@echo "exec supprimer"