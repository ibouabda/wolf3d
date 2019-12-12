/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fish_eye.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retounsi <retounsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 14:10:37 by retounsi          #+#    #+#             */
/*   Updated: 2019/12/12 13:13:47 by retounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/wolf3d.h"

int		dist_mid_ray(t_env *e)
{

}

float	fish_eye_calc_dist(t_env *e)
{
	float	mid_dist;
	float	cos;
	float	real_dist_ray;

	mid_dist = dist_mid_ray(e);
	if (e->ray_dist != 0)
		cos = mid_dist / e->ray_dist;
	real_dist_ray = e->ray_dist * cos;
	return (real_dist_ray);
}

float	calc_column(t_env *e)
{
	float	column_size;
	float	ray_dist_fisheyed;
	float	top_wall;

	ray_dist_fisheyed = fish_eye_calc_dist(e);
	column_size = (64/ray_dist_fisheyed)*277;
	return(column_size);
}
