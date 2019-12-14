/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2dstrchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idris <idris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:35:35 by idris             #+#    #+#             */
/*   Updated: 2019/12/14 15:52:38 by idris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

int ft_2dstrchr(char **str, char c, t_dpoint *a)
{
    int y;
    int x;

    y = 0;
    while (str[y])
    {
        x = 0;
        while (str[y][x])
        {
            if (str[y][x] == c)
            {
                a->x = (int)x;
                a->y = (int)y;
                return (1);
            }
            x++;
        }
        y++;
    }
    return (0);
}