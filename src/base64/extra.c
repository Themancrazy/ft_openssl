/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 21:16:01 by anjansse          #+#    #+#             */
/*   Updated: 2019/06/14 14:11:16 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>
#include "../../include/base64.h"

/*
** Counts the number of padding bits at the end of input.
*/

int			extra_pad(char *str)
{
	int		i;

	i = ft_strlen(str);
	if (i - 1 > 0 && i - 2 > 0)
	{
		if (str[i - 1] == '=' && str[i - 2] == '=')
			return (2);
		else if (str[i - 1] == '=')
			return (1);
	}
	return (0);
}

/*
** Cuts out the padding characters at the end of input.
*/

char				*pad_end(char *str, int pad)
{
	if (pad == 0)
		str = ft_strjoin(str, "=");
	else if (pad == 2)
		str = ft_strjoin(str, "==");
	return (str);
}

/*
** Gets the size of encryption or decryption and returns it to be used
** for mallocing in encryption and decryption,
*/

int			get_size(char *str, char c)
{
	int		size;

	if (c == 'e')
	{
		size = ft_strlen(str) * 8;
		if (size % 6 != 0)
			return ((size / 6) + 1);
		else if (size % 6 == 0)
			return ((size / 6));
	}
	else if (c == 'd')
	{
		size = ((ft_strlen(str) * 6) - (extra_pad(str) * 2)) / 8;
		return (size);
	}
	return (0);
}

/*
** Dispatches all the B64_ENCODING characters to match with the encrypted char.
*/

int				*dispatch_b64(char *str)
{
	int		i;
	int		j;
	int		*id;

	i = 0;
	id = ft_memalloc(sizeof(int) * ft_strlen(str) + 1);
	while (*str)
	{
		j = 0;
		while (j < 64)
		{
			if (*str == B64_ENCODING[j])
				id[i] = j;
			j++;
		}
		i++;
		str++;
	}
	return (id);
}

/*
** Flag checker, returns a unsigned char that will tell which flags have been 
** activated.
*/

t_base64		check_b64_flags(t_base64 base, char *flag)
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
