/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 16:08:32 by rpagot            #+#    #+#             */
/*   Updated: 2017/09/18 05:49:01 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				ft_map_display(t_map *map)
{
	int	bits_per_pixel;
	int	size_line;
	int	endian;
	int	x1;
	int	x2;
	int	y1;
	int	y2;
	float	m;
	int	mx;
	int	my;
	int	d;
	int	x;
	int x3;
	int y3;
	int x4;
	int y4;
	int d2;
	int mx2;
	int my2;
	int xx;
	int y;

	x1 = 10;
	y1 = 10;
	x3 = 350;
	y3 = 50;

	x2 = 400;
	y2 = 250;
	x4 = 50;
	y4 = 250;
	if (!(map->win = mlx_new_window(map->mlx, 500, 500, "yolo")))
		return ;
	if (!(map->image = mlx_new_image(map->mlx, 500, 500)))
		return ;
	map->addr = mlx_get_data_addr(map->image, &bits_per_pixel, &size_line, &endian);
	int	*addr;

	addr = (int*) map->addr;
	m = (x2 - x1) / (y2 - y1);
	mx = x2 - x1;
	my = y2 - y1;
	mx2 = x4 - x3;
	my2 = y4 - y3;
	x = x1 + y1 * 500;
	xx = x3 + y3 * 500;
	d = 2 * my - mx;
	d2 = 2 * my2 - mx2;
	y = y3 * 2;
	x3 = -x3;
	while (x < 500 * 500 && xx < 500 * 500)
	{
		if (x > x1 + y1 * 500 && x <= y2 * 500 + x2)
		{
			addr[x] = 0x00FFFFFF;
			if (d > 0)
			{
				x += 500;
				d -= 2 * mx;
			}
			d += 2 * my;
		}
		if (xx > x3 + y3 * 500 && xx <= y4 * 500 + x4)
		{
			addr[- xx + y * 500 + 350 + 350] = 0x00FFFFFF;
			if (d2 > 0)
			{
				xx += 500;
				y += 2;
				d2 -= 2 * mx2;
			}
			d2 += 2 * my2;
		}
		x++;
		xx++;
	}
	mlx_put_image_to_window(map->mlx, map->win, map->image, 0, 0);
	mlx_loop(map->mlx);
}
