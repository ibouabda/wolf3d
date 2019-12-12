/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 13:46:58 by idris             #+#    #+#             */
/*   Updated: 2019/12/12 12:16:28 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/wolf3d.h"

// double calcul_first_ray(t_env *e)
// {
// 	return (tan(e->rot + e->ang / 2));
// }

void ray_dist(t_env *e)
{
	ft_distline(e->rot + e->ang / 2, e);
	printf("e->distx = %f, e->disty = %f, distance = %f", e->distx, e->disty, sqrt(e->distx * e->distx + e->disty * e->disty));
}