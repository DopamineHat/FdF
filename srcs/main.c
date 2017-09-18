/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 12:11:46 by rpagot            #+#    #+#             */
/*   Updated: 2017/09/13 13:28:34 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_map *map;

	if (!(argc == 2))
	{
		ft_putstr_fd("Fdf: invalid arguments.\n", 2);
		return (1);
	}
	map = ft_parsemap(argv[1]);
	int i;
	int i2;

	i = 0;
	i2 = 0;
	while(map->data[i])
	{
		while (map->data[i][i2] > 0)
		{
			printf("%d ", map->data[i][i2]);
			++i2;
		}
		printf("\n");
		++i;
		i2 = 0;
	}

	if (!(map->mlx = mlx_init()))
	  return (0);
	ft_map_display(map);
	return (0);
}
