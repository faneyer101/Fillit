/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_back.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: faneyer <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/24 02:52:29 by faneyer      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/28 19:16:42 by faneyer     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		ft_placement(t_tetri *box, char **map)
{
	int x;
	int y;
	int ox;
	int oy;

	y = box->omapy;
	oy = 0;
	while (((y - box->omapy) < (box->size_y)) && *map[y])
	{
		x = box->omapx;
		ox = 0;
		while ((x - box->omapx) < (box->size_x) && map[y][x])
		{
			if (box->content_tab[oy][ox] == '#')
				map[y][x] = box->lettre;
			x++;
			ox++;
		}
		y++;
		oy++;
	}
	return (0);
}

int		ft_tcheck_placement(t_tetri *box, char **map, int oy, int ox)
{
	int	x;
	int	y;

	y = 0;
	while (box->size_y > y)
	{
		x = 0;
		while (box->size_x > x)
		{
			if (box->content_tab[y][x] == '#' && map[oy + y][ox + x] != '.')
				return (-1);
			x++;
		}
		y++;
	}
	return (0);
}

int		ft_check_position(t_tetri *box, char **map)
{
	int	x;
	int	y;

	y = box->omapy;
	x = box->omapx;
	while (y < g_tools.len)
	{
		while (x < g_tools.len)
		{
			if (ft_tcheck_placement(box, map, y, x) == 0)
			{
				box->omapy = y;
				box->omapx = x;
				ft_placement(box, map);
				box->omapx++;
				return (0);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (-1);
}

void	ft_deltetri(t_tetri *box, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (*map[y] != '\0')
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == box->lettre)
				map[y][x] = '.';
			x++;
		}
		y++;
	}
}

int		ft_backtracking(t_tetri **list, char **map)
{
	while ((*list) != NULL)
	{
		if (ft_check_position((*list), map) != 0)
		{
			ft_ini((*list));
			if ((*list)->prev != NULL)
				(*list) = (*list)->prev;
			else
				return (-1);
			ft_deltetri((*list), map);
		}
		else
			(*list) = (*list)->next;
	}
	return (0);
}
