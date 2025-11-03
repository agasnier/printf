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
	int ret1, ret2;
	char *ptr = "Hello";

	printf("\n════════════════════════════════════════════════════════════════════════════\n");
	printf("                       FT_PRINTF COMPREHENSIVE TEST\n");
	printf("════════════════════════════════════════════════════════════════════════════\n\n");

	// Test %c normal
	printf("Test: %%c normal\n");
	printf("ft_printf: ");
	ret1 = ft_printf("%c", 'A');
	printf("%*s", 30 - ret1, "");
	printf("printf: ");
	ret2 = printf("%c", 'A');
	if (ret1 != ret2) printf("  [FAIL %d vs %d]", ret1, ret2);
	else printf("  [OK]");
	printf("\n\n");

	// Test %c null
	printf("Test: %%c null\n");
	printf("ft_printf: ");
	ret1 = ft_printf("%c", 0);
	printf("%*s", 30 - ret1, "");
	printf("printf: ");
	ret2 = printf("%c", 0);
	if (ret1 != ret2) printf("  [FAIL %d vs %d]", ret1, ret2);
	else printf("  [OK]");
	printf("\n\n");

	// Test %s normal
	printf("Test: %%s normal\n");
	printf("ft_printf: ");
	ret1 = ft_printf("%s", "Hello");
	printf("%*s", 30 - ret1, "");
	printf("printf: ");
	ret2 = printf("%s", "Hello");
	if (ret1 != ret2) printf("  [FAIL %d vs %d]", ret1, ret2);
	else printf("  [OK]");
	printf("\n\n");

	// Test %s NULL
	printf("Test: %%s NULL\n");
	printf("ft_printf: ");
	ret1 = ft_printf("%s", (char *)NULL);
	printf("%*s", 30 - ret1, "");
	printf("printf: ");
	ret2 = printf("%s", (char *)NULL);
	if (ret1 != ret2) printf("  [FAIL %d vs %d]", ret1, ret2);
	else printf("  [OK]");
	printf("\n\n");

	// Test %s empty
	printf("Test: %%s empty\n");
	printf("ft_printf: ");
	ret1 = ft_printf("%s", "");
	printf("%*s", 30 - ret1, "");
	printf("printf: ");
	ret2 = printf("%s", "");
	if (ret1 != ret2) printf("  [FAIL %d vs %d]", ret1, ret2);
	else printf("  [OK]");
	printf("\n\n");

	// Test %d positive
	printf("Test: %%d positive (42)\n");
	printf("ft_printf: ");
	ret1 = ft_printf("%d", 42);
	printf("%*s", 30 - ret1, "");
	printf("printf: ");
	ret2 = printf("%d", 42);
	if (ret1 != ret2) printf("  [FAIL %d vs %d]", ret1, ret2);
	else printf("  [OK]");
	printf("\n\n");

	// Test %d negative
	printf("Test: %%d negative (-42)\n");
	printf("ft_printf: ");
	ret1 = ft_printf("%d", -42);
	printf("%*s", 30 - ret1, "");
	printf("printf: ");
	ret2 = printf("%d", -42);
	if (ret1 != ret2) printf("  [FAIL %d vs %d]", ret1, ret2);
	else printf("  [OK]");
	printf("\n\n");

	// Test %d zero
	printf("Test: %%d zero\n");
	printf("ft_printf: ");
	ret1 = ft_printf("%d", 0);
	printf("%*s", 30 - ret1, "");
	printf("printf: ");
	ret2 = printf("%d", 0);
	if (ret1 != ret2) printf("  [FAIL %d vs %d]", ret1, ret2);
	else printf("  [OK]");
	printf("\n\n");

	// Test %d INT_MAX
	printf("Test: %%d INT_MAX\n");
	printf("ft_printf: ");
	ret1 = ft_printf("%d", INT_MAX);
	printf("%*s", 30 - ret1, "");
	printf("printf: ");
	ret2 = printf("%d", INT_MAX);
	if (ret1 != ret2) printf("  [FAIL %d vs %d]", ret1, ret2);
	else printf("  [OK]");
	printf("\n\n");

	// Test %d INT_MIN
	printf("Test: %%d INT_MIN\n");
	printf("ft_printf: ");
	ret1 = ft_printf("%d", INT_MIN);
	printf("%*s", 30 - ret1, "");
	printf("printf: ");
	ret2 = printf("%d", INT_MIN);
	if (ret1 != ret2) printf("  [FAIL %d vs %d]", ret1, ret2);
	else printf("  [OK]");
	printf("\n\n");

	// Test %i
	printf("Test: %%i (42)\n");
	printf("ft_printf: ");
	ret1 = ft_printf("%i", 42);
	printf("%*s", 30 - ret1, "");
	printf("printf: ");
	ret2 = printf("%i", 42);
	if (ret1 != ret2) printf("  [FAIL %d vs %d]", ret1, ret2);
	else printf("  [OK]");
	printf("\n\n");

	// Test %u
	printf("Test: %%u (42)\n");
	printf("ft_printf: ");
	ret1 = ft_printf("%u", 42);
	printf("%*s", 30 - ret1, "");
	printf("printf: ");
	ret2 = printf("%u", 42);
	if (ret1 != ret2) printf("  [FAIL %d vs %d]", ret1, ret2);
	else printf("  [OK]");
	printf("\n\n");

	// Test %u zero
	printf("Test: %%u zero\n");
	printf("ft_printf: ");
	ret1 = ft_printf("%u", 0);
	printf("%*s", 30 - ret1, "");
	printf("printf: ");
	ret2 = printf("%u", 0);
	if (ret1 != ret2) printf("  [FAIL %d vs %d]", ret1, ret2);
	else printf("  [OK]");
	printf("\n\n");

	// Test %u UINT_MAX
	printf("Test: %%u UINT_MAX\n");
	printf("ft_printf: ");
	ret1 = ft_printf("%u", UINT_MAX);
	printf("%*s", 30 - ret1, "");
	printf("printf: ");
	ret2 = printf("%u", UINT_MAX);
	if (ret1 != ret2) printf("  [FAIL %d vs %d]", ret1, ret2);
	else printf("  [OK]");
	printf("\n\n");

	// Test %x
	printf("Test: %%x (255)\n");
	printf("ft_printf: ");
	ret1 = ft_printf("%x", 255);
	printf("%*s", 30 - ret1, "");
	printf("printf: ");
	ret2 = printf("%x", 255);
	if (ret1 != ret2) printf("  [FAIL %d vs %d]", ret1, ret2);
	else printf("  [OK]");
	printf("\n\n");

	// Test %x zero
	printf("Test: %%x zero\n");
	printf("ft_printf: ");
	ret1 = ft_printf("%x", 0);
	printf("%*s", 30 - ret1, "");
	printf("printf: ");
	ret2 = printf("%x", 0);
	if (ret1 != ret2) printf("  [FAIL %d vs %d]", ret1, ret2);
	else printf("  [OK]");
	printf("\n\n");

	// Test %X
	printf("Test: %%X (255)\n");
	printf("ft_printf: ");
	ret1 = ft_printf("%X", 255);
	printf("%*s", 30 - ret1, "");
	printf("printf: ");
	ret2 = printf("%X", 255);
	if (ret1 != ret2) printf("  [FAIL %d vs %d]", ret1, ret2);
	else printf("  [OK]");
	printf("\n\n");

	// Test %p
	printf("Test: %%p (pointer)\n");
	printf("ft_printf: ");
	ret1 = ft_printf("%p", ptr);
	printf("%*s", 30 - ret1, "");
	printf("printf: ");
	ret2 = printf("%p", ptr);
	if (ret1 != ret2) printf("  [FAIL %d vs %d]", ret1, ret2);
	else printf("  [OK]");
	printf("\n\n");

	// Test %p NULL
	printf("Test: %%p NULL\n");
	printf("ft_printf: ");
	ret1 = ft_printf("%p", NULL);
	printf("%*s", 30 - ret1, "");
	printf("printf: ");
	ret2 = printf("%p", NULL);
	if (ret1 != ret2) printf("  [FAIL %d vs %d]", ret1, ret2);
	else printf("  [OK]");
	printf("\n\n");

	// Test %%
	printf("Test: %%%%\n");
	printf("ft_printf: ");
	ret1 = ft_printf("%%");
	printf("%*s", 30 - ret1, "");
	printf("printf: ");
	ret2 = printf("%%");
	if (ret1 != ret2) printf("  [FAIL %d vs %d]", ret1, ret2);
	else printf("  [OK]");
	printf("\n\n");

	// Test with width
	printf("Test: |%%10s| with 'Hi'\n");
	printf("ft_printf: ");
	ret1 = ft_printf("|%10s|", "Hi");
	printf("%*s", 30 - ret1, "");
	printf("printf: ");
	ret2 = printf("|%10s|", "Hi");
	if (ret1 != ret2) printf("  [FAIL %d vs %d]", ret1, ret2);
	else printf("  [OK]");
	printf("\n\n");

	printf("Test: |%%10d| with 42\n");
	printf("ft_printf: ");
	ret1 = ft_printf("|%10d|", 42);
	printf("%*s", 30 - ret1, "");
	printf("printf: ");
	ret2 = printf("|%10d|", 42);
	if (ret1 != ret2) printf("  [FAIL %d vs %d]", ret1, ret2);
	else printf("  [OK]");
	printf("\n\n");

	printf("Test: |%%-10s| with 'Hi'\n");
	printf("ft_printf: ");
	ret1 = ft_printf("|%-10s|", "Hi");
	printf("%*s", 30 - ret1, "");
	printf("printf: ");
	ret2 = printf("|%-10s|", "Hi");
	if (ret1 != ret2) printf("  [FAIL %d vs %d]", ret1, ret2);
	else printf("  [OK]");
	printf("\n\n");

	printf("Test: |%%-10d| with 42\n");
	printf("ft_printf: ");
	ret1 = ft_printf("|%-10d|", 42);
	printf("%*s", 30 - ret1, "");
	printf("printf: ");
	ret2 = printf("|%-10d|", 42);
	if (ret1 != ret2) printf("  [FAIL %d vs %d]", ret1, ret2);
	else printf("  [OK]");
	printf("\n\n");

	// Test with zero padding
	printf("Test: |%%010d| with 42\n");
	printf("ft_printf: ");
	ret1 = ft_printf("|%010d|", 42);
	printf("%*s", 30 - ret1, "");
	printf("printf: ");
	ret2 = printf("|%010d|", 42);
	if (ret1 != ret2) printf("  [FAIL %d vs %d]", ret1, ret2);
	else printf("  [OK]");
	printf("\n\n");

	printf("Test: |%%010d| with -42\n");
	printf("ft_printf: ");
	ret1 = ft_printf("|%010d|", -42);
	printf("%*s", 30 - ret1, "");
	printf("printf: ");
	ret2 = printf("|%010d|", -42);
	if (ret1 != ret2) printf("  [FAIL %d vs %d]", ret1, ret2);
	else printf("  [OK]");
	printf("\n\n");

	// Test with precision
	printf("Test: |%%.3s| with 'Hello'\n");
	printf("ft_printf: ");
	ret1 = ft_printf("|%.3s|", "Hello");
	printf("%*s", 30 - ret1, "");
	printf("printf: ");
	ret2 = printf("|%.3s|", "Hello");
	if (ret1 != ret2) printf("  [FAIL %d vs %d]", ret1, ret2);
	else printf("  [OK]");
	printf("\n\n");

	printf("Test: |%%.0s| with 'Hello'\n");
	printf("ft_printf: ");
	ret1 = ft_printf("|%.0s|", "Hello");
	printf("%*s", 30 - ret1, "");
	printf("printf: ");
	ret2 = printf("|%.0s|", "Hello");
	if (ret1 != ret2) printf("  [FAIL %d vs %d]", ret1, ret2);
	else printf("  [OK]");
	printf("\n\n");

	printf("Test: |%%.5d| with 42\n");
	printf("ft_printf: ");
	ret1 = ft_printf("|%.5d|", 42);
	printf("%*s", 30 - ret1, "");
	printf("printf: ");
	ret2 = printf("|%.5d|", 42);
	if (ret1 != ret2) printf("  [FAIL %d vs %d]", ret1, ret2);
	else printf("  [OK]");
	printf("\n\n");

	printf("Test: |%%.5d| with -42\n");
	printf("ft_printf: ");
	ret1 = ft_printf("|%.5d|", -42);
	printf("%*s", 30 - ret1, "");
	printf("printf: ");
	ret2 = printf("|%.5d|", -42);
	if (ret1 != ret2) printf("  [FAIL %d vs %d]", ret1, ret2);
	else printf("  [OK]");
	printf("\n\n");

	printf("Test: |%%.0d| with 0\n");
	printf("ft_printf: ");
	ret1 = ft_printf("|%.0d|", 0);
	printf("%*s", 30 - ret1, "");
	printf("printf: ");
	ret2 = printf("|%.0d|", 0);
	if (ret1 != ret2) printf("  [FAIL %d vs %d]", ret1, ret2);
	else printf("  [OK]");
	printf("\n\n");

	// Test with +
	printf("Test: %%+d with 42\n");
	printf("ft_printf: ");
	ret1 = ft_printf("%+d", 42);
	printf("%*s", 30 - ret1, "");
	printf("printf: ");
	ret2 = printf("%+d", 42);
	if (ret1 != ret2) printf("  [FAIL %d vs %d]", ret1, ret2);
	else printf("  [OK]");
	printf("\n\n");

	printf("Test: %%+d with -42\n");
	printf("ft_printf: ");
	ret1 = ft_printf("%+d", -42);
	printf("%*s", 30 - ret1, "");
	printf("printf: ");
	ret2 = printf("%+d", -42);
	if (ret1 != ret2) printf("  [FAIL %d vs %d]", ret1, ret2);
	else printf("  [OK]");
	printf("\n\n");

	printf("Test: %%+d with 0\n");
	printf("ft_printf: ");
	ret1 = ft_printf("%+d", 0);
	printf("%*s", 30 - ret1, "");
	printf("printf: ");
	ret2 = printf("%+d", 0);
	if (ret1 != ret2) printf("  [FAIL %d vs %d]", ret1, ret2);
	else printf("  [OK]");
	printf("\n\n");

	// Test with space
	printf("Test: %% d with 42\n");
	printf("ft_printf: ");
	ret1 = ft_printf("% d", 42);
	printf("%*s", 30 - ret1, "");
	printf("printf: ");
	ret2 = printf("% d", 42);
	if (ret1 != ret2) printf("  [FAIL %d vs %d]", ret1, ret2);
	else printf("  [OK]");
	printf("\n\n");

	printf("Test: %% d with -42\n");
	printf("ft_printf: ");
	ret1 = ft_printf("% d", -42);
	printf("%*s", 30 - ret1, "");
	printf("printf: ");
	ret2 = printf("% d", -42);
	if (ret1 != ret2) printf("  [FAIL %d vs %d]", ret1, ret2);
	else printf("  [OK]");
	printf("\n\n");

	// Test with #
	printf("Test: %%#x with 255\n");
	printf("ft_printf: ");
	ret1 = ft_printf("%#x", 255);
	printf("%*s", 30 - ret1, "");
	printf("printf: ");
	ret2 = printf("%#x", 255);
	if (ret1 != ret2) printf("  [FAIL %d vs %d]", ret1, ret2);
	else printf("  [OK]");
	printf("\n\n");

	printf("Test: %%#X with 255\n");
	printf("ft_printf: ");
	ret1 = ft_printf("%#X", 255);
	printf("%*s", 30 - ret1, "");
	printf("printf: ");
	ret2 = printf("%#X", 255);
	if (ret1 != ret2) printf("  [FAIL %d vs %d]", ret1, ret2);
	else printf("  [OK]");
	printf("\n\n");

	printf("Test: %%#x with 0\n");
	printf("ft_printf: ");
	ret1 = ft_printf("%#x", 0);
	printf("%*s", 30 - ret1, "");
	printf("printf: ");
	ret2 = printf("%#x", 0);
	if (ret1 != ret2) printf("  [FAIL %d vs %d]", ret1, ret2);
	else printf("  [OK]");
	printf("\n\n");

	// Combinations
	printf("Test: |%%10.5d| with 42\n");
	printf("ft_printf: ");
	ret1 = ft_printf("|%10.5d|", 42);
	printf("%*s", 30 - ret1, "");
	printf("printf: ");
	ret2 = printf("|%10.5d|", 42);
	if (ret1 != ret2) printf("  [FAIL %d vs %d]", ret1, ret2);
	else printf("  [OK]");
	printf("\n\n");

	printf("Test: |%%-10.5d| with 42\n");
	printf("ft_printf: ");
	ret1 = ft_printf("|%-10.5d|", 42);
	printf("%*s", 30 - ret1, "");
	printf("printf: ");
	ret2 = printf("|%-10.5d|", 42);
	if (ret1 != ret2) printf("  [FAIL %d vs %d]", ret1, ret2);
	else printf("  [OK]");
	printf("\n\n");

	printf("Test: |%%#10x| with 42\n");
	printf("ft_printf: ");
	ret1 = ft_printf("|%#10x|", 42);
	printf("%*s", 30 - ret1, "");
	printf("printf: ");
	ret2 = printf("|%#10x|", 42);
	if (ret1 != ret2) printf("  [FAIL %d vs %d]", ret1, ret2);
	else printf("  [OK]");
	printf("\n\n");

	printf("Test: |%%+010d| with 42\n");
	printf("ft_printf: ");
	ret1 = ft_printf("|%+010d|", 42);
	printf("%*s", 30 - ret1, "");
	printf("printf: ");
	ret2 = printf("|%+010d|", 42);
	if (ret1 != ret2) printf("  [FAIL %d vs %d]", ret1, ret2);
	else printf("  [OK]");
	printf("\n\n");

	printf("Test: |%% 010d| with 42\n");
	printf("ft_printf: ");
	ret1 = ft_printf("|% 010d|", 42);
	printf("%*s", 30 - ret1, "");
	printf("printf: ");
	ret2 = printf("|% 010d|", 42);
	if (ret1 != ret2) printf("  [FAIL %d vs %d]", ret1, ret2);
	else printf("  [OK]");
	printf("\n\n");

	// Mix
	printf("Test: %%d %%s %%x mixed\n");
	printf("ft_printf: ");
	ret1 = ft_printf("%d %s %x", 42, "test", 255);
	printf("%*s", 30 - ret1, "");
	printf("printf: ");
	ret2 = printf("%d %s %x", 42, "test", 255);
	if (ret1 != ret2) printf("  [FAIL %d vs %d]", ret1, ret2);
	else printf("  [OK]");
	printf("\n\n");

	printf("Test: No format specifiers\n");
	printf("ft_printf: ");
	ret1 = ft_printf("Hello World");
	printf("%*s", 30 - ret1, "");
	printf("printf: ");
	ret2 = printf("Hello World");
	if (ret1 != ret2) printf("  [FAIL %d vs %d]", ret1, ret2);
	else printf("  [OK]");
	printf("\n\n");

	printf("Test: Empty string\n");
	printf("ft_printf: ");
	ret1 = ft_printf("");
	printf("%*s", 30 - ret1, "");
	printf("printf: ");
	ret2 = printf("");
	if (ret1 != ret2) printf("  [FAIL %d vs %d]", ret1, ret2);
	else printf("  [OK]");
	printf("\n\n");

	printf("════════════════════════════════════════════════════════════════════════════\n");
	printf("                          Tests completed\n");
	printf("════════════════════════════════════════════════════════════════════════════\n\n");

	return 0;
}
