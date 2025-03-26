/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par-utils0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 09:46:32 by joleksia          #+#    #+#             */
/*   Updated: 2025/03/26 10:59:39 by joleksia         ###   ########.fr       */
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

char	*par_readfile(int fd)
{
	char	*fc0;
	int		i;
	char	c;

	fc0 = malloc(0);
	if (!fc0)
		return (0);
	c = par_fgetc(fd);
	i = 0;
	while (c)
	{
		fc0 = par_realloc(fc0, ++i);
		if (!fc0)
			return (0);
		fc0[i - 1] = c;
		c = par_fgetc(fd);
	}
	return (fc0);
}

int	par_isspace(int c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}
