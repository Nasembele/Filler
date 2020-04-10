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

int ft_fitt(t_map *map, int j, int const_i, t_piece *pic, t_coord *dot) // записывает в отдельную структуру координаты и сумму
{
    int jp;
    int ip;
    int ch_0;
    int i;

    jp = 0;
    ip = 0;
    ch_0 = 0;
    dot->t_eval = 0;
    // записать координаты мапы
    dot->t_y = j;
    dot->t_x = const_i;
    while (jp < pic->height)
    {
        ip = 0;
        i = const_i;
        while (ip < pic->width)
        {   
            //printf("hm %d\n", map->ht_map[j][i]); //
            //printf("pic %c\n", pic->pic[jp][ip]); 
            if (map->ht_map[j][i] == -1 && pic->pic[jp][ip] == '*')
                break;
            if (map->ht_map[j][i] == 0 && pic->pic[jp][ip] == '*' && ch_0 == 1)
                break; 
            if (map->ht_map[j][i] == 0 && pic->pic[jp][ip] == '*' && ch_0 == 0)
                ch_0 = 1;
            if (map->ht_map[j][i] != 0 && map->ht_map[j][i] != -1 && pic->pic[jp][ip] == '*')
                dot->t_eval = dot->t_eval + map->ht_map[j][i];

            //if ((map->ht_map[j][i] != 0 && map->ht_map[j][i] != -1) ||
            //((map->ht_map[j][i] == 0 || map->ht_map[j][i] == -1) && ))
            
            ip++;
            i++;
        }
        if (ip < pic->width) //  обнулить сумму и координаты
        {
            dot->t_y = 0;
            dot->t_x = 0;
            dot->t_eval = 0;
            return (0);
        }
        jp++;
        j++;
    }
    // сравнить оценки
    if (dot->eval == 0 && ch_0)
        dot->eval = dot->t_eval;
    if (dot->t_eval <= dot->eval && ch_0)
    {
        dot->eval = dot->t_eval;
        dot->x = dot->t_x;
        dot->y = dot->t_y;
    }
    return (0);
}

int ft_algorithm(t_map *map, t_piece *pic)
{
    int     j;
    int     i;
    t_coord dot;

    j = 0;
    dot.y = 0;
    dot.x = 0;
    dot.eval = 0;
    while (j < map->height)
    {
        i = 0;
        while (i < map->height)
        {
            if (j + pic->height <= map->height && i + pic->width <= map->width)
                ft_fitt(map, j, i, pic, &dot);
            i++;
        }
        j++;
    }
    printf("%d %d\n", dot.y, dot.x); // заменить на разрешенную функцию
    return (0);    
}