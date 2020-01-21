/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 15:38:47 by ibouabda          #+#    #+#             */
/*   Updated: 2020/01/19 14:34:39 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/wolf3d.h"

void	highline(t_env *e, double m)
{
	int x;
	int y;

	e->disty = e->player.y;
	e->distx = e->player.x;
	y = (int)(e->disty + 0.5);
	x = (int)(e->distx + 0.5);
	while (e->disty >= 0 && e->distx >= 0 && e->disty < e->mapy && e->distx < e->mapx
	&& x < e->mapx && y < e->mapy && e->dbtab[y][x] != '1')
	{
		// printf("e->distx = %f\n", e->distx);
		// printf("e->disty = %f\n", e->disty);
		e->distx += m * 0.01;
		e->disty -= 0.01;
		y = (int)(e->disty + 0.5);
		x = (int)(e->distx + 0.5);
	}
	// printf("e->distx = %f\n", e->distx);
	// printf("e->disty = %f\n", e->disty);
	e->disty = e->disty - e->player.y;
	e->distx = e->distx - e->player.x;
}

void	highline2(t_env *e, double m)
{
	int x;
	int y;

	e->disty = e->player.y;
	e->distx = e->player.x;
	y = (int)(e->disty + 0.5);
	x = (int)(e->distx + 0.5);
	while (e->disty >= 0 && e->distx >= 0 && e->disty < e->mapy && e->distx < e->mapx
	&& x < e->mapx && y < e->mapy && e->dbtab[y][x] != '1')
	{
		// printf("e->distx = %f\n", e->distx);
		// printf("e->disty = %f\n", e->disty);
		e->distx -= m * 0.01;
		e->disty += 0.01;
		y = (int)(e->disty + 0.5);
		x = (int)(e->distx + 0.5);
	}
	e->disty = e->disty - e->player.y;
	e->distx = e->distx - e->player.x;
}

void	ft_line(t_env *e, double m)
{
	int y;
	int x;

	e->disty = e->player.y;
	e->distx = e->player.x;
	y = (int)(e->disty + 0.5);
	x = (int)(e->distx + 0.5);
	while (e->disty >= 0 && e->distx >= 0 && e->disty < e->mapy && e->distx < e->mapx
	&& x < e->mapx && y < e->mapy && e->dbtab[y][x] != '1')
	{
		// printf("e->distx = %f\n", e->distx);
		// printf("e->disty = %f\n", e->disty);
		// printf("e->disty = %i\n", (int)e->disty);
		e->disty -= m * 0.01;
		e->distx += 0.01;
		y = (int)(e->disty + 0.5);
		x = (int)(e->distx + 0.5);
	}
	// printf("e->distx = %f\n", e->distx);
	// printf("e->disty = %f\n", e->disty);
	// printf("m = %f\n", m);
	e->disty = e->disty - e->player.y;
	e->distx = e->distx - e->player.x;
}

int		ft_distline(t_env *e)
{
	double m;

	// if ((int)(e->rayang + 0.0001) == 90 || (int)(e->rayang + 0.0001) == 270)
	// 	((int)(e->rayang + 0.0001) == 90 ? vertical(e) : vertical2(e));
	// else
	// {
		// printf("e->rayang = %f\n", e->rayang);
		m = tan(e->rayang / e->pi);
		// printf("m = %f\n", m);
		if (m >= -1.0 && m <= 1.0)
			((e->rayang >= 270.0 && e->rayang <= 360.0) || (e->rayang >= 0.0 && e->rayang <= 90.0)) ? ft_line(e, m) : ft_line2(e, m); //condition (m >= 0)
		else
		{
			m = 1 / m;
			(e->rayang >= 0.0 && e->rayang <= 180.0) ? highline(e, m) : highline2(e, m); //condition (m >= 0)
		}
	// }
	return (1);
}
