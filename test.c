/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 07:46:08 by joleksia          #+#    #+#             */
/*   Updated: 2025/03/21 10:44:23 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	main(void)
{
	t_map	map;

	if (!par_map_init(&map, "example.cub"))
		return (1);
	printf("NO: %s\n", map.wall_no_file);
	printf("SO: %s\n", map.wall_so_file);
	printf("WE: %s\n", map.wall_we_file);
	printf("EA: %s\n", map.wall_ea_file);
	printf("F: %i %i %i\n", map.color_floor[0], map.color_floor[1], map.color_floor[2]);
	printf("C: %i %i %i\n", map.color_ceiling[0], map.color_ceiling[1], map.color_ceiling[2]);
	par_map_unload(&map);
	return (0);
}
