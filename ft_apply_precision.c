/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <algasnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 10:47:20 by algasnie          #+#    #+#             */
/*   Updated: 2025/11/03 10:48:27 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char *ft_apply_preci_str(t_data *data, char *result)
{
	char *tmp;

	if (data->prec >= (int)ft_strlen(result))
		return (result);
	tmp = malloc(sizeof(char) * (data->prec + 1));
	if (!tmp)
		return (NULL);
	ft_memcpy(tmp, result, data->prec);
	tmp[data->prec] = '\0';
	free(result);
	return(tmp);
}

static char *ft_apply_preci_numb_pos(char *padding, char *result)
{
	char *tmp;

	tmp = ft_strjoin(padding, result);
	free(padding);
	free(result);
	return (tmp);
}

static char *ft_apply_preci_numb_neg(char *padding, char *result)
{
	char *tmp;

	tmp = ft_strjoin("-", padding);
	free(padding);
	padding = ft_strjoin(tmp, result + 1);
	free(result);
	free(tmp);
	return (padding);
}

static char *ft_apply_preci_numb(t_data *data, char *result)
{
	char	*tmp;
	char	*padding;
	int		len_padding;

	if (data->prec == 0)
	{
		free(result);
		tmp = ft_strdup("");
		return (tmp);
	}
	if (result[0] == '-')
		len_padding = data->prec - (int)ft_strlen(result) + 1;
	else
		len_padding = data->prec - (int)ft_strlen(result);
	if (len_padding <= 0)
		return (result);

	padding = malloc(len_padding + 1);
	if (!padding)
		return (NULL);
	ft_memset(padding, '0', len_padding);
	padding[len_padding] = '\0';
	if (result[0] == '-')
		tmp = ft_apply_preci_numb_neg(padding, result);
	else 
		tmp = ft_apply_preci_numb_pos(padding, result);
	return (tmp);
}

char *ft_apply_preci(t_data *data, char *result)
{
		if (data->spec == 's')
			result = ft_apply_preci_str(data, result);
		else if (data->spec == 'd' || data->spec == 'i' || data->spec == 'u' || data->spec == 'x' || data->spec == 'X')
			result = ft_apply_preci_numb(data, result);
		return (result);
}