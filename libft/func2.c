/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobabeke <mobabeke@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 12:38:05 by mobabeke          #+#    #+#             */
/*   Updated: 2023/01/21 14:16:40 by mobabeke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_unputnbr_fd(unsigned int n, int fd)
{
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
		ft_putchar_fd('0' + n, fd);
}

int	ft_unintlen(unsigned int i)
{
	int	length;

	length = 0;
	if (i == 0)
		return (1);
	while (i != 0)
	{
		i /= 10;
		length++;
	}
	return (length);
}

int	printpers(char i)
{
	ft_putchar_fd(i, 1);
	return (1);
}

int	ft_intlen(int x)
{
	int	len;

	len = 0;
	if (x == 0)
		return (1);
	if (x == -2147483648)
		return (11);
	if (x < 0)
	{
		x = -x;
		len++;
	}
	while (x != 0)
	{
		x /= 10;
		len++;
	}
	return (len);
}
