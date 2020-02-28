/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_switch.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pitirard <pitirard@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/24 04:40:09 by faneyer      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/31 15:03:41 by pitirard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		getcount_y(char **content_tab)
{
	int	x;
	int	y;

	y = 0;
	while (*content_tab[y])
	{
		x = 0;
		while (content_tab[y][x])
		{
			if (content_tab[y][x] == '#')
				return ((y * 4) + x);
			x++;
		}
		y++;
	}
	return (0);
}

void	ft_swap_tab(char **tmp, char **content_tab)
{
	*tmp = content_tab[0];
	content_tab[0] = content_tab[2];
	content_tab[2] = *tmp;
	*tmp = content_tab[1];
	content_tab[1] = content_tab[3];
	content_tab[3] = *tmp;
}

void	ft_switch_y(char **content_tab)
{
	int		x;
	int		y;
	int		c;
	char	*tmp;

	x = 0;
	c = getcount_y(content_tab);
	y = -1;
	if (c > 3 && c < 8)
	{
		tmp = content_tab[0];
		while (++y < 3)
			content_tab[y] = content_tab[y + 1];
		content_tab[3] = tmp;
	}
	else if (c > 7 && c < 12)
	{
		ft_swap_tab(&tmp, content_tab);
	}
	else if (c >= 12)
	{
		tmp = content_tab[0];
		content_tab[0] = content_tab[3];
		content_tab[3] = tmp;
	}
}

int		getcount_x(t_tetri *box)
{
	int	x;
	int	y;

	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			if (box->content_tab[y][x] == '#')
				return (x);
			y++;
		}
		x++;
	}
	return (0);
}

void	ft_switch_x(t_tetri *box)
{
	int	x;
	int	y;
	int	c;

	y = 0;
	c = getcount_x(box);
	x = 0;
	while (c < 4 && c > 0)
	{
		y = 0;
		while (y < 4)
		{
			box->content_tab[y][x] = box->content_tab[y][c];
			box->content_tab[y][c] = '.';
			y++;
		}
		c++;
		x++;
	}
}
