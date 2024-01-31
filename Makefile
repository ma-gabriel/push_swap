# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: geymat <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/08 04:17:20 by geymat            #+#    #+#              #
#    Updated: 2024/01/18 11:54:42 by geymat           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = push_swap.c \
       utils.c \
       create.c \
       algo.c \
       ft_split.c \
       selection_sort.c \
       backtracking.c \
       backtrack_utils.c \
       ft_backtrack.c \
       pa_backtrack.c \
       pb_backtrack.c \
       ra_backtrack.c \
       rb_backtrack.c \
       rra_backtrack.c \
       rr_backtrack.c \
       rrb_backtrack.c \
       rrr_backtrack.c \
       sa_backtrack.c \
       sb_backtrack.c \
       ss_backtrack.c \
       utils_s.c

HEADERS = push_swap.h \
	  structs.h

OBJECTS = $(SRCS:.c=.o)

NAME = push_swap 

CFLAGS = -Wall -Wextra -Werror

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@ -I.

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE) all

.PHONY: re all clean fclean
