/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <algasnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:29:10 by algasnie          #+#    #+#             */
/*   Updated: 2025/11/06 16:04:27 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include "libft/libft.h"

int main(void)
{
	int ft;
	int nor;
	
////////////////////////////////////////////////////////////////////////////////////	
	printf("Prints a single character. \n");
	ft = ft_printf("%c\t", 'c');
	nor = printf("%c\t", 'c');
	printf("%d\n\n", ft - nor);

	ft = ft_printf("%5c\t", 'c');
	nor = printf("%5c\t", 'c');
	printf("%d\n\n", ft - nor);

	ft = ft_printf("%-5c\t", 'c');
	nor = printf("%-5c\t", 'c');
	printf("%d\n\n", ft - nor);
	
////////////////////////////////////////////////////////////////////////////////////
	printf("Prints a string \n");
	ft = ft_printf("%s\t", "Alexandre");
	nor = printf("%s\tn", "Alexandre");
	printf("%d\n\n", ft - nor);

	ft = ft_printf("%10s\t", "Alexandre");
	nor = printf("%10s\t", "Alexandre");
	printf("%d\n\n", ft - nor);

	ft = ft_printf("%-10s\t", "Alexandre");
	nor = printf("%-10s\t", "Alexandre");
	printf("%d\n\n", ft - nor);


////////////////////////////////////////////////////////////////////////////////////
	printf("The void * pointer argument has to be printed in hexadecimal format\n");
	ft = ft_printf("%p\t", &ft);
	nor = printf("%p\t", &ft);
	printf("%d\n\n", ft - nor);

	ft = ft_printf("%15p\t", &ft);
	nor = printf("%15p\t", &ft);
	printf("%d\n\n", ft - nor);	

	ft = ft_printf("%-15p\t", &ft);
	nor = printf("%-15p\t", &ft);
	printf("%d\n\n", ft - nor);


////////////////////////////////////////////////////////////////////////////////////	
	printf("Prints a decimal (base 10) number.\n");
	ft = ft_printf("%d\t", +52);
	nor = printf("%d\t", +52);
	printf("%d\n\n", ft - nor);

	ft = ft_printf("%5d\t", +52);
	nor = printf("%5d\t", +52);
	printf("%d\n\n", ft - nor);

	ft = ft_printf("%-5d\t", +52);
	nor = printf("%-5d\t", +52);
	printf("%d\n\n", ft - nor);

	ft = ft_printf("%05d\t", +52);
	nor = printf("%05d\t", +52);
	printf("%d\n\n", ft - nor);

	ft = ft_printf("% d\t", +52);
	nor = printf("% d\t", +52);
	printf("%d\n\n", ft - nor);

	ft = ft_printf("%+d\t", +52);
	nor = printf("%+d\t", +52);
	printf("%d\n\n", ft - nor);
	

////////////////////////////////////////////////////////////////////////////////////	
	printf("Prints an integer in base 10.\n");
	ft = ft_printf("%i\t", -52);
	nor = printf("%i\t", -52);
	printf("%d\n\n", ft - nor);

	ft = ft_printf("%5i\t", -52);
	nor = printf("%5i\t", -52);
	printf("%d\n\n", ft - nor);
	
	ft = ft_printf("%-5i\t", -52);
	nor = printf("%-5i\t", -52);
	printf("%d\n\n", ft - nor);

	ft = ft_printf("%05i\t", -52);
	nor = printf("%05i\t", -52);
	printf("%d\n\n", ft - nor);

	ft = ft_printf("% i\t", -52);
	nor = printf("% i\t", -52);
	printf("%d\n\n", ft - nor);	

	ft = ft_printf("%+i\t", +52);
	nor = printf("%+i\t", +52);
	printf("%d\n\n", ft - nor);	


////////////////////////////////////////////////////////////////////////////////////	
	printf("Prints an unsigned decimal (base 10) number.\n");
	ft = ft_printf("%u\t", +52);
	nor = printf("%u\t", +52);
	printf("%d\n\n", ft - nor);

	ft = ft_printf("%5u\t", +52);
	nor = printf("%5u\t", +52);
	printf("%d\n\n", ft - nor);	

	ft = ft_printf("%-5u\t", +52);
	nor = printf("%-5u\t", +52);
	printf("%d\n\n", ft - nor);

	ft = ft_printf("%05u\t", +52);
	nor = printf("%05u\t", +52);
	printf("%d\n\n", ft - nor);	


////////////////////////////////////////////////////////////////////////////////////	
	printf("Prints a number in hexadecimal (base 16) lowercase format.\n");
	ft = ft_printf("%x\t", 52);
	nor = printf("%x\t", 52);
	printf("%d\n\n", ft - nor);

	ft = ft_printf("%5x\t", 52);
	nor = printf("%5x\t", 52);
	printf("%d\n\n", ft - nor);

	ft = ft_printf("%-5x\t", 52);
	nor = printf("%-5x\t", 52);
	printf("%d\n\n", ft - nor);

	ft = ft_printf("%05x\t", 52);
	nor = printf("%05x\t", 52);
	printf("%d\n\n", ft - nor);

	ft = ft_printf("%#x\t", 52);
	nor = printf("%#x\t", 52);
	printf("%d\n\n", ft - nor);


////////////////////////////////////////////////////////////////////////////////////	
	printf("Prints a number in hexadecimal (base 16) uppercase format.\n");
	ft = ft_printf("%X\t", 52);
	nor = printf("%X\t", 52);
	printf("%d\n\n", ft - nor);

	ft = ft_printf("%5X\t", 52);
	nor = printf("%5X\t", 52);
	printf("%d\n\n", ft - nor);

	ft = ft_printf("%-5X\t", 52);
	nor = printf("%-5X\t", 52);
	printf("%d\n\n", ft - nor);

	ft = ft_printf("%05X\t", 52);
	nor = printf("%05X\t", 52);
	printf("%d\n\n", ft - nor);

	ft = ft_printf("%#X\t", 52);
	nor = printf("%#X\t", 52);
	printf("%d\n\n", ft - nor);


////////////////////////////////////////////////////////////////////////////////////	
	printf("Prints a percent sign\n");
	ft = ft_printf("%%\t");
	nor = printf("%%\t");
	printf("%d\n\n", ft - nor);

	return (0);
}