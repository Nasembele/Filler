/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_piece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyster <soyster@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 18:23:46 by soyster           #+#    #+#             */
/*   Updated: 2020/03/16 19:07:34 by soyster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

int	ft_parse_piece_size(t_map *map, t_piece *pic)
{
	char	*line;
	char	**tab;

	if (!get_next_line(map->fd, &line))
	{
		ft_free_string_arr(map->map);
		free_heatmap(map, map->height);
		return (0);
	}
	if (!line || !line[0])
	{
		if (line)
			ft_strdel(&line);
		ft_free_string_arr(map->map);
		free_heatmap(map, map->height);
		return (0);
	}
	tab = ft_strsplit(line, ' ');
	ft_strdel(&line);
	if (!ft_pic_w_h(tab, pic, map))
		return (0);
	return (1);
}

int	ft_pic_w_h(char **tab, t_piece *pic, t_map *map)
{
	char	**arr;

	if (ft_strcmp(tab[0], "Piece") != 0 || ft_len_arr(tab) != 3)
	{
		ft_free_string_arr(map->map);
		free_heatmap(map, map->height);
		ft_free_string_arr(tab);
		return (0);
	}
	pic->height = ft_atoi(tab[1]);
	arr = ft_strsplit(tab[2], ':');
	pic->width = ft_atoi(arr[0]);
	ft_free_string_arr(tab);
	ft_free_string_arr(arr);
	return (1);
}

int	ft_parse_piece(t_map *map, t_piece *pic)
{
	if (!(pic->pic = (char**)malloc(sizeof(char*) * (pic->height + 1))))
	{
		ft_free_string_arr(map->map);
		free_heatmap(map, map->height);
		return (0);
	}
	if (!ft_read_pic(0, pic, map))
		return (0);
	pic->pic[pic->height] = NULL;
	return (1);
}

int	ft_read_pic(int j, t_piece *pic, t_map *map)
{
	char	*line;

	while (j < pic->height)
	{
		if (!get_next_line(map->fd, &line))
		{
			ft_free_string_arr(map->map);
			free_heatmap(map, map->height);
			pic->pic[j] = NULL;
			ft_free_string_arr(pic->pic);
			return (0);
		}
		if (!line || !line[0])
		{
			ft_free_string_arr(map->map);
			free_heatmap(map, map->height);
			pic->pic[j] = NULL;
			ft_free_string_arr(pic->pic);
			return (0);
		}
		pic->pic[j] = line;
		j++;
		line = NULL;
	}
	return (1);
}

int	ft_len_arr(char **arr)
{
	int	i;

	i = 0;
	if (arr && *arr)
	{
		while (arr[i])
			i++;
	}
	return (i);
}
