/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguilher <rguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:12:34 by rguilher          #+#    #+#             */
/*   Updated: 2022/11/04 17:31:35 by rguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count(int n)
{
	int	counter;

	counter = 1;
	if (n < 0)
		counter++;
	n /= 10;
	while (n)
	{
		counter++;
		n = n / 10;
	}
	return (counter);
}

static void	transfer_itoa(char *str, int size, int n, int is_negative)
{
	str[size] = '\0';
	while (size--)
	{
		str[size] = n % 10 + 48;
		n = n / 10;
	}
	if (is_negative)
		str[0] = '-';
	ft_putstr(str);
}

int	ft_itoa(int n)
{
	int		counter;
	int		is_negative;
	int		size;
	char	*str;

	is_negative = 0;
	size = ft_count(n);
	counter = ft_count(n);
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return (counter);
	}
	if (n < 0)
	{
		is_negative = 1;
		n *= -1;
	}
	str = (char *)malloc((size + 1) * sizeof(char));
	if (!str)
		return (0);
	transfer_itoa(str, size, n, is_negative);
	free(str);
	return (counter);
}
