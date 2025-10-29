/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <algasnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 12:15:42 by algasnie          #+#    #+#             */
/*   Updated: 2025/10/29 21:14:37 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"


void	ft_init_struct(t_data *data)
{

	data->hash = 0;
	data->minus = 0;
	data->zero = 0;
	data->plus = 0;
	data->space = 0;
	data->width = 0;
	data->is_prec = 0;
	data->prec = 0;
}

void	ft_pars_flags(char *str, size_t *i, t_data *data)
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
void	ft_pars_width(char *str, size_t *i, t_data *data)
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
void	ft_pars_preci(char *str, size_t *i, t_data *data)
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

int	ft_putchar_mod(char c, t_data *data)
{
	if (data->minus == 0)
		write(1, &c, 1);
	return (1);
}

int	ft_pars_speci(char *str, size_t *i, t_data *data, va_list args)
{
	int len;

	len = 0;
	if (str[*i] == 'c')
		len += ft_putchar_mod(va_arg(args, int), data);
	/*else if (str[*i] == 's')

	else if (str[*i] == 'p')

	else if (str[*i] == 'd')

	else if (str[*i] == 'i')

	else if (str[*i] == 'u')

	else if (str[*i] == 'x')

	else if (str[*i] == 'X')

	else if (str[*i] == '%')*/
	
	else 
		write(1, &str[*i], 1);

	return (len);
//si le spec n'est pas bon il faut tout afficher
}

size_t	ft_pars_data(char *str, size_t *i, va_list args)
{
	size_t	len;
	t_data	data;

	len = 0;
	ft_init_struct(&data);
	ft_pars_flags(str, i, &data);
	ft_pars_width(str, i, &data);
	ft_pars_preci(str, i, &data);
	len += ft_pars_speci(str, i, &data, args);


	return (len);
}

size_t	ft_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printf(const char *str, ...)
{
	va_list	args; //creation list variables
	va_start(args, str); //fait pointer args apres s

	size_t	i;
	size_t	len_print;
	
	//if (!s)

	i = 0;
	len_print = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len_print += ft_pars_data((char *)str, &i, args); //const casté
		}
		else
		{
			len_print += write(1, &str[i], 1);
		}
		i++;
	}
	va_end(args); //ferme la list
	return (len_print);
}

int	main(void)
{
	int diff1;
	int diff2;

	printf("\n");
	ft_printf("Prints a single character.\n");
	diff1 = ft_printf("%c", 'c');
	printf("\t\t");
	diff2 = printf("%c", 'c');
	printf("\t\tdiff: %d\n", diff1 - diff2);
	
	printf("\n");
	ft_printf("Prints a string (as defined by the common C convention).\n");
	diff1 = ft_printf("%s", "Hello, world!");
	printf("\t");
	diff2 = printf("%s", "Hello, world!");
	printf("\tdiff: %d\n", diff1 - diff2);
	
	//%p The void * pointer argument has to be printed in hexadecimal format.

	printf("\n");
	ft_printf("Prints a decimal (base 10) number.\n");
	diff1 = ft_printf("%d\t", 256);
	printf("\t");
	diff2 = printf("%d\t", 256);
	printf("\tdiff: %d\n", diff1 - diff2);
	
	
	//%i Prints an integer in base 10.
	//%u Prints an unsigned decimal (base 10) number.
	//%x Prints a number in hexadecimal (base 16) lowercase format.
	//%X Prints a number in hexadecimal (base 16) uppercase format.
	
	printf("\n");
	ft_printf("Prints a percent sign.\n");
	diff1 = ft_printf("%%\t");
	printf("\t");
	diff2 = printf("%%\t");
	printf("\tdiff: %d\n", diff1 - diff2);

	return (0);
}
