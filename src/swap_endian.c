/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_endian.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 18:51:22 by anjansse          #+#    #+#             */
/*   Updated: 2019/03/22 07:37:55 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

t_ssl				*handle_flags(t_ssl *s)
{
	int		arg;

	while ((s->i != s->ac) && s->av[s->i][0] == '-')
	{
		arg = 1;
		while (s->av[s->i][arg])
		{
			if (s->av[s->i][arg] == 's')
				s->fl |= FLS;
			else if (s->av[s->i][arg] == 'q')
				s->fl |= FLQ;
			else if (s->av[s->i][arg] == 'p')
				s->fl |= FLP;
			else if (s->av[s->i][arg] == 'r')
				s->fl |= FLR;
			else
				ft_printf("Unknown option: \"%s\"\n", s->av[s->i]);
			arg++;
		}
		s->i++;
	}
	return (s);
}

char				*handle_files(t_ssl *s, int argc, char **argv, int fd)
{
	char	*line;
	char	*str;

	str = ft_strnew(1);
	line = NULL;
	while (get_next_line(fd, &line))
	{
		if (!(s->fl & FLS))
			line = ft_strappend(line, '\n');
		str = !*str ? ft_strjoinfree(line, str) : ft_strjoinfree(str, line);
	}
	return (str);
}

void				handle_str(t_ssl *s, char *sol, char *type)
{
	char		*final_sol;

	final_sol = "";
	while (get_next_line(0, &sol) > 0)
	{
		sol = ft_strappend(sol, '\n');
		final_sol = ft_strjoin(final_sol, sol);
	}
	if (s->fl & FLP)
		ft_printf("%s", final_sol);
	if (ft_strequ(type, "md5"))
		md5_hash(final_sol, 0, "");
	else if (ft_strequ(type, "sha256"))
		sha256_hash(final_sol, 0, "");
	else if (ft_strequ(type, "sha512"))
		sha512_hash(final_sol, 0, "");
	else if (ft_strequ(type, "sha224"))
		sha224_hash(final_sol, 0, "");
	else if (ft_strequ(type, "sha384"))
		sha384_hash(final_sol, 0, "");
}

uint32_t			swap_endian(uint32_t num)
{
	return ((num >> 24) & 0xff) | ((num << 8) & 0xff0000) | ((num >> 8) &\
			0xff00) | ((num << 24) & 0xff000000);
}

uint64_t			swap_endian64(uint64_t x)
{
	x = (x & 0x00000000FFFFFFFF) << 32 | (x & 0xFFFFFFFF00000000) >> 32;
	x = (x & 0x0000FFFF0000FFFF) << 16 | (x & 0xFFFF0000FFFF0000) >> 16;
	x = (x & 0x00FF00FF00FF00FF) << 8 | (x & 0xFF00FF00FF00FF00) >> 8;
	return (x);
}
