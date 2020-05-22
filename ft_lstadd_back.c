/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdustin <kdustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 20:26:08 by kdustin           #+#    #+#             */
/*   Updated: 2020/05/18 17:25:43 by kdustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (lst != NULL)
	{
		temp = *lst;
		if (*lst == NULL)
			*lst = new;
		else if (new)
		{
			temp = ft_lstlast(temp);
			temp->next = new;
		}
	}
}
