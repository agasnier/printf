/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <algasnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 11:36:10 by algasnie          #+#    #+#             */
/*   Updated: 2025/11/01 18:53:39 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
#include "libft/libft.h"

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

// ft_printf.c
void	ft_init_struct(t_data *data);
int		ft_operator(char *str, int *i, va_list args);
int		ft_printf(const char *str, ...);

// ft_format_char.c
char	*ft_char_str(char c);
char	*ft_string(char *s);

// ft_format_num.c
char	*ft_numb(int num);
int		ft_num_len(unsigned long int num, int base_size);
char	*ft_unsigned(unsigned int num);

// ft_format_hex.c
char	*ft_hex(unsigned long int num, char spec);

// ft_pars.c
void	ft_pars_flags(char *str, int *i, t_data *data);
void	ft_pars_width(char *str, int *i, t_data *data);
void	ft_pars_preci(char *str, int *i, t_data *data);
void	ft_pars_speci(char *str, int *i, t_data *data);

// ft_apply_struct.c
int		ft_apply_struct(t_data *data, char *result);
char	*ft_create_str(t_data *data, va_list args);

#endif