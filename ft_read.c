/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_read.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pitirard <pitirard@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/16 16:27:03 by faneyer      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/31 14:04:42 by pitirard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		ft_read(char *av, t_tetri **list)
{
	char	buff[21];
	int		fd;
	int		ret;
	int		i;

	i = 0;
	if ((fd = open(av, O_RDONLY)) == -1)
		return (-1);
	if (fd == -1 || read(fd, buff, 0) > 0)
		return (-1);
	while ((ret = read(fd, buff, 21)) > 0)
	{
		buff[ret] = '\0';
		if (ft_checkerror(buff) == -1 || i > 26)
			return (-1);
		else
			push_back_list(list, buff);
		i++;
	}
	g_tools.nbpieces = i;
	if ((ret == 0 && i == 0) || ft_strlen(buff) > 20)
		return (-1);
	if (close(fd) == -1)
		return (-1);
	return (0);
}
