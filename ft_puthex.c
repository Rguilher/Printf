/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguilher <rguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:33:22 by rguilher          #+#    #+#             */
/*   Updated: 2022/11/04 18:09:30 by rguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long n, int flag)
{
	int	counter;

	counter = 0;
	if (n >= 16)
	{
		counter = counter + ft_puthex((n / 16), flag);
		counter = counter + ft_puthex((n % 16), flag);
	}
	else
	{
		if (n < 10)
			return (ft_putchar(HEX[n]));
		else
			return (ft_putchar(HEX[n] - ('x' - flag)));
	}
	return (counter);
}
