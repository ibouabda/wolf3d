/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttabint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 10:52:15 by ibouabda          #+#    #+#             */
/*   Updated: 2019/10/10 20:01:37 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

void	ft_puttabint(int *tab, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_putnbr(tab[i]);
		ft_putstr(" ");
		i++;
	}
	ft_putendl("");
}
