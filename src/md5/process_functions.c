/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 12:39:42 by anjansse          #+#    #+#             */
/*   Updated: 2019/03/21 22:04:44 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"

t_md5			*md5f(t_md5 *m, int i)
{
	m->fg[0] = ((m->abcd[1] & m->abcd[2]) | (~m->abcd[1] & m->abcd[3]));
	m->fg[1] = i;
	return (m);
}

t_md5			*md5g(t_md5 *m, int i)
{
	m->fg[0] = ((m->abcd[1] & m->abcd[3]) | (m->abcd[2] & ~m->abcd[3]));
	m->fg[1] = ((5 * i) + 1) % 16;
	return (m);
}

t_md5			*md5h(t_md5 *m, int i)
{
	m->fg[0] = (m->abcd[1] ^ m->abcd[2] ^ m->abcd[3]);
	m->fg[1] = ((3 * i) + 5) % 16;
	return (m);
}

t_md5			*md5i(t_md5 *m, int i)
{
	m->fg[0] = (m->abcd[2] ^ (m->abcd[1] | ~m->abcd[3]));
	m->fg[1] = (7 * i) % 16;
	return (m);
}

uint32_t		md5leftrotate(uint32_t f, int n)
{
	return ((f << n) | (f >> (32 - n)));
}
