/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasandri <hasandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 09:16:29 by hasandri          #+#    #+#             */
/*   Updated: 2026/05/07 17:49:00 by hasandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(int fd, va_list args, const char format)
{
	if (format == 'c')
		return (ft_putchar(va_arg(args, int), fd));
	else if (format == 's')
		return (ft_putstr(va_arg(args, char *), fd));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(args, int), fd));
	else if (format == 'f')
		return (ft_putfloat(va_arg(args, double), 2, fd));
	else if (format == '%')
		return (ft_putchar('%', fd));
	return (0);
}

int	ft_printf(int fd, const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	if (!format)
		return (-1);
	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (-1);
			len += ft_format(fd, args, format[i + 1]);
			i++;
		}
		else
			len += ft_putchar(format[i], fd);
		i++;
	}
	va_end (args);
	return (len);
}
