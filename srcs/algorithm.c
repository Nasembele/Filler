/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyster <soyster@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 19:10:52 by soyster           #+#    #+#             */
/*   Updated: 2020/03/16 20:54:23 by soyster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

void	ft_fitt(t_map *map, t_tmpcd *tmp_dot, t_piece *pic, t_coord *dot)
{
	int	jp;
	int	ip;
	int	ch_0;
	int	i;

	jp = -1;
	ch_0 = ft_init(dot, tmp_dot);
	while (++jp < pic->height)
	{
		ip = -1;
		i = tmp_dot->const_i;
		while (++ip < pic->width)
		{
			if (cond1(map->ht_map[tmp_dot->j][i], pic->pic[jp][ip], ch_0))
				break ;
			ch_0 = cond2(map->ht_map[tmp_dot->j][i], pic->pic[jp][ip], ch_0);
			if (map->ht_map[tmp_dot->j][i] != 0
			&& map->ht_map[tmp_dot->j][i] != -1 && pic->pic[jp][ip] == '*')
				dot->t_eval = dot->t_eval + map->ht_map[tmp_dot->j][i];
			i++;
		}
		if (!ft_null(ip, pic, dot, tmp_dot))
			return ;
	}
	ft_result(dot, ch_0);
}

int		ft_algorithm(t_map *map, t_piece *pic)
{
	int		j;
	int		i;
	t_coord	dot;
	t_tmpcd	tmp_dot;

	j = -1;
	dot.y = 0;
	dot.x = 0;
	dot.eval = 0;
	while (++j < map->height)
	{
		i = -1;
		while (++i < map->width)
		{
			if (j + pic->height <= map->height && i + pic->width <= map->width)
			{
				tmp_dot.j = j;
				tmp_dot.const_i = i;
				ft_fitt(map, &tmp_dot, pic, &dot);
			}
		}
	}
	ft_print_coord(dot.y, dot.x, map, pic);
	return (0);
}

void	ft_print_coord(int y, int x, t_map *map, t_piece *pic)
{
	ft_putnbr(y);
	write(1, " ", 1);
	ft_putnbr(x);
	write(1, "\n", 1);
	ft_free_string_arr(map->map);
	free_heatmap(map, map->height);
	ft_free_string_arr(pic->pic);
}

void	ft_free_string_arr(char **t)
{
	char	**curr;

	if (t && *t)
	{
		curr = t;
		while (*curr)
			free(*(curr++));
		free(t);
		t = NULL;
	}
	if (t)
	{
		free(t);
		t = NULL;
	}
}

void	free_heatmap(t_map *map, int height)
{
	int i;

	i = 0;
	while (i < height)
	{
		if (map->ht_map[i])
		{
			free(map->ht_map[i]);
			map->ht_map[i] = NULL;
		}
		i++;
	}
	free(map->ht_map);
	map->ht_map = NULL;
}
