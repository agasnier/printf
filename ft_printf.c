/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <algasnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 12:15:42 by algasnie          #+#    #+#             */
/*   Updated: 2025/10/24 14:45:29 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "libft/libft.h"

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

	unsigned int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			ft_putnbr_fd(va_arg(args, int), 1);
			i++;
		}
		else
			write(1, &s[i], 1);
		i++;
	}
	write(1, "\n", 1);
	
	//va_arg(args, int); //valeur prochaine variable int
	//va_end(args) //ferme la list
	return (0);
}

int	main(void)
{
	ft_printf("Ecole %d ! Ecole %d !", 42, 43);
	return (0);
}
