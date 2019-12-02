/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 14:47:22 by ibouabda          #+#    #+#             */
/*   Updated: 2019/12/02 15:09:06 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/wolf3d.h"

void	ft_exit(int err, char **dbtable, t_list *m)
{
	if (dbtable)
		ft_2dmemdel((void**)dbtable);
	if (m)
		ft_lstdelstr(m);
	if (err == 1)
		ft_putendl("error");
	while (1);
	exit(err);
}

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
	ft_putendl("Error");
	while (1);
	exit(1);
}

int		main(int argc, char **argv)
{
	t_env e;

	if (argc != 2)
		ft_exit(1, NULL, NULL);
	checkandparse(argv[1], &e);
	printf("%i\n", e.winx);
	printf("%i\n", e.winy);
	printf("%s\n%s\n%s\n%s\n%s\n", e.west_texture, e.east_texture, e.north_texture, e.sprite_texture, e.south_texture);
	ft_puttabint(e.ceiling_color, 3);
	ft_puttabint(e.floor_color, 3);
	ft_putendl("");
	ft_2dputstr(e.dbtab);
	ft_putnbrl(e.mapx);
	ft_putnbrl(e.mapy);
	while(1);
	return (0);
}
