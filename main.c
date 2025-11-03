/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <algasnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:02:57 by algasnie          #+#    #+#             */
/*   Updated: 2025/11/03 15:44:13 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	int diff1;
	int diff2;
	char *ptr = "Alex";

	printf("\n========== TESTS DE BASE ==========\n");
	// Test string seule
	printf("\n[%%c]\n");
	diff1 = ft_printf("Alexandre");
	printf("\t\t");
	diff2 = printf("Alexandre");
	printf("\t\tdiff: %d\n", diff1 - diff2);
	
		
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

	// Test %010d
	printf("\n[%%+010d]\n");
	diff1 = ft_printf("%+010d", 42);
	printf("\t");
	diff2 = printf("%+010d", 42);
	printf("\tdiff: %d\n", diff1 - diff2);

	// Test % 010d
	printf("\n[%% 010d]\n");
	diff1 = ft_printf("% 010d", 42);
	printf("\t");
	diff2 = printf("% 010d", 42);
	printf("\tdiff: %d\n", diff1 - diff2);

	// Test %05x
	printf("\n[%%05x]\n");
	diff1 = ft_printf("%05x", 42);
	printf("\t\t");
	diff2 = printf("%05x", 42);
	printf("\t\tdiff: %d\n", diff1 - diff2);

		// Test %05x
	printf("\n[%%05x]\n");
	diff1 = ft_printf("%x", 42);
	printf("\t\t");
	diff2 = printf("%x", 42);
	printf("\t\tdiff: %d\n", diff1 - diff2);

	printf("\n========== TESTS PRECISION ==========\n");

	// Test %.3s
	printf("\n[%%.0s]\n");
	diff1 = ft_printf("%.0s", "Hello");
	printf("\t\t");
	diff2 = printf("%.0s", "Hello");
	printf("\t\tdiff: %d\n", diff1 - diff2);
	
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

		// Test %.3s
	printf("\n[%%.0d]\n");
	diff1 = ft_printf("%.0d", 42);
	printf("\t\t");
	diff2 = printf("%.0d", 42);
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

	printf("\n[Multiple]\n");
	diff1 = ft_printf(NULL, 42);
	printf("\t");
	diff2 = printf(NULL, 42);
	printf("\tdiff: %d\n", diff1 - diff2);

	return (0);
}