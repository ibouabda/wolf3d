/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 13:46:58 by idris             #+#    #+#             */
/*   Updated: 2020/02/02 16:08:39 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/wolf3d.h"

void	ray_dist(t_env *e)
{
	int i;

	i = 0;
	e->rayang = e->rot + 30;
	while (i < e->winx)
	{
		if (e->rayang > 360.0)
			e->rayang -= 360.0;
		else if (e->rayang < 0.0)
			e->rayang = 360.0 + e->rayang;
		e->ray_dist = sqrt(ft_dda(e)) * 64;
		display_column(e, i, 0, 0);
		e->rayang -= e->raylag;
		i++;
	}
}
