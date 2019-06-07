/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 16:01:22 by anjansse          #+#    #+#             */
/*   Updated: 2019/06/06 16:11:12 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE64_H
# define BASE64_H

# define B64_SIZE(x) ((x * 8) / 6)

typedef struct			s_base64 {
	int					size;
}						t_base64;

#endif
