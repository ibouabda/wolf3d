/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 09:12:18 by redatounsi        #+#    #+#             */
/*   Updated: 2020/02/02 16:10:23 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/wolf3d.h"

void	ddax(t_env *e, float ystep, int x, int y)
{
	x = (e->rayang >= 270.0 && e->rayang <= 360.0)
	|| (e->rayang >= 0.0 && e->rayang <= 90.0)
	? (int)(e->ddax.x) : (int)(e->ddax.x - 0.5);
	y = (int)(e->ddax.y);
	while (e->ddax.y >= 0 && e->ddax.x >= 0
	&& e->ddax.y < e->mapy && e->ddax.x < e->mapx
	&& x < e->mapx && y < e->mapy && e->dbtab[y][x] != '1')
	{
		if ((e->rayang >= 270.0 && e->rayang <= 360.0)
		|| (e->rayang >= 0.0 && e->rayang <= 90.0))
		{
			e->ddax.x = e->ddax.x + 1.0;
			e->ddax.y = e->ddax.y - ystep;
			x = (int)(e->ddax.x);
		}
		else
		{
			e->ddax.x = e->ddax.x - 1.0;
			e->ddax.y = e->ddax.y + ystep;
			x = (int)(e->ddax.x - 0.5);
		}
		y = (int)(e->ddax.y);
	}
	e->wallx.y = e->ddax.y;
	e->wallx.x = e->ddax.x;
}

void	dday(t_env *e, float xstep, int x, int y)
{
	x = (int)(e->dday.x);
	y = e->rayang >= 0.0 && e->rayang <= 180.0 ?
	(int)(e->dday.y - 0.5) : (int)(e->dday.y);
	while (e->dday.y >= 0 && e->dday.x >= 0
	&& e->dday.y < e->mapy && e->dday.x < e->mapx
	&& x < e->mapx && y < e->mapy && e->dbtab[y][x] != '1')
	{
		if (e->rayang >= 0.0 && e->rayang <= 180.0)
		{
			e->dday.y = e->dday.y - 1.0;
			e->dday.x = e->dday.x + xstep;
			y = (int)(e->dday.y - 0.5);
		}
		else
		{
			e->dday.y = e->dday.y + 1.0;
			e->dday.x = e->dday.x - xstep;
			y = (int)(e->dday.y + 0.5);
		}
		x = (int)(e->dday.x);
	}
	e->wally.y = e->dday.y;
	e->wally.x = e->dday.x;
}

void	prepddax(t_env *e, float ystep)
{
	if ((e->rayang >= 270.0 && e->rayang <= 360.0)
	|| (e->rayang >= 0.0 && e->rayang <= 90.0))
	{
		e->ddax.x = 1 - (e->player.x - ((int)(e->player.x)));
		if ((int)e->ddax.x == 1)
		{
			e->ddax.y = e->player.y;
			e->ddax.x = e->player.x;
		}
		else
		{
			e->ddax.y = e->player.y - ystep * e->ddax.x;
			e->ddax.x = e->ddax.x + e->player.x;
		}
	}
	else
	{
		e->ddax.x = (e->player.x - ((int)(e->player.x)));
		e->ddax.y = e->player.y + ystep * e->ddax.x;
		e->ddax.x = e->player.x - (e->ddax.x);
	}
	ddax(e, ystep, 0, 0);
}

void	prepdday(t_env *e, float xstep)
{
	if (e->rayang >= 0.0 && e->rayang <= 180.0)
	{
		e->dday.y = (e->player.y - ((int)(e->player.y)));
		e->dday.x = e->player.x + xstep * e->dday.y;
		e->dday.y = e->player.y - e->dday.y;
	}
	else
	{
		e->dday.y = 1 - (e->player.y - ((int)(e->player.y)));
		if ((int)e->dday.y == 1)
		{
			e->dday.x = e->player.x;
			e->dday.y = e->player.y;
		}
		else
		{
			e->dday.x = e->player.x - xstep * e->dday.y;
			e->dday.y = e->player.y + e->dday.y;
		}
	}
	dday(e, xstep, 0, 0);
}

float	ft_dda(t_env *e)
{
	float ystep;
	float xstep;

	ystep = tan(e->rayang / e->pi);
	xstep = 1 / ystep;
	prepddax(e, ystep);
	prepdday(e, xstep);
	e->ddax.y = e->ddax.y - e->player.y;
	e->ddax.x = e->ddax.x - e->player.x;
	e->dday.y = e->dday.y - e->player.y;
	e->dday.x = e->dday.x - e->player.x;
	xstep = e->ddax.x * e->ddax.x + e->ddax.y * e->ddax.y;
	ystep = e->dday.y * e->dday.y + e->dday.x * e->dday.x;
	if (ystep < xstep)
	{
		e->wall_dir = 'h';
		e->ddax = e->wally;
		return (ystep);
	}
	else if (ystep > xstep)
		e->wall_dir = 'v';
	e->ddax = e->wallx;
	return (xstep);
}
