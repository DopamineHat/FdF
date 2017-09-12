# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adeletan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/16 07:30:41 by adeletan          #+#    #+#              #
#    Updated: 2017/09/12 09:36:06 by rpagot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fdf

LIBFT = libft/libft.a

FLAGS := -L./minilibx -lmlx -framework OpenGl -framework AppKit -g3 -fsanitize=address
INCLUDES := -I./minilibx -I./includes -I./libft

SRCS := main.c \
		ft_parse.c

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
