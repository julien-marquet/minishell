# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/11/07 17:49:46 by jmarquet     #+#   ##    ##    #+#        #
#    Updated: 2018/09/25 18:20:27 by jmarquet    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = minishell
PATH_HEAD = ./
LIB_NAME = ft
PATH = ./
SRCS = $(addprefix $(PATH), main.c allocators.c helpers.c destructors.c expansions.c expansions_utilities.c parsers.c dispatchers.c exec.c env.c searchers.c)
HEADER_FILE = $(addprefix $(PATH_HEAD), minishell.h)
OBJ = $(SRCS:.c=.o)

PATH_LIBFT = ./Libft/
LIBFT_HEADER = $(addprefix $(PATH_LIBFT), libft.h ft_printf/ft_printf.h)
LIBFT_SRCS = $(addprefix $(PATH_LIBFT), ft_getenv.c ft_numlen_c.c ft_numlen_i.c ft_numlen_ll.c ft_bintree_free.c ft_bintree_traversal.c ft_bintree_insert.c ft_bintree_new.c ft_printbinary.c ft_memprepend.c ft_strreplace.c ft_strcutswap.c ft_strnfill.c ft_memsub.c ft_strswapfree.c ft_strcspn.c ft_strlen.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_strcmp.c ft_strncmp.c ft_strcpy.c ft_strncpy.c ft_putchar.c ft_putstr.c ft_putendl.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_memalloc.c ft_memdel.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strdup.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnequ.c ft_strnstr.c ft_atoi.c ft_isspace.c ft_putnbr.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_swap.c ft_iscntrl.c ft_isblank.c ft_isgraph.c ft_ispunct.c ft_isxdigit.c ft_atof.c ft_pow.c ft_strcicmp.c ft_strncicmp.c ft_isprime.c ft_strndup.c ft_printf/utils_2.c ft_printf/helpers_lst.c ft_printf/formatters_number.c ft_printf/formatters_string.c ft_printf/converters.c ft_printf/util_convstr.c ft_printf/util_getstrsize.c ft_printf/utils.c ft_printf/wide_char_helpers.c ft_printf/ft_printf.c ft_printf/freers.c ft_printf/initializers.c ft_printf/parsers.c ft_printf/helpers.c ft_printf/formatters_main.c ft_printf/width_handler.c ft_printf/flags_handler.c ft_printf/prec_handler.c)
LIBFT_OBJ = $(LIBFT_SRCS:.c=.o)

CC := $(shell whereis gcc)
AR := $(shell whereis ar)
RM := $(shell whereis rm)
FLAGS = -fsanitize=address -g

export CC
export AR
export RM
export FLAGS

.PHONY: clean, fclean, all, re, $(NAME)libft

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_OBJ) $(HEADER_FILE) $(LIBFT_HEADER)
	$(MAKE) -eC $(PATH_LIBFT)
	$(CC) $(FLAGS) -o $(NAME) -L$(PATH_LIBFT) -l$(LIB_NAME) $(OBJ) -I $(PATH_HEAD)
$(PATH)%.o:$(PATH)%.c
	$(CC) $(FLAGS) -c $< -o $@ -I $(PATH_HEAD)
clean:
	$(MAKE) -eC $(PATH_LIBFT) clean
	$(RM) -f $(OBJ)
fclean: clean
	$(MAKE) -eC $(PATH_LIBFT) fclean
	$(RM) -f $(NAME)
re: fclean all
	
