/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <algasnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 10:51:17 by algasnie          #+#    #+#             */
/*   Updated: 2025/11/03 15:25:10 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_apply_width_right(t_data *data, char *padding)
{
	char	*tmp;

	tmp = ft_strjoin(data->result, padding);
	free(data->result);
	data->result = tmp;
}

static void	ft_apply_width_left(t_data *data, char *padding)
{
	char	*tmp;

	if (data->zero && (data->result[0] == ' ' || data->result[0] == '+'
			|| data->result[0] == '-'))
	{
		if (data->result[0] == ' ')
			tmp = ft_strjoin(" ", padding);
		else if (data->result[0] == '+')
			tmp = ft_strjoin("+", padding);
		else if (data->result[0] == '-')
			tmp = ft_strjoin("-", padding);
		free(padding);
		padding = ft_strjoin(tmp, data->result + 1);
		free(data->result);
		data->result = padding;
		return ;
	}
	tmp = ft_strjoin(padding, data->result);
	free(data->result);
	data->result = tmp;
}

void	ft_apply_width(t_data *data)
{
	int		len_padding;
	char	*padding;

	len_padding = data->width - (int)ft_strlen(data->result);
	if (len_padding <= 0)
		return ;
	padding = malloc(sizeof(char) * (len_padding + 1));
	if (data->minus)
	{
		ft_memset(padding, ' ', len_padding);
		ft_apply_width_right(data, padding);
	}
	else if (data->zero)
	{
		ft_memset(padding, '0', len_padding);
		ft_apply_width_left(data, padding);
	}
	else
	{
		ft_memset(padding, ' ', len_padding);
		ft_apply_width_left(data, padding);
	}
}
