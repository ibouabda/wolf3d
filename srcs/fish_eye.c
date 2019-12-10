/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fish_eye.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retounsi <retounsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 14:10:37 by retounsi          #+#    #+#             */
/*   Updated: 2019/12/10 17:33:07 by retounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/wolf3d.h"

float		dist_mid_ray(t_env *e)
{

}

float	fish_eye_calc_dist(t_env *e)
{
	float	mid_dist;
	float	cos;
	float	real_dist_ray;

	e->count_ray++;
	mid_dist = dist_mid_ray(e);
	if (e->ray_dist != 0)
		cos = mid_dist / e->ray_dist;
	real_dist_ray = e->ray_dist * cos;
	return (real_dist_ray);
}

void	calc_colonne(t_env *e)
{
	int		wall_size;
	int		ray_dist_fisheyed;

	ray_dist_fisheyed = fish_eye_calc_dist(e);
	wall_size = (64/ray_dist)*277;
}
