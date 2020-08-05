##
## Duo Project C Library
## DCLL_C_Library
## File description:
## Makefile use for DCLL_C_library compilation
##

SRC_LIBMY	=	lib/my	\

TESTS_LIBMY	=	tests/tests_dcll/	\

NAME_LIBMY	=	-ldcll	\

CRITERION_FLAGS	=	-lcriterion --coverage	\

override LDFLAGS	+=	-L./lib	\

override LDLIBS	+=	$(CRITERION_FLAGS)	\
					$(NAME_LIBMY)	\

override CPPFLAGS	+=	-I ./include/	\

RM	=	rm -rf	\

MV	=	mv	\

MKDIR	=	mkdir	\

MAKE	=	make	\

CC	=	gcc	\

TESTS_DIR	=	tests/	\

COVERAGE_DIR	=	coverage/	\

UNIT_TESTS_BINARY	=	unit_tests	\

all:
	$(MAKE) -C $(SRC_LIBMY)

debug:
	$(MAKE) debug -C $(SRC_LIBMY)

tests_run:
	@find -name "*.gcda" -delete
	@find -name "*.gcno" -delete
	$(MAKE) -C $(SRC_LIBMY)
	$(CC) -o $(UNIT_TESTS_BINARY) $(TESTS_LIBMY) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)
	./$(UNIT_TESTS_BINARY)
	$(MKDIR) -p $(COVERAGE_DIR)
	$(MV) *.gcda $(COVERAGE_DIR)
	$(MV) *.gcno $(COVERAGE_DIR)
	$(RM) $(UNIT_TESTS_BINARY)

clean:
	@find -name "*.gcda" -delete
	@find -name "*.gcno" -delete
	$(RM) $(UNIT_TESTS_BINARY)
	$(MAKE) clean -C $(SRC_LIBMY)

fclean: clean
	$(MAKE) fclean -C $(SRC_LIBMY)
	$(RM) $(COVERAGE_DIR)

re:	fclean all

.NOTPARALLEL:
.PHONY: all debug tests_run clean fclean re
