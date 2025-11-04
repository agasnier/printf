/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <algasnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 12:15:42 by algasnie          #+#    #+#             */
/*   Updated: 2025/11/04 09:48:45 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printf_helper(char *str, va_list args)
{
	int		i;
	int		len_print;
	int		len_func;

	i = 0;
	len_print = 0;
	len_func = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len_func = ft_operator(str, &i, args);
			if (len_func == -1)
				return (-1);
			len_print += len_func;
		}
		else
			len_print += write(1, &str[i], 1);
		i++;
	}
	return (len_print);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len_print;

	va_start(args, str);
	if (!str)
		return (-1);
	len_print = ft_printf_helper((char *)str, args);
	va_end(args);
	return (len_print);
}
