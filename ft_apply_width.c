/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <algasnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 10:51:17 by algasnie          #+#    #+#             */
/*   Updated: 2025/11/03 10:51:38 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *ft_apply_width(t_data *data, char *result)
{
	int len_padding;
	char *padding;
	char *tmp;

	len_padding = data->width - (int)ft_strlen(result);
	if (len_padding > 0)
	{
		padding = malloc(sizeof(char) * (data->width + 1));
		if (!padding)
			return (NULL);
		padding[data->width] = '\0';
		if (data->zero)
			ft_memset(padding, '0', (size_t)len_padding);
		else
			ft_memset(padding, ' ', (size_t)len_padding);
		if (data->minus)
			tmp = ft_strjoin(result, padding);
		else
			tmp = ft_strjoin(padding, result);
		free(padding);
		free(result);
		return (tmp);
	}
	return (result);
}