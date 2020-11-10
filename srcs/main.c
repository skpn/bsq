/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 16:24:42 by edbaudou          #+#    #+#             */
/*   Updated: 2019/02/27 22:41:11 by sikpenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

void	ft_initialize_info(t_var *map_info)
{
	map_info->back_n = 0;
	map_info->line_size = 0;
	map_info->bomb_number = 0;
	map_info->char_empty = 0;
	map_info->char_filled = 0;
	map_info->char_obstacle = 0;
	map_info->line_max = 0;
}

int		main(int ac, char **av)
{
	int			i;
	t_var		*v_max;
	t_var		*map_info;
	int			fd;

	errno = 0;
	if (!(v_max = (t_var*)malloc(sizeof(t_var))))
		return (-1);
	if (!(map_info = (t_var*)malloc(sizeof(t_var))))
		return (-1);
	ft_set_v_max(-1, -1, 0, v_max);
	ft_initialize_info(map_info);
	i = 1;
	if (ac <= 1)
		ft_read_from_args(0, v_max, 0, 0);
	else
		while (i < ac)
		{
			fd = open(av[i], O_RDONLY);
			if (errno == 0)
				ft_read_from_args(fd, v_max, 0, 0);
			else
				write(2, "map error\n", 10);
			i++;
		}
	return (1);
}
