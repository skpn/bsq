/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikpenou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 20:47:16 by sikpenou          #+#    #+#             */
/*   Updated: 2019/02/27 22:39:19 by sikpenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

int		ft_putchar_err(void)
{
	write(2, "map error\n", 10);
	return (-1);
}

int		ft_check1(t_var *info, char buff)
{
	if (info->char_empty == 0 || info->char_obstacle == 0 ||
			info->char_filled == 0 || info->back_n == 0 || info->line_max == 0)
	{
		ft_putchar('a');
		return (-1);
	}
	else if (buff != '\n' && buff != info->char_obstacle
			&& buff != info->char_filled && buff != info->char_empty)
	{
		ft_putchar('b');
		return (-1);
	}
	else
	{
		ft_putchar('c');
		return (0);
	}
}
