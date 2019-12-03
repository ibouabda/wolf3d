/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retounsi <retounsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 10:56:23 by retounsi          #+#    #+#             */
/*   Updated: 2019/12/03 12:29:22 by retounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/wolf3d.h"

void	open_texture(t_env *e)
{
	int width;
	int height;

	if (!open(e->tex.north_tex, O_RDONLY))
		ft_exit_params(e);
	if (!open(e->tex.south_tex, O_RDONLY))
		ft_exit_params(e);
	if (!open(e->tex.east_tex, O_RDONLY))
		ft_exit_params(e);
	if (!open(e->tex.west_tex, O_RDONLY))
		ft_exit_params(e);
	if (!open(e->tex.sprite_tex, O_RDONLY))
		ft_exit_params(e);
	mlx_xpm_file_to_image(e->tex.north_img, e->tex.north_tex, &width, &height);
}
