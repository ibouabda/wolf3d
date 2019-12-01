/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_first_param.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retounsi <retounsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 13:50:25 by retounsi          #+#    #+#             */
/*   Updated: 2019/12/01 20:00:51 by retounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/wolf3d.h"

void	read_colors(char *line, t_env *e, int i, int **tab)
{
	size_t c;

	c = 0;
	if (*tab)
		ft_exit_params(e);
	if (!(*tab = (int*)malloc(sizeof(int) * 3)))
		ft_exit_params(e);
	if (!line[i] || line[i] != ' ')
		ft_exit_params(e);
	while (line[i] && line[i] == ' ')
		i++;
	while (line[i])
	{
		if (((*tab)[c] = ft_atoi(line + i)) > 255
		|| (*tab)[c++] < 0 || !ft_isdigit(line[i]))
			ft_exit_params(e);
		while (line[i] && ft_isdigit(line[i]))
			i++;
		if (line[i] == ',')
			i++;
	}
	if (line[i])
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

int		read_first_param(int fd, t_env *e)
{
	char	*line;

	e->winx = 0;
	e->winy = 0;
	e->floor_color = NULL;
	e->ceiling_color = NULL;
	while (get_next_line(fd, &line))
	{
		if (line[0] == 'R' && line[1] && line[1] == ' ')
			read_res(line, e, 1);
		if (line[0] == 'S' && line[1] && line[1] == ' ')
			read_path(line, e, 1, &e->sprite_texture);
		if (line[0] == 'F' && line[1] && line[1] == ' ')
			read_colors(line, e, 1, &e->floor_color);
		if (line[0] == 'C' && line[1] && line[1] == ' ')
			read_colors(line, e, 1, &e->ceiling_color);
		if (line[0] == 'N' && line[1] && line[1] == 'O')
			read_path(line, e, 2, &e->north_texture);
		if (line[0] == 'S' && line[1] && line[1] == 'O')
			read_path(line, e, 2, &e->south_texture);
		if (line[0] == 'W' && line[1] && line[1] == 'E')
			read_path(line, e, 2, &e->west_texture);
		if (line[0] == 'E' && line[1] && line[1] == 'A')
			read_path(line, e, 2, &e->east_texture);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return (0);
}
