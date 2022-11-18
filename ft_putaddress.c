/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguilher <rguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:19:40 by rguilher          #+#    #+#             */
/*   Updated: 2022/11/04 17:27:19 by rguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putaddress(unsigned long int n)
{
	int	counter;

	if (n == 0)
		counter = ft_putstr("(nil)");
	else
	{
		counter = ft_putstr("0x");
		counter = counter + ft_puthex(n, 'x');
	}
	return (counter);
}
