/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdustin <kdustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 18:10:41 by kdustin           #+#    #+#             */
/*   Updated: 2020/05/17 17:39:22 by kdustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;
	char	*p_dest;
	char	*p_src;

	i = 0;
	p_dest = (char*)dest;
	p_src = (char*)src;
	while (i < n)
	{
		if (p_src[i] == (char)c)
		{
			p_dest[i] = p_src[i];
			return (&(p_dest[i + 1]));
		}
		p_dest[i] = p_src[i];
		i++;
	}
	return (NULL);
}
