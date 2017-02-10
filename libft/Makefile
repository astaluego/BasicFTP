# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aderuell <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/14 13:20:23 by aderuell          #+#    #+#              #
#    Updated: 2015/03/11 16:23:24 by aderuell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NNAME = ft
INCLUDE = ./includes
SRCPATH = ./srcs/
CFLAGS = -Wall -Werror -Wextra -ansi -pedantic
C = \033[1;35m
SRCS =	ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strlen.c \
		ft_strdup.c \
		ft_strcpy.c \
		ft_strncpy.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strstr.c \
		ft_strnstr.c \
		ft_strcmp.c \
		ft_strncmp.c \
		ft_atoi.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_islower.c \
		ft_isupper.c \
		ft_isprint.c \
		ft_iswhite.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_memalloc.c \
		ft_memdel.c \
		ft_strnew.c \
		ft_strdel.c \
		ft_strclr.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_strjoinchar.c \
		ft_strtrim.c \
		ft_strsplit.c \
		ft_itoa.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putendl.c \
		ft_putnbr.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstmap.c \
		get_next_line.c \

V = 0
S = 0
G = 0
T = 0
SILENCE_1 :=
SILENCE_0 :=@
SKIP_1 :=
SKIP_0 := \033[A
NORC_1 := norme
NORC_0 :=
DEBUG_1 := -g
DEBUG_0 :=
SKIP = $(SKIP_$(V))
DEBUG = $(DEBUG_$(G))
SILENCE = $(SILENCE_$(V))
NAME = lib$(NNAME).a
CLNAME = l$(NNAME)
CC = $(SILENCE)gcc
LIB = $(SILENCE)ar rc
RM = $(SILENCE)rm -rf
SRC = $(addprefix $(SRCPATH), $(SRCS))
OBJS= $(SRC:.c=.o)
SKIP_1 :=
SKIP_0 := \033[A
SKIP = $(SKIP_$(V))

W := o
BART := $(shell echo '$(OBJS)'|wc -w|tr -d ' ')
BARC = $(words $W)$(eval W := o $W)
BAR = $(shell printf "%`expr $(BARC) '*' 100 / $(BART)`s" | tr ' ' '=')

U = $(C)[$(NAME)]----->\033[0m

all: $(NORC) $(NAME)

$(NAME):$(OBJS)
	@echo "$(U)$(C)[COMPILE:\033[1;32m DONE$(C)]"
	@echo "$(U)$(C)[BUILD LIB]\033[0;32m"
	$(LIB) $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "$(SKIP)$(U)$(C)[BUILD  :\033[1;32m DONE$(C)]\033[0m\033[K"

.c.o:
	@echo "$(U)$(C)[COMPILE: \033[1;34m$<\033[A\033[0m"
	@echo "\033[0;32m"
	$(CC) -o $@ $(DEBUG) $(CFLAGS) -I $(INCLUDE) -c $<
	@printf "\033[1;34m[%-100s] %s%%\n" $(BAR) `echo $W|wc -w|tr -d ' '`
	@echo "$(SKIP)\033[A\033[2K$(SKIP)"

clean:
	@echo "$(U)$(C)[CLEAN]\033[0;32m"
	$(RM) $(OBJS)
	@echo "$(SKIP)$(U)$(C)[CLEAN:\033[1;32m   DONE$(C)]\033[0m"

fclean: clean
	@echo "$(U)$(C)[F-CLEAN]\033[0;32m"
	$(RM) $(NAME)
	@echo "$(SKIP)$(U)$(C)[F-CLEAN:\033[1;32m DONE$(C)]\033[0m"

re: fclean all

.PHONY: clean fclean
