/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeletan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 03:04:19 by adeletan          #+#    #+#             */
/*   Updated: 2017/09/05 07:27:57 by lmenigau         ###   ########.fr       */
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
	int index;
	int index2;

	index = 0;
	index2 = 0;
	while(map->data[index])
	{
		while (map->data[index][index2] > 0)
		{
			printf("%d ", map->data[index][index2]);
			++index2;
		}
		printf("\n");
		++index;
		index2 = 0;
	}
	return (0);
}
