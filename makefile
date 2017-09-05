# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adeletan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/16 07:30:41 by adeletan          #+#    #+#              #
#    Updated: 2017/09/02 03:07:58 by adeletan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := wolf3d

LIBFT = libft/libft.a

FLAGS := -L./minilibx -lmlx -framework OpenGl -framework AppKit
INCLUDES := -I./minilibx -I./includes

SRCS := main.c			

SRCSP := $(addprefix ./srcs/,  $(SRCS))
OBJS = $(SRCS:.c=.o)
OBJSP = $(addprefix ./objs/, $(SRCS:.c=.o))
OBJS = $(SRCSP:.c=.o)

all : lib $(NAME)

lib :
	make -C libft/


$(NAME): $(OBJS)
	gcc $(FLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(INCLUDES)

%.o : %.c
	gcc -c -o $@ $< $(INCLUDES)

clean :
	make -C libft/ clean
	rm -rf $(OBJSP) $(OBJS)

fclean : clean
	make -C libft/ fclean
	rm -rf $(NAME)

re : fclean all
