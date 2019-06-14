/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 21:16:01 by anjansse          #+#    #+#             */
/*   Updated: 2019/06/13 22:07:20 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>
#include "../../include/base64.h"

int			get_size(char *str, char c)
{
	int		size;

	size = ft_strlen(str) * 8;
	if (c == 'e')
	{
		if (size % 6 != 0)
			return ((size / 6) + 1);
		else if (size % 6 == 0)
			return ((size / 6));
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
