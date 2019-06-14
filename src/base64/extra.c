/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 21:16:01 by anjansse          #+#    #+#             */
/*   Updated: 2019/06/13 23:08:14 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>
#include "../../include/base64.h"

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
		size = ((ft_strlen(str) - extra_pad(str)) * 6) / 8;
	}
	return (0);
}

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

char				*pad_end(char *str, int pad)
{
	if (pad == 0)
		str = ft_strjoin(str, "=");
	else if (pad == 2)
		str = ft_strjoin(str, "==");
	return (str);
}
