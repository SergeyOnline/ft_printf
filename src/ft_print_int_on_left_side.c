/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_on_left_side.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sbroderi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 14:21:18 by Sbroderi          #+#    #+#             */
/*   Updated: 2020/06/03 14:21:20 by Sbroderi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_wmp_prsn_more_digits(t_flags *flags,
									int num, char *str, int *i)
{
	int		j;

	j = 0;
	if (num < 0)
		ft_putchar('-', flags);
	if (flags->plus != DEFAULT && num >= 0)
		ft_putchar('+', flags);
	while ((*i)++ < flags->prsn - ft_strlen(str))
		ft_putchar('0', flags);
	(*i)--;
	while ((*i)++ < flags->prsn)
		ft_putchar(str[j++], flags);
	(*i)--;
	(*i) += (num < 0 || flags->plus != DEFAULT || flags->space != DEFAULT);
	while ((*i)++ < flags->width)
		ft_putchar(' ', flags);
}

static void	ft_wmp_prsn_less_digits(t_flags *flags,
									int num, char *str, int *i)
{
	if (num < 0)
	{
		ft_putchar('-', flags);
		(*i)++;
	}
	if (flags->plus != DEFAULT && num >= 0)
	{
		ft_putchar('+', flags);
		(*i)++;
	}
	ft_putstr(str, flags);
	(*i) += ft_strlen(str);
	while ((*i)++ < flags->width)
		ft_putchar(' ', flags);
}

static void	ft_width_more_prsn(t_flags *flags, int num, char *str)
{
	int i;

	i = 0;
	if (flags->space != DEFAULT && flags->plus == DEFAULT && num >= 0)
	{
		ft_putchar(' ', flags);
		if (flags->prsn < ft_strlen(str))
			i++;
	}
	if (flags->prsn > ft_strlen(str))
		ft_wmp_prsn_more_digits(flags, num, str, &i);
	else
		ft_wmp_prsn_less_digits(flags, num, str, &i);
}

static void	ft_prsn_more_width(t_flags *flags, int num, char *str)
{
	int i;

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

void		ft_print_int_on_left_side(t_flags *flags, int num)
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
		|| (ft_digits_in_number(num) > flags->width
			&& ft_digits_in_number(num) > flags->prsn))
		ft_print_int_without_flags(flags, num);
	else if (flags->width > flags->prsn)
		ft_width_more_prsn(flags, num, str);
	else
		ft_prsn_more_width(flags, num, str);
	free(str);
}
