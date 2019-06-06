/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha256.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 11:42:56 by anjansse          #+#    #+#             */
/*   Updated: 2019/03/21 22:08:26 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SHA256_H
# define FT_SHA256_H

# include "ft_ssl.h"

typedef struct		s_sha256 {
	uint32_t		h[8];
	uint32_t		a[8];
	uint32_t		w[64];
	uint32_t		mod[4];
	uint32_t		tmp[4];
	char			*msg;
	char			*block_64;
}					t_sha256;

t_sha256			*sha256_prepare_om(char *str, t_sha256 *m);
t_sha256			*sha256_init_hash(t_sha256 *m, int max);
t_sha256			*sha256_create_block(t_sha256 *m, int start);
t_sha256			*sha256_reset_abcd(t_sha256 *m);
t_sha256			*sha256_update_abcd(t_sha256 *m);
t_sha256			*process_sha256(t_sha256 *m);
void				sha256_hash(char *str, int flag, char *fn);
void				sha224_hash(char *str, int flag, char *fn);
void				print_sha256(t_sha256 *m, int flag, char *fn);

uint32_t			sha256s0(uint32_t hash);
uint32_t			sha256s1(uint32_t hash);
uint32_t			sha256ss0(uint32_t hash);
uint32_t			sha256ss1(uint32_t hash);

#endif
