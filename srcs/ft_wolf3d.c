/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idris <idris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:22:01 by ibouabda          #+#    #+#             */
/*   Updated: 2019/12/09 15:30:12 by idris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/wolf3d.h"


void	interface(t_env *e)
{
	int a;

	a = e->winy / 23;
	mlx_string_put(e->mlx_ptr, e->win_ptr, e->winx / 2 - ft_strlen(FDF) * 5,\
	e->winy / 2.5 - a, 0xD50097, FDF);
	mlx_string_put(e->mlx_ptr, e->win_ptr, e->winx / 2 - ft_strlen(BEGIN) * 5,\
	e->winy / 2.5, 0x0000FF, BEGIN);
	mlx_string_put(e->mlx_ptr, e->win_ptr, e->winx / 2 - ft_strlen(MOVE) * 5,\
	e->winy / 2.5 + a * 2, 0x0000FF, MOVE);
	mlx_string_put(e->mlx_ptr, e->win_ptr, e->winx / 2 - ft_strlen(ANGLE) * 5,\
	e->winy / 2.5 + a * 3, 0xD50097, ANGLE);
	mlx_string_put(e->mlx_ptr, e->win_ptr, e->winx / 2 - ft_strlen(ZOOM) * 5,\
	e->winy / 2.5 + a * 4, 0x0000FF, ZOOM);
	mlx_string_put(e->mlx_ptr, e->win_ptr, e->winx / 2 - ft_strlen(INC) * 5,\
	e->winy / 2.5 + a * 5, 0xD50097, INC);
	mlx_string_put(e->mlx_ptr, e->win_ptr, e->winx / 2 - ft_strlen(INC) * 5,\
	e->winy / 2.5 + a * 6, 0x0000FF, PROJ);
	mlx_string_put(e->mlx_ptr, e->win_ptr, e->winx / 2 - ft_strlen(PAUSE) * 5,\
	e->winy / 2.5 + a * 7, 0xD50097, PAUSE);
	mlx_string_put(e->mlx_ptr, e->win_ptr, e->winx / 2 - ft_strlen(RESET) * 5,\
	e->winy / 2.5 + a * 8, 0x0000FF, RESET);
	mlx_string_put(e->mlx_ptr, e->win_ptr, e->winx / 2 - ft_strlen(QUIT) * 5,\
	e->winy / 2.5 + a * 9, 0xD50097, QUIT);
}

void	ft_line2(t_point a, t_point b, t_env *e, float m)
{
	float y;
	float mh;
	float h;

	y = a.y;
	h = a.h;
	mh = (float)(b.h - a.h) / (float)(b.x - a.x);
	while (a.x >= b.x)
	{
		if (a.x < e->winx && a.y < e->winy && a.x >= 0 && a.y >= 0)
			ft_find_color(a, e);
		y -= m;
		h -= mh;
		a.y = (int)(y + 0.5);
		a.h = (int)(h + 0.5);
		a.x--;
	}
}

void	ft_vertical(t_point a, t_point b, t_env *e)
{
	float h;
	float mh;

	mh = (float)(b.h - a.h) / (float)(b.y - a.y);
	h = a.h;
	while (a.y <= b.y)
	{
		if (a.x < e->winx && a.y < e->winy && a.x >= 0 && a.y >= 0)
			ft_find_color(a, e);
		a.y++;
		h += mh;
		a.h = (int)(h + 0.5);
	}
}

void	ft_vertical2(t_point a, t_point b, t_env *e)
{
	float h;
	float mh;

	mh = (float)(b.h - a.h) / (float)(b.y - a.y);
	h = a.h;
	while (a.y >= b.y)
	{
		if (a.x < e->winx && a.y < e->winy && a.x >= 0 && a.y >= 0)
			ft_find_color(a, e);
		a.y--;
		h -= mh;
		a.h = (int)(h + 0.5);
	}
}
