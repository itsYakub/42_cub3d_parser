/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par-map1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 07:48:04 by joleksia          #+#    #+#             */
/*   Updated: 2025/03/21 08:51:32 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "parser.h"

int	par_map_ext(const char *filepath)
{
	char	*ext;
	int		cmp;

	ext = ft_strrchr(filepath, '.');
	if (!ext)
		return (0);
	cmp = ft_strncmp(ext, PAR_F_EXT, ft_strlen(PAR_F_EXT));
	return (!cmp);
}
