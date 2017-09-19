/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 16:08:32 by rpagot            #+#    #+#             */
/*   Updated: 2017/09/19 07:16:39 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void				ft_draw_line(t_map *map)
{
	int		*addr;

	addr = (int *)map->addr;
	map->mx = abs(map->x2 - map->x1);
	map->my = -abs(map->y2 - map->y1);
	map->signx = map->x1 < map->x2 ? 1 : -1;
	map->signy = map->y1 < map->y2 ? 1 : -1;
	map->d = map->mx + map->my;
	while (map->x1 + map->y1 * 500 < 500 * 500)
	{
		addr[map->x1 + map->y1 * 500] = 0x00FFFFFF;
		if (map->x1 + map->y1 * 500 == map->x2 + map->y2 * 500)
			break ;
		map->d2 = map->d * 2;
		if (map->d2 >= map->my)
		{
			map->d += map->my;
			map->x1 += map->signx;
		}
		if (map->d2 <= map->mx)
		{
			map->d += map->mx;
			map->y1 += map->signy;
		}
	}
}

void						ft_map_display(t_map *map)
{
	int	bits_per_pixel;
	int	size_line;
	int	endian;

	map->x1 = 400;
	map->y1 = 400;
	map->x2 = 350;
	map->y2 = 50;
	if (!(map->win = mlx_new_window(map->mlx, 500, 500, "yolo")))
		return ;
	if (!(map->image = mlx_new_image(map->mlx, 500, 500)))
		return ;
	map->addr = mlx_get_data_addr(map->image, &bits_per_pixel,
			&size_line, &endian);
	int	*addr;

	addr = (int *)map->addr;
	ft_draw_line(map);
	mlx_put_image_to_window(map->mlx, map->win, map->image, 0, 0);
	mlx_loop(map->mlx);
}
