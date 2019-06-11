/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 16:01:22 by anjansse          #+#    #+#             */
/*   Updated: 2019/06/10 22:16:02 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE64_H
# define BASE64_H

# define POWER2(x) (x * (2 * 2))
# define E_B64_SIZE(x) ((x * 8) / 6)
# define D_B64_SIZE(x) 0
# define RIGHT_SHIFT(c) (c >> 2)
# define LEFT_SHIFT(c) (c & 63)
# define SHIFT(a, b, x, y) ((a & POWER2(8 - y) - 1) | (b >> x))
# define FLE 0x01
# define FLD 0x02
# define FLI 0x04
# define FLO 0x08

typedef struct			s_base64 {
	int					size;
	unsigned char		flag;
}						t_base64;

#endif
