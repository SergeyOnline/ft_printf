/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sbroderi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 12:05:22 by Sbroderi          #+#    #+#             */
/*   Updated: 2020/06/03 12:05:24 by Sbroderi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_print_int(t_flags *flags, int num)
{
	if (flags->minus == DEFAULT)
		ft_print_int_on_right_side(flags, num);
	else
		ft_print_int_on_left_side(flags, num);
}
