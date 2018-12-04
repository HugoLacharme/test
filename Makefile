#Variables
ROOT_DIR	=	$(realpath .)

SRC	=	$(ROOT_DIR)/comment.c\
		$(ROOT_DIR)/compile.c\
		$(ROOT_DIR)/corrector.c\
		$(ROOT_DIR)/find_errors.c\
		$(ROOT_DIR)/free.c\
		$(ROOT_DIR)/openf.c\
		$(ROOT_DIR)/parseur_util.c\
		$(ROOT_DIR)/parseur.c\
		$(ROOT_DIR)/utils.c\
		$(ROOT_DIR)/fct_corr/point_virg.c\
		$(ROOT_DIR)/get_tab.c\
		$(ROOT_DIR)/find_line.c\
		$(ROOT_DIR)/struct_errt.c\

CC	=	gcc

NAME	=	correcteur

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-std=c99 -fpic -Wall -Wextra -D_XOPEN_SOURCE=700

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

#Clean and Cleanall
.PHONY: clean cleanall

clean: 
	@rm -rf *.o
	@echo ".o supprimer"

fclean: clean
	@rm -rf $(NAME)
	@echo "exec supprimer"

re:	fclean all