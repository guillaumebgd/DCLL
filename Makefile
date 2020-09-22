##
## Duo Project C Library
## DCLL
## File description:
## Makefile use for DCLL compilation
##

SRC_LIBDCLL	=	lib/dcll	\

NAME_LIBDCLL	=	-ldcll	\

override LDFLAGS	+=	-L./lib	\

override LDLIBS	+=	$(NAME_LIBDCLL)	\

override CPPFLAGS	+=	-I ./include/	\

UNIT_TESTS_BINARY	=	unit_tests	\

TEST_COVERAGE_DIR	=	tests/coverage	\

all:
	$(MAKE) -C $(SRC_LIBDCLL)

debug:
	$(MAKE) debug -C $(SRC_LIBDCLL)

tests_run:	LDLIBS += -lcriterion --coverage
tests_run:	CFLAGS += --coverage
tests_run:
	@find -name "*.gcda" -delete
	@find -name "*.gcno" -delete
	$(MAKE) -C $(SRC_LIBDCLL)
	$(CC) -O3 -o $(UNIT_TESTS_BINARY) tests/test_*.c $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)
	./$(UNIT_TESTS_BINARY)
	$(RM) -rf $(UNIT_TESTS_BINARY)
	mkdir $(TEST_COVERAGE_DIR)
	mv *.gc* $(TEST_COVERAGE_DIR)

clean:
	@find -name "*.gcda" -delete
	@find -name "*.gcno" -delete
	$(RM) -rf $(UNIT_TESTS_BINARY)
	$(RM) -rf $(TEST_COVERAGE_DIR)
	$(MAKE) clean -C $(SRC_LIBDCLL)

fclean: clean
	$(MAKE) fclean -C $(SRC_LIBDCLL)

re:	fclean all

.NOTPARALLEL:
.PHONY: all debug tests_run clean fclean re
