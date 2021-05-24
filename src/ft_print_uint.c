/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sbroderi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 13:36:58 by Sbroderi          #+#    #+#             */
/*   Updated: 2020/06/05 13:37:00 by Sbroderi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_print_uint(t_flags *flags, unsigned int num)
{
	if (flags->minus == DEFAULT)
		ft_print_uint_on_right_side(flags, num);
	else
		ft_print_uint_on_left_side(flags, num);
}
