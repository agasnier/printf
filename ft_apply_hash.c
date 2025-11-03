/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_hash.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <algasnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 10:50:01 by algasnie          #+#    #+#             */
/*   Updated: 2025/11/03 10:50:56 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *ft_apply_hash(t_data *data, char *result)
{
	char *tmp;

	if (!data->hash || (data->spec != 'x' && data->spec != 'X'))
		return (result);
	if (result[0] == '0' && result[1] == '\0')
		return (result);
	if (data->spec == 'x')
		tmp = ft_strjoin("0x", result);
	if (data->spec == 'X')
		tmp = ft_strjoin("0X", result);
	free(result);
	return(tmp);
}