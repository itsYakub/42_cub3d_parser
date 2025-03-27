/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 07:46:08 by joleksia          #+#    #+#             */
/*   Updated: 2025/03/27 11:45:03 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	main(void)
{
	t_map	*map;
	char	*filepaths[] = {
		"example0.cub",
		"example-invalid0.cub",
		"example-invalid1.cub",
		"example1.cub",
		"example.c",
		"test.c",
		"example-invalid2.cub",
		"example-invalid3.cub",
		"example-invalid4.cub",
		0
	};

	for (int i = 0; filepaths[i]; i++) {
		printf("\033[1m---\033[0m\n");
		printf("\033[1m[ test %d. ]:\033[0m\n", i);
		map = par_map_init(filepaths[i]);
		if (!map)
		{
			printf("\033[31;1m[ test %d. ] Test failed\033[0m\n", i);
			continue;
		}
		printf("\033[32;1m[ test %d. ] Test passed\033[0m\n", i);
		printf("\033[1mSize:\t%d, %d\n", map->map_size[0], map->map_size[1]);
		printf("\033[1mSpawn:\t%d, %d\n", map->map_spawn[0], map->map_spawn[1]);
		par_map_unload(map);
	}

	printf("\033[1m---\033[0m\n");
	return (0);
}
