/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pescola- <pescola-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:53:46 by pescola-          #+#    #+#             */

/*                                                                            */
/* ************************************************************************** */

#include"libftprintf.h"
int	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

int	put_str(const char *s)
{
	if (!s)
	{
	  if (write (1, "(NULL)", 6) != 6)
	    return (-1);
	  return (6);
	}
	if (write(1, &s[0], ft_strlen(s)) != ft_strlen(s))
	  return (-1)
	return (ft_strlen(s));
}
