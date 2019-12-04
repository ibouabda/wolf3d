/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 11:57:58 by ibouabda          #+#    #+#             */
/*   Updated: 2019/12/04 12:03:15 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/wolf3d.h"

int		key_hook(int keycode, t_env *e)
{
	if (keycode == ESC)
	{
		mlx_destroy_image(e->mlx_ptr, e->north_img);
		mlx_destroy_window(e->mlx_ptr, e->win_ptr);
		ft_exit(0, e->dbtab, NULL);
	}
	return (0);
}