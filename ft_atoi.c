/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdustin <kdustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 01:05:45 by kdustin           #+#    #+#             */
/*   Updated: 2020/05/19 01:09:35 by kdustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	long long int	num;
	int				minus;

	minus = 1;
	while (*str == '\f' || *str == '\v' || *str == ' '
		|| *str == '\t' || *str == '\n' || *str == '\r')
		str++;
	if (*str == '-')
	{
		minus = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	num = 0;
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			break ;
		num += *str - '0';
		num *= 10;
		str++;
	}
	return (num / 10 * minus);
}
