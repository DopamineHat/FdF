#ifndef FDF_H
# define FDF_H

#include <mlx.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

#include "libft.h"

typedef struct	s_map
{
		int		width;
		int		length;
		void	*mlx;
		void	*win;
		void	*image;
		char	*addr;
		int		**data;
		int		signx;
		int		signy;
		int		d;
		int		d2;
		int		x1;
		int		y1;
		int		x2;
		int		y2;
		int		mx;
		int		my;
		int		sizex;
		int		error;
		int		xn;
		int		widthx;
		int		yn;
}				t_map;

t_map		*ft_parsemap(char *str, t_map *map);
void		ft_map_display(t_map *map);

#endif
