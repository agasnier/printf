/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <algasnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 11:36:10 by algasnie          #+#    #+#             */
/*   Updated: 2025/10/29 18:32:11 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_data
{
	int		hash;
	int		minus;
	int		zero;
	int		plus;
	int		space;
	int		width;
	int		is_prec;
	int		prec;
	char	spec;
}	t_data;


#endif