/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retounsi <retounsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 10:56:23 by retounsi          #+#    #+#             */
/*   Updated: 2020/01/24 12:22:39 by retounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/wolf3d.h"

void	open_texture(t_env *e)
{
	int		width;
	int		height;
	int		bpp;
	int		s_l;
	int		endian;

	if ((e->tex.west_img = mlx_xpm_file_to_image(e->mlx_ptr, e->tex.west_tex, &width, &height)) == NULL)
		ft_exit(1, NULL, e);
	if ((e->tex.north_img = mlx_xpm_file_to_image(e->mlx_ptr, e->tex.north_tex, &width, &height)) == NULL)
		ft_exit(1, NULL, e);
	if ((e->tex.south_img = mlx_xpm_file_to_image(e->mlx_ptr, e->tex.south_tex, &width, &height)) == NULL)
		ft_exit(1, NULL, e);
	if ((e->tex.sprite_img = mlx_xpm_file_to_image(e->mlx_ptr, e->tex.sprite_tex, &width, &height)) == NULL)
		ft_exit(1, NULL, e);
	if ((e->tex.east_img = mlx_xpm_file_to_image(e->mlx_ptr, e->tex.east_tex, &width, &height)) == NULL)
		ft_exit(1, NULL, e);
	e->tex.north_tex =  mlx_get_data_addr(e->tex.north_img, &(bpp), &(s_l), &(endian));
	e->tex.south_tex =  mlx_get_data_addr(e->tex.south_img, &(bpp), &(s_l), &(endian));
	e->tex.west_tex =  mlx_get_data_addr(e->tex.west_img, &(bpp), &(s_l), &(endian));
	e->tex.east_tex = mlx_get_data_addr(e->tex.east_img, &(bpp), &(s_l), &(endian));
}
