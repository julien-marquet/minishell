# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/11/07 17:49:46 by jmarquet     #+#   ##    ##    #+#        #
#    Updated: 2018/09/18 18:21:48 by jmarquet    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = minishell
PATH_HEAD = ./
PATH_LIBFT = ./Libft/
LIB_NAME = ft
PATH = ./
SRCS = $(addprefix $(PATH), main.c allocators.c helpers.c destructors.c)
OBJ = $(SRCS:.c=.o)
HEADER_FILE = $(addprefix $(PATH_HEAD), minishell.h)

CC := $(shell whereis gcc)
AR := $(shell whereis ar)
RM := $(shell whereis rm)
FLAGS = -fsanitize=address -g

export CC
export AR
export RM
export FLAGS

.PHONY: clean, fclean, all, re, test

all: $(NAME)

$(NAME): $(OBJ) $(HEADER_FILE) | $(NAME)libft
	$(CC) $(FLAGS) -o $(NAME) -L$(PATH_LIBFT) -l$(LIB_NAME) $(OBJ) -I $(PATH_HEAD)
$(NAME)libft: 
	@make -eC $(PATH_LIBFT)
%.o:%.c
	$(CC) $(FLAGS) -c $< -I $(PATH_HEAD)
clean:
	make -eC $(PATH_LIBFT) clean
	$(RM) -f $(OBJ)
fclean: clean
	make -eC $(PATH_LIBFT) fclean
	$(RM) -f $(NAME)
re: fclean all
	
