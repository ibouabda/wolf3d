/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 15:38:47 by ibouabda          #+#    #+#             */
/*   Updated: 2019/12/10 17:13:26 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/wolf3d.h"

void	highline(t_env *e, float m)
{
	int x;

	e->disty = e->player.y;
	e->distx = e->player.x;
	while (e->dbtab[(int)e->disty][x] != '1')
	{
		e->distx += m;
		x = (int)(x + 0.5);
		e->disty++;
	}
}

void	highline2(t_env *e, float m)
{
	int x;

	e->disty = e->player.y;
	e->distx = e->player.x;
	while (e->dbtab[(int)e->disty][x] != '1')
	{
		e->distx -= m;
		x = (int)(x + 0.5); //arrondi en negatif ???
		e->disty--;
	}
}

void	ft_line(t_env *e, float m)
{
	int y;

	e->disty = e->player.y;
	e->distx = e->player.x;
	while (e->dbtab[y][(int)e->distx] != '1')
	{
		e->disty += m;
		y = (int)(y + 0.5);
		e->distx++;
	}
}

int		ft_drawline(float angle, t_env *e)
{
	float m;

	if (angle == 90 || angle == 270)
		(angle == 90) ? vertical(e) : vertical2(e);
	else
	{
		m = tan(angle);
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
