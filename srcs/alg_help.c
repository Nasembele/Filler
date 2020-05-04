/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_help.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyster <soyster@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 19:10:52 by soyster           #+#    #+#             */
/*   Updated: 2020/03/16 20:54:23 by soyster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

int		cond1(int a, char b, int ch_0)
{
	if ((a == -1 && b == '*') || (a == 0 && b == '*' && ch_0 == 1))
		return (1);
	return (0);
}

int		cond2(int a, char b, int ch_0)
{
	if ((a == 0 && b == '*' && ch_0 == 0) || ch_0 == 1)
		return (1);
	return (0);
}

int		ft_init(t_coord *dot, t_tmpcd *tmp_dot)
{
	dot->t_eval = 0;
	dot->t_y = tmp_dot->j;
	dot->t_x = tmp_dot->const_i;
	return (0);
}

int		ft_null(int ip, t_piece *pic, t_coord *dot, t_tmpcd *tmp_dot)
{
	if (ip < pic->width)
	{
		dot->t_y = 0;
		dot->t_x = 0;
		dot->t_eval = 0;
		tmp_dot->j++;
		return (0);
	}
	tmp_dot->j++;
	return (1);
}

void	ft_result(t_coord *dot, int ch_0)
{
	if (dot->eval == 0 && ch_0)
		dot->eval = dot->t_eval;
	if (dot->t_eval <= dot->eval && ch_0)
	{
		dot->eval = dot->t_eval;
		dot->x = dot->t_x;
		dot->y = dot->t_y;
	}
}
