/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikpenou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 00:02:29 by sikpenou          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/02/27 22:45:55 by sikpenou         ###   ########.fr       */
=======
/*   Updated: 2019/02/26 20:44:28 by sikpenou         ###   ########.fr       */
>>>>>>> master
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

void	ft_initialize(int *tab, int size)
{
	int		i;

	i = 0;
	while (i <= size)
	{
		tab[i] = -1;
		i++;
	}
}

void	ft_set_first_line(t_var *v_max, int *buff, int i)
{
	int		j;

	j = 0;
	v_max->char_filled = buff[i - 1];
	v_max->char_obstacle = buff[i - 2];
	v_max->char_empty = buff[i - 3];
	buff[i - 3] = '\0';
	while (buff[j])
	{
		if (!(buff[j] >= '0' && buff[j] <= '9') || buff[i - 1] == buff[i - 2] ||
			buff[i - 1] == buff[i - 3] || buff[i - 2] == buff[i - 3] ||
			buff[i - 1] < 32 || buff[i - 1] == 127 || buff[i - 2] < 32 ||
			buff[i - 2] == 127 || v_max->char_empty < 32 || v_max->char_empty ==
			127)
			v_max->char_filled = 0;
		j++;
	}
	v_max->line_max = ft_int_tab_to_int(buff);
	v_max->line_size = 0;
	//free(buff);
}

int		*ft_read_file(t_var *v_max, int fd, int *bomb)
{
	int		i;
	int		*buff;
	char	reading;

	reading = 0;
	if (!(buff = (int*)malloc(sizeof(int) * 2)))
		return (0);
	ft_initialize(buff, 2);
	i = 0;
	while (read(fd, &reading, 1) > 0)
	{
		if (v_max->back_n == 1)
		{
			if (reading != '\n')
			{
				if (reading == v_max->char_empty)
				{
					buff[i] = 1;
					if (buff[i] > v_max->value)
						ft_set_v_max(v_max->back_n, i + 1, 1, v_max);
				}
				else
				{
					buff[i] = 0;
					bomb = ft_put_bomb(i, bomb, v_max);
				}
			}
		}
		else
			buff[i] = reading;
		v_max->back_n = reading == '\n' ? v_max->back_n + 1 : v_max->back_n;
		if (v_max->back_n == 1 && reading == '\n')
		{
			ft_set_first_line(v_max, buff, i);
			if (!(buff = (int*)malloc(sizeof(int) * 2)))
				return (0);
			ft_initialize(buff, 2);
			i = -1;
		}
		else if (v_max->back_n == 2 && reading == '\n')
			return (buff);
		buff[++i] = -1;
		v_max->line_size++;
		buff = ft_realloc(buff, v_max->line_size + 1);
	}
	return (NULL);
}

int		ft_read_from_args(int fd, t_var *v_max, int pos, int res)
{
	int		*line;
	char	buff;
	int		*bomb;
	int		tmp;

	tmp = 0;
	if (!(bomb = (int*)malloc(sizeof(int) * 2)))
		return (ft_putchar_err());
	ft_initialize(bomb, 2);
	line = ft_read_file(v_max, fd, bomb);
	if (ft_check1(v_max, '\n') == -1)
		return (ft_putchar_err());
	while ((read(fd, &buff, 1)) > 0)
	{
		if (ft_check1(v_max, buff) == -1)
			return (ft_putchar_err());
		if (buff == '\n')
		{
			if (pos != v_max->line_size - 1)
				return (ft_putchar_err());
			v_max->back_n++;
			tmp = line[0];
			pos = -1;
		}
		else if (buff == v_max->char_obstacle)
		{
			tmp = line[pos];
			line[pos] = 0;
			bomb = ft_put_bomb((v_max->back_n - 1) * v_max->line_size + pos,
					bomb, v_max);
		}
		else if (pos == 0)
		{
			tmp = line[pos];
			line[pos] = 1;
		}
		else
		{
			res = ft_min(tmp, line[pos - 1], line[pos], pos) + 1;
			tmp = line[pos];
			line[pos] = res;
			if (line[pos] > v_max->value)
				ft_set_v_max(v_max->back_n, pos, line[pos], v_max);
		}
		pos++;
	}
	if (v_max->back_n - 1 != v_max->line_max)
		return (ft_putchar_err());
	ft_print_map(v_max, bomb, v_max);
	close(fd);
	return (0);
}
