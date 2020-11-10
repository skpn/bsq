/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 16:19:44 by edbaudou          #+#    #+#             */
/*   Updated: 2019/02/27 22:30:47 by sikpenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>

typedef struct		s_var
{
	int		pos_sq;
	int		value;
	int		line_max;
	int		back_n;
	char	char_empty;
	char	char_obstacle;
	char	char_filled;
	int		line_size;
	int		bomb_number;
}					t_var;

void				ft_initialize(int *tab, int size);
void				ft_putchar(char c);
void				ft_putstr(char *str);
int					ft_atoi(char *str);
int					ft_strlen(char *str);
void				ft_putnbr(int nb);
int					*ft_realloc(int *str, int new_size);
int					*ft_strcpy(int *dest, int *srcs);
int					*ft_read_file(t_var *map_info, int fd, int *bomb);
int					ft_read_from_args(int fd, t_var *v_max, int pos, int res);
void				ft_print_line();
void				ft_print_map(t_var *info, int *bomb, t_var *v_max);
int					ft_int_tab_to_int(int *tab);
void				ft_set_first_line(t_var *info, int *buff, int i);
void				ft_initialize_info(t_var *info);
char				*ft_algo(char *line, int *buff);
int					ft_min(int up, int diag, int left, int pos);
void				ft_set_v_max(int x, int y, int new_val, t_var *v_max);
int					*ft_put_bomb(int x, int *bomb, t_var *info);
void				ft_get_bomb(int *x, int *y, int *bomb, t_var *info);
int					ft_putchar_err(void);
int					ft_check1(t_var *info, char c);
int					ft_check_first_line(int *s);

#endif
