/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_hash.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 12:11:07 by anjansse          #+#    #+#             */
/*   Updated: 2019/03/21 22:08:46 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static uint32_t		g_k[64] = {
	0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
	0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
	0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
	0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
	0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
	0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
	0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
	0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
	0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
	0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
	0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
	0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
	0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
	0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
	0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
	0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

t_sha256			*process_sha256(t_sha256 *m)
{
	int		i;

	i = -1;
	while (++i < 64)
	{
		m->mod[3] = sha256ss1(m->a[4]);
		m->tmp[2] = (m->a[4] & m->a[5]) ^ ((~m->a[4]) & m->a[6]);
		m->tmp[0] = m->a[7] + m->mod[3] + m->tmp[2] + g_k[i] + m->w[i];
		m->mod[2] = sha256ss0(m->a[0]);
		m->tmp[3] = (m->a[0] & m->a[1]) ^ (m->a[0] & m->a[2]) ^\
					(m->a[1] & m->a[2]);
		m->tmp[1] = m->mod[2] + m->tmp[3];
		m->a[7] = m->a[6];
		m->a[6] = m->a[5];
		m->a[5] = m->a[4];
		m->a[4] = m->a[3] + m->tmp[0];
		m->a[3] = m->a[2];
		m->a[2] = m->a[1];
		m->a[1] = m->a[0];
		m->a[0] = m->tmp[0] + m->tmp[1];
	}
	return (m);
}

t_sha256			*sha256_init_hash(t_sha256 *m, int max)
{
	int		i;
	int		start;
	int		blocks;

	i = 0;
	start = 0;
	blocks = max / 64;
	while (i < blocks)
	{
		m = sha256_create_block(m, start);
		m = sha256_reset_abcd(m);
		m = process_sha256(m);
		m = sha256_update_abcd(m);
		start += 64;
		i++;
	}
	return (m);
}

t_sha256			*sha256_prepare_om(char *str, t_sha256 *m)
{
	int				i;
	int				len;
	long long		max;

	len = ft_strlen(str);
	max = max_size(len) + 4;
	m->msg = ft_memalloc(max);
	ft_memcpy(m->msg, str, len);
	m->msg[len] = (unsigned char)0x80;
	i = len + 1;
	while (i < (max - 8))
		m->msg[i++] = 0;
	max = swap_endian(8 * len);
	ft_memcpy(m->msg + i, &max, 8);
	return (m);
}

void				sha256_hash(char *str, int flag, char *fn)
{
	t_sha256	*s;

	s = (t_sha256 *)malloc(sizeof(t_sha256));
	s = sha256_prepare_om(str, s);
	s->h[0] = 0x6a09e667;
	s->h[1] = 0xbb67ae85;
	s->h[2] = 0x3c6ef372;
	s->h[3] = 0xa54ff53a;
	s->h[4] = 0x510e527f;
	s->h[5] = 0x9b05688c;
	s->h[6] = 0x1f83d9ab;
	s->h[7] = 0x5be0cd19;
	s = sha256_init_hash(s, max_size(ft_strlen(s->msg)));
	print_sha256(s, flag, fn);
}
