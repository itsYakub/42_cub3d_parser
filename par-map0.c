/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par-map0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 07:34:01 by joleksia          #+#    #+#             */
/*   Updated: 2025/03/26 11:11:56 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	__par_extract_map(t_map *map, const char *filepath);

int	par_map_init(t_map *map, const char *filepath)
{
	if (!__par_extract_map(map, filepath))
	{
		return (0);
	}
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
	if (map->cell_data)
	{
		while (map->height--)
		{
			if (map->cell_data[map->height])
				free(map->cell_data[map->height]);
		}
		free(map->cell_data);
	}
	return (1);
}

static int	__par_extract_map(t_map *map, const char *filepath)
{
	char	*fc;
	int		fd;

	map = ft_memset(map, 0, sizeof(t_map));
	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		return (!printf("error: invalid filepath\n"));
	if (!par_map_ext(filepath))
	{
		close(fd);
		return (!printf("error: invalid extension\n"));
	}
	fc = par_readfile(fd);
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
