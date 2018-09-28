	# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmarquet <jmarquet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 17:49:46 by jmarquet          #+#    #+#              #
#    Updated: 2017/11/16 20:28:14 by jmarquet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
PATH_HEAD= ./
PATH_SRCS = ./
PATH_PRINTF = ./ft_printf/
HEADERS = $(addprefix $(PATH_HEAD), libft.h)
PRINTF_HEADERS = $(addprefix $(PATH_PRINTF), ft_printf.h)
SRCS = $(addprefix $(PATH_SRCS), ft_construct_str.c ft_getenv.c ft_numlen_c.c ft_numlen_i.c ft_numlen_ll.c ft_bintree_free.c ft_bintree_traversal.c ft_bintree_insert.c ft_bintree_new.c ft_printbinary.c ft_memprepend.c ft_strreplace.c ft_strcutswap.c ft_strnfill.c ft_memsub.c ft_strswapfree.c ft_strcspn.c ft_strlen.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_strcmp.c ft_strncmp.c ft_strcpy.c ft_strncpy.c ft_putchar.c ft_putstr.c ft_putendl.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_memalloc.c ft_memdel.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strdup.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnequ.c ft_strnstr.c ft_atoi.c ft_isspace.c ft_putnbr.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_swap.c ft_iscntrl.c ft_isblank.c ft_isgraph.c ft_ispunct.c ft_isxdigit.c ft_atof.c ft_pow.c ft_strcicmp.c ft_strncicmp.c ft_isprime.c ft_strndup.c)
PRINTF_SRCS = $(addprefix $(PATH_PRINTF), utils_2.c helpers_lst.c formatters_number.c formatters_string.c converters.c util_convstr.c util_getstrsize.c utils.c wide_char_helpers.c ft_printf.c freers.c initializers.c parsers.c helpers.c formatters_main.c width_handler.c flags_handler.c prec_handler.c)
OBJ = $(SRCS:.c=.o)
PRINTF_OBJ = $(PRINTF_SRCS:.c=.o)

FLAGS = -Wall -Werror -Wextra
CC = $(shell whereis gcc)
AR = $(shell whereis ar)
RM = $(shell whereis rm)

.PHONY: clean, fclean, all, re, test

all: $(NAME)

$(NAME): $(OBJ) $(PRINTF_OBJ) $(HEADERS) $(PRINTF_HEADERS)
	$(AR) -rcs $(NAME) $(OBJ) $(PRINTF_OBJ)
%.o:%.c
	$(CC) $(FLAGS) -o $@ -c $< -I $(PATH_HEAD) -I $(PATH_PRINTF) 
clean:
	$(RM) -f $(OBJ) $(PRINTF_OBJ)
fclean: clean
	$(RM) -f $(NAME)
re: fclean all
	
