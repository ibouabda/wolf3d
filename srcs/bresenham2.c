/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 15:38:17 by ibouabda          #+#    #+#             */
/*   Updated: 2019/12/10 17:13:25 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/wolf3d.h"

void	ft_line2(t_env *e, float m)
{
	int y;

	e->disty = e->player.y;
	e->distx = e->player.x;
	while (e->dbtab[y][(int)e->distx] != '1')
	{
		e->disty -= m;
		y = (int)(y + 0.5);
		e->distx--;
	}
}

void	vertical(t_env *e)
{
	e->disty = e->player.y;
	e->distx = e->player.x;
	while (e->dbtab[(int)e->disty][(int)e->distx] != '1')
	{
		e->disty++;
	}
}

void	vertical2(t_env *e)
{
	e->disty = e->player.y;
	e->distx = e->player.x;
	while (e->dbtab[(int)e->disty][(int)e->distx] != '1')
	{
		e->disty--;
	}
}