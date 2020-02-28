/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_checkerror.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pitirard <pitirard@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/19 14:28:11 by faneyer      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/24 05:33:42 by faneyer     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int	check_block(char *tetri)
{
	int	i;
	int	link;

	i = 0;
	link = 0;
	while (tetri[i] && i < 20)
	{
		if (tetri[i] == '#')
		{
			if (i < 19 && tetri[i + 1] == '#')
				link++;
			if (i > 0 && tetri[i - 1] == '#')
				link++;
			if (i > 4 && tetri[i - 5] == '#')
				link++;
			if (i < 16 && tetri[i + 5] == '#')
				link++;
		}
		i++;
	}
	if (link == 6 || link == 8)
		return (0);
	return (-1);
}

int	ft_checkerror(char *tetri)
{
	int		block;
	int		point;
	int		line;
	int		i;

	block = 0;
	point = 0;
	line = 0;
	i = 0;
	while (i < 20)
	{
		if (tetri[0] == '\n')
			return (-1);
		else if (tetri[i] == '#')
			block++;
		else if (tetri[i] == '.')
			point++;
		else if (tetri[i] == '\n' && (i / (line + 1)) == 4)
			line++;
		i++;
	}
	if (block != 4 || point != 12 || line != 4)
		return (-1);
	return (check_block(tetri));
}
