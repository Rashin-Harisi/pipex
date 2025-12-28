/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 14:36:43 by rabdolho          #+#    #+#             */
/*   Updated: 2025/12/26 11:44:35 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	flag_update(t_flags *flags, const char **str)
{
	if (**str == '-')
		flags->minus = 1;
	if (**str == '+')
		flags->plus = 1;
	if (**str == '#')
		flags->hash = 1;
	if (**str == '0')
		flags->zero = 1;
	if (**str == ' ')
		flags->space = 1;
	(*str)++;
}

void	check_flags(t_flags *flags, const char **str)
{
	while (**str == '-' || **str == '0' || **str == '#'
		|| **str == '+' || **str == ' ')
		flag_update(flags, str);
	if (ft_isdigit(**str))
	{
		flags->width = ft_atoi(*str);
		while (ft_isdigit(**str))
			(*str)++;
	}
	if (**str == '.')
	{
		flags->dot = 1;
		(*str)++;
	}
	if (ft_isdigit(**str))
	{
		flags->precision = ft_atoi(*str);
		while (ft_isdigit(**str))
		{
			(*str)++;
		}
	}
	else
		flags->precision = 0;
}
