/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 07:46:08 by joleksia          #+#    #+#             */
/*   Updated: 2025/03/26 11:12:52 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	main(void)
{
	t_map	map;
	char	*filepaths[] = {
		"example0.cub",
		"example-invalid0.cub",
		"example-invalid1.cub",
		"example1.cub",
		"example.c",
		"test.c",
		0
	};

	for (int i = 0; filepaths[i]; i++) {
		printf("\033[1m---\033[0m\n");
		printf("\033[1m[ test %d. ]:\033[0m\n", i);
		if (!par_map_init(&map, filepaths[i]))
		{
			printf("\033[31;1m[ test %d. ] Test failed\033[0m\n", i);
			continue;
		}
		printf("\033[32;1m[ test %d. ] Test passed\033[0m\n", i);
		printf("NO:\t%s\n", map.wall_no_file);
		printf("SO:\t%s\n", map.wall_so_file);
		printf("WE:\t%s\n", map.wall_we_file);
		printf("EA:\t%s\n", map.wall_ea_file);
		printf("F:\t%i, %i, %i\n", map.color_floor[0], map.color_floor[1], map.color_floor[2]);
		printf("C:\t%i, %i, %i\n", map.color_ceiling[0], map.color_ceiling[1], map.color_ceiling[2]);
		printf("Map:\n");
		for (int j = 0; j < (int) map.height; j++) {
			printf("%s\n", map.cell_data[j]);
		}
		par_map_unload(&map);
	}

	printf("\033[1m---\033[0m\n");
	return (0);
}
