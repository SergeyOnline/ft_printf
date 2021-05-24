/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint_on_right_side.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sbroderi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 13:38:29 by Sbroderi          #+#    #+#             */
/*   Updated: 2020/06/05 13:38:32 by Sbroderi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_wmp_prsn_more_digits(t_flags *flags, char *str, int *i)
{
	while ((*i)++ < (flags->width - flags->prsn) && flags->prsn != DEFAULT)
		ft_putchar(' ', flags);
	(*i)--;
	while ((*i)++ < flags->width - ft_strlen(str))
		ft_putchar('0', flags);
	ft_putstr(str, flags);
}

static void	ft_wmp_prsn_less_digits(t_flags *flags, char *str, int *i)
{
	int size_num;

	size_num = ft_strlen(str);
	while ((*i)++ < flags->width - size_num)
	{
		(flags->zero == DEFAULT || flags->prsn != DEFAULT)
		? ft_putchar(' ', flags) : ft_putchar('0', flags);
	}
	ft_putstr(str, flags);
}

static void	ft_width_more_prsn(t_flags *flags, char *str)
{
	int	i;
	int	size_num;

	i = 0;
	size_num = ft_strlen(str);
	if (flags->prsn > size_num)
		ft_wmp_prsn_more_digits(flags, str, &i);
	else
		ft_wmp_prsn_less_digits(flags, str, &i);
}

static void	ft_prsn_more_width(t_flags *flags, char *str)
{
	int	i;
	int	size_num;

	size_num = ft_strlen(str);
	i = 0;
	while (i++ < flags->prsn - size_num)
		ft_putchar('0', flags);
	ft_putstr(str, flags);
}

void		ft_print_uint_on_right_side(t_flags *flags, unsigned int num)
{
	char	*str;
	int		size_num;

	if (flags->prsn == 0 && num == 0)
		str = ft_strdup("");
	else
	{
		str = (flags->type == T_HEX_L || flags->type == T_HEX_U) ?
				ft_hextoa(num) : ft_uitoa(num);
		if (flags->type == T_HEX_U)
			ft_str_uppercase(str);
	}
	if (!str)
		flags->error = -1;
	size_num = ft_strlen(str);
	if ((flags->prsn == DEFAULT && flags->width == DEFAULT)
		|| (size_num > flags->width
			&& size_num > flags->prsn))
		ft_print_uint_without_flags(flags, num);
	else if (flags->width > flags->prsn)
		ft_width_more_prsn(flags, str);
	else
		ft_prsn_more_width(flags, str);
	free(str);
}
