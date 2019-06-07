/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 14:44:17 by anjansse          #+#    #+#             */
/*   Updated: 2019/06/07 13:33:17 by anjansse         ###   ########.fr       */
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

void			base64(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	int				i;
	int				j;
	int				x;
	unsigned char	pi;
	t_base64	base;

	get_binary(argv[0]);
	i = -1;
	j = 2;
	x = 0;
	base.size = B64_SIZE(ft_strlen(argv[0]));
	printf("SIZE IS %d\n", base.size);
	char test[base.size];
	ft_printf(CYAN"BEFORE-> %s\n"RESET, argv[0]);
	while (++i < base.size)
	{
		//ft_memcpy(&pi, &argv[0], 2);
		pi = 0;
		ft_printf("%d. AT THIS TURN AV IS \x1b[91m%08b\n"RESET, i, argv[0][x]);
		if (j == 8)
			j = 2;
		pi |= argv[0][x] >> j;
		ft_printf("%d. \x1b[92mJ = %d\x1b[0m\tBEFORE THIS TURN PI IS %06b\n", i, j, pi);
		if (x - 1 > 0 && j != 2)
			pi |= argv[0][x - 1] << (8 - j);
		//ft_printf("AT THIS TURN PI IS %06b\n", pi);
		//ft_memmove(&argv[0], &argv[0], j);
		test[i] = base64_encoding[pi];
		if (x != ft_strlen(argv[0]))
			x++;
		j += 2;
		ft_printf("%d. AFTER THIS TURN PI IS \x1b[93m\x1b[1m%06b\n\x1b[0m", i, pi);
	}
	ft_printf(CYAN"AFTER-> %s\n"RESET, test);
}
