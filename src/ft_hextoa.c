/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hextoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sbroderi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 11:09:43 by Sbroderi          #+#    #+#             */
/*   Updated: 2020/06/04 11:09:47 by Sbroderi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_swap_char(char *a, char *b)
{
	char	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static char	*ft_strrev(char *str)
{
	int	i;
	int	i_end;

	i = 0;
	i_end = 0;
	while (str[i_end] != '\0')
	{
		i_end++;
	}
	i_end--;
	while (i < i_end)
	{
		ft_swap_char(&str[i], &str[i_end]);
		i++;
		i_end--;
	}
	return (str);
}

char		*ft_hextoa(size_t n)
{
	char	*str;
	int		i;
	int		size;
	size_t	num;

	num = n;
	size = 0;
	i = 0;
	while (num / 16 != 0)
	{
		size++;
		num /= 16;
	}
	if (!(str = ft_calloc(size + 2, sizeof(char))))
		return (NULL);
	num = n;
	while (num / 16 != 0)
	{
		str[i++] = ((num % 16) < 10) ?
		('0' + (num % 16)) : ('a' + (num % 16 - 10));
		num /= 16;
	}
	str[i] = (num < 10) ? ('0' + num) : ('a' + (num % 10));
	return (ft_strrev(str));
}
