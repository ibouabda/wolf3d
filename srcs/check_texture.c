/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 10:56:23 by retounsi          #+#    #+#             */
/*   Updated: 2019/12/04 15:15:01 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/wolf3d.h"

void	open_texture(t_env *e)
{
	int width;
	int height;
	if ((e->tex.west_img = mlx_xpm_file_to_image(e->mlx_ptr, e->tex.west_tex, &width, &height)) == NULL)
		ft_exit(1, NULL, e);
	if ((e->tex.east_img = mlx_xpm_file_to_image(e->mlx_ptr, e->tex.east_tex, &width, &height)) == NULL)
		ft_exit(1, NULL, e);
	if ((e->tex.north_img = mlx_xpm_file_to_image(e->mlx_ptr, e->tex.north_tex, &width, &height)) == NULL)
		ft_exit(1, NULL, e);
	if ((e->tex.south_img = mlx_xpm_file_to_image(e->mlx_ptr, e->tex.south_tex, &width, &height)) == NULL)
		ft_exit(1, NULL, e);
	if ((e->tex.sprite_img = mlx_xpm_file_to_image(e->mlx_ptr, e->tex.sprite_tex, &width, &height)) == NULL)
		ft_exit(1, NULL, e);
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->tex.north_img, 0, 0);
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->tex.east_img, 256, 256);
	ft_putnbrl(width);
	ft_putnbrl(height);
}
