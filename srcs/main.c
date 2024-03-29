/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 14:47:22 by ibouabda          #+#    #+#             */
/*   Updated: 2020/02/08 10:06:06 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/wolf3d.h"

void	ft_exit_img(int err, t_list *m, t_env *e)
{
	if (e->images.east.ptr_image)
	{
		mlx_destroy_image(e->mlx_ptr, e->images.east.ptr_image);
	}
	if (e->images.north.ptr_image)
	{
		mlx_destroy_image(e->mlx_ptr, e->images.north.ptr_image);
	}
	if (e->images.south.ptr_image)
	{
		mlx_destroy_image(e->mlx_ptr, e->images.south.ptr_image);
	}
	if (e->images.west.ptr_image)
	{
		mlx_destroy_image(e->mlx_ptr, e->images.west.ptr_image);
	}
	mlx_destroy_image(e->mlx_ptr, e->esc_img_ptr);
	mlx_destroy_image(e->mlx_ptr, e->img_ptr);
	mlx_destroy_window(e->mlx_ptr, e->win_ptr);
	ft_exit(err, m, e);
}

void	ft_exit(int err, t_list *m, t_env *e)
{
	if (e->images.floor_color)
		ft_memdel((void**)&e->images.floor_color);
	if (e->images.ceiling_color)
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
	e->dbtab = NULL;
	e->player.x = -1;
	e->player.y = -1;
	e->pi = (180.0 / M_PI);
	e->texel.y = 0;
	e->var = 0.000001;
}

int		hook_close(t_env *e)
{
	ft_exit(0, NULL, e);
	return (0);
}

int		main(int argc, char **argv)
{
	t_env	e;

	ft_initialize(&e);
	if (argc != 2)
		ft_exit(1, NULL, &e);
	checkandparse(argv[1], &e);
	e.bool = 0;
	e.project_screen = (e.winx / 2) / (tan(30 / e.pi));
	e.midy = e.winy / 2;
	e.winx_img = e.winx * 4;
	new_window(&e);
	e.esc_img_ptr = mlx_new_image(e.mlx_ptr, e.winx, e.winy);
	mlx_put_image_to_window(e.mlx_ptr, e.win_ptr, e.esc_img_ptr, 0, 0);
	interface(&e);
	img(&e);
	open_texture(&e);
	e.texture_res_img = e.images.north.width * 4;
	ray_dist(&e);
	mlx_hook(e.win_ptr, 17, (1L << 0), hook_close, &e);
	mlx_hook(e.win_ptr, 2, (1 << 0), key_hook, &e);
	mlx_loop(e.mlx_ptr);
	return (0);
}
