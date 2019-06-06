/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 12:39:42 by anjansse          #+#    #+#             */
/*   Updated: 2019/03/21 21:52:59 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"

uint32_t	sha256ss0(uint32_t hash)
{
	return ((ROTR(hash, 2, 32)) ^ (ROTR(hash, 13, 32)) ^ (ROTR(hash, 22, 32)));
}

uint32_t	sha256ss1(uint32_t hash)
{
	return ((ROTR(hash, 6, 32)) ^ (ROTR(hash, 11, 32)) ^ (ROTR(hash, 25, 32)));
}

uint32_t	sha256s0(uint32_t hash)
{
	return ((ROTR(hash, 7, 32)) ^ (ROTR(hash, 18, 32)) ^ (hash >> 3));
}

uint32_t	sha256s1(uint32_t hash)
{
	return ((ROTR(hash, 17, 32)) ^ (ROTR(hash, 19, 32)) ^ (hash >> 10));
}
