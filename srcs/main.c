/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyster <soyster@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 13:25:03 by soyster           #+#    #+#             */
/*   Updated: 2020/03/16 19:12:00 by soyster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

int	main(void)
{
	t_start	inf;
	t_map	map;
	t_piece	pic;

	map.fd = 0;
	if (!ft_parse_player(&inf, &map))
		return (0);
	while (1)
	{
		if (!ft_parse_map_size(&map))
			return (0);
		if (!ft_parse_map(&map))
			return (0);
		if (!ft_create_heatmap(&map, &inf))
			return (0);
		if (!ft_parse_piece_size(&map, &pic))
			return (0);
		if (!ft_parse_piece(&map, &pic))
			return (0);
		ft_algorithm(&map, &pic);
	}
	return (0);
}
