/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retounsi <retounsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 16:03:26 by retounsi          #+#    #+#             */
/*   Updated: 2019/12/01 19:58:05 by retounsi         ###   ########.fr       */
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
