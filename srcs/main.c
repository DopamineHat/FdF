/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 12:11:46 by rpagot            #+#    #+#             */
/*   Updated: 2017/10/06 08:47:33 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_set_values(t_map *map)
{
	map->sizey = 0;
	map->posx = 0;
	map->posy = 0;
	map->width = 800;
	map->length = 800;
	map->xn = 1;
	map->yn = 1;
	map->sizex = 0;
	map->sizey = 0;
	map->mlx = mlx_init();
	map->zoom = 2;
	map->zratio = 2;
	map->win = mlx_new_window(map->mlx, map->width * 2,
			map->length * 2, "FdF");
}

int				main(int argc, char **argv)
{
	t_map	*map;
	int		i;
	int		i2;

	if (!(argc == 2))
	{
		ft_putstr_fd("FdF: invalid arguments.\n", 2);
		return (1);
	}
	if (!(map = (t_map*)malloc(sizeof(t_map))))
		return (1);
	ft_set_values(map);
	ft_parsemap(argv[1], map);
	ft_map_display(map);
	mlx_hook(map->win, KEYPRESS, KEYRELEASE, &ft_hook_keys, map);
	mlx_loop(map->mlx);
	return (0);
}
