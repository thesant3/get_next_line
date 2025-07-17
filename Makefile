#library file's name
NAME = get_next_line.a
#dir for .h file
INC_DIR = ./inc
#dir for .o files
OBJ_DIR = ./obj
#dir for .c files
SRC_DIR = ./src
#dir for .a files
BIN_DIR = ./bin

#compiler and flags
cc = gcc
CFLAGS = -Wall -Wextra -Werror -I./

#Make the static library
AR = ar rcs

#Delete files
RM = rm -rf

SRC = $(wildcard $(SRC_DIR)/*.c)

SRC_BONUS =$(wildcard $(SRC_DR)/*.c)

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

OBJ_BONUS = $(SRC_BONUS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

#rule to compile everything
all : $(NAME)

#rule to make the library
$(NAME) : $(OBJ)
	mkdir -p $(BIN_DIR)
	$(AR) $(NAME) $(OBJ)

#rule to make the library and bonus
bonus: $(OBJ) $(OBJ_BONUS)
	$(AR) $(NAME) $(OBJ) $(OBJ_BONUS)
	
#%.c to %.o
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) -MD $(CFLAGS) -c $< -o $@

-include $(OBJ_DIR)/*.d

clean:
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME) $(OBJ_DIR)

re : fclean all

#indicate that the next rules are not real files
.PHONY: all clean fclean re
