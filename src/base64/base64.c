/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 14:44:17 by anjansse          #+#    #+#             */
/*   Updated: 2019/06/13 23:38:40 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>
#include "../../include/base64.h"

static char			base64_encoding[64] = {
	'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O',
	'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd',
	'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
	't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7',
	'8', '9', '+', '/',
};

static void				encrypt_b64(char *str, int i, int xy[2], char *encrypt)
{
	if (xy[0] == 10)
			xy[0] = 2;
	if (xy[1] == -2)
			xy[1] = 6;
	if (xy[0] == 2)
		encrypt[i] = base64_encoding[RIGHT_SHIFT(*str)];
	else if (xy[0] == 4 || xy[0] == 6)
		encrypt[i] = base64_encoding[SHIFT(*(str - 1), *str, xy[0], xy[1])];
	else if (xy[1] == 0)
		encrypt[i] = base64_encoding[LEFT_SHIFT(*str)];
}

void					manage_ie(char *str)
{
	int		i;
	int		size;
	int		xy[2];
	char	*encrypted;

	i = 0;
	xy[0] = 2;
	xy[1] = 6;
	size = get_size(str, 'e');
	encrypted = ft_memalloc(sizeof(char) * size + 5);
	while (size > 0)
	{
		encrypt_b64(str, i, xy, encrypted);
		xy[0] += 2;
		xy[1] -= 2;
		if (xy[1] != 0)
			str++;
		size--;
		i++;
	}
	encrypted = pad_end(encrypted, xy[1]);
	ft_putstr(encrypted);
	ft_putchar('\n');
	free(encrypted);
}

void			decrypt_str(char *str)
{
	int		size;
	int		chunk;
	char	*decrypted;

	str = skip_ws(ft_strdup(str));
	size = get_size(str, 'd');
	decrypted = ft_memalloc(sizeof(char) * size + 5);
	chunk = (extra_pad(str) == 0) ? 3 : (extra_pad(str) == 1) ? 2 : 1;
	while (size > 0)
	{
		size--;
	}
	ft_putstr(str);
}

void			base64(int argc, char **argv)
{
	t_base64	base;
	char		*input;
	
	base.flag = 0;
	if (argc >= 1 && argc <= 2)
	{
		base = check_b64_flags(base, argv[0]);
		input = get_input(argv[1], base);
		if (base.flag & FLE || base.flag & FLI)
			manage_ie(input);
		else if (base.flag & FLD || base.flag & FLO)
			decrypt_str(input);
	}
	else
		send_error(ft_strdup(RED"Number of arguments not correct."RESET));
}
