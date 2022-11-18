/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguilher <rguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:42:07 by rguilher          #+#    #+#             */
/*   Updated: 2022/11/04 17:24:56 by rguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	counter;

	counter = 0;
	if (str)
	{
		while (str[counter])
		{
			write(1, &str[counter], 1);
			counter++;
		}
	}
	else
		counter = counter + ft_putstr("(null)");
	return (counter);
}
