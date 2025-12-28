/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:54:59 by rabdolho          #+#    #+#             */
/*   Updated: 2025/12/26 11:48:44 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	flags_minus(int *width, int *total_length)
{
	while ((*width)--)
	{
		ft_putchar_fd(' ', 1);
		(*total_length)++;
	}
}

void	print_string(char *str, t_flags *flags, int *total_length)
{
	int	width;
	int	length;
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	length = ft_strlen(str);
	if (flags->dot == 1 && (flags->precision < length))
		length = flags->precision;
	if (flags->width > length)
		width = flags->width - length;
	else
		width = 0;
	if (flags->minus == 0)
		flags_minus(&width, total_length);
	while (i < length)
	{
		ft_putchar_fd(str[i++], 1);
		(*total_length)++;
	}
	if (flags->minus == 1)
		flags_minus(&width, total_length);
}
