/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdustin <kdustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 22:43:49 by kdustin           #+#    #+#             */
/*   Updated: 2020/05/08 01:30:58 by kdustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*p_s;

	p_s = (char*)s;
	i = 0;
	while (i < n)
	{
		if (p_s[i] == (char)c)
			return (&p_s[i]);
		i++;
	}
	return (NULL);
}
