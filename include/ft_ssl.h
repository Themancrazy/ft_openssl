/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 10:16:02 by anjansse          #+#    #+#             */
/*   Updated: 2019/06/13 20:57:05 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/includes/libft.h"
# include "ft_md5.h"
# include "ft_sha256.h"
# include "ft_sha512.h"
# include "base64.h"

# define FLS 0x01
# define FLQ 0x02
# define FLP 0x04
# define FLR 0x08

# define CMD 9

# define ROTR(x, n, w) ((x >> n) | (x << (w - n)))
# define ROTL(x, n, w) ((x << n) | (x >> (w - n)))

typedef void		(t_hash_disp)(int, char **);

typedef struct		s_dis {
	char			*name;
	t_hash_disp		*hash;
}					t_dis;

typedef struct		s_ssl {
	int				i;
	int				ac;
	char			**av;
	unsigned char	fl;
}					t_ssl;

t_ssl				*handle_flags(t_ssl *s);
char				*handle_files(t_ssl *s, int fd);
void				handle_str(t_ssl *s, char *sol, char *type);
void				dispatcher(int argc, char **argv);
void				handle_stdin(void);
void				process_stdio_cmd(void);
uint32_t			swap_endian(uint32_t num);
uint64_t			swap_endian64(uint64_t x);
void				send_error(char *error);

void				ssl_md5(int argc, char **argv);
void				ssl_sha224(int argc, char **argv);
void				ssl_sha256(int argc, char **argv);
void				ssl_sha384(int argc, char **argv);
void				ssl_sha512(int argc, char **argv);

void				base64(int argc, char **argv);
void				des(int argc, char **argv);
void				des_cbc(int argc, char **argv);
void				des_ecb(int argc, char **argv);

#endif
