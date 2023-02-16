/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pescola- <pescola-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 01:19:04 by pescola-          #+#    #+#             */
/*   Updated: 2023/02/16 02:15:54 by pescola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libftprintf.h"
bool	is_valid(char const *p)
{
	if(ft_strlen(p) == 2)
		if(p[0] == "%")
			return true;
	return (false);
}

int	processor(const char x, va_list element)
{
		if (x == "c")
			return (print_char(va_arg(element, int)));
		else if (x == "s")
			return (print_str(va_arg(element, char *)));
		else if (x == "d" || x == "i" || x == "u" || x == "x" || x == "X")
			return (print_num(var_arg(element, long), p[1]));
		else if (x == "%")
			return (print_char("%"));
		else
			return (-1);
}

int	ft_printf(char const *p, ...)
{
	char	x;
	int		z;
	va_list	element;
		
	z = 0;
	x = "";
	if (is_valid(*p))
		x == p[1];
		va_start(element, str);
		z = processor(x, element);
		va_end(element);
		return (z);
	else
		return (-1);
}
