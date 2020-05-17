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
	int		gnl;
	char	**tab;

	line = NULL;
	gnl = get_next_line(map->fd, &line);
	if (gnl == 0 || gnl == -1 || !line || !line[0])
	{
		if (line)
			ft_strdel(&line);
		return (0);
	}
	tab = ft_strsplit(line, ' ');
	ft_strdel(&line);
	ft_fill_infpl(inf, tab, 1);
	if (ft_strcmp(tab[0], "$$$") != 0 || ft_len_arr(tab) != 5)
	{
		ft_free_string_arr(tab);
		return (0);
	}
	ft_fill_infpl(inf, tab, 2);
	ft_free_string_arr(tab);
	if (inf->my == 'A')
		return (0);
	return (1);
}

int	ft_fill_infpl(t_start *inf, char **tab, int key)
{
	if (key == 1)
	{
		inf->my = 'A';
		inf->en = 'A';
	}
	if (key == 2 && ft_strlen(tab[2]) == 2)
	{
		if (tab[2][1] == '1')
		{
			inf->my = 'O';
			inf->en = 'X';
		}
		if (tab[2][1] == '2')
		{
			inf->my = 'X';
			inf->en = 'O';
		}
	}
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
	if (gnl == 0 || gnl == -1 || !line || !line[0])
	{
		if (line)
			ft_strdel(&line);
		return (0);
	}
	tab = ft_strsplit(line, ' ');
	ft_strdel(&line);
	if (!ft_checklenarr(tab, map, 0, 1))
		return (0);
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
	if (line)
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
		if (!ft_checklenarr(tab, map, j, 2))
			return (0);
		map->map[j] = ft_strdup(tab[1]);
		j++;
		ft_free_string_arr(tab);
	}
	map->map[j] = NULL;
	return (1);
}
