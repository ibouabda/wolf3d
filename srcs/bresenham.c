/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 15:38:47 by ibouabda          #+#    #+#             */
/*   Updated: 2019/12/12 13:18:33 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/wolf3d.h"

void	highline(t_env *e, float m)
{
	// int x;

	e->disty = e->player.y;
	e->distx = e->player.x;
	while (e->disty >= 0 && e->distx >= 0 && e->disty < e->mapy && e->distx < e->mapx
	&& e->dbtab[(int)e->disty][(int)e->distx] != '1')
	{
		printf("e->distx = %f\n", e->distx);
		printf("e->disty = %f\n", e->disty);
		e->distx += m;
		// x = (int)(x + 0.5); //arrondi en negatif ???
		e->disty++;
	}
	e->disty = e->disty - e->player.y;
	e->distx = e->distx - e->player.x;
}

void	highline2(t_env *e, float m)
{
	// int x;

	e->disty = e->player.y;
	e->distx = e->player.x;
	while (e->disty >= 0 && e->distx >= 0 && e->disty < e->mapy && e->distx < e->mapx
	&& e->dbtab[(int)e->disty][(int)e->distx] != '1')
	{
		printf("e->distx = %f\n", e->distx);
		printf("e->disty = %f\n", e->disty);
		e->distx -= m;
		// x = (int)(x + 0.5); //arrondi en negatif ???
		e->disty--;
	}
	e->disty = e->disty - e->player.y;
	e->distx = e->distx - e->player.x;
}

void	ft_line(t_env *e, float m)
{
	// int y;

	e->disty = e->player.y;
	e->distx = e->player.x;
	while (e->disty >= 0 && e->distx >= 0 && e->disty < e->mapy && e->distx < e->mapx
	&& e->dbtab[(int)e->disty][(int)e->distx] != '1')
	{
		printf("e->distx = %f\n", e->distx);
		printf("e->disty = %f\n", e->disty);
		// printf("e->disty = %i\n", y);
		e->disty += m;
		// y = (int)(e->disty + 0.5);
		e->distx++;
	}
	e->disty = e->disty - e->player.y;
	e->distx = e->distx - e->player.x;
}

int		ft_distline(float angle, t_env *e)
{
	float m;

	if (angle == 90 || angle == 270)
		(angle == 90) ? vertical(e) : vertical2(e);
	else
	{
		printf("angle = %f\n", angle);
		m = tan(angle / (180 / M_PI));
		printf("m = %f\n", m);
		if (m >= -1.0 && m <= 1.0)
			(m >= 0 ) ? ft_line(e, m) : ft_line2(e, m); //condition (m >= 0)
		else
		{
			m = 1 / m;
			(m >= 0) ? highline(e, m) : highline2(e, m); //condition (m >= 0)
		}
	}
	return (1);
}
