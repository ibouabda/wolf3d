/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 13:50:25 by retounsi          #+#    #+#             */
/*   Updated: 2019/12/02 11:20:59 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/wolf3d.h"

void	read_path(char *line, t_env *e, int i, char **str)
{
	size_t c;

	c = 0;
	if (!line[i] || line[i] != ' ')
		ft_exit_params(e);
	while (line[i] && line[i] == ' ')
		i++;
	if (*str)
		ft_exit_params(e);
	if (!(*str = ft_strnew(ft_strlen(line + i))))
		ft_exit_params(e);
	while (line[i] && line[i] != ' ' && ft_isprint(line[i]))
		(*str)[c++] = line[i++];
	if (line[i])
		ft_exit_params(e);
}

void	read_colors(char *line, t_env *e, int i, int **tab)
{
	size_t c;

	c = 0;
	if (*tab)
		ft_exit_params(e);
	*tab = ft_intnew_clean(3);
	if (!line[i] || line[i] != ' ')
		ft_exit_params(e);
	while (line[i] && line[i] == ' ')
		i++;
	while (line[i] && c < 3)
	{
		if (((*tab)[c] = ft_atoi(line + i)) > 255
		|| (*tab)[c++] < 0 || !ft_isdigit(line[i]))
			ft_exit_params(e);
		while (line[i] && ft_isdigit(line[i]))
			i++;
		if (line[i] == ',')
			i++;
	}
	printf("%i\n", *tab[0]);
	if (line[i] || (*tab)[c] == -1 || !ft_isdigit(line[i - 1]))
		ft_exit_params(e);
}

void	read_res(char *line, t_env *e, int i)
{
	if (!line[i] || line[i] != ' ')
		ft_exit_params(e);
	while (line [i] && line[i] == ' ')
		i++;
	if (e->winx != 0)
		ft_exit_params(e);
	e->winx = ft_atoi(line + i);
	while (line[i] && ft_isdigit(line[i]))
		i++;
	if (line[i] != ' ')
		ft_exit_params(e);
	while (line[i] && line[i] == ' ')
		i++;
	if (e->winy != 0)
		ft_exit_params(e);
	e->winy = ft_atoi(line + i);
	while (line[i] && ft_isdigit(line[i]))
		i++;
}

void search_id(char *line, t_env *e)
{
	if (line[0] == 'R')
		read_res(line, e, 1);
	if (line[0] == 'S')
		read_path(line, e, 1, &e->sprite_texture);
	if (line[0] == 'F')
		read_colors(line, e, 1, &e->floor_color);
	if (line[0] == 'C')
		read_colors(line, e, 1, &e->ceiling_color);
	if (line[0] == 'N' && line[1] == 'O')
		read_path(line, e, 2, &e->north_texture);
	if (line[0] == 'S' && line[1] == 'O')
		read_path(line, e, 2, &e->south_texture);
	if (line[0] == 'W' && line[1] == 'E')
		read_path(line, e, 2, &e->west_texture);
	if (line[0] == 'E' && line[1] == 'A')
		read_path(line, e, 2, &e->east_texture);
	ft_strdel(&line);
}

int		read_first_param(int fd, t_env *e)
{
	char	*line;

	e->winx = 0;
	e->winy = 0;
	e->floor_color = NULL;
	e->ceiling_color = NULL;
	e->north_texture = NULL;
	e->south_texture = NULL;
	e->west_texture = NULL;
	e->east_texture = NULL;
	e->sprite_texture = NULL;
	while (get_next_line(fd, &line))
		search_id(line, e);
	search_id(line, e);
	return (0);
}
