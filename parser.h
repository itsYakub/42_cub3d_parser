/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 07:22:12 by joleksia          #+#    #+#             */
/*   Updated: 2025/03/26 09:53:21 by joleksia         ###   ########.fr       */
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

typedef enum e_parse_mode
{
	PARSE_MODE_MISC = 0,
	PARSE_MODE_CELL
}	t_parse_mode;

typedef struct s_map
{
	t_parse_mode	parse_mode;
	/* misc. part */
	int				misc_fill[6];
	char			*wall_no_file;
	char			*wall_so_file;
	char			*wall_we_file;
	char			*wall_ea_file;
	t_vec3i			color_floor;
	t_vec3i			color_ceiling;
	/* cell part */
	char			**cell_data;
	unsigned int	height;
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

/* ./par-extract-data0.c ./par-extract-data1.c ./par-extract-data2.c */
int		par_extract(t_map *map, const char *s);
int		par_process_line(t_map *map, char *line);
int		par_getpath(char *s, char **dst);
int		par_getcol(char *s, t_vec3i dst);
int		par_line_empty(char *s);
int		par_parse_misc(t_map *map, char *s);
int		par_parse_cell(t_map *map, char *s);
void	par_check_current_fill(t_map *map, char *s);
int		par_misc_filled(t_map *map);

/* ./par-utils0.c */
void	*par_realloc(void *ptr, size_t size);
char	*par_readfile(int fd);
int		par_isspace(int c);

#endif /* PARSER_H */
