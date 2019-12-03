/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 10:56:23 by retounsi          #+#    #+#             */
/*   Updated: 2019/12/03 12:48:58 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/wolf3d.h"

void	open_texture(t_env *e)
{
	int width;
	int height;
	if(open(e->north_texture, O_RDONLY) < 0)
		ft_exit_params(e);
	// if(open(e->south_texture, O_RDONLY) < 0)
	// 	ft_exit_params(e);
	// if(open(e->east_texture, O_RDONLY) < 0)
	// 	ft_exit_params(e);
	// if(open(e->west_texture, O_RDONLY) < 0)
	// 	ft_exit_params(e);
	// if(open(e->sprite_texture, O_RDONLY) < 0)
	// 	ft_exit_params(e);
	if ((e->north_img = mlx_xpm_file_to_image(e->mlx_ptr, e->north_texture, &width, &height)) == NULL)
	{
		printf("a\n");
		ft_exit_params(e);
	}
	else
		mlx_put_image_to_window(e->north_img, e->win_ptr, e->img_ptr, e->winx, e->winy);
}
