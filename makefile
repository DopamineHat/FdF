# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/06 01:11:02 by rpagot            #+#    #+#              #
#    Updated: 2017/10/06 01:12:09 by rpagot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fdf

LIBFT = libft/libft.a

CFLAGS := -L./minilibx_macos -lmlx

INCLUDES := -I./minilibx_macos -I./includes -I./libft -framework OpenGl \
	-framework Appkit

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
	gcc $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(INCLUDES)

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
