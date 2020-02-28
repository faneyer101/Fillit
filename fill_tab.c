/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fill_tab.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pitirard <pitirard@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/22 19:29:41 by pitirard     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/30 17:43:03 by pitirard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

char	**create_map(char **map)
{
	int	x;
	int	y;

	y = -1;
	while (++y < g_tools.len)
	{
		x = -1;
		while (++x < g_tools.len)
			map[y][x] = '.';
		map[y][x] = '\0';
	}
	map[y][0] = 0;
	return (map);
}

char	**fill_tab(t_tetri **list, char **map)
{
	static int	i;
	int			size;

	map = NULL;
	if (list && i == 0)
	{
		g_tools.len = ft_sqrt2(4 * g_tools.nbpieces);
		i = 1;
	}
	else
		g_tools.len += 1;
	if (!(map = (char**)malloc(sizeof(char*) * (g_tools.len + 1))))
		return (NULL);
	size = 0;
	while (size < (g_tools.len))
	{
		if (!(map[size] = ft_strnew(g_tools.len)))
			return (NULL);
		size++;
	}
	map[size] = ft_strdup("");
	map = create_map(map);
	return (map);
}
