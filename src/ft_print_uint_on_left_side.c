/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint_on_left_side.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sbroderi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 13:46:54 by Sbroderi          #+#    #+#             */
/*   Updated: 2020/06/05 13:46:56 by Sbroderi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_wmp_prsn_more_digits(t_flags *flags,
									unsigned int num, char *str, int *i)
{
	size_t			j;
	int				size_num;

	size_num = (flags->type == T_HEX_L || flags->type == T_HEX_U) ?
				ft_strlen(str) : ft_digits_in_number(num);
	j = 0;
	while ((*i)++ < flags->prsn - size_num)
		ft_putchar('0', flags);
	(*i)--;
	while ((*i)++ < flags->prsn)
		ft_putchar(str[j++], flags);
	(*i)--;
	(*i) += (flags->plus != DEFAULT || flags->space != DEFAULT);
	while ((*i)++ < flags->width)
		ft_putchar(' ', flags);
}

static void	ft_wmp_prsn_less_digits(t_flags *flags, char *str, int *i)
{
	ft_putstr(str, flags);
	(*i) += ft_strlen(str);
	while ((*i)++ < flags->width)
		ft_putchar(' ', flags);
}

static void	ft_width_more_prsn(t_flags *flags, unsigned int num, char *str)
{
	int	i;
	int	size_num;

	size_num = (flags->type == T_HEX_L || flags->type == T_HEX_U) ?
				ft_strlen(str) : ft_digits_in_number(num);
	i = 0;
	if (flags->prsn > size_num)
		ft_wmp_prsn_more_digits(flags, num, str, &i);
	else
		ft_wmp_prsn_less_digits(flags, str, &i);
}

static void	ft_prsn_more_width(t_flags *flags, unsigned int num, char *str)
{
	int	i;
	int	size_num;

	size_num = (flags->type == T_HEX_L || flags->type == T_HEX_U) ?
				ft_strlen(str) : ft_digits_in_number(num);
	i = 0;
	while (i++ < flags->prsn - size_num)
		ft_putchar('0', flags);
	ft_putstr(str, flags);
}

void		ft_print_uint_on_left_side(t_flags *flags, unsigned int num)
{
	char	*str;
	int		i;
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
	flags->error = (str == NULL) ? -1 : 0;
	size_num = ft_strlen(str);
	i = 0;
	if ((flags->prsn == DEFAULT && flags->width == DEFAULT)
		|| (size_num > flags->width
			&& size_num > flags->prsn))
		ft_print_uint_without_flags(flags, num);
	else if (flags->width > flags->prsn)
		ft_width_more_prsn(flags, num, str);
	else
		ft_prsn_more_width(flags, num, str);
	free(str);
}
