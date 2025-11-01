/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <algasnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 17:59:09 by algasnie          #+#    #+#             */
/*   Updated: 2025/11/01 21:27:04 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_hex(unsigned long int num, char spec)
{
	char *base;
	char *c_num;
	char *hex;
	int len;
	
	hex = NULL;
	if (spec == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	len = ft_num_len((unsigned long int)num, 16);
	c_num = malloc(sizeof(char) * (len + 1));
	if (!c_num)
		return (NULL);
	c_num[len] = '\0';
	if (num == 0)
		c_num[0] = base[0];
	while (num > 0)
	{
		c_num[--len] = base[num % 16];
		num /= 16;
	}
	if (spec == 'p')
	{
		hex = ft_strjoin("0x", c_num);
		free(c_num);
		return (hex);
	}
	return (c_num);
}