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

int main(void)
{
    t_start inf_pl;
    t_map   map;
    t_piece pic;

    //map.fd = open("/Users/roman/Desktop/filler/srcs/myfile.txt", O_RDONLY);
    map.fd = 0;
    ft_parse_player(&inf_pl, &map); //map потом убрать для fd для дебага  запускать только первый раз  проверять что есть этот кусок, он есть только вначале?
    ft_parse_map_size(&map);
    ft_parse_map(&map);
    ft_create_heatmap(&map, &inf_pl);
    //printf("%d%d\n", map.ht_map[0][0], map.ht_map[0][1]); //
    ft_parse_piece_size(&map, &pic);
    ft_parse_piece(&map, &pic);
    ft_algorithm(&map, &pic);
    return (0);
} 

