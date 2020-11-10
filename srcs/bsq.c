/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 16:30:46 by edbaudou          #+#    #+#             */
/*   Updated: 2019/02/27 22:16:02 by sikpenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

int		ft_min(int up, int diag, int left, int pos)
{
	(void)pos;
	if (up < diag && up < left)
	{
		return (up);
	}
	else if (diag < left)
	{
		return (diag);
	}
	else
	{
		return (left);
	}
}

void	ft_set_v_max(int x, int y, int new_val, t_var *v_max)
{
	v_max->pos_sq = (x - 1 - new_val + 1) * v_max->line_size + (y - new_val +
			1);
	v_max->value = new_val;
}
