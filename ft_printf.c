/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <algasnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 12:15:42 by algasnie          #+#    #+#             */
/*   Updated: 2025/10/24 17:34:58 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "libft/libft.h"

int	ft_integer(int i)
{
	char	*convert;
	size_t	len;
	
	convert = ft_itoa(i);
	ft_putstr_fd(convert, 1);
	len = ft_strlen(convert);
	free(convert);
	return (len);
}

int	ft_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_str(char *s)
{
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}

int	ft_pourcent(void)
{
	write(1, "%", 1);
	return (1);
}

/*int	ft_printf(const char *s, ...)
{
	va_list	args; //creation variable
	va_start(args, s); //fait pointer args apres s
	va_arg(args, int); //valeur prochaine variable int
	va_end(args) //ferme la list
}*/

int	ft_printf(const char *s, ...)
{
	va_list	args; //creation variable
	va_start(args, s); //fait pointer args apres s

	size_t	i;
	size_t	len_print;

		//%c Prints a single character.
		//%s Prints a string (as defined by the common C convention).
	//%p The void * pointer argument has to be printed in hexadecimal format.
	//%d Prints a decimal (base 10) number.
	//%i Prints an integer in base 10.
	//%u Prints an unsigned decimal (base 10) number.
	//%x Prints a number in hexadecimal (base 16) lowercase format.
	//%X Prints a number in hexadecimal (base 16) uppercase format.
		//%% Prints a percent sign.
	
	i = 0;
	len_print = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			if (s[i + 1] == 'c')
				len_print += ft_char(va_arg(args, int));
			if (s[i + 1] == 's')
				len_print += ft_str(va_arg(args, char *));
			if (s[i + 1] == 'd')
				len_print += ft_integer(va_arg(args, int));
			if (s[i + 1] == '%')
				len_print += ft_pourcent();
			i += 2;
		}
		else
		{
			write(1, &s[i], 1);
			i++;
			len_print += 1;
		}
	}
	
	//va_arg(args, int); //valeur prochaine variable int
	//va_end(args) //ferme la list
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
