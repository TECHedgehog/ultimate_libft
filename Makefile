# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eherrero <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/07 13:05:48 by eherrero          #+#    #+#              #
#    Updated: 2019/11/11 15:00:10 by eherrero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libultra.a

CC=gcc

CFLAGS=-g -Wall -Wextra -Werror -O3

RM=rm -f

LDFLAGS=-L.

LDLIBS=-lft

HDDIRS=-I includes/

SRCSTR=ultra_str0.c ultra_str1.c
SRCIO=ultra_io0.c
SRCFREE=frees.c
SRCLOG=log.c

SRC=$(SRCSTR) $(SRCIO) checks.c $(SRCFREE) $(SRCLOG)

OBJ=$(SRC:.c=.o)

$(NAME):
	$(CC) $(CFLAGS) -c $(SRC) $(HDDIRS)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJ) $(OBJ2)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean all bonus