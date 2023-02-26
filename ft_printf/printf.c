/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pescola- <pescola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 01:19:04 by pescola-          #+#    #+#             */
/*   Updated: 2023/02/26 19:3 by pescola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	processor(const char x, va_list element)
{
	if (x == 'c')
		return (ft_putchar(va_arg(element, int)));
	else if (x == 's')
		return (put_str(va_arg(element, char *)));
	else if (x == 'd' || x == 'i')
		return (put_num(va_arg(element, int), x));
	else if (x == 'u')
		return (put_num(va_arg(element, unsigned int), x));
	else if (x == 'x' || x == 'X' || x == 'p')
		return (put_num(va_arg(element, unsigned long), x));
	else if (x == '%')
		return (ft_putchar('%'));
	else
		return (-1);
}

int	printer(char const *p, va_list element)
{
	int	ans;
	int	i;
	int	temp;

	ans = 0;
	i = -1;
	temp = 0;
	while (p[++i])
	{
		if (p[i] == '%')
		{
			temp = processor(p[++i], element);
			if (temp == -1)
				return (-1);
			ans += temp;
		}
		else
		{
			if (write(1, &p[i], 1) != 1)
				return (-1);
			ans++;
		}
	}
	return (ans);
}

int	ft_printf(char const *p, ...)
{
	int		ans;
	int		i;
	va_list	element;
	int		temp;

	ans = 0;
	i = -1;
	temp = 0;
	va_start(element, p);
	ans = printer(p, element);
	va_end(element);
	return (ans);
}
