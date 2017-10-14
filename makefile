# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/06 01:11:02 by rpagot            #+#    #+#              #
#    Updated: 2017/10/11 07:09:28 by rpagot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fdf

LIBFT = libft/libft.a

CGLAGS := -Wall -Wextra -Werror -Ofast -march=native
LCFLAGS := -L./minilibx_macos -lmlx -framework OpenGL \
		-framework Appkit


INCLUDES := -I./minilibx_macos -I./includes -I./libft

SRCS := main.c \
		ft_parse.c \
		ft_map.c \
		ft_process_line.c \
		ft_hook_keys.c

SRCSP := $(addprefix ./srcs/,  $(SRCS))
OBJS = $(SRCS:.c=.o)
OBJSP = $(addprefix ./objs/, $(SRCS:.c=.o))
OBJS = $(SRCSP:.c=.o)

all : lib $(NAME)

lib :
	make -C libft/
	make -C minilibx_macos/


$(NAME): $(OBJS)
	gcc $(LCFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(INCLUDES)

%.o : %.c
	gcc $(CFLAGS)  $(INCLUDES) -c -o $@ $<

clean :
	make -C libft/ clean
	make -C minilibx_macos/ clean
	rm -rf $(OBJSP) $(OBJS)

fclean : clean
	make -C libft/ fclean
	rm -rf $(NAME)

re : fclean all
