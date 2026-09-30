/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fetraand <fetraand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 09:16:58 by hasandri          #+#    #+#             */
/*   Updated: 2026/05/13 00:26:17 by fetraand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c, int fd)
{
	return (write(fd, &c, 1));
}

int	ft_putstr(const char *str, int fd)
{
	int	i;

	if (!str)
		return (ft_putstr("(null)", fd));
	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n, int fd)
{
	int	len;

	len = 0;
	if (n == -2147483648)
	{
		len += ft_putstr("-2147483648", fd);
		return (len);
	}
	if (n < 0)
	{
		len += ft_putchar('-', fd);
		n = -n;
	}
	if (n >= 10)
	{
		len += ft_putnbr((n / 10), fd);
		len += ft_putnbr((n % 10), fd);
	}
	else
		len += ft_putchar((n + '0'), fd);
	return (len);
}

static int	fractional_part(int fd, int precision, double fraction)
{
	int	digit;
	int	count;

	count = 0;
	while (precision--)
	{
		fraction *= 10;
		digit = (int)fraction;
		count += ft_putchar(digit + '0', fd);
		fraction -= digit;
	}
	return (count);
}

int	ft_putfloat(double nb, int precision, int fd)
{
	long	integer_part;
	double	fraction;
	double	rounding;
	int		count;
	int		p;

	count = 0;
	rounding = 0.5;
	p = precision;
	while (p--)
		rounding /= 10;
	nb += rounding;
	if (nb < 0)
	{
		count += ft_putchar('-', fd);
		nb = -nb;
	}
	integer_part = (long)nb;
	fraction = nb - integer_part;
	count += ft_putnbr(integer_part, fd);
	count += ft_putchar('.', fd);
	count += fractional_part(fd, precision, fraction);
	return (count);
}
