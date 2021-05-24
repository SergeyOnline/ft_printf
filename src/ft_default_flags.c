/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_default_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sbroderi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 12:06:00 by Sbroderi          #+#    #+#             */
/*   Updated: 2020/06/06 12:06:02 by Sbroderi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_default_flags(t_flags *flags)
{
	flags->type = '\0';
	flags->minus = DEFAULT;
	flags->plus = DEFAULT;
	flags->space = DEFAULT;
	flags->width = DEFAULT;
	flags->prsn = DEFAULT;
	flags->zero = DEFAULT;
	flags->offset = 0;
}
