
CC := c++

CFLAGS := -Wall -Wextra -Werror -std=c++98

NAME := canon

MAIN := main.cpp

INC := Fixed.hpp

SRCS := Fixed.cpp

OBJ_DIR := objs

OBJS := $(addprefix $(OBJ_DIR)/, $(SRCS:%.cpp=%.o))



all : $(NAME)

$(NAME) : $(OBJS) $(MAIN)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o : %.cpp $(INC) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(OBJ_DIR) :
	mkdir -p objs

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re

