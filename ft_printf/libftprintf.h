/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pescola- <pescola-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 02:22:36 by pescola-          #+#    #+#             */
/*   Updated: 2023/02/16 02:39:11 by pescola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
#define LIBFTPRINTF_H

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>

typedef struct s_list
{
	void	*content;
	struct s_list *next;
	t_list;
}

int	ft_putchar(const char c);
int	put_num(long n, const char base);
int	put_str(const char *s);
int	ft_printf(char const *p, ...);
#endif
