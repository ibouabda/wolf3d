/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_column.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retounsi <retounsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 14:10:37 by retounsi          #+#    #+#             */
/*   Updated: 2019/12/12 17:13:00 by retounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/wolf3d.h"

int		dist_mid_ray(t_env *e)
{
	return (0);
}

float	fish_eye_calc_dist(t_env *e)
{
	float	mid_dist;
	float	cos;
	float	real_dist_ray;

	mid_dist = 10;
	if (e->ray_dist != 0)
		cos = mid_dist / e->ray_dist;
	real_dist_ray = e->ray_dist * cos;
	return (real_dist_ray);
}

int		calc_column(t_env *e)
{
	float	column_size;
	float	ray_dist_fisheyed;
	float	top_wall;

	ray_dist_fisheyed = fish_eye_calc_dist(e);
	printf("fisheye : %f", ray_dist_fisheyed);
	column_size = (64/ray_dist_fisheyed)*277;
	printf("col_before : %f\n", column_size);
	return(column_size);
}

void	display_column(t_env *e)
{
	float	i;
	int	top_wall;
	int	column_size;

	e->ray_dist = 10;
	column_size = calc_column(e);
	top_wall = (e->winy/2)-(column_size/2);
	if (top_wall < 0 || top_wall > e->winy)
		top_wall = 0;
	i = 0;
	printf("top wall : %i, column_size : %i\n", top_wall, column_size);
	while (i <= column_size && i <= e->winy)
	{
		e->pixel.x = 160;
		e->pixel.y = top_wall;
		ft_fill_pixel(e->pixel, 150, e);
		top_wall++;
		i++;
	}
}
