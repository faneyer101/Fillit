/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_create_elem.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pitirard <pitirard@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/25 18:32:34 by faneyer      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/30 17:43:36 by pitirard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		ft_len_tetrix(char **tetri)
{
	int	len;
	int	y;
	int	x;
	int	save;

	len = 0;
	y = 0;
	while (tetri[y] != '\0' && y < 3)
	{
		x = 0;
		save = 0;
		while (tetri[y][x] != '\0')
		{
			if (tetri[y][x] == '#' ||
				(tetri[y][x] == '.' && tetri[y + 1][x] == '#'))
				save++;
			x++;
		}
		y++;
		if (len < save)
			len = save;
	}
	return (len);
}

void	ft_size_tetri(t_tetri *box)
{
	int	x;
	int	y;
	int sizey;

	sizey = 0;
	y = 0;
	box->size_x = ft_len_tetrix(box->content_tab);
	while (box->content_tab[y] != '\0')
	{
		x = 0;
		while (box->content_tab[y][x] != '\0')
		{
			if (box->content_tab[y][x] == '#' && box->size_y <= sizey)
				box->size_y = sizey + 1;
			x++;
		}
		sizey++;
		y++;
	}
}

void	ft_ini(t_tetri *box)
{
	box->omapx = 0;
	box->omapy = 0;
}

t_tetri	*ft_create_elem(char *s)
{
	t_tetri		*box;
	char		c;
	static int	i;

	c = 65 + i;
	box = NULL;
	box = (t_tetri*)malloc(sizeof(t_tetri));
	if (box == NULL)
		return (box);
	box->content_tab = ft_strsplit(s, '\n');
	ft_switch_x(box);
	ft_switch_y(box->content_tab);
	box->lettre = c;
	box->next = NULL;
	box->prev = NULL;
	box->size_x = 0;
	box->size_y = 0;
	ft_ini(box);
	ft_size_tetri(box);
	i += 1;
	return (box);
}
