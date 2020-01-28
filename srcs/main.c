/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retounsi <retounsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 14:47:22 by ibouabda          #+#    #+#             */
/*   Updated: 2020/01/28 17:14:28 by retounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/wolf3d.h"

void	ft_exit(int err, t_list *m, t_env *e)
{
	if (e->images.east.image)
		ft_strdel(&e->images.east.image);
	if (e->images.north.image)
		ft_strdel(&e->images.north.image);
	if (e->images.south.image)
		ft_strdel(&e->images.south.image);
	if (e->images.west.image)
		ft_strdel(&e->images.west.image);
	if (e->images.sprite.image)
		ft_strdel(&e->images.sprite.image);
	if (e->images.floor_color)
		ft_memdel((void**)&e->images.floor_color);
	if (e->images.ceiling_color)
		ft_memdel((void**)&e->images.ceiling_color);
	if (e->images.wall_color)
		ft_memdel((void**)&e->images.ceiling_color);
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
	e->images.floor_color = NULL;
	e->images.ceiling_color = NULL;
	e->images.north.image = NULL;
	e->images.south.image = NULL;
	e->images.west.image = NULL;
	e->images.east.image = NULL;
	e->images.sprite.image = NULL;
	e->dbtab = NULL;
	e->player.x = -1;
	e->player.y = -1;
	e->pi = (180.0 / M_PI);
	e->images.wall_color = ft_intnew(3);
	e->images.wall_color[0] = 200;
	e->images.wall_color[1] = 200;
	e->images.wall_color[2] = 200;
	e->texel.y = 0;
}

int		main(int argc, char **argv)
{
	t_env	e;

	ft_initialize(&e);
	if (argc != 2)
		ft_exit(1, NULL, &e);
	checkandparse(argv[1], &e);
	e.dist = (e.winx / 2) / (tan(30 / e.pi));
	e.midy = e.winy / 2;
	e.winx_img = e.winx * 4;
	new_window(&e);
	img(&e);
	open_texture(&e);
	e.texture_res_img = e.images.north.width * 4;
	ray_dist(&e);
	mlx_put_image_to_window(e.mlx_ptr, e.win_ptr, e.img_ptr, 0, 0);
	mlx_hook(e.win_ptr, 2, (1 << 0), key_hook, &e);
	mlx_loop(e.mlx_ptr);
	return (0);
}
