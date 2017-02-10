# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aderuell <aderuell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/01 22:17:21 by aderuell          #+#    #+#              #
#    Updated: 2016/04/25 15:27:43 by aderuell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = serveur
CLIENT = client
LIBNAME = ft

SRCS_SERVER = main.c \
init_server.c \
error.c \
ls_cd.c \
pwd_quit.c \
put.c \
get.c \
tool.c \

SRCS_CLIENT = main.c \
init_client.c \
error.c \
basic_command.c \
client_command.c \
put.c \
get.c \
tool.c \

V = 0
SILENCE_1 :=
SILENCE_0 :=@
SILENCE = $(SILENCE_$(V))
LNAME = lib$(LIBNAME)
CLNAME = l$(LIBNAME)
LIB = -L $(LNAME)/ -$(CLNAME)
INCLUDE = ./includes/
LINCLUDE = $(LNAME)/includes/
CFLAGS = -g -Wall -Werror -Wextra
CC = $(SILENCE)gcc
RM = $(SILENCE)rm -rf
MAKE = $(SILENCE)make V=$(V)

SRCPATH_SERVER = ./srcs/server/
SRCPATH_CLIENT = ./srcs/client/

INCLUDES = -I $(INCLUDE) -I $(LINCLUDE)
SRC_SERVER = $(addprefix $(SRCPATH_SERVER), $(SRCS_SERVER))
SRC_CLIENT = $(addprefix $(SRCPATH_CLIENT), $(SRCS_CLIENT))
OBJS_SERVER= $(SRC_SERVER:.c=.o)
OBJS_CLIENT= $(SRC_CLIENT:.c=.o)
SKIP_1 :=
SKIP_0 := \033[A
SKIP = $(SKIP_$(V))
C = \033[0;35m
U = $(C)[$(NAME)]------------>\033[0m

all: $(SERVER) $(CLIENT)

$(SERVER):$(OBJS_SERVER)
	@echo "$(U)$(C)[COMPILE:\033[1;32m DONE\033[0;35m]\033[0m"
	$(MAKE) all -C $(LNAME)
	@echo "$(U)$(C)[BUILD]\033[0;32m"
	$(CC) -o $(SERVER) -L . $(OBJS_SERVER) $(CFLAGS) $(INCLUDES) $(LIB)
	@echo "$(SKIP)\033[2K$(SKIP)\033[2K"
	@echo "$(SKIP)$(U)$(C)[BUILD  :\033[1;32m DONE$(C)]\033[0m"

$(CLIENT):$(OBJS_CLIENT)
	@echo "$(U)$(C)[COMPILE:\033[1;32m DONE\033[0;35m]\033[0m"
	$(MAKE) all -C $(LNAME)
	@echo "$(U)$(C)[BUILD]\033[0;32m"
	$(CC) -o $(CLIENT) -L . $(OBJS_CLIENT) $(CFLAGS) $(INCLUDES) $(LIB)
	@echo "$(SKIP)\033[2K$(SKIP)\033[2K"
	@echo "$(SKIP)$(U)$(C)[BUILD  :\033[1;32m DONE$(C)]\033[0m"

%.o: %.c
	@echo "$(U)$(C)[COMPILE: \033[0;35m$<\033[A\033[0m"
	@echo "\033[0;32m"
	$(CC) -o $@ $(CFLAGS) $(INCLUDES) -c $<
	@echo "\033[0;35m [.working.]"
	@echo "$(SKIP)\033[2K\033[A\033[2K$(SKIP)"

clean:
	@echo "$(U)$(C)[CLEAN]\033[1;32m"
	$(RM) $(OBJS_SERVER)
	$(RM) $(OBJS_CLIENT)
	@echo "$(SKIP)$(U)$(C)[CLEAN:\033[1;32m	 DONE$(C)]\033[0m"

fclean: clean
	$(MAKE) fclean -C $(LNAME)
	@echo "$(U)$(C)[F-CLEAN]\033[1;32m"
	$(RM) $(SERVER)
	$(RM) $(CLIENT)
	@echo "$(SKIP)$(U)$(C)[F-CLEAN:\033[1;32m DONE$(C)]\033[0m"

re: fclean all

.PHONY: clean fclean all re $(CLIENT) $(SERVER)
