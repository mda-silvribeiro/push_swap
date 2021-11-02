# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mda-silv <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/19 17:16:37 by mda-silv          #+#    #+#              #
#    Updated: 2021/02/22 13:59:24 by mda-silv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

LIB		= libft.h

CFLAGS	= -Wall -Wextra -Werror

CC 		= gcc

AR 		= ar -rcs

RM 		= rm -f


SRCS	= $(wildcard *.c)

OBJS	= $(SRCS:.c=.o)

all: 		$(NAME)

$(NAME):	$(OBJS)
			$(AR) $@ $^

bonus: 		$(OBJS)
			$(AR) $(NAME) $^

%.o: %.c 	$(LIB)
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			$(RM) $(OBJS)

fclean: 	clean
			$(RM) $(NAME)

re: 		fclean all
