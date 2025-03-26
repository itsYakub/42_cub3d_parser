/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par-extract-data0.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 09:01:51 by joleksia          #+#    #+#             */
/*   Updated: 2025/03/26 08:55:51 by joleksia         ###   ########.fr       */
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
	if (par_misc_filled(map))
		map->parse_mode = PARSE_MODE_CELL;
	if (map->parse_mode == PARSE_MODE_MISC)
		return (par_parse_misc(map, line));
	else if (map->parse_mode == PARSE_MODE_CELL)
		return (par_parse_cell(map, line));
	else
		return (0);
	while (par_line_empty(line))
		return (1);
	map->parse_mode = PARSE_MODE_CELL;
	return (1);
}
