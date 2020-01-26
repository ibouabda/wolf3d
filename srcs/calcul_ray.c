/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 13:46:58 by idris             #+#    #+#             */
/*   Updated: 2020/01/26 17:26:24 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/wolf3d.h"

void ray_dist(t_env *e)
{
	int i;
	int fd;

	i = 0;
	e->rayang = e->rot + e->ang / 2;
	// fd = open("test.txt", O_WRONLY);
    // printf("e->rayang = %f\n", e->rayang);
	while (i < e->winx)
	{
		if (e->rayang > 360.0)
			e->rayang -= 360.0;
		else if (e->rayang < 0.0)
			e->rayang = 360.0 + e->rayang;
		ft_dda(e);
		if (e->wall_dir == 'h')
			e->ray_dist = sqrt(e->dday.x * e->dday.x + e->dday.y * e->dday.y) * 30;
		else
			e->ray_dist = sqrt(e->ddax.x * e->ddax.x + e->ddax.y * e->ddax.y) * 30;
		// dprintf(fd, "angle : %f\n", (e->rayang));
		// dprintf(fd, "coef. : %f\n", (tan(e->rayang / e->pi)));
		// dprintf(fd, "ray_dist : %f\n", (e->ray_dist));
		display_column(e, i);
		// printf("test = %i\n", (int)(39.999999 + 0.000001));
        // printf("e->rayang = %f\n", e->rayang);
		e->rayang -= e->raylag;
		i++;
	}
	close(fd);
	// printf("e->rayang = %f\n", e->rayang);
	// printf("e->distx = %f, e->disty = %f, distance = %f", e->distx, e->disty, sqrt(e->distx * e->distx + e->disty * e->disty));
}
