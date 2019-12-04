/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retounsi <retounsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 13:50:25 by retounsi          #+#    #+#             */
/*   Updated: 2019/12/04 10:25:18 by retounsi         ###   ########.fr       */
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
	if (line[i] || !ft_isdigit(line[i - 1]) || (c < 3 && (*tab)[c] == -1))
		ft_exit_params(e);
}

void	read_res(char *line, t_env *e, int i)
{
	if (!line[i] || line[i] != ' ')
		ft_exit_params(e);
	while (line[i] && line[i] == ' ')
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

void	search_id(char *line, t_env *e)
{
	if (line[0] == 'R')
		read_res(line, e, 1);
	if (line[0] == 'S' && line[1] != 'O')
		read_path(line, e, 1, &e->tex.sprite_tex);
	if (line[0] == 'F')
		read_colors(line, e, 1, &e->tex.floor_color);
	if (line[0] == 'C')
		read_colors(line, e, 1, &e->tex.ceiling_color);
	if (line[0] == 'N' && line[1] == 'O')
		read_path(line, e, 2, &e->tex.north_tex);
	if (line[0] == 'S' && line[1] == 'O')
		read_path(line, e, 2, &e->tex.south_tex);
	if (line[0] == 'W' && line[1] == 'E')
		read_path(line, e, 2, &e->tex.west_tex);
	if (line[0] == 'E' && line[1] == 'A')
		read_path(line, e, 2, &e->tex.east_tex);
	ft_strdel(&line);
}

int		read_first_param(int fd, t_env *e)
{
	char	*line;

	while (get_next_line(fd, &line))
	{
		search_id(line, e);
		if (!(e->winx == 0 || e->winy == 0 || e->tex.floor_color == 0
		|| e->tex.ceiling_color == 0 || e->tex.north_tex == 0
		|| e->tex.south_tex == 0 || e->tex.west_tex == 0
		|| e->tex.east_tex == 0 || e->tex.sprite_tex == 0))
		{
			e->bool = 1;
			break ;
		}
	}
	if (e->bool == 0)
		ft_exit_params(e);
	return (0);
}
