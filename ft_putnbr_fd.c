/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdustin <kdustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 17:32:52 by kdustin           #+#    #+#             */
/*   Updated: 2020/05/19 01:03:38 by kdustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int			digits[10];
	int			i;
	int long	number;

	number = n;
	if (number == (i = 0))
		ft_putchar_fd('0', fd);
	if (number < 0)
	{
		ft_putchar_fd('-', fd);
		number = number * (-1);
	}
	while (number)
	{
		digits[i] = number % 10;
		number = number / 10;
		i++;
	}
	while (i-- > 0)
	{
		ft_putchar_fd(digits[i] + '0', fd);
	}
}
