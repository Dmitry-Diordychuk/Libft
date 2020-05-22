/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdustin <kdustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 02:01:04 by kdustin           #+#    #+#             */
/*   Updated: 2020/05/19 01:05:08 by kdustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*p;

	if (!(p = malloc(size * count)))
		return (NULL);
	i = 0;
	while (i < (count * size))
	{
		p[i] = 0;
		i++;
	}
	return ((void*)p);
}
