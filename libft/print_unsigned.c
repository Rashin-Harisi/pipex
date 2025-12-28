/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 16:35:44 by rabdolho          #+#    #+#             */
/*   Updated: 2025/12/26 11:49:02 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

static int	width_zero_handler(t_flags *flags,
	int *zero_precision, int *length)
{
	int		width;

	if (flags->dot == 1)
		flags->zero = 0;
	if (flags->dot == 1 && flags->precision > *length)
		*zero_precision = flags->precision - (*length);
	width = flags->width - (*length) - (*zero_precision);
	if (width < 0)
		width = 0;
	return (width);
}

static void	zero_print_handler(int *width, int *total_length)
{
	while ((*width)-- > 0)
	{
		ft_putchar_fd('0', 1);
		(*total_length)++;
	}
}

static void	space_print_handler(int *width, int *total_length)
{
	while ((*width)--)
	{
		ft_putchar_fd(' ', 1);
		(*total_length)++;
	}
}

static void	no_flags_minus(t_flags *flags, int *width, int *total_length,
	int *zero_precision)
{
	if (flags->dot)
	{
		space_print_handler(width, total_length);
		zero_print_handler(zero_precision, total_length);
	}
	else if (flags->zero)
		zero_print_handler(width, total_length);
	else
		space_print_handler(width, total_length);
}

void	print_unsigned(unsigned int n, t_flags *flags, int *total_length)
{
	int		width;
	char	*nbr;
	int		zero_precision;
	int		length;

	zero_precision = 0;
	nbr = ft_utoa(n);
	length = ft_strlen(nbr);
	if (flags->dot && n == 0 && flags->precision == 0)
		length = 0;
	width = width_zero_handler(flags, &zero_precision, &length);
	if (flags->minus == 0)
		no_flags_minus(flags, &width, total_length, &zero_precision);
	zero_print_handler(&zero_precision, total_length);
	write(1, nbr, length);
	(*total_length) += length;
	if (flags->minus == 1)
		space_print_handler(&width, total_length);
	free(nbr);
}
