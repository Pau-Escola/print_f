/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pescola- <pescola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 20:29:26 by pescola-          #+#    #+#             */
/*   Updated: 2023/02/24 19:58:33 by pescola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_putchar(const char c);
int	put_num(long long int n, const char base);
int	put_str(const char *s);
int	ft_printf(char const *p, ...);
int	ft_strlen(const char *s);
#endif
