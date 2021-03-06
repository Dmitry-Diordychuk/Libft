/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdustin <kdustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 00:01:54 by kdustin           #+#    #+#             */
/*   Updated: 2020/07/18 17:07:39 by kdustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The strlcat() function concatenates strings. It is designed to be safer, more
** consistent, and less error prone replacements for strncat(3). Unlike this
** function, strlcat() take the full size of the buffer (not just the length)
** and guarantee to NUL-terminate the result (as long as there is at least one
** byte free in dst). Note that a byte for the NUL should be included in size.
** Also note that strlcat() only operate on true ``C'' strings. This means that
** for strlcat() both src and dst must be NUL-terminated.
**
** The strlcat() function appends the NUL-terminated string src to the end of
** dst. It will append at most size - strlen(dst) - 1 bytes, NUL-terminating the
** result.
**
** The source and destination strings should not overlap, as the behavior is un-
** defined.
**
** RETURN VALUES
** The strlcat() function returns the total length of the string it tried to
** create. For strlcat() that means the initial length of dst plus the length of
** src. While this may seem somewhat confusing, it was done to make truncation
** detection simple.
**
** Note however, that if strlcat() traverses size characters without finding a
** NUL, the length of the string is considered to be size and the destination
** string will not be NUL-terminated (since there was no space for the NUL).
** This keeps strlcat() from running off the end of a string. In practice this
** should not happen (as it means that either size is incorrect or that dst is
** not a proper ``C'' string). The check exists to prevent potential security
** problems in incorrect code.
*/

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
