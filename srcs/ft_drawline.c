/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idris <idris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 11:50:30 by ibouabda          #+#    #+#             */
/*   Updated: 2019/12/09 15:01:19 by idris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/wolf3d.h"

void	highline(t_point a, t_point b, t_env *e, float m)
{
	float x;
	float h;
	float mh;

	x = a.x;
	mh = (float)(b.h - a.h) / (float)(b.y - a.y);
	h = a.h;
	while (a.y <= b.y)
	{
		if (a.x < e->winx && a.y < e->winy && a.x >= 0 && a.y >= 0)
			ft_find_color(a, e);
		x += m;
		a.x = (int)(x + 0.5);
		a.y++;
		h += mh;
		a.h = (int)(h + 0.5);
	}
}

void	highline2(t_point a, t_point b, t_env *e, float m)
{
	float x;
	float h;
	float mh;

	x = a.x;
	mh = (float)(b.h - a.h) / (float)(b.y - a.y);
	h = a.h;
	while (a.y >= b.y)
	{
		if (a.x < e->winx && a.y < e->winy && a.x >= 0 && a.y >= 0)
			ft_find_color(a, e);
		x -= m;
		a.x = (int)(x + 0.5);
		a.y--;
		h -= mh;
		a.h = (int)(h + 0.5);
	}
}

void	ft_line(t_point a, t_point b, t_env *e, float m)
{
	float y;
	float mh;
	float h;

	y = a.y;
	h = a.h;
	mh = (float)(b.h - a.h) / (float)(b.x - a.x);
	while (a.x <= b.x)
	{
		if (a.x < e->winx && a.y < e->winy && a.x >= 0 && a.y >= 0)
			ft_find_color(a, e);
		y += m;
		h += mh;
		a.y = (int)(y + 0.5);
		a.h = (int)(h + 0.5);
		a.x++;
	}
}

int		ft_drawline(t_point *a, t_point *b, t_env *e)
{
	float m;

	if (a->x == b->x)
		(a->y < b->y) ? ft_vertical(*a, *b, e) : ft_vertical2(*a, *b, e);
	else
	{
		m = (float)(b->y - a->y) / (float)(b->x - a->x);
		if (m >= -1.0 && m <= 1.0)
			(a->x < b->x) ? ft_line(*a, *b, e, m) : ft_line2(*a, *b, e, m);
		else
		{
			m = (float)(b->x - a->x) / (float)(b->y - a->y);
			(a->y < b->y) ? highline(*a, *b, e, m) : highline2(*a, *b, e, m);
		}
	}
	return (1);
}
