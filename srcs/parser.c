/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyster <soyster@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 13:47:11 by soyster           #+#    #+#             */
/*   Updated: 2020/03/16 16:53:12 by soyster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

int ft_parse_player(t_start *inf_pl, t_map *map)
{
    char    *line;
    int     i;

    i = 0;
    get_next_line(map->fd, &line);
    if (!line || !line[i])
    {
        if (line)
        {  
            free(line); //???
            line = NULL;
        }
        return (0); //neval
    }
    inf_pl->my_symb = 'A';
    inf_pl->enemy_symb = 'A';
    while (line[i] && line[i] != 'p')
        i++;
    if (line[++i] == '1')
    {
        inf_pl->my_symb = 'O';
        inf_pl->enemy_symb = 'X';
    }
    if (line[i] == '2')
    {
        inf_pl->my_symb = 'X'; 
        inf_pl->enemy_symb = 'O';
    }
    free(line);
    line = NULL;
    if (inf_pl->my_symb == 'A')
        return (0); // neval
    return (1);
}

int ft_parse_map_size(t_map *map)
{
    char    *line;
    int     i;
    int     check_width;
    char    **tab;

    map->height = 0;
    map->width = 0;
    check_width = 0;
    i = 0;
    get_next_line(map->fd, &line);
    if (!line || !line[0])
    {
        if (line)
            free(line); //?
            line = NULL;
        return (0);
    }
    tab = ft_strsplit(line, ' ');
    //валидация на строку
    //line = "pgdfg 3 9";
    char	**current;
    if (ft_strcmp(tab[0], "Plateau") != 0)
    {
        free(line);	
        if (tab && *tab)
	{
		current = ((tab));
		while ((*current))
			free((*(current++)));
		free((tab));
		(tab) = NULL;
    }
        return (0);
    }
          
    	if (tab && *tab)
	{
		current = ((tab));
		while ((*current))
			free((*(current++)));
		free((tab));
		(tab) = NULL;
    }
    //map->height = ft_atoi(tab[1]);
    //map->width = 
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
    free(line);
    line = NULL; // записать и проверить на меньше или равно 0 и выйти 
    if (map->height == 0 || map->width == 0)
        return (0);
    return (1);
}

char    *ft_strbackcat(char *line, int num, int size)
{
    char    *res;
    int     i;

    i = 0;
    if (!(res = (char*)malloc(sizeof(char) * size + 1)))
        return (0);
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
    char    **tab;

    get_next_line(map->fd, &line);
    //валидация на строку на каждую?
    j = 0;
    if (line)
    {
        free (line);
        line = NULL;
    }
    if (!(map->map = (char**)malloc(sizeof(char*) * (map->height + 1))))  //new
        return (0); // проверить на выделение и зафришить в конце
    while (j < map->height)
    {
        //line = "12345678";
        get_next_line(map->fd, &line);
       
        //tmp = ft_strdup(line);
        //if (!(line = ft_strbackcat(line, 4, map->width)))
        //    return (0);
    
        //map->map[j] = (char*)malloc(sizeof(char) * map->width); // проверить на выделение и зафришить в конце
       // tmp = line;
        tab = ft_strsplit(line, ' '); // добавить защиту
        free(line);
        line = NULL;
        map->map[j] = ft_strdup(tab[1]);
        //printf("%s\n", map->map[j]);
        j++;
        //free(line); // так нельзя фришить
              char	**current;
    	if (tab && *tab)
	{
		current = ((tab));
		while ((*current))
			free((*(current++)));
		free((tab));
		(tab) = NULL;
    }
    }
    map->map[j] = NULL;
    return (1);
}