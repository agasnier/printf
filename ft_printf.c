/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <algasnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 12:15:42 by algasnie          #+#    #+#             */
/*   Updated: 2025/11/02 10:44:17 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	data->spec = '\0';
}

int	ft_operator(char *str, int *i, va_list args)
{
	int	len;
	t_data	data;
	char *result;

	len = 0;
	ft_init_struct(&data); //ok
	ft_pars_flags(str, i, &data); //ok
	ft_pars_width(str, i, &data); //ok
	ft_pars_preci(str, i, &data); //ok
	ft_pars_speci(str, i, &data); //ok
	result = ft_create_str(&data, args); //ok
	len = ft_apply_struct(&data, result); 
	return (len);
	
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	va_start(args, str);

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
			len_func = ft_operator((char *)str, &i, args);
			if (len_func == -1)
				return (-1);
			len_print += len_func;
		}
		else
			len_print += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (len_print);
}

int	main(void)
{
	int diff1;
	int diff2;
	char *ptr = "Alex";

	printf("\n========== TESTS DE BASE ==========\n");

	// Test %c
	printf("\n[%%c]\n");
	diff1 = ft_printf("%c", 'c');
	printf("\t\t");
	diff2 = printf("%c", 'c');
	printf("\t\tdiff: %d\n", diff1 - diff2);

	// Test %s
	printf("\n\n");
	diff1 = ft_printf("%s", "Hello, world!");
	printf("\t");
	diff2 = printf("%s", "Hello, world!");
	printf("\tdiff: %d\n", diff1 - diff2);

	// Test %s NULL
	printf("\n\n");
	diff1 = ft_printf("%s", (char *)NULL);
	printf("\t\t");
	diff2 = printf("%s", (char *)NULL);
	printf("\t\tdiff: %d\n", diff1 - diff2);

	// Test %d positif
	printf("\n[%d positif]\n", '%');
	diff1 = ft_printf("%d", 256);
	printf("\t\t");
	diff2 = printf("%d", 256);
	printf("\t\tdiff: %d\n", diff1 - diff2);

	// Test %d négatif
	printf("\n[%d negatif]\n", '%');
	diff1 = ft_printf("%d", -256);
	printf("\t\t");
	diff2 = printf("%d", -256);
	printf("\t\tdiff: %d\n", diff1 - diff2);

	// Test %d zero
	printf("\n[%d zero]\n", '%');
	diff1 = ft_printf("%d", 0);
	printf("\t\t");
	diff2 = printf("%d", 0);
	printf("\t\tdiff: %d\n", diff1 - diff2);

	// Test %i
	printf("\n[%i]\n", '%');
	diff1 = ft_printf("%i", 256);
	printf("\t\t");
	diff2 = printf("%i", 256);
	printf("\t\tdiff: %d\n", diff1 - diff2);

	// Test %u
	printf("\n[%u]\n", '%');
	diff1 = ft_printf("%u", 256);
	printf("\t\t");
	diff2 = printf("%u", 256);
	printf("\t\tdiff: %d\n", diff1 - diff2);

	// Test %u max
	printf("\n[%u max]\n", '%');
	diff1 = ft_printf("%u", 4294967295u);
	printf("\t");
	diff2 = printf("%u", 4294967295u);
	printf("\tdiff: %d\n", diff1 - diff2);

	// Test %x
	printf("\n[%x]\n", '%');
	diff1 = ft_printf("%x", 700);
	printf("\t\t");
	diff2 = printf("%x", 700);
	printf("\t\tdiff: %d\n", diff1 - diff2);

	// Test %X
	printf("\n[%X]\n", '%');
	diff1 = ft_printf("%X", 700);
	printf("\t\t");
	diff2 = printf("%X", 700);
	printf("\t\tdiff: %d\n", diff1 - diff2);

	// Test %p
	printf("\n\n");
	diff1 = ft_printf("%p", ptr);
	printf("\t");
	diff2 = printf("%p", ptr);
	printf("\tdiff: %d\n", diff1 - diff2);

	// Test %%
	printf("\n[%%]\n");
	diff1 = ft_printf("%%");
	printf("\t\t");
	diff2 = printf("%%");
	printf("\t\tdiff: %d\n", diff1 - diff2);

	printf("\n========== TESTS FLAGS # ==========\n");

	// Test %#x
	printf("\n[%#x]\n", '%');
	diff1 = ft_printf("%#x", 700);
	printf("\t\t");
	diff2 = printf("%#x", 700);
	printf("\t\tdiff: %d\n", diff1 - diff2);

	// Test %#X
	printf("\n[%#X]\n", '%');
	diff1 = ft_printf("%#X", 700);
	printf("\t\t");
	diff2 = printf("%#X", 700);
	printf("\t\tdiff: %d\n", diff1 - diff2);

	// Test %#x avec 0
	printf("\n[%#x zero]\n", '%');
	diff1 = ft_printf("%#x", 0);
	printf("\t\t");
	diff2 = printf("%#x", 0);
	printf("\t\tdiff: %d\n", diff1 - diff2);

	printf("\n========== TESTS FLAGS + ==========\n");

	// Test %+d positif
	printf("\n[%+d positif]\n", '%');
	diff1 = ft_printf("%+d", 42);
	printf("\t\t");
	diff2 = printf("%+d", 42);
	printf("\t\tdiff: %d\n", diff1 - diff2);

	// Test %+d négatif
	printf("\n[%+d negatif]\n", '%');
	diff1 = ft_printf("%+d", -42);
	printf("\t\t");
	diff2 = printf("%+d", -42);
	printf("\t\tdiff: %d\n", diff1 - diff2);

	// Test %+i
	printf("\n[%+i]\n", '%');
	diff1 = ft_printf("%+i", 42);
	printf("\t\t");
	diff2 = printf("%+i", 42);
	printf("\t\tdiff: %d\n", diff1 - diff2);

	printf("\n========== TESTS FLAGS ESPACE ==========\n");

	// Test % d positif
	printf("\n[%% d positif]\n");
	diff1 = ft_printf("% d", 42);
	printf("\t\t");
	diff2 = printf("% d", 42);
	printf("\t\tdiff: %d\n", diff1 - diff2);

	// Test % d négatif
	printf("\n[%% d negatif]\n");
	diff1 = ft_printf("% d", -42);
	printf("\t\t");
	diff2 = printf("% d", -42);
	printf("\t\tdiff: %d\n", diff1 - diff2);

	printf("\n========== TESTS WIDTH ==========\n");

	// Test %10s
	printf("\n[%%10s]\n");
	diff1 = ft_printf("%10s", "Hello");
	printf("\t");
	diff2 = printf("%10s", "Hello");
	printf("\tdiff: %d\n", diff1 - diff2);

	// Test %10d
	printf("\n[%%10d]\n");
	diff1 = ft_printf("%10d", 42);
	printf("\t");
	diff2 = printf("%10d", 42);
	printf("\tdiff: %d\n", diff1 - diff2);

	// Test %5c
	printf("\n[%%5c]\n");
	diff1 = ft_printf("%5c", 'x');
	printf("\t\t");
	diff2 = printf("%5c", 'x');
	printf("\t\tdiff: %d\n", diff1 - diff2);

	printf("\n========== TESTS FLAG - ==========\n");

	// Test %-10s
	printf("\n[%%-10s]\n");
	diff1 = ft_printf("%-10s", "Hello");
	printf("\t");
	diff2 = printf("%-10s", "Hello");
	printf("\tdiff: %d\n", diff1 - diff2);

	// Test %-10d
	printf("\n[%%-10d]\n");
	diff1 = ft_printf("%-10d", 42);
	printf("\t");
	diff2 = printf("%-10d", 42);
	printf("\tdiff: %d\n", diff1 - diff2);

	printf("\n========== TESTS FLAG 0 ==========\n");

	// Test %010d
	printf("\n[%%010d]\n");
	diff1 = ft_printf("%010d", 42);
	printf("\t");
	diff2 = printf("%010d", 42);
	printf("\tdiff: %d\n", diff1 - diff2);

	// Test %010d
	printf("\n[%%010d]\n");
	diff1 = ft_printf("%010d", -42);
	printf("\t");
	diff2 = printf("%010d", -42);
	printf("\tdiff: %d\n", diff1 - diff2);

	// Test %05x
	printf("\n[%%05x]\n");
	diff1 = ft_printf("%05x", 42);
	printf("\t\t");
	diff2 = printf("%05x", 42);
	printf("\t\tdiff: %d\n", diff1 - diff2);

	printf("\n========== TESTS PRECISION ==========\n");

	// Test %.3s
	printf("\n[%%.3s]\n");
	diff1 = ft_printf("%.3s", "Hello");
	printf("\t\t");
	diff2 = printf("%.3s", "Hello");
	printf("\t\tdiff: %d\n", diff1 - diff2);

	// Test %.10s
	printf("\n[%%.3s]\n");
	diff1 = ft_printf("%.10s", "Hello");
	printf("\t\t");
	diff2 = printf("%.10s", "Hello");
	printf("\t\tdiff: %d\n", diff1 - diff2);

	// Test %.5d
	printf("\n[%%.5d]\n");
	diff1 = ft_printf("%.5d", 42);
	printf("\t\t");
	diff2 = printf("%.5d", 42);
	printf("\t\tdiff: %d\n", diff1 - diff2);

		// Test %.5d
	printf("\n[%%.5d]\n");
	diff1 = ft_printf("%.5d", -42);
	printf("\t\t");
	diff2 = printf("%.5d", -42);
	printf("\t\tdiff: %d\n", diff1 - diff2);

	// Test %.0d avec 0
	printf("\n[%%.0d zero]\n");
	diff1 = ft_printf("%.0d", 0);
	printf("\t\t");
	diff2 = printf("%.0d", 0);
	printf("\t\tdiff: %d\n", diff1 - diff2);

	printf("\n========== TESTS COMBINAISONS ==========\n");

	// Test %10.5d
	printf("\n[%%10.5d]\n");
	diff1 = ft_printf("%10.5d", 42);
	printf("\t");
	diff2 = printf("%10.5d", 42);
	printf("\tdiff: %d\n", diff1 - diff2);

	// Test %-10.5d
	printf("\n[%%-10.5d]\n");
	diff1 = ft_printf("%-10.5d", 42);
	printf("\t");
	diff2 = printf("%-10.5d", 42);
	printf("\tdiff: %d\n", diff1 - diff2);

	// Test %#10x
	printf("\n[%%#10x]\n");
	diff1 = ft_printf("%#10x", 42);
	printf("\t");
	diff2 = printf("%#10x", 42);
	printf("\tdiff: %d\n", diff1 - diff2);

	// Test %+10d
	printf("\n[%%+10d]\n");
	diff1 = ft_printf("%+10d", 42);
	printf("\t");
	diff2 = printf("%+10d", 42);
	printf("\tdiff: %d\n", diff1 - diff2);

	printf("\n========== TESTS MULTIPLES ==========\n");

	// Test multiple formats
	printf("\n[Multiple]\n");
	diff1 = ft_printf("%d %s %x", 42, "test", 255);
	printf("\t");
	diff2 = printf("%d %s %x", 42, "test", 255);
	printf("\tdiff: %d\n", diff1 - diff2);

	printf("\n========================================\n");

	return (0);
}
