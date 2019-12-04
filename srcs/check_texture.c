/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 10:56:23 by retounsi          #+#    #+#             */
/*   Updated: 2019/12/04 12:24:36 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/wolf3d.h"

void	open_texture(t_env *e)
{
	int width;
	int height;
	if ((e->west_img = mlx_xpm_file_to_image(e->mlx_ptr, e->west_texture, &width, &height)) == NULL)
		ft_exit_params(e);
	if ((e->east_img = mlx_xpm_file_to_image(e->mlx_ptr, e->east_texture, &width, &height)) == NULL)
		ft_exit_params(e);
	if ((e->north_img = mlx_xpm_file_to_image(e->mlx_ptr, e->north_texture, &width, &height)) == NULL)
		ft_exit_params(e);
	if ((e->south_img = mlx_xpm_file_to_image(e->mlx_ptr, e->south_texture, &width, &height)) == NULL)
		ft_exit_params(e);
	if ((e->sprite_img = mlx_xpm_file_to_image(e->mlx_ptr, e->sprite_texture, &width, &height)) == NULL)
		ft_exit_params(e);
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->north_img, 0, 0);
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->east_img, 256, 256);
	ft_putnbrl(width);
	ft_putnbrl(height);
}
