/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pescola- <pescola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 19:59:10 by pescola-          #+#    #+#             */
/*   Updated: 2023/02/24 19:59:14 by pescola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	put_str(const char *s)
{
	if (!s)
	{
		if (write (1, "(null)", 6) != 6)
			return (-1);
		return (6);
	}
	if (write(1, &s[0], ft_strlen(s)) != ft_strlen(s))
		return (-1);
	return (ft_strlen(s));
}
