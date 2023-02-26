/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pescola- <pescola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 23:59:26 by pescola-          #+#    #+#             */
/*   Updated: 2023/02/26 19:23:50 by pescola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	print_hex(unsigned int n, const char ch)
{	
	char	*hex_base_no_cap;
	char	*hex_base_cap;

	hex_base_no_cap = "0123456789abcdef";
	hex_base_cap = "0123456789ABCDEF";
	if (ch == 'x' || ch == 'p')
		return (ft_putchar(hex_base_no_cap[n]));
	else if (ch == 'X')
		return (ft_putchar(hex_base_cap[n]));
	else
		return (-1);
}

int	put_dec(long long int n, const char x, int res)
{	
	if (n < 0)
	{
		n *= -1;
		if (write(1, "-", 1) != 1)
			return (-1);
		res++;
	}
	if (n > 9)
	{
		res = put_dec(n / 10, x, res);
		if (res == -1)
			return (-1);
		n = n % 10;
	}
	if (n < 10)
	{
		if (ft_putchar(n + '0') != 1)
			return (-1);
		res++;
		return (res);
	}
	return (-1);
}

int	put_hex(unsigned int n, const char base, int res)
{	
	if (n > 15)
	{
		res = put_hex(n / 16, base, res);
		if (res == -1)
			return (-1);
		n = n % 16;
	}	
	if (print_hex(n, base) != 1)
		return (-1);
	res++;
	return (res);
}

int	put_pointr(unsigned long long n, const char base, int res)
{	
	if (n > 15)
	{
		res = put_pointr(n / 16, base, res);
		n = n % 16;
	}	
	if (print_hex(n, base) != 1)
		return (-1);
	res++;
	return (res);
}

int	put_num(long long int n, const char base)
{
	if (base == 'd' || base == 'i' || base == 'u')
		return (put_dec(n, base, 0));
	else if (base == 'x' || base == 'X')
		return (put_hex(n, base, 0));
	else if (base == 'p')
	{
		if (write(1, "0x", 2) != 2)
			return (-1);
		return (put_pointr((unsigned long long)n, base, 0) + 2);
	}
	else
		return (-1);
}
