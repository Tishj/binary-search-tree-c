# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tbruinem <tbruinem@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/03/19 18:02:35 by tbruinem      #+#    #+#                  #
#    Updated: 2021/03/19 18:05:36 by tbruinem      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME =	bstlib.a

SRC_DIR =	./src/
OBJ_DIR =	./obj/

SRC =	bstree_init.c \
		bstree_insert.c \
		key_compare.c \
		bstree_delete.c \
		bstree_find.c

OBJ =	$(SRC:%.c=$(OBJ_DIR)%.o)
