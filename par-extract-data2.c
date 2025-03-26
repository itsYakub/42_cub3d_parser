/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par-extract-data2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 06:53:12 by joleksia          #+#    #+#             */
/*   Updated: 2025/03/26 11:00:35 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	par_parse_misc(t_map *map, char *s)
{
	par_check_current_fill(map, s);
	if (!ft_strncmp(s, "NO", 2))
		return (par_getpath(s + 2, &map->wall_no_file));
	else if (!ft_strncmp(s, "SO", 2))
		return (par_getpath(s + 2, &map->wall_so_file));
	else if (!ft_strncmp(s, "WE", 2))
		return (par_getpath(s + 2, &map->wall_we_file));
	else if (!ft_strncmp(s, "EA", 2))
		return (par_getpath(s + 2, &map->wall_ea_file));
	else if (!ft_strncmp(s, "F", 1))
		return (par_getcol(s + 1, map->color_floor));
	else if (!ft_strncmp(s, "C", 1))
		return (par_getcol(s + 1, map->color_ceiling));
	else if (par_line_empty(s))
		return (1);
	return (0);
}

int	par_parse_cell(t_map *map, char *s)
{
	if (!ft_strncmp(s, "NO", 2) || !ft_strncmp(s, "SO", 2)
		|| !ft_strncmp(s, "WE", 2) || !ft_strncmp(s, "EA", 2)
		|| !ft_strncmp(s, "F", 1) || !ft_strncmp(s, "C", 1)
		|| par_line_empty(s))
		return (0);
	map->cell_data = par_realloc(map->cell_data, ++map->height * sizeof(char *));
	map->cell_data[map->height - 1] = ft_strdup(s);
	return (1);
}

void	par_check_current_fill(t_map *map, char *s)
{
	map->misc_fill[0] = map->misc_fill[0] || !ft_strncmp(s, "NO", 2);
	map->misc_fill[1] = map->misc_fill[1] || !ft_strncmp(s, "SO", 2);
	map->misc_fill[2] = map->misc_fill[2] || !ft_strncmp(s, "WE", 2);
	map->misc_fill[3] = map->misc_fill[3] || !ft_strncmp(s, "EA", 2);
	map->misc_fill[4] = map->misc_fill[4] || !ft_strncmp(s, "F", 1);
	map->misc_fill[5] = map->misc_fill[5] || !ft_strncmp(s, "C", 1);
}

int	par_misc_filled(t_map *map)
{
	return (
		map->misc_fill[0]
		&& map->misc_fill[1]
		&& map->misc_fill[2]
		&& map->misc_fill[3]
		&& map->misc_fill[4]
		&& map->misc_fill[5]
	);
}
