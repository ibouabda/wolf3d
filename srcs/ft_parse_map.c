/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 11:41:11 by ibouabda          #+#    #+#             */
/*   Updated: 2019/12/02 15:43:04 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/wolf3d.h"

char		*ft_insert_char(char *str, int nbvar)
{
	char	*tab;
	int		i;
	int		k;

	i = 0;
	k = 0;
	tab = ft_strnew(nbvar);
	while (str[i])
	{
		while (str[i] && str[i] != ' ')
		{
			tab[k] = str[i];
			i++;
		}
		while (str[i] == ' ')
			i++;
		k++;
	}
	return (tab);
}

char		**create_dbtable(t_list *m, int size, int nbvar)
{
	char	**dbchar;
	int	y;

	dbchar = ft_2dstrnew(size);
	y = 0;
	while (m)
	{
		dbchar[y] = ft_insert_char((char*)m->content, nbvar);
		m = m->next;
		y++;
	}
	return (dbchar);
}

void		read_file(int fd, t_env *e)
{
	char	*line;
	t_list	*m;

	m = NULL;
	e->mapy = 1;
	e->mapx = 0;
	e->dbtab = NULL;
	while (get_next_line(fd, &line) && !line[0])
		ft_strdel(&line);
	m = ft_lstnewd(line, 0);
	while (get_next_line(fd, &line) > 0)
	{
		ft_lstaddend(&m, ft_lstnewd(line, 0));
		if (!line[0])
			ft_exit(1, e->dbtab, m);
		e->mapy++;
	}
	ft_lstaddend(&m, ft_lstnewd(line, 0));
	e->mapy++;
	if (!line || !line[0])
		ft_exit(1, e->dbtab, m);
	if (!m || !((char *)m->content)[0] || (e->mapx = ft_check_line(m)) == 0)
		ft_exit(1, e->dbtab, m);
	e->dbtab = create_dbtable(m, e->mapy, e->mapx);
	ft_lstdelstr(m);
}

void verify_map(t_env *e)
{
	int i;

	i = 0;
	while (e->dbtab[0][i])
	{
		if (e->dbtab[0][i] != '1')
			ft_exit(1, e->dbtab, NULL);
		i++;
	}
	i = 0;
	while (e->dbtab[e->mapy - 1][i])
	{
		if (e->dbtab[e->mapy - 1][i] != '1')
			ft_exit(1, e->dbtab, NULL);
		i++;
	}
	i = 0;
	while (e->dbtab[i])
	{
		if (e->dbtab[i][0] && e->dbtab[i][0] != '1')
			ft_exit(1, e->dbtab, NULL);
		i++;
	}
	i = 0;
	while (e->dbtab[i])
	{
		if (e->dbtab[i][e->mapx - 1] && e->dbtab[i][e->mapx - 1] != '1')
			ft_exit(1, e->dbtab, NULL);
		i++;
	}
}

void		checkandparse(char *argv, t_env *e)
{
	int fd;
	int fd_dir;

	if (ft_strlen(argv) >= 4 &&
	ft_strcmp(&(argv)[ft_strlen(argv) - 4], ".cub") != 0)
		ft_exit(1, NULL, NULL);
	fd_dir = open(argv, O_DIRECTORY);
	if ((fd = open(argv, O_RDONLY)) < 0 || fd_dir > 0)
	{
		if (fd_dir > 0)
			close(fd_dir);
		ft_exit(1, NULL, NULL);
	}
	read_first_param(fd, e);
	e->bool = 0;
	read_file(fd, e);
	verify_map(e);
	close(fd);
}