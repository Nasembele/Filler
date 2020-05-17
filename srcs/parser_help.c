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

int	ft_checklenarr(char **tab, t_map *map, int j, int key)
{
	if (key == 1 &&
	(ft_len_arr(tab) != 3 || ft_strcmp(tab[0], "Plateau") != 0))
	{
		ft_free_string_arr(tab);
		return (0);
	}
	if (key == 2 && ft_len_arr(tab) != 2)
	{
		map->map[j] = NULL;
		ft_free_string_arr(map->map);
		ft_free_string_arr(tab);
		return (0);
	}
	return (1);
}
