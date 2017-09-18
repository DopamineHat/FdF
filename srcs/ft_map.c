/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 16:08:32 by rpagot            #+#    #+#             */
/*   Updated: 2017/09/18 07:29:33 by rpagot           ###   ########.fr       */
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
	int	mx;
	int	my;
	int	signx;
	int	signy;
	int	d;
	int d2;
	int y;

	x1 = 400;
	y1 = 400;

	x2 = 350;
	y2 = 50;
	if (!(map->win = mlx_new_window(map->mlx, 500, 500, "yolo")))
		return ;
	if (!(map->image = mlx_new_image(map->mlx, 500, 500)))
		return ;
	map->addr = mlx_get_data_addr(map->image, &bits_per_pixel, &size_line, &endian);
	int	*addr;

	addr = (int*) map->addr;
	mx = abs(x2 - x1);
	my = -abs(y2 - y1);
	signx = x1 < x2 ? 1 : -1;
	signy = y1 < y2 ? 1 : -1;
	d = mx + my;
	while (x1 + y1 * 500 < 500 * 500)
	{
		addr[x1 + y1 * 500] = 0x00FFFFFF;
		if (x1 + y1 * 500 == x2 + y2 * 500)
			break;
		d2 = d * 2;
		if (d2 >= my)
		{
			d += my;
			x1 += signx;
		}
		if (d2 <= mx)
		{
			d += mx;
			y1 += signy;
		}
	}
	mlx_put_image_to_window(map->mlx, map->win, map->image, 0, 0);
	mlx_loop(map->mlx);
}
