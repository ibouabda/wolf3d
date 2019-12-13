/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idris <idris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 15:38:47 by ibouabda          #+#    #+#             */
/*   Updated: 2019/12/13 11:42:03 by idris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/wolf3d.h"

void	highline(t_env *e, double m)
{
	int x;

	e->disty = e->player.y;
	e->distx = e->player.x;
	x = (int)(e->distx + 0.5);
	while (e->disty >= 0 && e->distx >= 0 && e->disty < e->mapy && e->distx < e->mapx
	&& e->dbtab[(int)e->disty][x] != '1')
	{
		// printf("e->distx = %f\n", e->distx);
		// printf("e->disty = %f\n", e->disty);
		e->distx += m;
		x = (int)(e->distx + 0.5); //arrondi en negatif ???
		e->disty--;
	}
	e->disty = e->disty - e->player.y;
	e->distx = e->distx - e->player.x;
}

void	highline2(t_env *e, double m)
{
	int x;

	e->disty = e->player.y;
	e->distx = e->player.x;
	x = (int)(e->distx + 0.5);
	while (e->disty >= 0 && e->distx >= 0 && e->disty < e->mapy && e->distx < e->mapx
	&& e->dbtab[(int)e->disty][x] != '1')
	{
		// printf("e->distx = %f\n", e->distx);
		// printf("e->disty = %f\n", e->disty);
		e->distx -= m;
		x = (int)(e->distx + 0.5); //arrondi en negatif ???
		e->disty++;
	}
	e->disty = e->disty - e->player.y;
	e->distx = e->distx - e->player.x;
}

void	ft_line(t_env *e, double m)
{
	int y;

	e->disty = e->player.y;
	e->distx = e->player.x;
	y = (int)(e->disty + 0.5);
	while (e->disty >= 0 && e->distx >= 0 && e->disty < e->mapy && e->distx < e->mapx
	&& e->dbtab[y][(int)e->distx] != '1')
	{
		// printf("e->distx = %f\n", e->distx);
		// printf("e->disty = %f\n", e->disty);
		// printf("e->disty = %i\n", (int)e->disty);
		e->disty -= m;
		y = (int)(e->disty + 0.5);
		e->distx++;
	}
	// printf("e->distx = %f\n", e->distx);
	// printf("e->disty = %f\n", e->disty);
	// printf("m = %f\n", m);
	e->disty = e->disty - e->player.y;
	e->distx = e->distx - e->player.x;
}

int		ft_distline(double angle, t_env *e)
{
	double m;

	if (angle == 450 || angle == 630)
		(angle == 450) ? vertical(e) : vertical2(e);
	else
	{
		// printf("angle = %f\n", angle);
		m = tan(angle / (180 / M_PI));
		// printf("m = %f\n", m);
		if (m >= -1.0 && m <= 1.0)
			((angle >= 270 && angle <= 360) || (angle >= 0 && angle <= 90)) ? ft_line(e, m) : ft_line2(e, m); //condition (m >= 0)
		else
		{
			m = 1 / m;
			(angle >= 0 && angle <= 180) ? highline(e, m) : highline2(e, m); //condition (m >= 0)
		}
	}
	return (1);
}
