/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlima-fe <rlima-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 12:07:42 by rlima-fe          #+#    #+#             */
/*   Updated: 2023/10/26 16:04:06 by rlima-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_type(char format, va_list args, int flag)
{
	int	s;

	s = 0;
	if (format == 'c')
		s = ft_putchar(va_arg(args, int));
	else if (format == 's')
		s = ft_putstr(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		s = ft_putnbr(va_arg(args, int), flag);
	else if (format == 'u')
		s = ft_putnbrbase(va_arg(args, unsigned int), DEC, 0, flag);
	else if (format == 'x')
		s = ft_putnbrbase(va_arg(args, unsigned int), HEXLOW, 0, flag);
	else if (format == 'X')
		s = ft_putnbrbase(va_arg(args, unsigned int), HEXUP, 0, flag);
	else if (format == 'p')
		s = ft_putnbrbase(va_arg(args, unsigned long long), HEXLOW, -1, flag);
	else if (format == '%')
		s = ft_putchar('%');
	return (s);
}

int	ft_flags(char type)
{
	int	flag;

	flag = 0;
	if (type == '+')
		flag = 1;
	if (type == '#')
		flag = 2;
	return (flag);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		size;
	int		flag;
	int		i;

	va_start(args, str);
	i = 0;
	size = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			flag = ft_flags(str[i + 1]);
			if (flag)
				i++;
			size += format_type(str[i++ + 1], args, flag);
		}
		else
			size += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (size);
}
