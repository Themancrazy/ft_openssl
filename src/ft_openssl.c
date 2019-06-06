/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 13:47:30 by anjansse          #+#    #+#             */
/*   Updated: 2019/03/22 07:12:46 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

t_dis				g_dis_table[CMD] = {
	{"md5", &ssl_md5},
	{"sha256", &ssl_sha256},
	{"sha224", &ssl_sha224},
	{"sha384", &ssl_sha384},
	{"sha512", &ssl_sha512},
};

static void			manage_error(char *str, t_dis *cmd)
{
	int		i;

	i = 0;
	ft_printf("ft_ssl: Error: '%s' is an invalid command.\n\n", str);
	ft_printf("Standard commands:\n\nMessage Digest commands:\n");
	while (i < CMD)
		ft_printf("%s\n", cmd[i++].name);
	ft_printf("\nCipher commands:\n");
}

void				dispatcher(int argc, char **argv)
{
	int		i;

	i = 0;
	while (i < CMD)
	{
		if (ft_strequ(argv[0], g_dis_table[i].name))
		{
			g_dis_table[i].hash(--argc, ++argv);
			return ;
		}
		i++;
	}
	manage_error(argv[0], g_dis_table);
}

int					main(int argc, char **argv)
{
	if (argc < 2)
		process_stdio_cmd();
	dispatcher(--argc, ++argv);
	return (0);
}
