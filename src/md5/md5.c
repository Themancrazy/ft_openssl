/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 20:08:33 by anjansse          #+#    #+#             */
/*   Updated: 2019/03/21 22:06:57 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

t_md5			*update_abcd(t_md5 *m)
{
	m->abcd0[0] = m->abcd0[0] + m->abcd[0];
	m->abcd0[1] = m->abcd0[1] + m->abcd[1];
	m->abcd0[2] = m->abcd0[2] + m->abcd[2];
	m->abcd0[3] = m->abcd0[3] + m->abcd[3];
	return (m);
}

static t_ssl	*other_ssl_md5(t_ssl *s, char *sol, char *fn, int flag)
{
	int		fd;

	while ((fd = open(s->av[s->i], O_RDONLY)) > 2)
	{
		sol = "";
		sol = ft_strjoin(sol, handle_files(s, s->ac, s->av, fd));
		if (s->fl & FLP)
			ft_putstr(sol);
		if (!(s->fl & FLQ) && (!(s->fl & FLR)))
			ft_printf("MD5(%s)= ", s->av[s->i]);
		if (s->fl & FLR)
			fn = s->av[s->i];
		md5_hash(sol, flag, fn);
		s->i++;
	}
	return (s);
}

void			ssl_md5(int argc, char **argv)
{
	int		fd;
	int		flag;
	char	*sol;
	char	*fn;
	t_ssl	*s;

	s = ft_memalloc(sizeof(t_ssl));
	s->i = -1;
	s->av = argv;
	s->ac = argc;
	while (++s->i <= s->ac)
	{
		if (s->av[s->i] && s->av[s->i][0] == '-')
			s = handle_flags(s);
		flag = (s->fl & FLR) ? 1 : 0;
		if (s->fl & FLS)
		{
			ft_printf("MD5 (\"%s\") = ", s->av[s->i]);
			md5_hash(s->av[s->i++], flag, "");
		}
		s = other_ssl_md5(s, sol, fn, flag);
		if (s->ac == 0 || s->fl & FLP)
			handle_str(s, sol, "md5");
	}
}
