/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook_keys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 05:26:07 by rpagot            #+#    #+#             */
/*   Updated: 2017/10/06 08:35:16 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_reset_values(t_map *map)
{
	map->xn = 1;
	map->yn = 1;
	map->sizex = 0;
	map->sizey = 0;
	mlx_destroy_image(map->mlx, map->image);
}

static int		ft_hook_keys4(int key, t_map *map)
{
	if (key == KEY_DOWN)
	{
		map->blackscreen = mlx_new_image(map->mlx, map->width * 2,
				map->length * 2);
		mlx_put_image_to_window(map->mlx, map->win, map->blackscreen,
				0, 0);
		if (map->zratio > 1)
			map->zratio /= 2;
		ft_map_display(map);
	}
	return (0);
}

static int		ft_hook_keys3(int key, t_map *map)
{
	if (key == KEY_S)
	{
		map->blackscreen = mlx_new_image(map->mlx, map->width * 2,
				map->length * 2);
		mlx_put_image_to_window(map->mlx, map->win, map->blackscreen,
				0, 0);
		map->posy += 10;
		ft_map_display(map);
	}
	if (key == KEY_UP)
	{
		map->blackscreen = mlx_new_image(map->mlx, map->width * 2,
				map->length * 2);
		mlx_put_image_to_window(map->mlx, map->win, map->blackscreen,
				0, 0);
		map->zratio *= 2;
		ft_map_display(map);
	}
	ft_hook_keys4(key, map);
	return (0);
}

static int		ft_hook_keys2(int key, t_map *map)
{
	if (key == KEY_A)
	{
		map->blackscreen = mlx_new_image(map->mlx, map->width * 2,
				map->length * 2);
		mlx_put_image_to_window(map->mlx, map->win, map->blackscreen,
				0, 0);
		map->posx -= 10;
		ft_map_display(map);
	}
	if (key == KEY_W)
	{
		map->blackscreen = mlx_new_image(map->mlx, map->width * 2,
				map->length * 2);
		mlx_put_image_to_window(map->mlx, map->win, map->blackscreen,
				0, 0);
		map->posy -= 10;
		ft_map_display(map);
	}
	ft_hook_keys3(key, map);
	return (0);
}

int				ft_hook_keys(int key, t_map *map)
{
	if (key == KEY_ESCAPE)
	{
		mlx_destroy_window(map->mlx, map->win);
		free(map);
		exit(EXIT_SUCCESS);
	}
	else if (key == KEY_PAD_SUB)
	{
		map->zoom *= 2;
		ft_reset_values(map);
		ft_map_display(map);
	}
	else if (key == KEY_D)
	{
		map->blackscreen = mlx_new_image(map->mlx, map->width * 2,
				map->length * 2);
		mlx_put_image_to_window(map->mlx, map->win, map->blackscreen,
				0, 0);
		map->posx += 10;
		ft_map_display(map);
	}
	ft_hook_keys2(key, map);
	return (0);
}
