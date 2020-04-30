/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyster <soyster@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 13:49:07 by soyster           #+#    #+#             */
/*   Updated: 2020/03/16 18:57:14 by soyster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

int ft_mod(int a)
{
    if (a < 0)
        a = -a;
    return (a);
}

int ft_dist(t_map *map, int my_j, int my_i, t_start *inf_pl)
{
    int dist;
    int dist_ptr;
    int j;
    int i;

    j = 0;
    i = 0;
    dist = 0;
    dist_ptr = 0;
    while (j < map->height)
    {
        i = 0;
        while (i < map->width)
        {
            
            if (map->map[j][i] == inf_pl->enemy_symb || map->map[j][i] == inf_pl->enemy_symb + 32)
            {               
                dist_ptr = ft_mod(j - my_j) + ft_mod(i - my_i);
                if (dist == 0 || (dist != 0 && dist > dist_ptr))
                    dist = dist_ptr;
            }
            i++;
        }
        //printf("%s\n", map->map[j]); // потом убрать
        j++;
    }
    return (dist);
}

int ft_create_heatmap(t_map *map, t_start *inf_pl)
{
    int j;
    int i;

    j = 0;
    if (!(map->ht_map = (int**)malloc(sizeof(int*) * map->height))) //  зафришить в конце // еще фиршить все предыдущее
        return (0);
    while (j < map->height)
    {
        i = 0;
        if (!(map->ht_map[j] = (int*)malloc(sizeof(int) * map->width)))
            return (0); //  зафришить в конце
        while (i < map->width)
        {
            if (map->map[j][i] == '.')
                map->ht_map[j][i] = ft_dist(map, j, i, inf_pl);
            else if (map->map[j][i] == inf_pl->my_symb || map->map[j][i] == inf_pl->my_symb + 32)
                    map->ht_map[j][i] = 0; // мои фигуры
                else
                    map->ht_map[j][i] = -1; // вражеские фигуры
            //printf("%d", map->ht_map[j][i]); // потом убрать
            i++;
        }
        //printf("\n"); // потом убрать
        j++;
    }
    return (1);
}