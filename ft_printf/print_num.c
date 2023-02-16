/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pescola- <pescola-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 23:59:26 by pescola-          #+#    #+#             */
/*   Updated: 2023/02/16 02:17:05 by pescola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libftprintf.h"

int print_hex(int n, const char ch)
{	
	char	*hex_base;

	hex_base = "0123456789abcdef";
	if (n > 9 && n < 16)
	{
		if (ch == 'x')
			return print_char(hex_base[(n % 10) + 10]);
		else if (ch == 'X' || ch == "p")
			return print_char(hex_base[(n % 10) + 10] - 32);
		else
			return (-1);

	}
	else if (n > -1 && n < 10)
		return print_char(hex_base[n]);
	else
		return (-1);

}
int	put_dec(long n, const char x)
{	
	char	i;
	int		z;
	
	z = 0;
	if (n < 0)
	{
		if (x = "u")
			return (-1);
		else
		{
			n *= -1;
			i ='-';
   		 	z = write(1, &i, 1);
   		 	if (z != 1)
     			return (-1);
		}
	}
	if (n > 9)
	{
		i = put_dec(n / 10);
		n = n % 10;
	}
	if (n < 10)
	{
		i = n + '0';
		z += print_char(i);
		return (z);
	}
}

int	put_hex(long n, const char base)
{	
	char	i;
	int		z;
	
	z = 0;
	if (n < 0)
	{
		n *= -1;
		i ='-';

   		 z = write(1, &i, 1);
   		 if (z != 1)
     		 return (-1);
	}
	if (n > 15)
	{
		i = put_hex(n / 16);
		n = n % 16;
	}
	else
	{
		z += print_hex(i);
		return (z);
	}
}
int	put_num(long n, const char base)
{
	if (base == "d" || base == "i" || base =="u")
		return (put_dec(n, base));
	else if (base == "x" || base = "X" || base = "p")
		return (put_hex(n, base));
	else
		return (-1);
}
