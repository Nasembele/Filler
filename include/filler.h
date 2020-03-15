/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyster <soyster@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 18:42:12 by soyster           #+#    #+#             */
/*   Updated: 2020/03/15 23:31:13 by soyster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

typedef struct  s_start
{
    char        my_symb;
    char        enemy_symb;
}               t_start;

typedef struct  s_map
{
    int         height;
    int         width;
    char        **map;
    int         fd; // для дебага, потом убрать
}               t_map;
