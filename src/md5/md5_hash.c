/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_hash.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 12:11:07 by anjansse          #+#    #+#             */
/*   Updated: 2019/06/13 12:04:16 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static int				g_s[64] = {
	7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
	5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20,
	4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
	6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21
};

static uint32_t			g_k[64] = {
	0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
	0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
	0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
	0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
	0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
	0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
	0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
	0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
	0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
	0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
	0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
	0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
	0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
	0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
	0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
	0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391,
};

t_md5					*md5_shift(t_md5 *m, int i)
{
	m->fg[0] = m->fg[0] + m->abcd[0] + g_k[i] + m->w[m->fg[1]];
	m->abcd[0] = m->abcd[3];
	m->abcd[3] = m->abcd[2];
	m->abcd[2] = m->abcd[1];
	m->abcd[1] = m->abcd[1] + md5leftrotate(m->fg[0], g_s[i]);
	return (m);
}

t_md5					*process_md5(t_md5 *m)
{
	int				i;

	i = 0;
	while (i < 64)
	{
		if (i >= 0 && i <= 15)
			m = md5f(m, i);
		else if (i >= 16 && i <= 31)
			m = md5g(m, i);
		else if (i >= 32 && i <= 47)
			m = md5h(m, i);
		else if (i >= 48 && i <= 63)
			m = md5i(m, i);
		m = md5_shift(m, i);
		i++;
	}
	return (m);
}

t_md5					*init_hash(t_md5 *m, int max)
{
	int		i;
	int		start;
	int		blocks;

	i = 0;
	start = 0;
	blocks = max / 64;
	m->abcd0[0] = 0x67452301;
	m->abcd0[1] = 0xefcdab89;
	m->abcd0[2] = 0x98badcfe;
	m->abcd0[3] = 0x10325476;
	while (i < blocks)
	{
		m = reset_abcd(m);
		m = create_block(m, start);
		m = process_md5(m);
		m = update_abcd(m);
		start += 64;
		i++;
	}
	return (m);
}

t_md5					*prepare_om(char *str, t_md5 *m)
{
	int				i;
	int				len;
	long long		max;

	len = ft_strlen(str);
	max = max_size(len);
	m->msg = ft_memalloc(max);
	ft_memcpy(m->msg, str, len);
	m->msg[len] = (unsigned char)0x80;
	i = len + 1;
	while (i < (max - 8))
		m->msg[i++] = 0;
	max = 8 * len;
	ft_memcpy(m->msg + i, &max, 8);
	return (m);
}

void					md5_hash(char *str, int flag, char *fn)
{
	t_md5	*md5;

	md5 = (t_md5 *)malloc(sizeof(t_md5));
	md5 = prepare_om(str, md5);
	md5 = init_hash(md5, max_size(ft_strlen(md5->msg)));
	print_md5(md5, flag, fn);
}
