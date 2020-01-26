/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retounsi <retounsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 13:50:25 by retounsi          #+#    #+#             */
/*   Updated: 2020/01/26 14:25:36 by retounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/wolf3d.h"

void	read_path(char *line, t_env *e, int i, char **str)
{
	size_t c;

	c = 0;
	if (!line[i] || line[i] != ' ')
		ft_exit(1, NULL, e);
	while (line[i] && line[i] == ' ')
		i++;
	if (*str)
		ft_exit(1, NULL, e);
	if (!(*str = ft_strnew(ft_strlen(line + i))))
		ft_exit(1, NULL, e);
	while (line[i] && line[i] != ' ' && ft_isprint(line[i]))
		(*str)[c++] = line[i++];
	if (line[i])
		ft_exit(1, NULL, e);
}

void	read_colors(char *line, t_env *e, int i, int **tab)
{
	size_t c;

	c = 0;
	if (*tab)
		ft_exit(1, NULL, e);
	*tab = ft_intnew_clean(3);
	if (!line[i] || line[i] != ' ')
		ft_exit(1, NULL, e);
	while (line[i] && line[i] == ' ')
		i++;
	while (line[i] && c < 3)
	{
		if (((*tab)[c] = ft_atoi(line + i)) > 255
		|| (*tab)[c++] < 0 || !ft_isdigit(line[i]))
			ft_exit(1, NULL, e);
		while (line[i] && ft_isdigit(line[i]))
			i++;
		if (line[i] == ',')
			i++;
	}
	if (line[i] || !ft_isdigit(line[i - 1]) || (c < 3 && (*tab)[c] == -1))
		ft_exit(1, NULL, e);
}

void	read_res(char *line, t_env *e, int i)
{
	if (!line[i] || line[i] != ' ')
		ft_exit(1, NULL, e);
	while (line[i] && line[i] == ' ')
		i++;
	if (e->winx != 0)
		ft_exit(1, NULL, e);
	e->winx = ft_atoi(line + i);
	while (line[i] && ft_isdigit(line[i]))
		i++;
	if (line[i] != ' ')
		ft_exit(1, NULL, e);
	while (line[i] && line[i] == ' ')
		i++;
	if (e->winy != 0)
		ft_exit(1, NULL, e);
	e->winy = ft_atoi(line + i);
	while (line[i] && ft_isdigit(line[i]))
		i++;
	e->midx = e->winx / 2;
	e->midy = e->winy / 2;
	e->ang = 60.0f;
	e->raylag = e->ang / e->winx;
}

void	search_id(char *line, t_env *e)
{
	if (line[0] == 'R')
		read_res(line, e, 1);
	if (line[0] == 'S' && line[1] != 'O')
		read_path(line, e, 1, &e->images.sprite.image);
	if (line[0] == 'F')
		read_colors(line, e, 1, &e->images.floor_color);
	if (line[0] == 'C')
		read_colors(line, e, 1, &e->images.ceiling_color);
	if (line[0] == 'N' && line[1] == 'O')
		read_path(line, e, 2, &e->images.north.image);
	if (line[0] == 'S' && line[1] == 'O')
		read_path(line, e, 2, &e->images.south.image);
	if (line[0] == 'W' && line[1] == 'E')
		read_path(line, e, 2, &e->images.west.image);
	if (line[0] == 'E' && line[1] == 'A')
		read_path(line, e, 2, &e->images.east.image);
	ft_strdel(&line);
}

int		read_first_param(int fd, t_env *e, t_images *images)
{
	char	*line;

	while (get_next_line(fd, &line))
	{
		search_id(line, e);
		if (!(e->winx == 0 || e->winy == 0 || images->floor_color == 0
		|| images->ceiling_color == 0 || images->north.image == 0
		|| images->south.image == 0 || images->west.image == 0
		|| images->east.image == 0 || images->sprite.image == 0))
		{
			e->bool = 1;
			break ;
		}
	}
	if (e->bool == 0)
		ft_exit(1, NULL, e);
	return (0);
}
