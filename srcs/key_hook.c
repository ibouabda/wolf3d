/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retounsi <retounsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 11:57:58 by ibouabda          #+#    #+#             */
/*   Updated: 2020/01/28 17:40:36 by retounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/wolf3d.h"

void	move_ws(int keycode, t_env *e)
{
	double y;
	double x;

	x = cos(e->rot / e->pi);
	y = sin(e->rot / e->pi);
	if ((keycode == W
	&& e->dbtab[(int)(e->player.y - y)][(int)(e->player.x + x)] != '1' &&
	e->dbtab[(int)(e->player.y - y)][(int)(e->player.x)] != '1' &&
	e->dbtab[(int)(e->player.y)][(int)(e->player.x + x)] != '1')
	|| (keycode == S
	&& e->dbtab[(int)(e->player.y + y)][(int)(e->player.x - x)] != '1' &&
	e->dbtab[(int)(e->player.y)][(int)(e->player.x - x)] != '1' &&
	e->dbtab[(int)(e->player.y + y)][(int)(e->player.x)] != '1'))
	{
		e->player.y = (keycode == W) ? e->player.y - y : e->player.y + y;
		e->player.x = (keycode == W) ? e->player.x + x : e->player.x - x;
	}
}

void	move_ad(int keycode, t_env *e)
{
	double y;
	double x;

	x = sin(e->rot / e->pi);
	y = cos(e->rot / e->pi);
	if ((keycode == A
	&& e->dbtab[(int)(e->player.y - y)][(int)(e->player.x - x)] != '1' &&
	e->dbtab[(int)(e->player.y - y)][(int)(e->player.x)] != '1' &&
	e->dbtab[(int)(e->player.y)][(int)(e->player.x - x)] != '1')
	|| (keycode == D
	&& e->dbtab[(int)(e->player.y + y)][(int)(e->player.x + x)] != '1' &&
	e->dbtab[(int)(e->player.y)][(int)(e->player.x + x)] != '1' &&
	e->dbtab[(int)(e->player.y + y)][(int)(e->player.x)] != '1'))
	{
		e->player.y = (keycode == A) ? e->player.y - y : e->player.y + y;
		e->player.x = (keycode == A) ? e->player.x - x : e->player.x + x;
	}
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == ESC)
	{
		mlx_destroy_image(e->mlx_ptr, e->img_ptr);
		mlx_destroy_window(e->mlx_ptr, e->win_ptr);
		ft_exit(0, NULL, e);
	}
	if (keycode == W || keycode == S)
		move_ws(keycode, e);
	if (keycode == A || keycode == D)
		move_ad(keycode, e);
	if (keycode == LEFT_ARROW)
		e->rot = e->rot + 5;
	if (keycode == RIGHT_ARROW)
		e->rot = e->rot - 5;
	if (e->rot > 360.0)
		e->rot -= 360.0;
	else if (e->rot < 0.0)
		e->rot = 360.0 + e->rot;
	new_img(e);
	ray_dist(e);
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->img_ptr, 0, 0);
	return (0);
}
