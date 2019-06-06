/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 20:24:13 by anjansse          #+#    #+#             */
/*   Updated: 2019/03/21 22:00:14 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void				print_sha512(t_sha512 *m, int flag, char *fn)
{
	int		i;

	i = 0;
	while (i < 8)
		ft_printf("%08llx", (m->h[i++]));
	if (flag == 1)
		ft_printf(" %s", fn);
	ft_putchar('\n');
	free(m);
}

t_sha512			*sha512_create_block(t_sha512 *m, int start)
{
	int			j;
	int			four;

	j = -1;
	four = 0;
	m->block_128 = ft_strsub(m->msg, start, 128);
	j = -1;
	while (++j < 80)
	{
		if (j < 16)
		{
			ft_memcpy(&m->w[j], (m->block_128 + four), 8);
			m->w[j] = swap_endian64(m->w[j]);
			four += 8;
		}
		else
		{
			m->mod[0] = sha512s0(m->w[j - 15]);
			m->mod[1] = sha512s1(m->w[j - 2]);
			m->w[j] = m->w[j - 16] + m->mod[0] + m->w[j - 7] + m->mod[1];
		}
	}
	return (m);
}

t_sha512			*sha512_reset_abcd(t_sha512 *m)
{
	m->a[0] = m->h[0];
	m->a[1] = m->h[1];
	m->a[2] = m->h[2];
	m->a[3] = m->h[3];
	m->a[4] = m->h[4];
	m->a[5] = m->h[5];
	m->a[6] = m->h[6];
	m->a[7] = m->h[7];
	return (m);
}

t_sha512			*sha512_update_abcd(t_sha512 *m)
{
	m->h[0] += m->a[0];
	m->h[1] += m->a[1];
	m->h[2] += m->a[2];
	m->h[3] += m->a[3];
	m->h[4] += m->a[4];
	m->h[5] += m->a[5];
	m->h[6] += m->a[6];
	m->h[7] += m->a[7];
	return (m);
}
