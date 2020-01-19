/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_column.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retounsi <retounsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 14:10:37 by retounsi          #+#    #+#             */
/*   Updated: 2020/01/19 16:18:09 by retounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/wolf3d.h"

// void	print_sprite(t_env *e, void *dist_sprite, int ray_num)
// {
// 	int top_sprite;
// 	int sprite_size;
// 	int i;

// 	i = 0;
// 	sprite_size = 22 * (e->median_ray_sprite / 277);
// 	top_sprite = (e->winy / 2) + (sprite_size / 2);
// 	while (i < sprite_size)
// 	{
// 		e->pixel.x = ray_num;
// 		e->pixel.y = top_sprite;
// 		ft_fill_pixel(e->pixel, /*?*/, e);
// 		top_sprite++;
// 		i++;
// 	}
// }

// void	display_sprite(t_env *e, t_list *sprite, int ray_num)
// {
// 	while (sprite)
// 	{
// 		print_sprite(e, sprite->content, ray_num);
// 		sprite = sprite->next;
// 	}
// }

double	fish_eye_calc_dist(t_env *e)
{
	double	real_dist_ray;

	real_dist_ray = ABS(e->ray_dist * cos((e->rayang - e->rot) / e->pi));
	// printf("ray_ang : %f\n", e->rayang);
	// printf("ray_ang - e->rot : %f\n", e->rayang - e->rot);
	// printf("ray_dist : %f\n", e->ray_dist);
	// printf("cos : %f\n", cos);
	// printf("real_ray : %f\n", real_dist_ray);
	// printf("ray_dist * cos : %f\n", (double)((double)e->ray_dist * (double)cos));
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
	e->texel.x = ray_num / 5;
	e->texel.y = 0;
	while (i < e->winy && i < top_wall)
	{
		e->pixel.x = ray_num;
		e->pixel.y = i;
		ft_fill_pixel(e->pixel, e->tex.ceiling_color, e);
		i++;
	}
	i = 0;
	while (i < e->winy && i < column_size)
	{
		e->pixel.x = ray_num;
		e->pixel.y = top_wall;
		print_texture(e, e->pixel, e->texel);
		e->texel.y++;
		top_wall++;
		i++;
	}
	while (top_wall < e->winy)
	{
		e->pixel.x = ray_num;
		e->pixel.y = top_wall;
		ft_fill_pixel(e->pixel, e->tex.floor_color, e);
		top_wall++;
	}
}
