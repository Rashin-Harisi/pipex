/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 20:53:33 by rabdolho          #+#    #+#             */
/*   Updated: 2025/12/26 11:45:41 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <unistd.h>

static int	valid_specifier(const char str)
{
	if (str == 'c' || str == 's' || str == 'p' || str == 'd'
		|| str == 'u' || str == 'i' || str == 'x' || str == 'X' || str == '%')
		return (1);
	else
		return (0);
}

static void	print_handler(const char str, va_list *args,
	t_flags *flags, int *total_length)
{
	if (str == 'c')
		print_char(va_arg(*args, int), flags, total_length);
	else if (str == 's')
		print_string(va_arg(*args, char *), flags, total_length);
	else if (str == 'p')
		print_pointer(va_arg(*args, void *), flags, total_length);
	else if (str == 'd' || str == 'i')
		print_decimal(va_arg(*args, int), flags, total_length);
	else if (str == 'u')
		print_unsigned(va_arg(*args, unsigned int), flags, total_length);
	else if (str == 'x')
		print_hex_small(va_arg(*args, unsigned int), flags, total_length);
	else if (str == 'X')
		print_hex_big(va_arg(*args, unsigned int), flags, total_length);
	else if (str == '%')
	{
		ft_putchar_fd('%', 1);
		(*total_length)++;
	}
}

static void	format_specifier_handler(const char **str, va_list *args,
	t_flags *flags, int *total_length)
{
	(*str)++;
	ft_memset(flags, 0, sizeof(*flags));
	check_flags(flags, str);
	print_handler(**str, args, flags, total_length);
	if (valid_specifier(**str))
		(*str)++;
	else
	{
		ft_putchar_fd('%', 1);
		ft_putchar_fd(**str, 1);
		(*total_length) += 2;
		(*str)++;
	}
}

static void	print_char_handler(const char **str, int *total_length)
{
	ft_putchar_fd(**str, 1);
	(*total_length)++;
	(*str)++;
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		total_length;
	t_flags	flags;

	if (!str || *str == '\0')
		return (0);
	total_length = 0;
	ft_memset(&flags, 0, sizeof(flags));
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
			format_specifier_handler(&str, &args, &flags, &total_length);
		else if (*str == '\n')
		{
			write(1, "\n", 1);
			total_length++;
			str++;
		}
		else
			print_char_handler(&str, &total_length);
	}
	va_end(args);
	return (total_length);
}

/*
int main()
{
	printf("---------------test character-------------------\n");
	char c = 'C';
	printf("The original : |%5c| \n", c);
	ft_printf("My function : |%5c| \n", c);
	printf("---------------test string-------------------\n");
	char *test = "hello world";
	printf("The original : |%-7.3s| \n", test);
	ft_printf("My function : |%-7.3s| \n", test);
	printf("---------------test pointer-------------------\n");
        char *test_p = "hello world";
        printf("The original: |%020p| \n", test_p);
        ft_printf("My function : |%020p| \n", test_p);
	printf("---------------test integer and decimal -------------------\n");
	printf("the origin : |%-05d| \n" , -42);
	ft_printf("my finction : |%-05d| \n", -42);
	printf("---------------test unsigned int-------------------\n");
	printf("the origin: |%015.11u| \n", 4294967295);
	ft_printf("my function: |%015.11u| \n", 4294967295);
        printf("---------------test hex-small-------------------\n");
        printf("the origin: |%#015.11x| \n", 4294967295);
        ft_printf("my function: |%#015.11x| \n", 4294967295);
        printf("---------------test hex-big-------------------\n");
        printf("the origin: |%#015.11X| \n", 4294967295);
        ft_printf("my function: |%#015.11X| \n", 4294967295);


	return 0;
}*/
