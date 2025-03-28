/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 07:46:08 by joleksia          #+#    #+#             */
/*   Updated: 2025/03/28 08:24:08 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	main(void)
{
	t_map	*map;
	char	*filepaths[] = {
		"./maps/example0.cub",
		"./maps/example1.cub",
		"./maps/example-inv-misc-after-cell.cub",
		"./maps/example-inv-hole-in-map.cub",
		"./maps/example-inv-characters.cub",
		"./maps/example-inv-multiple-spawn.cub",
		"./maps/example-inv-no-spawn.cub",
		"./maps/example-inv-hole-in-middle.cub",
		"./maps/example-inv-empty.cub",
		"./maps/example-inv-extension.c",
		"./test.c",
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
