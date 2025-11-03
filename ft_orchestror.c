/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_orchestror.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <algasnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 17:59:02 by algasnie          #+#    #+#             */
/*   Updated: 2025/11/03 10:58:05 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_apply_struct(t_data *data)
{
	int len;

	len = 0;

	//
	if (!data->result || data->spec == '\0')
		return (0);

	if (data->minus)
		data->zero = 0;
	if (data->plus)
		data->space = 0;
	
	//1. Appliquer la précision
	if (data->is_prec)
		data->result = ft_apply_preci(data, data->result);
	//2. Appliquer les flags de signe (+ et ' ' et -)
	if (data->plus || data->space)
		data->result = ft_apply_sign(data, data->result);
	//3. Appliquer le flag # (hash)
	if (data->hash)
		data->result = ft_apply_hash(data, data->result);
	//4. Appliquer le width (padding)
	if(data->width)
		data->result = ft_apply_width(data, data->result);

    // ÉTAPE 6: Afficher et libérer
	len = ft_strlen(data->result);
	write(1, data->result, len);
	free(data->result);
    // ÉTAPE 7: Retourner la longueur
	return (len);
}

void	ft_create_str(t_data *data, va_list args)
{
	if (data->spec == 'c')
		data->result = ft_char_str(va_arg(args, int)); //ok retourne NULL si erreur format_char.c
	else if (data->spec == '%')
		data->result = ft_char_str('%'); //ok retourne NULL si erreur format_char.c
	else if (data->spec == 's')
		data->result = ft_string(va_arg(args, char *)); //ok retourne NULL si erreur format_char.c
	else if (data->spec == 'x' || data->spec == 'X')
		data->result = ft_hex((unsigned long int)va_arg(args, unsigned int), data->spec); //ok retourne NULL si erreur format_char.c
	else if (data->spec == 'p')
		data->result = ft_hex((unsigned long int)va_arg(args, void *), 'p'); //ok retourne NULL si erreur format_hex.c
	else if (data->spec == 'd' || data->spec == 'i')
		data->result = ft_numb(va_arg(args, int)); //ok retourne NULL si erreur format_num.c
	else if (data->spec == 'u')
		data->result = ft_unsigned(va_arg(args, unsigned int)); //ok retourne NULL si erreur format_num.c
}

int	ft_operator(char *str, int *i, va_list args)
{
	int	len;
	t_data	data;

	len = 0;
	ft_init_struct(&data); //ok ft_struct.c
	ft_pars_flags(str, i, &data); //ok ft_struct.c
	ft_pars_width(str, i, &data); //ok ft_struct.c
	ft_pars_preci(str, i, &data); //ok ft_struct.c
	ft_pars_speci(str, i, &data); //ok ft_struct.c
	ft_create_str(&data, args); // ok
	if (!data.result)
		return (-1);
	len = ft_apply_struct(&data); 
	return (len);
}

