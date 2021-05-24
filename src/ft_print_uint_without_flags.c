/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint_without_flags.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sbroderi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 13:58:50 by Sbroderi          #+#    #+#             */
/*   Updated: 2020/06/05 13:58:52 by Sbroderi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_uint_without_flags(t_flags *flags, unsigned int num)
{
	char	*str;

	if (flags->prsn == 0 && num == 0)
		str = ft_strdup("");
	else
	{
		str = (flags->type == T_HEX_L || flags->type == T_HEX_U) ?
				ft_hextoa(num) : ft_uitoa(num);
		if (flags->type == T_HEX_U)
			str = ft_str_uppercase(str);
	}
	if (!str)
		flags->error = -1;
	ft_putstr(str, flags);
	free(str);
}
