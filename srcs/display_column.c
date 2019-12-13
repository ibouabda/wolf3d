/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_column.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idris <idris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 14:10:37 by retounsi          #+#    #+#             */
/*   Updated: 2019/12/13 12:31:31 by idris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/wolf3d.h"

double	dist_mid_ray(t_env *e)
{
	int i;
	double rayang;

	i = 0;
	rayang = e->rot;
	if (rayang > 360.0)
		rayang -= 360.0;
	else if (rayang < 0.0)
		rayang = 360.0 - rayang;
	ft_distline(rayang, e);
	return(sqrt(e->distx * e->distx + e->disty * e->disty) * 100);
}

double	fish_eye_calc_dist(t_env *e)
{
	double	mid_dist;
	double	cos;
	double	real_dist_ray;

	mid_dist = dist_mid_ray(e);
	cos = mid_dist / e->ray_dist;
	real_dist_ray = e->ray_dist * cos;
	printf("cos : %f\n", e->ray_dist);
	printf("cos : %f\n", cos);
	printf("ray : %f\n", real_dist_ray);
	return (real_dist_ray);
}

int		calc_column(t_env *e)
{
	double	column_size;
	double	ray_dist_fisheyed;
	double	top_wall;

	ray_dist_fisheyed = fish_eye_calc_dist(e);
	column_size = (64 / ray_dist_fisheyed) * 277;
	return(column_size);
}

void	display_column(t_env *e, int ray_num)
{
	int		i;
	int		top_wall;
	int		column_size;

	column_size = calc_column(e);
	top_wall = (e->winy / 2) - (column_size / 2);
	if (top_wall < 0 || top_wall > e->winy)
		top_wall = 0;
	i = 0;
	while (i < e->winy && i < column_size)
	{
		e->pixel.x = ray_num;
		e->pixel.y = top_wall;
		ft_fill_pixel(e->pixel, 150, e);
		top_wall++;
		i++;
	}
}
