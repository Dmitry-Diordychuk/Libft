/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdustin <kdustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 00:01:54 by kdustin           #+#    #+#             */
/*   Updated: 2020/05/09 17:49:55 by kdustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size > (dst_len))
	{
		i = dst_len;
		j = 0;
		while (i < size - 1 && src[j] != '\0')
		{
			dst[i] = src[j];
			j++;
			i++;
		}
		dst[i] = '\0';
		return (dst_len + src_len);
	}
	return (src_len + size);
}
