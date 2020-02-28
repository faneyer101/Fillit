/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_push_back_list.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pitirard <pitirard@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/25 18:32:44 by faneyer      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/14 15:34:27 by pitirard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void	push_back_list(t_tetri **begin_list, char *str)
{
	t_tetri	*list;
	t_tetri	*tmp;

	list = *begin_list;
	tmp = list;
	if (list)
	{
		while (list->next)
		{
			list = list->next;
			tmp = list;
		}
		list->next = ft_create_elem(str);
		list = list->next;
		list->prev = tmp;
	}
	else
		*begin_list = ft_create_elem(str);
}
