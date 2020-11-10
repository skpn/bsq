/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 23:08:56 by edbaudou          #+#    #+#             */
/*   Updated: 2019/02/27 22:33:19 by sikpenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

void	ft_print_line(int *line)
{
	int		pos;

	pos = 0;
	while (line[pos] != -1)
	{
		ft_putnbr(line[pos]);
		pos++;
	}
	ft_putchar('\n');
}

int		*ft_put_bomb(int offset, int *bomb, t_var *info)
{
	info->bomb_number++;
	if (info->bomb_number == 1)
	{
		bomb[0] = offset;
		bomb[info->bomb_number] = -1;
	}
	else
	{
		bomb = ft_realloc(bomb, info->bomb_number + 2);
		bomb[info->bomb_number - 1] = offset;
		bomb[info->bomb_number] = -1;
	}
	return (bomb);
}

void	ft_print_map(t_var *info, int *bomb, t_var *v_max)
{
	int			pos;
	int			ctr_sq;
	int			ctr_x;
	int			*cpy_bomb;
	t_var		*cpy_vmax;

	info->back_n--;
	cpy_vmax = v_max;
	pos = 0;
	ctr_x = 0;
	cpy_bomb = bomb;
	while (pos < info->line_size * info->back_n)
	{
		if (pos == *cpy_bomb)
		{
			ft_putchar(info->char_obstacle);
			cpy_bomb++;
		}
		else if (pos == v_max->pos_sq && ctr_x < cpy_vmax->value *
				cpy_vmax->value)
		{
			ctr_sq = 0;
			while (ctr_sq < cpy_vmax->value)
			{
				ft_putchar(info->char_filled);
				ctr_sq++;
				ctr_x++;
			}
			pos += cpy_vmax->value - 1;
			cpy_vmax->pos_sq += info->line_size;
		}
		else
			if ((pos + 1) % info->line_size == 0 && pos > 0)
				write(1, "\n", 1);
			else
				write(1, &(info->char_empty), 1);
		pos++;
	}
}
