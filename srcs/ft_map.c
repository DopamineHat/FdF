/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 16:08:32 by rpagot            #+#    #+#             */
/*   Updated: 2017/10/14 14:15:35 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void				ft_set_pointsx(t_map *map)
{
	map->x1 = map->xn * map->widthx - map->yn * map->widthx;
	map->y1 = (map->widthx * map->yn + map->xn * map->widthx) * 2 / map->zoom
				- (map->data[map->xn + (map->yn - 1) * map->sizex - 1]
				* map->zratio / map->zoom);
	map->x2 = (map->xn + 1) * map->widthx - map->yn * map->widthx;
	map->y2 = (map->widthx * map->yn + (map->xn + 1) * map->widthx)
				* 2 / map->zoom
				- (map->data[map->xn + (map->yn - 1) * map->sizex]
				* map->zratio / map->zoom);
}

static	void				ft_set_pointsy(t_map *map)
{
	map->x1 = map->xn * map->widthx - map->yn * map->widthx;
	map->y1 = (map->widthx * map->yn + map->xn * map->widthx) * 2 / map->zoom
		- (map->data[map->xn + (map->yn - 1) * map->sizex - 1]
		* map->zratio / map->zoom);
	map->x2 = map->xn * map->widthx - (map->yn + 1) * map->widthx;
	map->y2 = (map->widthx * (map->yn + 1) + map->xn * map->widthx)
		* 2 / map->zoom
		- (map->data[map->xn + map->yn * map->sizex - 1]
		* map->zratio / map->zoom);
}

static	void				ft_draw_line(t_map *map)
{
	int		*addr;

	addr = (int *)map->addr;
	map->mx = abs(map->x2 - map->x1);
	map->my = -abs(map->y2 - map->y1);
	map->signx = map->x1 < map->x2 ? 1 : -1;
	map->signy = map->y1 < map->y2 ? 1 : -1;
	map->d = map->mx + map->my;
	while (map->x1 + (map->y1 + map->sizex) * map->width * 2
			- map->width < map->width * map->length * 4
			&& map->x1 > -map->width
			&& (map->x1 + (map->y1 + map->sizex)
			* map->width * 2
			- map->width) > 0)
	{
		addr[map->x1 + (map->y1 + map->sizex) * map->width
			* 2 - map->width] = 0x00FFFFFF;
		if (map->x1 + map->y1 * map->width == map->x2 + map->y2 * map->width)
			break ;
		ft_process_line(map);
	}
}

static	void				ft_draw_grid(t_map *map)
{
	map->xn = 1;
	while (map->yn < map->sizey + 1)
	{
		while (map->xn < map->sizex)
		{
			ft_set_pointsx(map);
			ft_draw_line(map);
			map->xn++;
		}
		map->xn = 1;
		map->yn++;
	}
	map->yn = 1;
	while (map->xn < map->sizex + 1)
	{
		while (map->yn < map->sizey)
		{
			ft_set_pointsy(map);
			ft_draw_line(map);
			map->yn++;
		}
		map->yn = 1;
		map->xn++;
	}
}

void						ft_map_display(t_map *map)
{
	map->widthx = map->width * 2 / ((map->sizex + 1) * 1.5 * map->zoom);
	if (map->widthx == 0)
		map->widthx = 1;
	if (!(map->image = mlx_new_image(map->mlx, map->width * 2,
					map->length * 2)))
		return ;
	map->addr = mlx_get_data_addr(map->image, &map->bpp,
			&map->size_line, &map->endian);
	ft_draw_grid(map);
	mlx_put_image_to_window(map->mlx, map->win, map->image,
			map->posx, map->posy);
}
