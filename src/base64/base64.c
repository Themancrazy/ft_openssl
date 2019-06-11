/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 14:44:17 by anjansse          #+#    #+#             */
/*   Updated: 2019/06/10 22:19:21 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

static char		base64_encoding[64] = {
	'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O',
	'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd',
	'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
	't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7',
	'8', '9', '+', '/',
};

static void		get_binary(char *str)
{
	while (*str)
	{
		ft_printf("%08b ", *str);
		str++;
	}
	ft_putchar('\n');
}

static int				get_size(char *str, char c)
{
	if (c == 'e')
		return (E_B64_SIZE(ft_strlen(str)));
	return (0);
}

static t_base64			check_b64_flags(t_base64 base, char *flag)
{
	if (!ft_strcmp(flag, "-e"))
		base.flag |= FLE;
	else if (!ft_strcmp(flag, "-d"))
		base.flag |= FLD;
	else if (!ft_strcmp(flag, "-i"))
		base.flag |= FLI;
	else if (!ft_strcmp(flag, "-o"))
		base.flag |= FLO;
	return (base);
}

void			encrypt_str(char *str)
{
	int		size;
	int		xy[2];
	char	*encrypted;

	xy[0] = 2;
	xy[1] = 8;
	size = get_size(str, 'e');
	encrypted = (char *)malloc(sizeof(char) * size + 1);
	while (size > 0)
	{
		if (xy[0] == 10)
			xy[0] = 2;
		if (xy[1] == 0)
			xy[1] = 6;
		if (xy[0] == 2)
		{
			ft_putchar('1');
			ft_printf(CYAN BOLD"\n->%06b\n"RESET, RIGHT_SHIFT(*str));
			*encrypted = base64_encoding[RIGHT_SHIFT(*str)];
			ft_putchar(*encrypted);
		}
		else if (xy[1] == 2)
		{
			ft_putchar('2');
			ft_printf(CYAN BOLD"\n->%06b\n"RESET, LEFT_SHIFT(*str));
			*encrypted = base64_encoding[LEFT_SHIFT(*str)];
			ft_putchar(*encrypted);
		}
		else if (*(str - 1) && xy[0] != 2 && xy[0] != 8 && xy[1] != 2 && xy[1] != 0)
		{
			ft_putchar('3');
			ft_printf(CYAN BOLD"\n->%06b\n"RESET, SHIFT(*(str - 1), *str, xy[0], xy[1]));
			*encrypted = base64_encoding[SHIFT(*(str - 1), *str, xy[0], xy[1])];
			ft_putchar(*encrypted);
		}
		else if (*str == '\0')
			*encrypted = base64_encoding[SHIFT(*(str - 1), *str, 0, xy[1])];
		size--;
		if (*str)
			str++;
		xy[0] += 2;
		xy[1] -= 2;
		encrypted++;
	}
	ft_putstr(encrypted);
	ft_putchar('\n');
}

void			decrypt_str(char *str)
{

}

void			base64(int argc, char **argv)
{
	t_base64	base;
	
	base.flag = 0;
	if (argc > 1 && argc <= 2)
	{
		base = check_b64_flags(base, argv[0]);
		if (base.flag & FLE)
			encrypt_str(argv[1]);
		else if (base.flag & FLD)
			decrypt_str(argv[1]);
	}
	else
		send_error(ft_strdup(RED"Not enough arguments (check the flags)"RESET));
}
