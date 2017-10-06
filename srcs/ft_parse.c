/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 10:13:58 by rpagot            #+#    #+#             */
/*   Updated: 2017/10/06 08:33:32 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_map	*ft_set_sizex(t_map *map, int i)
{
	map->error = 0;
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
	off_t	size;

	size = 0;
	if ((fd = open(str, O_RDONLY)) > 0)
		while (get_next_line(fd, &line) > 0)
		{
			size += ft_strlen(line);
			free(line);
		}
	map->data = (int *)malloc(size * sizeof(int));
	if ((fd = open(str, O_RDONLY)) > 0)
	{
		while (get_next_line(fd, &line) > 0)
		{
			tab = ft_strsplit(line, ' ');
			atoi_tab(tab, map);
			free(line);
			ft_doublefree(&tab, &free);
			map->sizey++;
		}
	}
	return (map);
}
