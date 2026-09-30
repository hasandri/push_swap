/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasandri <hasandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 09:16:38 by hasandri          #+#    #+#             */
/*   Updated: 2026/05/07 17:49:02 by hasandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(int fd, const char *format, ...);
int	ft_putchar(int c, int fd);
int	ft_putstr(const char *str, int fd);
int	ft_putnbr(int n, int fd);
int	ft_putfloat(double nb, int precision, int fd);

#endif
