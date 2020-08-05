##
## Duo Project C Library
## DCLL_C_Library
## File description:
## Makefile use for DCLL_C_library compilation
##

SRC	=	\

override CFLAGS	=	-Wall -Wextra	\

override CPPFLAGS	+=	-I ./../../include/dcll	\

OBJ	=	$(SRC:.c=.o)	\

NAME	=	libdcll.a	\

CP	=	cp	\

AR	=	ar	\

OBJ	=	$(SRC:.c=.o)	\

all:	$(NAME)

$(NAME):	$(OBJ)
	$(AR) rc $(NAME) $(OBJ)
	$(CP) -u $(NAME) ../

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
