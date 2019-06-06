/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 20:24:13 by anjansse          #+#    #+#             */
/*   Updated: 2019/03/21 22:02:16 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"

void					print_md5(t_md5 *m, int flag, char *fn)
{
	int		i;

	i = 0;
	while (i < 4)
		ft_printf("%08x", swap_endian(m->abcd0[i++]));
	if (flag == 1)
		ft_printf(" %s", fn);
	ft_putchar('\n');
	free(m);
}

uint32_t				max_size(uint32_t n)
{
	uint32_t	x;

	x = 64;
	while (n > (x - 8))
		x += 64;
	return (x);
}

uint64_t				max_size64(uint64_t n)
{
	uint64_t	x;

	x = 128;
	while (n > (x - 8))
		x += 128;
	return (x);
}

t_md5					*create_block(t_md5 *m, int start)
{
	int			i;
	int			j;
	int			four;

	i = 0;
	j = 0;
	four = 0;
	m->block_64 = ft_strsub(m->msg, start, 64);
	while (j < 16)
	{
		m->w[j] = *(unsigned int *)ft_strsub(m->block_64, four, 4);
		four += 4;
		j++;
	}
	return (m);
}

t_md5					*reset_abcd(t_md5 *m)
{
	m->abcd[0] = m->abcd0[0];
	m->abcd[1] = m->abcd0[1];
	m->abcd[2] = m->abcd0[2];
	m->abcd[3] = m->abcd0[3];
	return (m);
}
