/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par-map0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 07:34:01 by joleksia          #+#    #+#             */
/*   Updated: 2025/03/21 10:45:29 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	*__par_realloc(void *ptr, size_t size);
static char	*__par_readfile(int fd);

int	par_map_init(t_map *map, const char *filepath)
{
	char	*fc;
	int		fd;

	map = ft_memset(map, 0, sizeof(t_map));
	if (!par_map_ext(filepath))
		return (!printf("error: invalid extension\n"));
	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		return (!printf("error: invalid filepath\n"));
	fc = __par_readfile(fd);
	close (fd);
	if (!fc)
		return (!printf("error: readfile error\n"));
	if (!par_extract(map, fc))
	{
		free(fc);
		return (!printf("error: extract error\n"));
	}
	free(fc);
	return (1);
}

int	par_map_unload(t_map *map)
{
	if (map->wall_no_file)
		free(map->wall_no_file);
	if (map->wall_so_file)
		free(map->wall_so_file);
	if (map->wall_we_file)
		free(map->wall_we_file);
	if (map->wall_ea_file)
		free(map->wall_ea_file);
	return (1);
}

static void	*__par_realloc(void *ptr, size_t size)
{
	void	*newptr;

	newptr = malloc(size);
	if (!newptr)
		return (0);
	newptr = ft_memcpy(newptr, ptr, size);
	free(ptr);
	return (newptr);
}

static char	*__par_readfile(int fd)
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
		fc0 = __par_realloc(fc0, ++i);
		if (!fc0)
			return (0);
		fc0[i - 1] = c;
		c = par_fgetc(fd);
	}
	return (fc0);
}
