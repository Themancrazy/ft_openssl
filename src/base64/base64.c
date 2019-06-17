/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 14:44:17 by anjansse          #+#    #+#             */
/*   Updated: 2019/06/14 13:25:50 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>
#include "../../include/base64.h"

/*
** Main encryption function. Uses the Base64 algorithm to encrypt input.
*/

static void				encrypt_b64(char *str, int i, int xy[2], char *encrypt)
{
	if (xy[0] == 10)
			xy[0] = 2;
	if (xy[1] == -2)
			xy[1] = 6;
	if (xy[0] == 2)
		encrypt[i] = B64_ENCODING[RIGHT_SHIFT(*str)];
	else if (xy[0] == 4 || xy[0] == 6)
		encrypt[i] = B64_ENCODING[SHIFT(*(str - 1), *str, xy[0], xy[1])];
	else if (xy[1] == 0)
		encrypt[i] = B64_ENCODING[LEFT_SHIFT(*str)];
}

/*
** Sets up all the variables used in the main encryption loop. xy[0] = x,
** xy[1] = y. The algorithm is displayed as a Macro in the base64.h.
*/

static void					manage_ie(char *str)
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

/*
** Main decryption function. Uses the Base64 algorithm to decrypt input back
** to normal str.
*/

static void			decrypt_b64(int *xy, int *id, char *decrypted)
{
	if (xy[0] == 8)
		xy[0] = 2;
	if (xy[1] == -2)
		xy[1] = 4;
	decrypted[xy[2]] = DECRYPT_B64(*id, *(id + 1), xy[0], xy[1]);
	xy[2]++;
	xy[0] += 2;
	xy[1] -= 2;
}

/*
** Sets up all the variables used in the main decryption loop. xy[0] = x,
** xy[1] = y and xy[3] = index of *decrypted str.
** The algorithm is displayed as DECRYPT_B64 Macro in the base64.h.
*/

static void				manage_od(char *str)
{
	int		xy[3];
	int		size;
	int		*id;
	char	*decrypted;

	str = skip_ws(ft_strdup(str));
	size = get_size(str, 'd');
	decrypted = ft_memalloc(sizeof(char) * size + 5);
	str = (extra_pad(str) == 0) ? str : (extra_pad(str) == 1) ? ft_strsub(str,\
			0, ft_strlen(str) - 1) : ft_strsub(str, 0, ft_strlen(str) - 2);
	id = dispatch_b64(str);
	xy[0] = 2;
	xy[1] = 4;
	xy[2] = 0;
	while (size > 0)
	{
		decrypt_b64(xy, id, decrypted);
		if (xy[0] == 8)
			id += 2;
		else if (xy[0] != 8)
			id++;
		size--;
	}
	ft_putstr(decrypted);
}

/*
** Main base64 receiving function.
*/

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
			manage_od(input);
	}
	else
		send_error(ft_strdup(RED"Number of arguments not correct."RESET));
}
