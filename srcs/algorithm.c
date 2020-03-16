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

int ft_algorithm(t_map *map, t_piece *pic)
{
    int j;
    int i;

    j = 0;
    while (j < map->height)
    {
        i = 0;
        while (i < map->height)
        {
            if (j + pic->height <= map->height && i + pic->width <= map->width)
            {
                
                
            }
            i++;
        }
        j++;
    }      
}