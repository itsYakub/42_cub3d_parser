/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par-dat1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 07:48:04 by joleksia          #+#    #+#             */
/*   Updated: 2025/03/28 07:01:49 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "parser.h"

int	par_dat_ext(const char *filepath)
{
	char	*ext;
	int		cmp;

	ext = ft_strrchr(filepath, '.');
	if (!ext)
		return (0);
	cmp = ft_strncmp(ext, PAR_F_EXT, ft_strlen(PAR_F_EXT));
	return (!cmp);
}

int	par_dat_inv_char(t_dat *dat)
{
	t_vec2i	i;

	i[1] = -1;
	while (++i[1] < (int) dat->height)
	{
		i[0] = -1;
		while (dat->cell_data[i[1]][++i[0]])
		{
			if (!ft_strchr("NESW01 ", dat->cell_data[i[1]][i[0]]))
				return (!printf("error: invalid character\n"));
		}
	}
	return (1);
}

int	par_dat_spawn_present(t_dat *dat)
{
	t_vec2i	i;
	int		scnt;

	scnt = 0;
	i[1] = -1;
	while (++i[1] < (int) dat->height)
	{
		i[0] = -1;
		while (dat->cell_data[i[1]][++i[0]])
		{
			if (ft_strchr("NESW", dat->cell_data[i[1]][i[0]]))
				scnt++;
		}
	}
	if (!scnt)
		printf("error: no spawn points\n");
	else if (scnt != 1)
		printf("error: more than one spawn points\n");
	return (scnt);
}

int	par_dat_check_spaces(t_dat *dat)
{
	t_vec2i	i;

	i[1] = -1;
	while (++i[1] < (int) dat->height)
	{
		i[0] = -1;
		while (dat->cell_data[i[1]][++i[0]])
		{
			if (dat->cell_data[i[1]][i[0]] == 32)
			{
				if ((i[0] > 0
						&& ft_strchr("0NEWS", dat->cell_data[i[1]][i[0] - 1]))
					|| (i[0] + 1 != 0
						&& ft_strchr("0NEWS", dat->cell_data[i[1]][i[0] + 1]))
					|| (i[1] > 0
						&& ft_strchr("0NEWS", dat->cell_data[i[1] - 1][i[0]]))
					|| (i[1] < (int) dat->height - 1
						&& ft_strchr("0NEWS", dat->cell_data[i[1] + 1][i[0]])))
					return (!printf("error: hole in the map\n"));
			}
		}
	}
	return (1);
}
