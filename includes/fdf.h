/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 18:47:28 by rpagot            #+#    #+#             */
/*   Updated: 2017/10/04 03:47:01 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>

# include "libft.h"
# include "key_codes_macos.h"
# include "events.h"

typedef struct	s_map
{
	int		width;
	int		length;
	void	*mlx;
	void	*win;
	void	*image;
	int		bpp;
	int		endian;
	int		size_line;
	char	*addr;
	int		*data;
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
	int		sizey;
	int		error;
	int		xn;
	int		widthx;
	int		yn;
	int		zoom;
}				t_map;

t_map			*ft_parsemap(char *str, t_map *map);
void			ft_map_display(t_map *map);
void			ft_process_line(t_map *map);

#endif
