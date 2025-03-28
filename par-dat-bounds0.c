/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par-dat-bounds0.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 08:05:10 by joleksia          #+#    #+#             */
/*   Updated: 2025/03/28 08:16:58 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
 *	111111
 *	 100001
 *	 111111
 * */

int	par_left_bound(t_dat *dat)
{
	int	x;
	int	y;

	y = -1;
	while (++y < (int) dat->height)
	{
		x = -1;
		while (dat->cell_data[y][++x])
		{
			if (dat->cell_data[y][x] == '0')
				return (!printf("error: open bound (l. %d,%d)\n", x, y));
			else if (ft_strchr("1", dat->cell_data[y][x]))
				break ;
		}
	}
	return (1);
}

int	par_right_bound(t_dat *dat)
{
	int	x;
	int	y;

	y = -1;
	while (++y < (int) dat->height)
	{
		x = ft_strlen(dat->cell_data[y]);
		while (x-- > 0)
		{
			if (dat->cell_data[y][x] == '0')
				return (!printf("error: open bound (r. %d,%d)\n", x, y));
			else if (ft_strchr("1", dat->cell_data[y][x]))
				break ;
		}
	}
	return (1);
}

int	par_top_bound(t_dat *dat)
{
	int	x;
	int	y;

	x = -1;
	while (dat->cell_data[0][++x] != 0)
	{
		y = -1;
		while (++y < (int) dat->height)
		{
			if (dat->cell_data[y][x] == '0')
				return (!printf("error: open bound (t. %d,%d)\n", x, y));
			else if (ft_strchr("1", dat->cell_data[y][x]))
				break ;
		}
	}
	return (1);
}

int	par_down_bound(t_dat *dat)
{
	int	x;
	int	y;

	x = -1;
	while (dat->cell_data[dat->height - 1][++x] != 0)
	{
		y = (int) dat->height;
		while (y-- > 0)
		{
			if (dat->cell_data[y][x] == '0')
				return (!printf("error: open bound (d. %d,%d)\n", x, y));
			else if (ft_strchr("1", dat->cell_data[y][x]))
				break ;
		}
	}
	return (1);
}
