/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha224_hash.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 19:41:02 by anjansse          #+#    #+#             */
/*   Updated: 2019/03/21 21:43:02 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void				print_sha224(t_sha256 *m, int flag, char *fn)
{
	int		i;

	i = 0;
	while (i < 7)
		ft_printf("%08x", (m->h[i++]));
	if (flag == 1)
		ft_printf(" %s", fn);
	ft_putchar('\n');
	free(m);
}

void					sha224_hash(char *str, int flag, char *fn)
{
	t_sha256	*s;

	s = (t_sha256 *)malloc(sizeof(t_sha256));
	s = sha256_prepare_om(str, s);
	s->h[0] = 0xc1059ed8;
	s->h[1] = 0x367cd507;
	s->h[2] = 0x3070dd17;
	s->h[3] = 0xf70e5939;
	s->h[4] = 0xffc00b31;
	s->h[5] = 0x68581511;
	s->h[6] = 0x64f98fa7;
	s->h[7] = 0xbefa4fa4;
	s = sha256_init_hash(s, max_size(ft_strlen(s->msg)));
	print_sha224(s, flag, fn);
}
