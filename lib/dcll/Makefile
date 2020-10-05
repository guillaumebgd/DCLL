##
## Duo Project C Library
## DCLL_C_Library
## File description:
## Makefile use for DCLL_C_library compilation
##

SRC	=	__dcll_get_abs_index.c	\
		__dcll_get_node_by_index.c	\
		dcll_create.c	\
		dcll_inject_array.c	\
		dcll_create_list.c	\
		dcll_create_node.c	\
		dcll_destroy_list.c	\
		dcll_destroy_node.c	\
		dcll_put_node_in_list.c	\
		dcll_set_node.c	\

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