/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyster <soyster@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 18:42:12 by soyster           #+#    #+#             */
/*   Updated: 2020/03/16 19:12:29 by soyster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdio.h> // убрать пототм
#include <fcntl.h> // убрать потом

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
    int         **ht_map;
    int         fd; // для дебага, потом убрать
}               t_map;

typedef struct  s_piece
{
    int         height;
    int         width;
    char        **pic;
}               t_piece;

int     ft_parse_player(t_start *inf_pl, t_map *map);
int     ft_parse_map_size(t_map *map);
char    *ft_strbackcat(char *line, int num, int size);
int     ft_parse_map(t_map *map);
int     ft_create_heatmap(t_map *map, t_start *inf_pl);
int     ft_mod(int a);
int     ft_dist(t_map *map, int my_j, int my_i, t_start *inf_pl);
int     ft_parse_piece_size(t_map *map, t_piece *pic);
int     ft_parse_piece(t_map *map, t_piece *pic);
int     ft_algorithm(t_map *map, t_piece *pic);