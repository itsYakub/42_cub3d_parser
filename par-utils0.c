/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par-utils0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 09:46:32 by joleksia          #+#    #+#             */
/*   Updated: 2025/03/27 10:52:03 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	*par_realloc(void *ptr, size_t size)
{
	void	*newptr;

	if (!ptr)
		return (malloc(size));
	newptr = malloc(size);
	if (!newptr)
		return (0);
	newptr = ft_memcpy(newptr, ptr, size);
	free(ptr);
	return (newptr);
}

char	*par_readfile(int fd, size_t flen)
{
	char	*fc;

	fc = (char *) malloc(flen + 1);
	if (!fc)
		return (0);
	if (read(fd, fc, flen) != (ssize_t) flen)
	{
		free(fc);
		return (0);
	}
	fc[flen] = 0;
	return (fc);
}

int	par_isspace(int c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	par_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

size_t	par_flen(const char *fpath)
{
	size_t	siz;
	char	c;
	int		fd;

	fd = open(fpath, O_RDONLY);
	siz = 0;
	while (read(fd, &c, 1))
		siz++;
	close(fd);
	return (siz);
}
