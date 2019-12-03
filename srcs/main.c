/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retounsi <retounsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 14:47:22 by ibouabda          #+#    #+#             */
/*   Updated: 2019/12/03 12:40:06 by retounsi         ###   ########.fr       */
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
	while (1)
		;
	exit(err);
}

void	ft_exit_params(t_env *e)
{
	if (e->tex.east_tex)
		ft_strdel(&e->tex.east_tex);
	if (e->tex.north_tex)
		ft_strdel(&e->tex.north_tex);
	if (e->tex.south_tex)
		ft_strdel(&e->tex.south_tex);
	if (e->tex.west_tex)
		ft_strdel(&e->tex.west_tex);
	if (e->tex.sprite_tex)
		ft_strdel(&e->tex.sprite_tex);
	if (e->tex.floor_color)
		ft_memdel((void**)&e->tex.floor_color);
	if (e->tex.ceiling_color)
		ft_memdel((void**)&e->tex.ceiling_color);
	ft_putendl("Error");
	while (1)
		;
	exit(1);
}

void	ft_initialize(t_env *e)
{
	e->bool = 0;
	e->winx = 0;
	e->winy = 0;
	e->tex.floor_color = NULL;
	e->tex.ceiling_color = NULL;
	e->tex.north_tex = NULL;
	e->tex.south_tex = NULL;
	e->tex.west_tex = NULL;
	e->tex.east_tex = NULL;
	e->tex.sprite_tex = NULL;
}

int		main(int argc, char **argv)
{
	t_env e;

	if (argc != 2)
		ft_exit(1, NULL, NULL);
	ft_initialize(&e);
	checkandparse(argv[1], &e);
	printf("%i\n", e.winx);
	printf("%i\n", e.winy);
	printf("%s\n%s\n%s\n%s\n%s\n", e.tex.west_tex, e.tex.east_tex, e.tex.north_tex, e.tex.sprite_tex, e.tex.south_tex);
	ft_puttabint(e.tex.ceiling_color, 3);
	ft_puttabint(e.tex.floor_color, 3);
	ft_putendl("");
	ft_2dputstr(e.dbtab);
	ft_putnbrl(e.mapx);
	ft_putnbrl(e.mapy);
	open_texture(&e);
	while (1)
		;
	return (0);
}
