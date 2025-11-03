/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_sign.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <algasnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 10:48:17 by algasnie          #+#    #+#             */
/*   Updated: 2025/11/03 10:50:38 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *ft_apply_sign(t_data *data, char *result)
{
	char *tmp;

	if (result[0] == '-')
		return (result);
	
	if (data->plus)
	{
		tmp = ft_strjoin("+", result);
		free(result);
		return (tmp);
	}

	if (data->space)
	{
		tmp = ft_strjoin(" ", result);
		free(result);
		return (tmp);
	}

	return (result);
}