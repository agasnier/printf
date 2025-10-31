/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <algasnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 12:15:42 by algasnie          #+#    #+#             */
/*   Updated: 2025/10/31 11:37:17 by algasnie         ###   ########.fr       */
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

int ft_char(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int ft_string(char *s)
{
	if (!s)
		s = "(null)";
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}

int	ft_numb(int num)
{
	char	*c_num;
	int	len;

	len = 0;
	c_num = ft_itoa(num);
	if (!c_num)
		return (-1);
	ft_putstr_fd(c_num, 1);
	len = ft_strlen(c_num);
	free(c_num);
	return (len);
}

int	ft_pars_speci(char *str, int *i, t_data *data, va_list args)
{
	int len;

	len = 0;
	if (str[*i] == 'c')
		len += ft_char(va_arg(args, int));
	else if (str[*i] == 's')
		len += ft_string(va_arg(args, char *));
	//else if (str[*i] == 'p')

	else if (str[*i] == 'd' || str[*i] == 'i')
		len += ft_numb(va_arg(args, int));

	/*else if (str[*i] == 'u')

	else if (str[*i] == 'x')

	else if (str[*i] == 'X')
*/
	else if (str[*i] == '%')
		len += ft_char('%');
	
	else 
		write(1, &str[*i], 1);

	data->minus = 0;
	
	return (len);
//si le spec n'est pas bon il faut tout afficher
}

int	ft_pars_data(char *str, int *i, va_list args)
{
	int	len;
	t_data	data;

	len = 0;
	ft_init_struct(&data);
	ft_pars_flags(str, i, &data);
	ft_pars_width(str, i, &data);
	ft_pars_preci(str, i, &data);
	len += ft_pars_speci(str, i, &data, args);
	//gerer le retour d'erreur à (-1)


	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args; //creation list variables
	va_start(args, str); //fait pointer args apres s

	int	i;
	int	len_print;
	int	len_func;

	if (!str)
		return (-1);

	i = 0;
	len_print = 0;
	len_func = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len_func = ft_pars_data((char *)str, &i, args); //const casté
			if (len_func == -1)
				return (-1);
			len_print += len_func;
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
	diff1 = ft_printf("%c", 'c');
	printf("\t\t");
	diff2 = printf("%c", 'c');
	printf("\t\tdiff: %d\n", diff1 - diff2);
	
	printf("\n");
	diff1 = ft_printf("%s", "Hello, world!");
	printf("\t");
	diff2 = printf("%s", "Hello, world!");
	printf("\tdiff: %d\n", diff1 - diff2);

	printf("\n");
	diff1 = ft_printf("%d", 256);
	printf("\t");
	diff2 = printf("%d", 256);
	printf("\tdiff: %d\n", diff1 - diff2);

	printf("\n");
	diff1 = ft_printf("%i", 256);
	printf("\t");
	diff2 = printf("%i", 256);
	printf("\tdiff: %d\n", diff1 - diff2);

	printf("\n");
	diff1 = ft_printf("%%");
	printf("\t");
	diff2 = printf("%%");
	printf("\tdiff: %d\n", diff1 - diff2);

	return (0);
}
