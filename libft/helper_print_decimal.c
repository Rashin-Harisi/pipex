/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_print_decimal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 10:00:30 by rabdolho          #+#    #+#             */
/*   Updated: 2025/12/26 11:46:49 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char	*sign_nbr_handler_decimal(char *sign, int n, t_flags *flags)
{
	int	nbr;

	nbr = n;
	if (n < 0)
	{
		*sign = '-';
		if (n == -2147483648)
			return (ft_strdup("2147483648"));
		nbr = -n;
	}
	else if (flags->plus == 1)
		*sign = '+';
	else if (flags->space == 1)
		*sign = ' ';
	return (ft_itoa(nbr));
}

int	width_handler_decimal(t_flags *flags, int *zero_precision,
	int length, char sign)
{
	int	width;

	if (flags->dot == 1)
		flags->zero = 0;
	if (flags->dot == 1 && flags->precision > length)
		*zero_precision = flags->precision - length;
	if (sign)
		width = flags->width - length - (*zero_precision) - 1;
	else
		width = flags->width - length - (*zero_precision);
	if (width < 0)
		width = 0;
	return (width);
}

void	sign_zero_handler_decimal(char sign, int *total_length,
	int *zero_precision)
{
	if (sign)
	{
		ft_putchar_fd(sign, 1);
		(*total_length)++;
	}
	while ((*zero_precision)-- > 0)
	{
		ft_putchar_fd('0', 1);
		(*total_length)++;
	}
}

void	no_flags_minus_decimal(t_flags *flags, int *width,
	int *total_length, char *sign)
{
	char	c;

	if (flags->dot || !flags->zero)
		c = ' ';
	else
	{
		if (*sign)
		{
			ft_putchar_fd(*sign, 1);
			(*total_length)++;
			*sign = 0;
		}
		c = '0';
	}
	while ((*width)--)
	{
		ft_putchar_fd(c, 1);
		(*total_length)++;
	}
}

void	yes_flags_minus_decimal(int *width, int *total_length)
{
	while ((*width)--)
	{
		ft_putchar_fd(' ', 1);
		(*total_length)++;
	}
}
