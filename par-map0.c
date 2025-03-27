/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par-map0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 07:09:39 by joleksia          #+#    #+#             */
/*   Updated: 2025/03/27 10:06:43 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	__par_map_siz(t_dat dat, t_vec2i dst);
static int	__par_map_playerspawn(t_dat dat, t_vec2i dst);

t_map	*par_map_init(const char *file)
{
	t_dat	dat;
	t_map	*map;

	if (!par_dat_init(&dat, file))
		return (0);
	map = (t_map *) ft_calloc(1, sizeof(t_map));
	if (!map)
	{
		par_dat_unload(&dat);
		return (0);
	}
	__par_map_siz(dat, map->map_size);
	__par_map_playerspawn(dat, map->map_spawn);
	par_dat_unload(&dat);
	return (map);
}

int	par_map_unload(t_map *map)
{
	if (!map)
		return (0);
	if (map->cell)
	{
		while (map->map_size[1]--)
			free(map->cell[map->map_size[1]]);
		free(map->cell);
	}
	free(map);
	return (1);
}

static int	__par_map_siz(t_dat dat, t_vec2i dst)
{
	int	i;

	dst[1] = dat.height;
	i = -1;
	while (++i < (int) dat.height)
		dst[0] = par_max(ft_strlen(dat.cell_data[i]), dst[0]);
	return (1);
}

static int	__par_map_playerspawn(t_dat dat, t_vec2i dst)
{
	int	i;
	int	j;

	i = -1;
	while (++i < (int) dat.height)
	{
		j = -1;
		while (dat.cell_data[i][++j])
		{
			if (ft_strchr("NSWE", dat.cell_data[i][j]))
			{
				dst[0] = j;
				dst[1] = i;
				return (1);
			}
		}
	}
	return (0);
}
