/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 07:22:12 by joleksia          #+#    #+#             */
/*   Updated: 2025/03/21 10:27:42 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

/*	SECTION:
 *		Macro definitions
 * */

# ifndef PAR_F_EXT
#  define PAR_F_EXT ".cub"
# endif

/*	SECTION:
 *		Include headers
 * */

# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "libft/libft.h"

/*	SECTION:
 *		Type definitions
 * */

typedef float			t_vec2[2];
typedef int				t_vec2i[2];
typedef float			t_vec3[3];
typedef int				t_vec3i[3];
typedef float			t_vec4[4];
typedef int				t_vec4i[4];

typedef struct s_map
{
	char	*wall_no_file;
	char	*wall_so_file;
	char	*wall_we_file;
	char	*wall_ea_file;
	t_vec3i	color_floor;
	t_vec3i	color_ceiling;
}	t_map;

/*	SECTION:
 *		Function declarations
 * */

/* ./par-map0.c ./par-map1.c */
int		par_map_init(t_map *map, const char *filepath);
int		par_map_unload(t_map *map);
int		par_map_ext(const char *filepath);

/* ./par-fgetc.c */
char	par_fgetc(int fd);
char	*par_sgetline(const char *s);

/* ./par-extract-data0.c ./par-extract-data1.c */
int		par_extract(t_map *map, const char *s);
int		par_process_line(t_map *map, char *line);
int		par_getpath(char *s, char **dst);
int		par_getcol(char *s, t_vec3i dst);

#endif /* PARSER_H */
