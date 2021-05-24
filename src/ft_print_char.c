/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sbroderi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 15:52:21 by Sbroderi          #+#    #+#             */
/*   Updated: 2020/05/29 15:53:12 by Sbroderi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_print_char(t_flags *flags, char ch)
{
	int		i;
	int		size;

	size = (flags->width > 0) ? (flags->width) : 1;
	i = 0;
	if (flags->minus == DEFAULT)
	{
		while (i++ < size - 1)
			(flags->type == PERCENT && flags->zero != DEFAULT) ?
			ft_putchar('0', flags) : ft_putchar(' ', flags);
		ft_putchar(ch, flags);
	}
	else
	{
		ft_putchar(ch, flags);
		i++;
		while (i++ < size)
			ft_putchar(' ', flags);
	}
}
