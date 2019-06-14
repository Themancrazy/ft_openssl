/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 15:54:05 by anjansse          #+#    #+#             */
/*   Updated: 2019/06/13 20:05:47 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void		read_file(char *filename, char **content)
{
	int		fd;
	struct	stat st;

	fd = open(filename, O_RDONLY);
	*content = NULL;
	stat(filename, &st);
	*content = (char *)mmap(*content, st.st_size, PROT_READ, MAP_PRIVATE,\
			fd, 0);
}
