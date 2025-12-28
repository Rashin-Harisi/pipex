/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 10:00:30 by rabdolho          #+#    #+#             */
/*   Updated: 2025/12/26 11:47:27 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void	print_decimal(int n, t_flags *flags, int *total_length)
{
	int		width;
	char	*nbr;
	int		length;
	char	sign;
	int		zero_precision;

	sign = 0;
	zero_precision = 0;
	if (n == 0)
		nbr = ft_strdup("0");
	else
		nbr = sign_nbr_handler_decimal(&sign, n, flags);
	length = ft_strlen(nbr);
	if (flags->dot && n == 0 && flags->precision == 0)
		length = 0;
	width = width_handler_decimal(flags, &zero_precision, length, sign);
	if (flags->minus == 0)
		no_flags_minus_decimal(flags, &width, total_length, &sign);
	sign_zero_handler_decimal(sign, total_length, &zero_precision);
	write(1, nbr, length);
	(*total_length) += length;
	if (flags->minus == 1)
		yes_flags_minus_decimal(&width, total_length);
	free(nbr);
}
