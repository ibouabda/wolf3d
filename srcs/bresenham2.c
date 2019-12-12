/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 15:38:17 by ibouabda          #+#    #+#             */
/*   Updated: 2019/12/12 17:08:53 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/wolf3d.h"

void	ft_line2(t_env *e, double m)
{
	e->disty = e->player.y;
	e->distx = e->player.x;
	while (e->disty >= 0 && e->distx >= 0 && e->disty < e->mapy && e->distx < e->mapx
	&& e->dbtab[(int)e->disty][(int)e->distx] != '1')
	{
		// printf("e->distx = %f\n", e->distx);
		// printf("e->disty = %f\n", e->disty);
		// printf("e->disty = %i\n", y);
		e->disty += m;
		// y = (int)(e->disty + 0.5);
		e->distx--;
	}
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