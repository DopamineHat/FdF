/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 10:13:58 by rpagot            #+#    #+#             */
/*   Updated: 2017/09/29 18:28:43 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_map	*ft_set_sizex(t_map *map, int i)
{
	if (map->sizex != i && map->sizex != 0)
	{
		map->error = 1;
		ft_putstr_fd("FdF : wrong file format. \n", 2);
	}
	map->sizex = i;
	return (map);
}

static	void	atoi_tab(char **tab, t_map *map)
{
	int i;
	int n;

	n = 0;
	i = 0;
	while (tab[n])
		++n;
	while (tab[i])
	{
		map->data[map->sizey * n + i] = ft_atoi(tab[i]);
		++i;
	}
	ft_set_sizex(map, i);
}

t_map			*ft_parsemap(char *str, t_map *map)
{
	char	*line;
	char	**tab;
	int		fd;
	int		i;
	off_t	size;

	map->error = 0;
	i = 0;
	if ((fd = open(str, O_RDONLY)) > 0)
	{
		size = lseek(fd, 0, SEEK_END);
		map->data = (int *)malloc(size * sizeof(int));
		lseek(fd, 0, SEEK_SET);
		while (get_next_line(fd, &line) > 0)
		{
			tab = ft_strsplit(line, ' ');
			atoi_tab(tab, map);
			free(line);
			ft_doublefree(tab, &free);
			++i;
			map->sizey = i;
		}
	}
	return (map);
}
