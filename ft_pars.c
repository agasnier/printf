/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <algasnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 17:58:01 by algasnie          #+#    #+#             */
/*   Updated: 2025/11/01 22:11:03 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pars_flags(char *str, int *i, t_data *data)
{
	while (str[*i] == '#' || str[*i] == '-' || str[*i] == '0' || str[*i] == '+' || str[*i] == ' ')
	{
		if (str[*i] == '#')
			data->hash = 1;
		else if (str[*i] == '-')
			data->minus = 1;
		else if (str[*i] == '0')
			data->zero = 1;
		else if (str[*i] == '+')
			data->plus = 1;
		else if (str[*i] == ' ')
			data->space = 1;
		(*i)++;
	}
}

//gerer la valeur dynamique ???
void	ft_pars_width(char *str, int *i, t_data *data)
{
	int	width;

	width = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		width *= 10;
		width += str[*i] - '0';
		(*i)++;
	}
	data->width = width;
}

//gerer la valeur dynamique ???
void	ft_pars_preci(char *str, int *i, t_data *data)
{
	int	prec;
	
	if (str[*i] != '.')
		return ;

	data->is_prec = 1;
	(*i)++;

	prec = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		prec *= 10;
		prec += str[*i] - '0';
		(*i)++;
	}
	data->prec = prec;
	
}

void	ft_pars_speci(char *str, int *i, t_data *data)
{
	if (str[*i] == 'c' || str[*i] == 'u' || str[*i] == 's' || str[*i] == 'p' || str[*i] == 'd' || str[*i] == 'i' || str[*i] == 'x' || str[*i] == 'X' || str[*i] == '%')
		data->spec = str[*i];
}