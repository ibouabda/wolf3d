/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 14:47:22 by ibouabda          #+#    #+#             */
/*   Updated: 2019/12/04 15:10:32 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/wolf3d.h"

void	ft_exit(int err, t_list *m, t_env *e)
{
	int i;

	i = 0;
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
	if (e->dbtab)
		ft_2dstrdel(e->dbtab);
	if (m)
		ft_lstdelstr(m);
	if (err == 1)
		ft_putendl("Error");
	exit(err);
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
	e->dbtab = NULL;
}

int		main(int argc, char **argv)
{
	t_env e;

	ft_initialize(&e);
	if (argc != 2)
		ft_exit(1, NULL, &e);
	checkandparse(argv[1], &e);
	new_window(&e);
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
	mlx_hook(e.win_ptr, 2, (1 << 0), key_hook, &e);
	mlx_loop(e.mlx_ptr);
	printf("a\n");
	return (0);
}
