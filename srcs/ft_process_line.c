/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 18:35:28 by rpagot            #+#    #+#             */
/*   Updated: 2017/09/29 18:45:19 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_process_line(t_map *map)
{
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
