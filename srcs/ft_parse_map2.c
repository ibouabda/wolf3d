/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 11:43:13 by ibouabda          #+#    #+#             */
/*   Updated: 2019/12/02 14:53:18 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../incl/wolf3d.h"


int ft_iscorrect(char c)
{
	if (c == '0' || c == '1' || c == '2' || c == '3' || c == 'N' || c == 'S'
	|| c == 'E' || c == 'O')
		return (1);
	return (0);
}

int		ft_analyze_line(char *line, int i, int nbvar)
{
	while (line[i] == ' ')
		i++;
	while (line[i])
	{
		if (!ft_iscorrect(line[i]))
			return (0);
		i++;
		if (line[i] && line[i] != ' ')
			return(0);
		while (line[i] == ' ')
			i++;
		nbvar++;
	}
	return (nbvar);
}

int		ft_check_line(t_list *m)
{
	int	nbvarmem;
	int	nbvar;

	nbvarmem = -1;
	while (m)
	{
		if ((nbvar = ft_analyze_line((char *)m->content, 0, 0)) == 0)
			return (0);
		if (nbvarmem == -1)
			nbvarmem = nbvar;
		else if (nbvarmem != nbvar)
			return (0);
		m = m->next;
	}
	return (nbvar);
}
