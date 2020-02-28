/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pitirard <pitirard@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/14 16:08:57 by pitirard     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/06 15:08:37 by faneyer     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "./libft/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct		s_tetri
{
	char			**content_tab;
	int				omapx;
	int				omapy;
	int				size_x;
	int				size_y;
	char			lettre;
	struct s_tetri	*prev;
	struct s_tetri	*next;
}					t_tetri;

typedef	struct		s_tool
{
	int				nbpieces;
	int				len;
}					t_tool;

t_tool				g_tools;

void				ft_ini(t_tetri *box);
t_tetri				*ft_create_elem(char *s);
int					ft_read(char *av, t_tetri **list);
void				push_back_list(t_tetri **begin_list, char *str);
int					ft_checkerror(char *tetri);
char				**fill_tab(t_tetri	**list, char **map);
int					ft_strclen(char *str, char c);
int					ft_backtracking(t_tetri **list, char **map);
void				ft_switch_x(t_tetri *box);
void				ft_switch_y(char **content_tab);

#endif
