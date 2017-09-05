#include "fdf.h"

static int	count_lines(char *str)
{
	int 	fd;
	char	*line;
	int		cnt;

	cnt = 0;
	if ((fd = open(str , O_RDONLY)) < 0)
		return (-1);
	while (get_next_line(fd, &line) > 0)
	{
		free(line);
		++cnt;
	}
	close(fd);
	return (cnt);
}

static	void	atoi_tab(int **array, char **tab)
{
	int index;

	index = 0;
	while (tab[index])
		++index;
	*array = (int*)malloc(sizeof(int) * (index + 1));
	bzero((void*)(*array), (index+1) * sizeof(int));
	index = 0;
	while (tab[index])
	{
		(*array)[index] = ft_atoi(tab[index]);
		++index;
	}
}

t_map	*ft_parsemap(char *str)
{
	char	*line;
	char	**tab;
	t_map	*map;
	int		fd;
	int		i;

	i = 0;
	if (!(map = (t_map*)malloc(sizeof(t_map))))
		return (map);
	map->data = (int**)malloc(sizeof(int*) * (count_lines(str) + 1));
	if ((fd = open(str , O_RDONLY)) > 0)
	{
		while (get_next_line(fd, &line) > 0)
		{
			tab = ft_strsplit(line, ' ');
			atoi_tab(&(map->data[i]), tab);
			free(line);
			ft_doublefree(tab, &free);
			++i;
		}	
	}
	map->data[i] = NULL;
	return (map);
}
			
			
