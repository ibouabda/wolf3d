/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idris <idris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 13:46:58 by idris             #+#    #+#             */
/*   Updated: 2019/12/14 17:48:17 by idris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/wolf3d.h"

void ray_dist(t_env *e)
{
	int i;

	i = 0;
	e->rayang = e->rot + e->ang / 2;
    // printf("e->rayang = %f\n", e->rayang);
	while (i < e->winx)
	{
		if (e->rayang > 360.0)
			e->rayang -= 360.0;
		else if (e->rayang < 0.0)
			e->rayang = 360.0 + e->rayang;
		ft_distline(e);
		e->ray_dist = sqrt(e->distx * e->distx + e->disty * e->disty) * 20;
		// printf("angle : %f\n", (e->rayang));
		// printf("ray : %f\n", (e->ray_dist));
		display_column(e, i);
		// printf("test = %i\n", (int)(39.999999 + 0.000001));
        // printf("e->rayang = %f\n", e->rayang);
		e->rayang -= e->raylag;
		i++;
	}
	// printf("e->rayang = %f\n", e->rayang);
	// printf("e->distx = %f, e->disty = %f, distance = %f", e->distx, e->disty, sqrt(e->distx * e->distx + e->disty * e->disty));
}