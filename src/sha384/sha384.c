/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha384.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 20:08:33 by anjansse          #+#    #+#             */
/*   Updated: 2019/06/13 12:08:23 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static t_ssl		*other_ssl_sha384(t_ssl *s, char *sol, char *fn, int flag)
{
	int		fd;

	while ((fd = open(s->av[s->i], O_RDONLY)) > 2)
	{
		sol = ft_strjoin(sol, handle_files(s, fd));
		if (s->fl & FLP)
			ft_putstr(sol);
		if (!(s->fl & FLQ) && (!(s->fl & FLR)))
			ft_printf("SHA384(%s)= ", s->av[s->i]);
		if (s->fl & FLR)
			fn = s->av[s->i];
		sha384_hash(sol, flag, fn);
		s->i++;
	}
	return (s);
}

void				print_sha384(t_sha512 *m, int flag, char *fn)
{
	int		i;

	i = 0;
	while (i < 6)
		ft_printf("%08llx", (m->h[i++]));
	if (flag == 1)
		ft_printf(" %s", fn);
	ft_putchar('\n');
	free(m);
}

void				sha384_hash(char *str, int flag, char *fn)
{
	t_sha512		*s;

	s = (t_sha512 *)malloc(sizeof(t_sha512));
	s = sha512_prepare_om(str, s);
	s->h[0] = 0xcbbb9d5dc1059ed8;
	s->h[1] = 0x629a292a367cd507;
	s->h[2] = 0x9159015a3070dd17;
	s->h[3] = 0x152fecd8f70e5939;
	s->h[4] = 0x67332667ffc00b31;
	s->h[5] = 0x8eb44a8768581511;
	s->h[6] = 0xdb0c2e0d64f98fa7;
	s->h[7] = 0x47b5481dbefa4fa4;
	s = sha512_init_hash(s, max_size64(ft_strlen(s->msg)));
	print_sha384(s, flag, fn);
}

void				ssl_sha384(int argc, char **argv)
{
	int		flag;
	char	*sol;
	char	*fn;
	t_ssl	*s;

	sol = "";
	fn = "";
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
			ft_printf("SHA384 (\"%s\") = ", s->av[s->i]);
			sha384_hash(s->av[s->i++], flag, "");
		}
		other_ssl_sha384(s, sol, fn, flag);
		if (s->ac == 0 || s->fl & FLP)
			handle_str(s, sol, "sha384");
	}
}
