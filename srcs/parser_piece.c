/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_piece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyster <soyster@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 18:23:46 by soyster           #+#    #+#             */
/*   Updated: 2020/03/16 19:07:34 by soyster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

int ft_parse_piece_size(t_map *map, t_piece *pic)
{
    char    *line;
    char    **tab;

    get_next_line(map->fd, &line);
    if (!line || !line[0])
        return (0);
    tab = ft_strsplit(line, ' ');
    if (ft_strcmp(tab[0], "Piece") != 0 || !tab[1] || !tab[2])
        return (0);
    pic->height = ft_atoi(tab[1]);
    pic->width = ft_atoi(ft_strsplit(tab[2], ':')[0]);
    //printf("%d %d\n", pic->height, pic->width); // потом убрать
    line = NULL;
    return (1);
}

int ft_parse_piece(t_map *map, t_piece *pic)
{
    char    *line;
    int     j;

    //валидация на строку на каждую?
    j = 0;
    if (!(pic->pic = (char**)malloc(sizeof(char*) * pic->height)))
        return (0); // проверить на выделение и зафришить в конце
    while (j < pic->height)
    {
        //line = "12345678";
        get_next_line(map->fd, &line);
        //map->map[j] = (char*)malloc(sizeof(char) * map->width); // проверить на выделение и зафришить в конце
        if (!line || !line[0])
            return (0);
        pic->pic[j] = line;
        //printf("%s\n", pic->pic[j]);
        j++;
        line = NULL;
    }
    return (1);
}