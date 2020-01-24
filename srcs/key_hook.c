/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redatounsi <redatounsi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 11:57:58 by ibouabda          #+#    #+#             */
/*   Updated: 2020/01/24 15:43:56 by redatounsi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/wolf3d.h"

void move_ws(int keycode, t_env *e)
{
	double y;
	double x;
	double m;

	m = tan(e->rot / e->pi);
	if (m >= -1.0 && m <= 1.0)
	{
		if ((e->rot >= 270 && e->rot <= 360) || (e->rot >= 0 && e->rot <= 90))
		{
			y = -m * 0.1;
			// printf("angle 315/45\n");
			x = sqrt(0.1 - y * y); // mouvement a 0.1 segfault
		}
		else
		{
			y = m * 0.1;
			// printf("angle 135/235\n");
			x = -sqrt(0.1 - y * y);
		}
	}
	else
	{
		m = 1 / m;
		 // a verifier
		if (e->rot >= 0 && e->rot <= 180)
		{
			x = m * 0.1;
			// printf("angle 0/180\n");
			y = -sqrt(0.1 - x * x);
		}
		else
		{
			x = -m * 0.1;
			// printf("angle 180/360\n");
			y = sqrt(0.1 - x * x);
		}
	}
	if ((keycode == W && e->dbtab[(int)(e->player.y + y + 0.5)][(int)(e->player.x + x + 0.5)] != '1')
	|| (keycode == S && e->dbtab[(int)(e->player.y - y + 0.5)][(int)(e->player.x - x + 0.5)] != '1'))
	{
		e->player.y = (keycode == W) ? e->player.y + y : e->player.y - y;
		e->player.x = (keycode == W) ? e->player.x + x : e->player.x - x;
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
	// if (keycode == A)
	// 	e->player.x += 0.2;
	// if (keycode == D)
	// 	e->player.x -= 0.2;
	if (keycode == LEFT_ARROW)
		e->rot = e->rot + 2;
	if (keycode == RIGHT_ARROW)
		e->rot = e->rot - 2;
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
