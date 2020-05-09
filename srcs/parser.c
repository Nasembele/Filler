/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyster <soyster@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 13:47:11 by soyster           #+#    #+#             */
/*   Updated: 2020/03/16 16:53:12 by soyster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

int	ft_parse_player(t_start *inf, t_map *map)
{
	char	*line;
	int		i;
	int		gnl;
	char	**tab;

	i = 0;
	line = NULL;
	gnl = get_next_line(map->fd, &line);
	if (gnl == 0 || gnl == -1)
		return (0);
	if (!line || !line[i])
	{
		if (line)
			ft_strdel(&line);
		return (0);
	}
	ft_fill_infpl(inf, 'A', 'A');
	tab = ft_strsplit(line, ' ');
	ft_strdel(&line);
	if (ft_strcmp(tab[0], "$$$") != 0 || ft_len_arr(tab) != 5)
	{
		ft_free_string_arr(tab);
		return (0);
	}
	if (ft_strlen(tab[2]) == 2)
	{
		if (tab[2][1] == '1')
			ft_fill_infpl(inf, 'O', 'X');
		if (tab[2][1] == '2')
			ft_fill_infpl(inf, 'X', 'O');
	}
	ft_free_string_arr(tab);
	if (inf->my == 'A')
		return (0);
	return (1);
}

int	ft_fill_infpl(t_start *inf, char my, char en)
{
	inf->my = my;
	inf->en = en;
	return (0);
}

int	ft_parse_map_size(t_map *map)
{
	char	*line;
	char	**tab;
	char	**arr;
	int		gnl;

	line = NULL;
	gnl = get_next_line(map->fd, &line);
	if (gnl == 0 || gnl == -1)
		return (0);
	if (!line || !line[0])
	{
		if (line)
			ft_strdel(&line);
		return (0);
	}
	tab = ft_strsplit(line, ' ');
	ft_strdel(&line);
	if (ft_strcmp(tab[0], "Plateau") != 0 || ft_len_arr(tab) != 3)
	{
		ft_free_string_arr(tab);
		return (0);
	}
	map->height = ft_atoi(tab[1]);
	arr = ft_strsplit(tab[2], ':');
	map->width = ft_atoi(arr[0]);
	ft_free_string_arr(tab);
	ft_free_string_arr(arr);
	return (1);
}

int	ft_parse_map(t_map *map)
{
	char	*line;
	int		gnl;

	line = NULL;
	gnl = get_next_line(map->fd, &line);
	if (gnl == 0 || gnl == -1)
		return (0);
	if (!line)
		return (0);
	if (line) // ?
		ft_strdel(&line);
	if (!(map->map = (char**)malloc(sizeof(char*) * (map->height + 1))))
		return (0);
	if (!ft_read_map(0, map, line))
		return (0);
	return (1);
}

int	ft_read_map(int j, t_map *map, char *line)
{
	char	**tab;
	int		gnl;

	while (j < map->height)
	{
		gnl = get_next_line(map->fd, &line);
		if (gnl == 0 || gnl == -1)
		{
			map->map[j] = NULL;
			ft_free_string_arr(map->map);
			return (0);
		}
		tab = ft_strsplit(line, ' ');
		ft_strdel(&line);
		if (ft_len_arr(tab) != 2)
		{
			map->map[j] = NULL;
			ft_free_string_arr(map->map);
			ft_free_string_arr(tab);
			return (0);
		}
		map->map[j] = ft_strdup(tab[1]);
		j++;
		ft_free_string_arr(tab);
	}
	map->map[j] = NULL;
	return (1);
}
