/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 17:57:04 by edbaudou          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/02/27 22:12:07 by sikpenou         ###   ########.fr       */
=======
/*   Updated: 2019/02/26 20:40:18 by sikpenou         ###   ########.fr       */
>>>>>>> master
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

int		*ft_strcpy(int *dest, int *src)
{
	int		i;

	i = 0;
	while (src[i] != -1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = -1;
	return (dest);
}

int		*ft_realloc(int *str, int new_size)
{
	int	*cpy;

	if (!str)
	{
		if (!(str = (int*)malloc(sizeof(int) * (new_size))))
			return (NULL);
		return (str);
	}
	if (!(cpy = (int*)malloc(sizeof(int) * (new_size + 1))))
		return (NULL);
	ft_initialize(cpy, new_size + 1);
	cpy = ft_strcpy(cpy, str);
	return (cpy);
}
