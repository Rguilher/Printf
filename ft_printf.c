/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguilher <rguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:17:15 by rguilher          #+#    #+#             */
/*   Updated: 2022/11/04 18:31:04 by rguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_flag(char flag, va_list args)
{
	if (flag == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (flag == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (flag == 'p')
		return (ft_putaddress(va_arg(args, unsigned long int)));
	if (flag == 'i')
		return (ft_itoa(va_arg(args, int)));
	if (flag == 'd')
		return (ft_itoa(va_arg(args, int)));
	if (flag == 'u')
		return (ft_utoa(va_arg(args, unsigned int)));
	if (flag == 'x')
		return (ft_puthex(va_arg(args, unsigned int), flag));
	if (flag == 'X')
		return (ft_puthex(va_arg(args, unsigned int), flag));
	else
		return (ft_putchar(flag));
}

int	ft_printf(const char *format, ...)
{
	int		counter;
	va_list	args;

	if (!format)
		return (-1);
	counter = 0;
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			counter = counter + handle_flag(*format, args);
		}
		else
		{
			ft_putchar(*format);
			counter++;
		}
		format++;
	}
	va_end(args);
	return (counter);
}
