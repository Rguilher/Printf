/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguilher <rguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:58:14 by rguilher          #+#    #+#             */
/*   Updated: 2022/11/04 17:25:22 by rguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count(unsigned int n)
{
	int	counter;

	counter = 1;
	while (n > 9)
	{
		n = n / 10;
		counter++;
	}
	return (counter);
}

int	ft_utoa(unsigned int n)
{
	char	*str;
	int		counter;
	int		size;

	size = ft_count(n);
	counter = ft_count(n);
	str = (char *)malloc((size + 1) * sizeof(char));
	if (!str)
		return (0);
	str[size] = '\0';
	while (size > 0)
	{
		str[size - 1] = (n % 10) + 48;
		n = n / 10;
		size--;
	}
	ft_putstr(str);
	free(str);
	return (counter);
}
