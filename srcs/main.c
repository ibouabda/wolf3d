/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retounsi <retounsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 14:47:22 by ibouabda          #+#    #+#             */
/*   Updated: 2020/01/21 13:28:38 by retounsi         ###   ########.fr       */
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
	if (e->tex.wall_color)
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
	e->dist = 277;
	e->tex.floor_color = NULL;
	e->tex.ceiling_color = NULL;
	e->tex.north_tex = NULL;
	e->tex.south_tex = NULL;
	e->tex.west_tex = NULL;
	e->tex.east_tex = NULL;
	e->tex.sprite_tex = NULL;
	e->dbtab = NULL;
	e->player.x = -1;
	e->player.y = -1;
	e->pi = (180.0 / M_PI);
	e->tex.wall_color = ft_intnew(3);
	e->tex.wall_color[0] = 200;
	e->tex.wall_color[1] = 200;
	e->tex.wall_color[2] = 200;
	e->texel.y = 0;
}

int		main(int argc, char **argv)
{
	t_env	e;
	int		bpp;
	int		s_l;
	int		endian;

	ft_initialize(&e);
	if (argc != 2)
		ft_exit(1, NULL, &e);
	checkandparse(argv[1], &e);
	new_window(&e);
	img(&e);
	// printf("%i\n", e.winx);
	// printf("%i\n", e.winy);
	// printf("%s\n%s\n%s\n%s\n%s\n", e.tex.west_tex, e.tex.east_tex, e.tex.north_tex, e.tex.sprite_tex, e.tex.south_tex);
	// ft_puttabint(e.tex.ceiling_color, 3);
	// ft_puttabint(e.tex.floor_color, 3);
	// ft_putendl("");
	// ft_2dputstr(e.dbtab);
	// printf("mapx = %i\n", e.mapx);
	// printf("mapy = %i\n", e.mapy);
	// printf("px = %i\n", e.player.x);
	// printf("py = %i\n", e.player.y);
	// printf("ang = %f\n", e.ang);
	// printf("rot = %i\n", e.rot);
	open_texture(&e);
	// printf("east_texture : %s\n", e.tex.east_tex);
	// printf("img : %s\n", e.img_string);
	// ft_2dputstr(e.dbtab);
	ray_dist(&e);
	mlx_put_image_to_window(e.mlx_ptr, e.win_ptr, e.img_ptr, 0, 0);
	mlx_hook(e.win_ptr, 2, (1 << 0), key_hook, &e);
	mlx_loop(e.mlx_ptr);
	return (0);
}
