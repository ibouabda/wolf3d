/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 14:47:22 by ibouabda          #+#    #+#             */
/*   Updated: 2019/12/04 12:04:32 by ibouabda         ###   ########.fr       */
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
	// while (1);
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
	// while (1);
	exit(1);
}

void	ft_initialize(t_env *e)
{
	e->bool = 0;
	e->winx = 0;
	e->winy = 0;
	e->floor_color = NULL;
	e->ceiling_color = NULL;
	e->north_texture = NULL;
	e->south_texture = NULL;
	e->west_texture = NULL;
	e->east_texture = NULL;
	e->sprite_texture = NULL;
}

int		main(int argc, char **argv)
{
	t_env e;

	if (argc != 2)
		ft_exit(1, NULL, NULL);
	ft_initialize(&e);
	checkandparse(argv[1], &e);
	new_window(&e);
	printf("%i\n", e.winx);
	printf("%i\n", e.winy);
	printf("%s\n%s\n%s\n%s\n%s\n", e.west_texture, e.east_texture, e.north_texture, e.sprite_texture, e.south_texture);
	ft_puttabint(e.ceiling_color, 3);
	ft_puttabint(e.floor_color, 3);
	ft_putendl("");
	ft_2dputstr(e.dbtab);
	ft_putnbrl(e.mapx);
	ft_putnbrl(e.mapy);
	open_texture(&e);
	mlx_hook(e.win_ptr, 2, (1 << 0), key_hook, &e);
	mlx_loop(e.mlx_ptr);
	// while(1);
	return (0);
}
