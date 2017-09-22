/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 10:13:58 by rpagot            #+#    #+#             */
/*   Updated: 2017/09/22 07:49:41 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_map	*ft_set_sizex(t_map *map, int i)
{
	if (map->sizex != i && map->sizex != 0)
		{
			map -> error = 1;
			ft_putstr_fd("FdF : wrong file format. \n", 2);
		}
	map->sizex = i;
	return (map);
}

static int	count_lines(char *str)
{
	int 	fd;
	char	*line;
	int		cnt;

	cnt = 0;
	if ((fd = open(str, O_RDONLY)) < 0)
		return (-1);
	while (get_next_line(fd, &line) > 0)
	{
		free(line);
		++cnt;
	}
	close(fd);
	return (cnt);
}

static	void	atoi_tab(int **array, char **tab, t_map *map)
{
	int index;

	index = 0;
	while (tab[index])
		++index;
	*array = (int*)malloc(sizeof(int) * (index + 1));
	bzero((void*)(*array), (index + 1) * sizeof(int));
	index = 0;
	while (tab[index])
	{
		(*array)[index] = ft_atoi(tab[index]);
		++index;
	}
	ft_set_sizex(map, index);
}

t_map	*ft_parsemap(char *str, t_map *map)
{
	char	*line;
	char	**tab;
	int		fd;
	int		i;

	map->sizex = 0;
	map->error = 0;
	i = 0;
	map->data = (int**)malloc(sizeof(int*) * (count_lines(str) + 1));
	if ((fd = open(str, O_RDONLY)) > 0)
	{
		while (get_next_line(fd, &line) > 0)
		{
			tab = ft_strsplit(line, ' ');
			atoi_tab(&(map->data[i]), tab, map);
			free(line);
			ft_doublefree(tab, &free);
			++i;
		}
	}
	map->data[i] = NULL;
	return (map);
}
