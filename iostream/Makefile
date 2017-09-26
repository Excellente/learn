CC = clang++
SRC = *.cpp
SRCDIR = ./src/
INC = ./include
SRCS = $(addprefix $(SRCDIR), $(SRC))
LIB = -L. -lboost_serialization

all:
	$(CC) $(SRCS) $(LIB) -I $(INC) -o test

clean:
	rm -f test

re: clean all