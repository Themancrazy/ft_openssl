/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha512.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 11:42:56 by anjansse          #+#    #+#             */
/*   Updated: 2019/03/22 07:31:01 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SHA512_H
# define FT_SHA512_H

# include "ft_ssl.h"

typedef struct		s_sha512 {
	uint64_t		h[8];
	uint64_t		a[8];
	uint64_t		w[80];
	uint64_t		mod[4];
	uint64_t		tmp[4];
	char			*msg;
	char			*block_128;
}					t_sha512;

t_sha512			*sha512_prepare_om(char *str, t_sha512 *m);
t_sha512			*sha512_init_hash(t_sha512 *m, int max);
t_sha512			*sha512_create_block(t_sha512 *m, int start);
t_sha512			*sha512_reset_abcd(t_sha512 *m);
t_sha512			*sha512_update_abcd(t_sha512 *m);
t_sha512			*process_sha512(t_sha512 *m);
void				sha384_hash(char *str, int flag, char *fn);
void				sha512_hash(char *str, int flag, char *fn);
void				print_sha512(t_sha512 *m, int flag, char *fn);
void				print_sha384(t_sha512 *m, int flag, char *fn);

uint64_t			sha512s0(uint64_t hash);
uint64_t			sha512s1(uint64_t hash);
uint64_t			sha512ss0(uint64_t hash);
uint64_t			sha512ss1(uint64_t hash);

#endif
