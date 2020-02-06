/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idris <idris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 11:57:58 by ibouabda          #+#    #+#             */
/*   Updated: 2020/02/06 12:29:36 by idris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/wolf3d.h"

void	move_ws(int keycode, t_env *e, float x, float y)
{
	if (((keycode == W || keycode == UP_ARROW)
	&& (e->dbtab[(int)(e->player.y - y - e->var)]
	[(int)(e->player.x + x - e->var)] != '1'
	&& e->dbtab[(int)(e->player.y - y + e->var)]
	[(int)(e->player.x + x + e->var)] != '1') &&
	((e->dbtab[(int)(e->player.y - y - e->var)][(int)(e->player.x)] != '1' &&
	e->dbtab[(int)(e->player.y - y + e->var)][(int)(e->player.x)] != '1') &&
	(e->dbtab[(int)(e->player.y)][(int)(e->player.x + x - e->var)] != '1' &&
	e->dbtab[(int)(e->player.y)][(int)(e->player.x + x + e->var)] != '1')))
	|| ((keycode == S || keycode == DOWN_ARROW)
	&& (e->dbtab[(int)(e->player.y + y - e->var)]
	[(int)(e->player.x - x - e->var)] != '1'
	&& e->dbtab[(int)(e->player.y + y + e->var)]
	[(int)(e->player.x - x + e->var)] != '1') &&
	((e->dbtab[(int)(e->player.y + y - e->var)][(int)(e->player.x)] != '1' &&
	e->dbtab[(int)(e->player.y + y + e->var)][(int)(e->player.x)] != '1') &&
	(e->dbtab[(int)(e->player.y)][(int)(e->player.x - x - e->var)] != '1' &&
	e->dbtab[(int)(e->player.y)][(int)(e->player.x - x + e->var)] != '1'))))
	{
		e->player.y = (keycode == W) || (keycode == UP_ARROW)
		? e->player.y - y : e->player.y + y;
		e->player.x = (keycode == W) || (keycode == UP_ARROW)
		? e->player.x + x : e->player.x - x;
	}
}

void	move_ad(int keycode, t_env *e, float x, float y)
{
	if ((keycode == A
	&& (e->dbtab[(int)(e->player.y - y - e->var)]
	[(int)(e->player.x - x - e->var)] != '1'
	&& e->dbtab[(int)(e->player.y - y + e->var)]
	[(int)(e->player.x - x + e->var)] != '1') &&
	((e->dbtab[(int)(e->player.y - y - e->var)][(int)(e->player.x)] != '1' &&
	e->dbtab[(int)(e->player.y - y + e->var)][(int)(e->player.x)] != '1') &&
	(e->dbtab[(int)(e->player.y)][(int)(e->player.x - x - e->var)] != '1' &&
	e->dbtab[(int)(e->player.y)][(int)(e->player.x - x + e->var)] != '1')))
	|| (keycode == D && (e->dbtab[(int)(e->player.y + y - e->var)]
	[(int)(e->player.x + x - e->var)] != '1'
	&& e->dbtab[(int)(e->player.y + y + e->var)]
	[(int)(e->player.x + x + e->var)] != '1') &&
	((e->dbtab[(int)(e->player.y + y - e->var)][(int)(e->player.x)] != '1' &&
	e->dbtab[(int)(e->player.y + y + e->var)][(int)(e->player.x)] != '1') &&
	(e->dbtab[(int)(e->player.y)][(int)(e->player.x + x - e->var)] != '1' &&
	e->dbtab[(int)(e->player.y)][(int)(e->player.x + x + e->var)] != '1'))))
	{
		e->player.y = (keycode == A) ? e->player.y - y : e->player.y + y;
		e->player.x = (keycode == A) ? e->player.x - x : e->player.x + x;
	}
}

void	interface(t_env *e)
{
	int a;

	a = e->winy / 20;
	mlx_string_put(e->mlx_ptr, e->win_ptr, e->winx / 2 - ft_strlen(TITLE) * 5,\
	e->winy / 4 - a, 0xffffff, TITLE);
	mlx_string_put(e->mlx_ptr, e->win_ptr, e->winx / 2 - ft_strlen(BEGIN) * 5,\
	e->winy / 4, 0xffffff, BEGIN);
	mlx_string_put(e->mlx_ptr, e->win_ptr, e->winx / 2 - ft_strlen(MOVE) * 5,\
	e->winy / 4 + a * 2, 0xffffff, MOVE);
	mlx_string_put(e->mlx_ptr, e->win_ptr, e->winx / 2 - ft_strlen(STRAF) * 5,\
	e->winy / 4 + a * 3, 0xffffff, STRAF);
	mlx_string_put(e->mlx_ptr, e->win_ptr, e->winx / 2 - ft_strlen(ROTATE) * 5,\
	e->winy / 4 + a * 4, 0xffffff, ROTATE);
	mlx_string_put(e->mlx_ptr, e->win_ptr, e->winx / 2 - ft_strlen(PAUSE) * 5,\
	e->winy / 4 + a * 5, 0xffffff, PAUSE);
	mlx_string_put(e->mlx_ptr, e->win_ptr, e->winx / 2 - ft_strlen(QUIT) * \
	5, e->winy / 4 + a * 7, 0xffffff, QUIT);
}

void	key_hook2(int keycode, t_env *e)
{
	if (keycode == ESC)
	{
		e->bool = 0;
		mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->esc_img_ptr, 0, 0);
		interface(e);
	}
	if (keycode == W || keycode == S || keycode == UP_ARROW
	|| keycode == DOWN_ARROW)
		move_ws(keycode, e, cos(e->rot / e->pi) / 2, sin(e->rot / e->pi) / 2);
	if (keycode == A || keycode == D)
		move_ad(keycode, e, sin(e->rot / e->pi) / 2, cos(e->rot / e->pi) / 2);
	if (keycode == LEFT_ARROW)
		e->rot = e->rot + 5;
	if (keycode == RIGHT_ARROW)
		e->rot = e->rot - 5;
	if (e->rot > 360.0)
		e->rot -= 360.0;
	else if (e->rot < 0.0)
		e->rot = 360.0 + e->rot;
	if (e->bool == 1)
	{
		new_img(e);
		ray_dist(e);
		mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->img_ptr, 0, 0);
	}
}

int		key_hook(int keycode, t_env *e)
{
	if (e->bool == 0)
	{
		e->bool = keycode == ENTER ? 1 : 0;
		if (keycode == ESC)
		{
			mlx_destroy_image(e->mlx_ptr, e->esc_img_ptr);
			mlx_destroy_image(e->mlx_ptr, e->img_ptr);
			mlx_destroy_window(e->mlx_ptr, e->win_ptr);
			ft_exit(0, NULL, e);
		}
	}
	if (e->bool == 1)
		key_hook2(keycode, e);
	return (0);
}
