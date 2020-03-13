/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyster <soyster@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 22:51:51 by soyster           #+#    #+#             */
/*   Updated: 2020/03/13 23:34:52 by soyster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <stdio.h>
#include <fcntl.h>

#include <stdbool.h> 
// true; == 1
// false; == 0

// $$$ exec p1 : [../filler/soyster.out]
// $$$ exec p2 : [../filler/soyster.out]


FILE * pFile;
int n;
char name [100];

int     parse_player();
int     parse_map_size();


int     parse_map(); //char ** array
int     create_heatmap(); //int ** array   анализирую то, что было в карте
int     parse_piece_size();
int     parse_piece();
void    algorithm(); //магия, благодаря которой всё работает
void    print_coords();

int main(int argc, char **argv)
{
    int fd;
    char *line;
    //char *line2 = "aaaaaaaaaaaa";

pFile = fopen ("myfile.txt","w");
    // fd = open(argv[1], O_RDONLY);
    // get_next_line(fd, &line);
    for (int i = 0; i < 8; i++) {
        get_next_line(0, &line);
        fprintf (pFile, "%s\n", line);
        ft_strdel(&line);
    }
   // fprintf (pFile, "%s\n", line2);
    return (0);
}