/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <algasnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:02:57 by algasnie          #+#    #+#             */
/*   Updated: 2025/11/03 21:40:00 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <string.h>
#include <limits.h>

int main(void)
{
	int ft_printf;
	int printf;

        print(" %c %c %c ", '0', 0, '1'));
        print(" %c %c %c ", '1', '2', '3'));
        print(" %c %c %c ", '2', '1', 0));
        print(" %c %c %c ", 0, '1', '2'));

For /home/alex/francinette/tests/printf/printfTester/tests/s_test.cpp:
32:     TEST(6, print(" %s %s ", "", "-"));
33:     TEST(7, print(" %s %s ", " - ", ""));
34:     TEST(8, print(" %s %s %s %s %s", " - ", "", "4", "", s2));
35:     TEST(9, print(" %s %s %s %s %s ", " - ", "", "4", "", "2 "));

For /home/alex/francinette/tests/printf/printfTester/tests/p_test.cpp:
30:     TEST(6, print(" %p %p ", LONG_MIN, LONG_MAX));
31:     TEST(7, print(" %p %p ", INT_MIN, INT_MAX));
32:     TEST(8, print(" %p %p ", ULONG_MAX, -ULONG_MAX));

For /home/alex/francinette/tests/printf/printfTester/tests/d_test.cpp:
53:     TEST(29, print(" %d %d %d %d %d %d %d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));


	return 0;
}
