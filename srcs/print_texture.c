/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retounsi <retounsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 15:47:38 by retounsi          #+#    #+#             */
/*   Updated: 2020/01/19 16:19:36 by retounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/wolf3d.h"

void	print_texture(t_env *e, t_point point, t_point texel)
{
	int	pos;

	pos = texel.y * e->winx * 4 + texel.x * 4;
	e->img_string[pos] = e->tex.south_img[pos];
	e->img_string[pos + 1] = e->tex.south_img[pos];
	e->img_string[pos + 2] = e->tex.south_img[pos];
}
