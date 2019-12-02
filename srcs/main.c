/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retounsi <retounsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 15:03:40 by retounsi          #+#    #+#             */
/*   Updated: 2019/12/02 10:09:22 by retounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../incl/wolf3d.h"

void	ft_exit_params(t_env *e)
{
	if (e->east_texture)
		ft_strdel(&e->east_texture);
	if (e->north_texture)
		ft_strdel(&e->north_texture);
	if (e->south_texture)
		ft_strdel(&e->south_texture);
	if (e->west_texture)
		ft_strdel(&e->west_texture);
	if (e->sprite_texture)
		ft_strdel(&e->sprite_texture);
	if (e->floor_color)
		ft_memdel((void**)&e->floor_color);
	if (e->ceiling_color)
		ft_memdel((void**)&e->ceiling_color);
	while (1);
	exit(1);
}

int		main(int argc, char **argv)
{
	int		fd;
	t_env	e;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	read_first_param(fd, &e);
	ft_puttabint(e.ceiling_color, 3);
	ft_puttabint(e.floor_color, 3);
	printf("%i\n", e.winx);
	printf("%i\n", e.winy);
	printf("%s\n%s\n%s\n%s\n%s\n", e.west_texture, e.east_texture, e.north_texture, e.sprite_texture,
	e.south_texture);
	while (1)
		;
}
