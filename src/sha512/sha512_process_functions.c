/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 12:39:42 by anjansse          #+#    #+#             */
/*   Updated: 2019/03/21 21:52:06 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"

uint64_t	sha512ss0(uint64_t hash)
{
	return ((ROTR(hash, 28, 64)) ^ (ROTR(hash, 34, 64)) ^ (ROTR(hash, 39, 64)));
}

uint64_t	sha512ss1(uint64_t hash)
{
	return ((ROTR(hash, 14, 64)) ^ (ROTR(hash, 18, 64)) ^ (ROTR(hash, 41, 64)));
}

uint64_t	sha512s0(uint64_t hash)
{
	return ((ROTR(hash, 1, 64)) ^ (ROTR(hash, 8, 64)) ^ (hash >> 7));
}

uint64_t	sha512s1(uint64_t hash)
{
	return ((ROTR(hash, 19, 64)) ^ (ROTR(hash, 61, 64)) ^ (hash >> 6));
}
