/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par-extract-data0.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 09:01:51 by joleksia          #+#    #+#             */
/*   Updated: 2025/03/21 11:01:02 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	par_extract(t_map *map, const char *s)
{
	char	*current_line;

	(void) map;
	current_line = par_sgetline(s);
	if (!current_line)
		return (!par_map_unload(map));
	s += ft_strlen(current_line) + 1;
	while (*s)
	{
		if (!par_process_line(map, current_line))
		{
			free(current_line);
			return (!par_map_unload(map));
		}
		free(current_line);
		current_line = par_sgetline(s);
		if (!current_line)
			return (!par_map_unload(map));
		s += ft_strlen(current_line) + 1;
	}
	free(current_line);
	return (1);
}

int	par_process_line(t_map *map, char *line)
{
	if (!ft_strncmp(line, "NO", 2))
		return (par_getpath(line + 2, &map->wall_no_file));
	else if (!ft_strncmp(line, "SO", 2))
		return (par_getpath(line + 2, &map->wall_so_file));
	else if (!ft_strncmp(line, "WE", 2))
		return (par_getpath(line + 2, &map->wall_we_file));
	else if (!ft_strncmp(line, "EA", 2))
		return (par_getpath(line + 2, &map->wall_ea_file));
	else if (!ft_strncmp(line, "F", 1))
		return (par_getcol(line + 1, map->color_floor));
	else if (!ft_strncmp(line, "C", 1))
		return (par_getcol(line + 1, map->color_ceiling));
	else
		printf("Something different!\n");
	return (0);
}
