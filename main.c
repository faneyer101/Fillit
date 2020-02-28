/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pitirard <pitirard@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/16 15:36:59 by faneyer      #+#   ##    ##    #+#       */
/*   Updated: 2019/02/06 15:08:10 by faneyer     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void	ft_free_map(char **map)
{
	int i;

	if (map)
	{
		i = 0;
		while (i <= g_tools.len)
		{
			free(map[i]);
			i++;
		}
		free(map);
	}
}

void	ft_norm(char ***map, t_tetri **list, t_tetri **begin_list)
{
	ft_free_map((*map));
	(*map) = fill_tab(list, (*map));
	*list = *begin_list;
	while (*list != NULL)
	{
		ft_ini(*list);
		*list = (*list)->next;
	}
	*list = *begin_list;
}

void	ft_free_lst(t_tetri **lst, char **map)
{
	t_tetri	*tmp;
	int		i;

	if (*lst)
	{
		while ((*lst) != NULL)
		{
			i = -1;
			tmp = (*lst)->next;
			while ((*lst)->content_tab[++i])
				free((*lst)->content_tab[i]);
			free((*lst)->content_tab);
			free(*lst);
			*lst = tmp;
		}
	}
	ft_free_map(map);
}

void	ft_display_map(t_tetri **list, char **map)
{
	int	i;

	i = 0;
	while (g_tools.len > i)
	{
		ft_putendl(map[i]);
		i++;
	}
	ft_free_lst(list, map);
}

int		main(int argc, char **argv)
{
	t_tetri	*list;
	t_tetri	*begin_list;
	char	**map;

	map = NULL;
	if (argc == 2)
	{
		list = NULL;
		if ((ft_read(argv[1], &list)) == -1)
		{
			ft_putendl("error");
			ft_free_lst(&list, map);
			return (1);
		}
		begin_list = list;
		map = fill_tab(&list, map);
		while (ft_backtracking(&list, map) != 0)
			ft_norm(&map, &list, &begin_list);
		list = begin_list;
		ft_display_map(&list, map);
	}
	else
		ft_putendl("usage: fillit source_file");
	return (0);
}
