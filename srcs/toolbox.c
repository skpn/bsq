/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikpenou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 23:33:36 by sikpenou          #+#    #+#             */
/*   Updated: 2019/02/26 20:35:59 by sikpenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

void	ft_putnbr(int nb)
{
	long int	nb_long;
	int			order;

	if (nb < 0)
		ft_putchar('-');
	nb_long = nb < 0 ? nb * -1 : nb;
	nb_long = nb == -2147483648 ? 2147483648 : nb_long * 1;
	order = 1;
	while (nb >= 10 || nb <= -10)
	{
		nb = nb / 10;
		order = order * 10;
	}
	while (order > 0)
	{
		ft_putchar('0' + nb_long / order);
		nb_long = nb_long % order;
		order = order / 10;
	}
}

int		ft_atoi(char *str)
{
	long int	res;
	int			i;
	int			sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((str[i] <= 32 || str[i] > 126) && str[i])
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int		ft_int_tab_to_int(int *tab)
{
	int		res;
	int		pos;

	res = 0;
	pos = 0;
	while (tab[pos] >= '0' && tab[pos] <= '9')
	{
		res = res * 10 + tab[pos] - 48;
		pos++;
	}
	return (res);
}
