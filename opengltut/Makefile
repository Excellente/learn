CC = clang++
SRC = display.cpp opengl.cpp
SRCDIR = src/
INC = include/
SRCS = $(addprefix $(SRCDIR), $(SRC))
SDL2_INC = ./lib/sld2/include/SDL2
all:
	$(CC) $(SRCS) -I $(INC) -I $(SDL2_LIB) -o test
