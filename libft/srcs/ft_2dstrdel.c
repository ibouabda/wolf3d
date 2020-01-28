/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2dstrdel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retounsi <retounsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 15:40:50 by ibouabda          #+#    #+#             */
/*   Updated: 2019/12/04 15:04:04 by retounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

void	ft_2dstrdel(char **as)
{
	size_t i;

	i = 0;
	if (as != NULL)
	{
		while (as[i])
		{
			free(as[i]);
			i++;
		}
		free(as);
		as = NULL;
	}
}
