/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdustin <kdustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 18:14:22 by kdustin           #+#    #+#             */
/*   Updated: 2020/05/09 18:24:57 by kdustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*result;
	char	*prev;

	if ((result = ft_strchr(s, c)) == NULL)
		return (NULL);
	if (result[0] == '\0' && c == 0)
		return (result);
	while (result != NULL)
	{
		prev = result;
		result = ft_strchr(result + 1, c);
	}
	return (prev);
}
