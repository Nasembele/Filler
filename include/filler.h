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
    char        my;
    char        en;
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

typedef struct  s_coord
{
    int         t_y;
    int         t_x;
    int         y;
    int         x;
    int         t_eval;
    int         eval;
	int			ch_0;
	int			i;
}               t_coord;

typedef struct  s_tcoord
{
    int         j;
    int         const_i;
}               t_tmpcd;

void	ft_print_coord(int y, int x, t_map *map, t_piece *pic);
int	ft_read_pic(int j, t_piece *pic, t_map *map);
int	ft_heat(int j, int i, t_start *inf, t_map *map);

int ft_pic_w_h(char **tab, t_piece *pic, t_map *map);
int	ft_read_map(int j, t_map *map, char *line);

int ft_fill_infpl(t_start *inf_pl, char my, char en);

int ft_len_arr(char **arr);
void		free_heatmap(t_map *map, int height);
void		ft_free_string_arr(char **arr); //???
int     ft_parse_player(t_start *inf_pl, t_map *map);
int     ft_parse_map_size(t_map *map);
int     ft_parse_map(t_map *map);
int     ft_create_heatmap(t_map *map, t_start *inf_pl);
int     ft_mod(int a);
int     ft_dist(t_map *map, int my_j, int my_i, t_start *inf_pl);
int     ft_parse_piece_size(t_map *map, t_piece *pic);
int     ft_parse_piece(t_map *map, t_piece *pic);
int     ft_algorithm(t_map *map, t_piece *pic);
int     ft_fitt(t_map *map, t_tmpcd *tmp_dot, t_piece *pic, t_coord *dot);