/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_on_right_side.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sbroderi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 14:17:21 by Sbroderi          #+#    #+#             */
/*   Updated: 2020/06/03 14:17:24 by Sbroderi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_wmp_prsn_more_digits(t_flags *flags,
									int num, char *str, int *i)
{
	while ((*i)++ < (flags->width - flags->prsn) && flags->prsn != DEFAULT)
	{
		if ((*i) == flags->width - flags->prsn && flags->plus != DEFAULT
			&& num >= 0)
			ft_putchar('+', flags);
		else if ((*i) == flags->width - flags->prsn && num < 0)
			ft_putchar('-', flags);
		else
			ft_putchar(' ', flags);
	}
	(*i)--;
	while ((*i)++ < flags->width - (int)ft_strlen(str))
		ft_putchar('0', flags);
	ft_putstr(str, flags);
}

static void	ft_wmp_prsn_less_digits(t_flags *flags,
									int num, char *str, int *i)
{
	if (num < 0 && flags->zero != DEFAULT
		&& flags->prsn == DEFAULT)
		ft_putchar('-', flags);
	if (flags->plus != DEFAULT && num >= 0
		&& flags->zero != DEFAULT && flags->prsn == DEFAULT)
	{
		ft_putchar('+', flags);
		(*i)++;
		flags->plus = DEFAULT;
	}
	if (num < 0)
		(*i)++;
	while ((*i)++ < flags->width - ft_strlen(str))
	{
		if ((*i) == flags->width - ft_strlen(str)
			&& flags->plus != DEFAULT && num >= 0)
			ft_putchar('+', flags);
		else
			(flags->zero == DEFAULT || flags->prsn != DEFAULT)
			? ft_putchar(' ', flags) : ft_putchar('0', flags);
	}
	if ((num < 0 && flags->zero == DEFAULT)
		|| (num < 0 && flags->prsn != DEFAULT))
		ft_putchar('-', flags);
	ft_putstr(str, flags);
}

static void	ft_width_more_prsn(t_flags *flags, int num, char *str)
{
	int	i;

	i = 0;
	if (flags->space != DEFAULT && flags->plus == DEFAULT && num >= 0)
	{
		ft_putchar(' ', flags);
		i++;
	}
	if (flags->prsn > ft_strlen(str))
		ft_wmp_prsn_more_digits(flags, num, str, &i);
	else
		ft_wmp_prsn_less_digits(flags, num, str, &i);
}

static void	ft_prsn_more_width(t_flags *flags, int num, char *str)
{
	int	i;

	i = 0;
	if (flags->space != DEFAULT && flags->plus == DEFAULT && num >= 0)
		ft_putchar(' ', flags);
	if (num < 0)
		ft_putchar('-', flags);
	else if (flags->plus != DEFAULT)
		ft_putchar('+', flags);
	while (i++ < flags->prsn - ft_strlen(str))
		ft_putchar('0', flags);
	ft_putstr(str, flags);
}

void		ft_print_int_on_right_side(t_flags *flags, int num)
{
	char	*str;
	int		nb;
	int		i;

	nb = (num < 0) ? num * (-1) : num;
	if (flags->prsn == 0 && num == 0)
		str = ft_strdup("");
	else if (num == -2147483648)
		str = ft_strdup("2147483648");
	else
		str = ft_itoa(nb);
	if (!str)
		flags->error = -1;
	i = 0;
	if ((flags->prsn == DEFAULT && flags->width == DEFAULT)
		|| (ft_strlen(str) > flags->width
			&& ft_strlen(str) > flags->prsn))
		ft_print_int_without_flags(flags, num);
	else if (flags->width > flags->prsn)
		ft_width_more_prsn(flags, num, str);
	else
		ft_prsn_more_width(flags, num, str);
	free(str);
}
