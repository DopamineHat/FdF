/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 12:11:46 by rpagot            #+#    #+#             */
/*   Updated: 2017/09/24 16:15:44 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_set_values(t_map *map)
{
	map->width = 500;
	map->length = 500;
	map->xn = 1;
	map->yn = 1;
	map->sizex = 0;
	map->sizey = 0;
}

int		main(int argc, char **argv)
{
	t_map	*map;
	int		i;
	int		i2;

	if (!(argc == 2))
	{
		ft_putstr_fd("Fdf: invalid arguments.\n", 2);
		return (1);
	}
	if (!(map = (t_map*)malloc(sizeof(t_map))))
		return (1);
	ft_set_values(map);
	ft_parsemap(argv[1], map);
	if (!(map->mlx = mlx_init()))
		return (0);
	ft_map_display(map);
	return (0);
}
