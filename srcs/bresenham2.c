/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idris <idris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 15:38:17 by ibouabda          #+#    #+#             */
/*   Updated: 2019/12/13 10:57:37 by idris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/wolf3d.h"

void	ft_line2(t_env *e, double m)
{
	int y;

	e->disty = e->player.y;
	e->distx = e->player.x;
	y = (int)(e->disty + 0.5);
	while (e->disty >= 0 && e->distx >= 0 && e->disty < e->mapy && e->distx < e->mapx
	&& e->dbtab[y][(int)e->distx] != '1')
	{
		printf("e->distx = %f\n", e->distx);
		printf("e->disty = %f\n", e->disty);
		printf("e->disty = %i\n", (int)e->disty);
		e->disty += m;
		y = (int)(e->disty + 0.5);
		e->distx--;
	}
	printf("e->distx = %f\n", e->distx);
	printf("e->disty = %f\n", e->disty);
	printf("m = %f\n", m);
	e->disty = e->disty - e->player.y;
	e->distx = e->distx - e->player.x;
}

void	vertical(t_env *e)
{
	e->disty = e->player.y;
	e->distx = e->player.x;
	while (e->disty> 0 && e->distx > 0 && e->disty< e->mapy && e->distx < e->mapx && e->dbtab[(int)e->disty][(int)e->distx] != '1')
	{
		e->disty--;
	}
}

void	vertical2(t_env *e)
{
	e->disty = e->player.y;
	e->distx = e->player.x;
	while (e->disty > 0 && e->distx > 0 && e->disty < e->mapy && e->distx < e->mapx && e->dbtab[(int)e->disty][(int)e->distx] != '1')
	{
		e->disty++;
	}
}