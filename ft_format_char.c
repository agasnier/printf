/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <algasnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 17:59:06 by algasnie          #+#    #+#             */
/*   Updated: 2025/11/01 21:20:21 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_char_str(char c)
{
	char *str;

	str = malloc(sizeof(char) * 2);
	str[0] = c;
	str[1] = '\0';

	return (str);
}

char	*ft_string(char *s)
{
	char *str;

	if (!s)
	{
		str = ft_strdup("(null)");
		return (str);
	}
	str = ft_strdup(s);
	return (str);
}