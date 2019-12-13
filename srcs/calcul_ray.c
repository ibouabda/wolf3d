/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idris <idris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 13:46:58 by idris             #+#    #+#             */
/*   Updated: 2019/12/13 11:07:13 by idris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/wolf3d.h"

// double calcul_first_ray(t_env *e)
// {
// 	return (tan(e->rot + e->ang / 2));
// }

void ray_dist(t_env *e)
{
	int i;
	double rayang;

	i = 0;
	rayang = e->rot + e->ang / 2;
    printf("rayang = %f\n", rayang);
	while (i <= e->winx)
	{
		if (rayang > 360.0)
			rayang -= 360.0;
		else if (rayang < 0.0)
			rayang = 360.0 - rayang;
		ft_distline(rayang, e);
        printf("rayang = %f\n", rayang);
		rayang -= e->raylag;
		i++;
	}
	// printf("rayang = %f\n", rayang);
	printf("e->distx = %f, e->disty = %f, distance = %f", e->distx, e->disty, sqrt(e->distx * e->distx + e->disty * e->disty));
}