/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 13:46:58 by idris             #+#    #+#             */
/*   Updated: 2020/01/28 12:25:33 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/wolf3d.h"

void	ray_dist(t_env *e)
{
	int i;

	i = 0;
	e->rayang = e->rot + e->ang / 2;
	while (i < e->winx)
	{
		if (e->rayang > 360.0)
			e->rayang -= 360.0;
		else if (e->rayang < 0.0)
			e->rayang = 360.0 + e->rayang;
		ft_dda(e);
		if (e->wall_dir == 'h')
			e->ray_dist = sqrt(e->dday.x * e->dday.x
			+ e->dday.y * e->dday.y) * 64;
		else
			e->ray_dist = sqrt(e->ddax.x * e->ddax.x
			+ e->ddax.y * e->ddax.y) * 64;
		display_column(e, i);
		e->rayang -= e->raylag;
		i++;
	}
}
