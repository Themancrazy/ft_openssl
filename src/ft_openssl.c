/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_openssl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 13:47:30 by anjansse          #+#    #+#             */
/*   Updated: 2019/06/17 19:05:10 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

t_dis				g_dis_table[CMD] = {
	{"md5", &ssl_md5},
	{"sha256", &ssl_sha256},
	{"sha224", &ssl_sha224},
	{"sha384", &ssl_sha384},
	{"sha512", &ssl_sha512},
	{"base64", &base64},
	{"des", &des},
	{"des-ecb", &des},
	{"des-cbc", &des},
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

char				*get_input(char *str, t_base64 base)
{
	int			fd;
	char		*line;
	char		*input;
	char		*file_content;

	input = "";
	fd = open(str, O_RDONLY);
	if (str && fd < 0 && (base.flag & FLE || base.flag & FLD))
		return (str);
	if (fd >= 0 && (base.flag & FLI || base.flag & FLO))
	{
		read_file(str, &file_content);
		return (file_content);
	}
	if (!str)
	{
		while (get_next_line(0, &line) > 0)
			input = ft_strjoinfree2(input, line);
	return (input);
	}
	send_error(ft_strdup(RED"Bad use of flag."RESET));
	return (NULL);
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
