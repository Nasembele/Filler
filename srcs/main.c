/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyster <soyster@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 20:50:45 by soyster           #+#    #+#             */
/*   Updated: 2020/03/16 00:03:44 by soyster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"
#include <stdio.h>
#include <fcntl.h>

int ft_parse_player(t_start *inf_player, t_map *map)
{
    char    *line;
    int     i;

    get_next_line(map->fd, &line);
    //валидация на строку
    //line = "p1";
    i = 0;
    while (line[i] != 'p')
        i++;
    if (line[++i] == '1')
    {
        inf_player->my_symb = 'O';
        inf_player->enemy_symb = 'X';
    }
    else
    {
        inf_player->my_symb = 'X'; 
        inf_player->enemy_symb = 'O';
    }
    //printf("%s\n", line);
    //printf("%c\n", inf_player->my_symb);
    return (0);
}

int ft_parse_map_size(t_map *map)
{
    char    *line;
    int     i;
    int     check_width;

    map->height = 0;
    map->width = 0;
    check_width = 0;
    get_next_line(map->fd, &line);
    //валидация на строку
    //line = "pgdfg 3 9";
    while (line[i])
    {
        if (line[i] >= 48 && line[i] <= 57 && !check_width)
        {
            if (map->height)
                map->height = map->height * 10 + (line[i] - '0');
            else
                map->height = line[i] - '0';
        }
        if (line[i] == ' ' && map->height)
            check_width = 1;
        if (line[i] >= 48 && line[i] <= 57 && check_width)
        {
            if (map->width)
                map->width = map->width * 10 + (line[i] - '0');
            else
                map->width = line[i] - '0';
        }
        i++;
    }
    //printf("%s\n", line);
    printf("%d\n", map->height);
    printf("%d\n", map->width);
    return (0);
}

char    *ft_strbackcat(char *line, int num, int size)
{
    char    *res;
    int     i;

    i = 0;
    res = (char*)malloc(sizeof(char) * size + 1);
    while (line[num])
    {
        res[i] = line[num];    
        i++;
        num++;
    }
    res[i] = '\0';
    return (res);
}

int ft_parse_map(t_map *map)
{
    char    *line;
    int     j;

    get_next_line(map->fd, &line);
    //валидация на строку на каждую?
    j = 0;
    map->map = (char**)malloc(sizeof(char*) * map->height);
    while (j < map->height)
    {
        //line = "12345678";
        get_next_line(map->fd, &line);
        line = ft_strbackcat(line, 4, map->width);
        map->map[j] = (char*)malloc(sizeof(char) * map->width);
        map->map[j] = line;
        printf("fffg: %s\n", map->map[j]);
        j++;
    }
    
    return (0);
}

int main()
{
    t_start inf_player;
    t_map   map;

    map.fd = open("/Users/soyster/Desktop/Filler/resources/maps/mini_map", O_RDONLY);
    ft_parse_player(&inf_player, &map); //map потом убрать для fd для дебага
    ft_parse_map_size(&map);
    ft_parse_map(&map);
    return (0);
} 
