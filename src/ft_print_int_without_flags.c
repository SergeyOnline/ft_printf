/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_without_flags.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sbroderi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 14:18:09 by Sbroderi          #+#    #+#             */
/*   Updated: 2020/06/03 14:18:11 by Sbroderi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_int_without_flags(t_flags *flags, int num)
{
	char	*str;
	int		nb;

	nb = (num < 0) ? num * (-1) : num;
	if (flags->prsn == 0 && num == 0)
		str = ft_strdup("");
	else if (num == -2147483648)
		str = ft_strdup("2147483648");
	else
		str = ft_itoa(nb);
	if (!str)
		flags->error = -1;
	if (flags->space != DEFAULT && flags->plus == DEFAULT && num >= 0)
		ft_putchar(' ', flags);
	if (num < 0)
		ft_putchar('-', flags);
	if (num >= 0 && flags->plus != DEFAULT)
		ft_putchar('+', flags);
	ft_putstr(str, flags);
	free(str);
}
