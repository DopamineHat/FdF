/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 12:11:46 by rpagot            #+#    #+#             */
/*   Updated: 2017/10/14 14:12:30 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_set_values(t_map *map, char *str)
{
	map->error = 0;
	map->sizey = 0;
	map->posx = 0;
	map->posy = 0;
	map->width = 600;
	map->length = 600;
	map->xn = 1;
	map->yn = 1;
	map->sizex = 0;
	map->sizey = 0;
	map->mlx = mlx_init();
	map->zoom = 2;
	map->zratio = 1;
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
	if (!(ft_strcmp(argv[1], "/dev/random")))
		return (1);
	if (open(argv[1], O_DIRECTORY) >= 0)
		return (1);
	if (!(map = (t_map*)malloc(sizeof(t_map))))
		return (1);
	if (open(argv[1], O_RDONLY) < 0)
		return (1);
	ft_set_values(map, argv[1]);
	ft_parsemap(argv[1], map);
	ft_map_display(map);
	mlx_hook(map->win, KEYPRESS, KEYRELEASE, &ft_hook_keys, map);
	mlx_loop(map->mlx);
	return (0);
}
