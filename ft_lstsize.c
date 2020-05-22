/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdustin <kdustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 20:21:24 by kdustin           #+#    #+#             */
/*   Updated: 2020/05/15 01:54:05 by kdustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int size;

	if (lst)
	{
		size = 0;
		while (lst->next != NULL)
		{
			lst = lst->next;
			size++;
		}
		return (++size);
	}
	return (0);
}
