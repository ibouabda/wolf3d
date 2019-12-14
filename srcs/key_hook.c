/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idris <idris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 11:57:58 by ibouabda          #+#    #+#             */
/*   Updated: 2019/12/14 18:22:27 by idris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/wolf3d.h"

void move_ws(int keycode, t_env *e)
{
	double y;
	double x;
	double m;

	m = tan(e->rot / (180.0 / M_PI));
	if (m >= -1.0 && m <= 1.0)
	{
		y = m;
		if ((e->rot >= 270 && e->rot <= 360) || (e->rot >= 0 && e->rot <= 90))
			x = sqrt(1 - y * y);
		else
			x = -sqrt(1 - y * y);
	}
	else
	{
		m = 1 / m;
		x = m;
		if (e->rot >= 0 && e->rot <= 180)
			y = -sqrt(1 - x * x);
		else
			y = sqrt(1 - x * x);
	}
	e->player.y = (keycode == W) ? e->player.y + y : e->player.y - y;
	e->player.x = (keycode == W) ? e->player.x + x : e->player.x - x;
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
	if (keycode == A)
		e->player.x += 0.2;
	if (keycode == D)
		e->player.x -= 0.2;
	if (keycode == LEFT_ARROW)
		e->rot = e->rot + 10;
	if (keycode == RIGHT_ARROW)
		e->rot = e->rot - 10;
	if (e->rot > 360.0)
		e->rot -= 360.0;
	else if (e->rot < 0.0)
		e->rot = 360.0 + e->rot;
	// printf("rot = %i\n", e->rot);
	// printf("e->player.x = %f\n", e->player.x);
	// printf("e->player.y = %f\n", e->player.y);
	new_img(e);
	ray_dist(e);
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->img_ptr, 0, 0);
	return (0);
}
