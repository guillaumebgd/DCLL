##
## Duo Project C Library
## DCLL_C_Library
## File description:
## Makefile use for DCLL_C_library compilation
##

SRC	=	__dcll_add_node.c	\
		__dcll_get_abs_index.c	\
		__dcll_get_node_by_index.c	\
		dcll_create.c	\
		dcll_destroy_list.c	\

override CFLAGS	=	-Wall -Wextra	\

override CPPFLAGS	+=	-I ./../../include/	\

OBJ	=	$(SRC:.c=.o)	\

NAME	=	libdcll.a	\

MV	=	mv	\

AR	=	ar	\

OBJ	=	$(SRC:.c=.o)	\

all:	$(NAME)

$(NAME):	$(OBJ)
	$(AR) rc $(NAME) $(OBJ)
	$(MV) $(NAME) ../

debug:
	$(CC) -g -o ../../$@ ../../main.c $(SRC) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) ../../debug
	$(RM) $(NAME)
	$(RM) ../$(NAME)

re:	fclean all

.PHONY: all debug clean fclean re