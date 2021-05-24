/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sbroderi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 23:29:22 by Sbroderi          #+#    #+#             */
/*   Updated: 2020/04/29 23:29:27 by Sbroderi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str, t_flags *flags)
{
	int	index;

	index = 0;
	if (str != 0)
		while (str[index] != '\0')
			ft_putchar(str[index++], flags);
}
