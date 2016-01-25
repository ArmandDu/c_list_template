
INC_DIR	=	../

INC_UNITY =	../tools/unity/src
TEST_DIR  =	./

UNITY_GEN =	../tools/unity/auto/generate_test_runner.rb

TEST_SRC  =	$(TEST_DIR)/test_template_list_basics.c
UNITY_SRC =	$(INC_UNITY)/unity.c
RUN_SRC	  =	$(TEST_DIR)/test_runners/test_test_Runner.c

SRC=		$(TEST_SRC) \
		$(UNITY_SRC) \
		$(RUN_SRC)

OBJ  =		$(SRC:.c=.o)

TEST_NAME =	list_template_test.out

CFLAGS	 +=	-Wall -Wextra -Werror
CFLAGS	 +=	-I$(INC_DIR) -I$(INC_UNITY)
CFLAGS	+=	-DTEST -ggdb

all: 		generate_runner test

generate_runner:
		ruby $(UNITY_GEN) $(TEST_SRC) $(RUN_SRC)


test:		$(OBJ)
		$(CC) -o $(TEST_NAME) $(OBJ) $(CFLAGS) $(SYMBOLS)
		./$(TEST_NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(TEST_NAME)
