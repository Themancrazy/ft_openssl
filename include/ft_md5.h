/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 20:18:01 by anjansse          #+#    #+#             */
/*   Updated: 2019/03/21 22:04:58 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MD5_H
# define FT_MD5_H

# include "ft_ssl.h"

typedef struct		s_md5 {
	uint32_t		abcd[4];
	uint32_t		abcd0[4];
	uint32_t		w[16];
	char			*msg;
	char			*block_64;
	uint32_t		fg[2];
}					t_md5;

uint32_t			max_size(uint32_t n);
uint64_t			max_size64(uint64_t n);
void				print_md5(t_md5 *m, int flag, char *fn);
void				md5_hash(char *str, int flag, char *fn);
t_md5				*prepare_om(char *str, t_md5 *m);
t_md5				*init_hash(t_md5 *m, int max);
t_md5				*md5_shift(t_md5 *m, int i);
t_md5				*process_md5(t_md5 *m, int max);
t_md5				*update_abcd(t_md5 *m);
t_md5				*reset_abcd(t_md5 *m);
t_md5				*create_block(t_md5 *m, int start);

uint32_t			md5leftrotate(uint32_t f, int n);
t_md5				*md5f(t_md5 *m, int i);
t_md5				*md5g(t_md5 *m, int i);
t_md5				*md5h(t_md5 *m, int i);
t_md5				*md5i(t_md5 *m, int i);

#endif
