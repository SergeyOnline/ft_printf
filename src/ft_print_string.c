/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sbroderi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 15:55:19 by Sbroderi          #+#    #+#             */
/*   Updated: 2020/05/29 15:55:25 by Sbroderi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_calculate_size(t_flags *flags, int value_len)
{
	int	size;

	size = value_len;
	if (flags->prsn >= 0)
		size = (flags->prsn > value_len) ? value_len : flags->prsn;
	if (flags->width >= 0)
	{
		if (flags->width > size)
			size += flags->width - size;
	}
	return (size);
}

static int	ft_calculate_spaces(t_flags *flags,
										int size, int val_len)
{
	int spaces;

	if (flags->prsn >= 0)
	{
		if (val_len > flags->prsn)
			spaces = size - flags->prsn;
		else
			spaces = size - val_len;
	}
	else
		spaces = size - val_len;
	return (spaces);
}

void		ft_print_string(t_flags *flags, char *str)
{
	int	size;
	int	i;
	int	j;
	int	spaces;

	i = 0;
	j = 0;
	size = ft_calculate_size(flags, (int)ft_strlen(str));
	spaces = ft_calculate_spaces(flags, size, (int)ft_strlen(str));
	if (flags->minus == DEFAULT)
	{
		while (i++ < spaces)
			ft_putchar(' ', flags);
		i--;
		while (i++ < size)
			ft_putchar(str[j++], flags);
	}
	else
	{
		while (i++ < size - spaces)
			ft_putchar(str[j++], flags);
		i--;
		while (i++ < size)
			ft_putchar(' ', flags);
	}
}
