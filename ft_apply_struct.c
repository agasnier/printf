/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <algasnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 17:59:02 by algasnie          #+#    #+#             */
/*   Updated: 2025/11/01 23:40:28 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *ft_create_str(t_data *data, va_list args)
{
	char *str;

	str = NULL;
	if (data->spec == 'c')
		str = ft_char_str(va_arg(args, int));
	else if (data->spec == '%')
		str = ft_char_str('%');
	else if (data->spec == 's')
		str = ft_string(va_arg(args, char *));
	else if (data->spec == 'p')
		str = ft_hex((unsigned long int)va_arg(args, void *), 'p');
	else if (data->spec == 'd' || data->spec == 'i')
		str = ft_numb(va_arg(args, int));
	else if (data->spec == 'u')
		str = ft_unsigned(va_arg(args, unsigned int));
	else if (data->spec == 'x' || data->spec == 'X')
		str = ft_hex((unsigned long int)va_arg(args, unsigned int), data->spec);
	return (str);
}

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

char *ft_apply_preci_str(t_data *data, char *result)
{
	
}

char *ft_apply_preci(t_data *data, char *result)
{
	
}

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

char *ft_apply_width(t_data *data, char *result)
{
	int len_padding;
	char *padding;
	char *tmp;

	len_padding = data->width - (int)ft_strlen(result);
	if (len_padding > 0)
	{
		padding = malloc(sizeof(char) * (len_padding + 1));
		if (!padding)
			return (NULL);
		padding[len_padding] = '\0';
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

int	ft_apply_struct(t_data *data, char *result)
{
	int len;

	len = 0;
	// ÉTAPE 0: Vérifications initiales
	if (!result || data->spec == '\0')
		return (0);
    // ÉTAPE 1: Gérer les conflits de flags
	if (data->minus)
		data->zero = 0;
	if (data->plus)
		data->space = 0;
    // ÉTAPE 2: Appliquer les flags de signe (+ et ' ')
	result = ft_apply_sign(data, result);
    // ÉTAPE 3: Appliquer la précision
	result = ft_apply_preci(data, result);
    // ÉTAPE 4: Appliquer le flag # (hash)
	result = ft_apply_hash(data, result);
    // ÉTAPE 5: Appliquer le width (padding)
	result = ft_apply_width(data, result);
    // ÉTAPE 6: Afficher et libérer
	len = ft_strlen(result);
	write(1, result, len);
	free(result);
    // ÉTAPE 7: Retourner la longueur
	return (len);
}
