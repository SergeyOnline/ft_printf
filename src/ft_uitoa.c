/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sbroderi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 13:20:43 by Sbroderi          #+#    #+#             */
/*   Updated: 2020/06/05 13:20:45 by Sbroderi         ###   ########.fr       */
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

char		*ft_uitoa(unsigned int n)
{
	unsigned int	num;
	char			*str;
	int				i;
	int				size;

	size = 0;
	i = 0;
	num = n;
	while (num / 10 != 0)
	{
		size++;
		num /= 10;
	}
	if (!(str = ft_calloc(size + 2, sizeof(char))))
		return (NULL);
	num = n;
	while (num / 10 > 0)
	{
		str[i++] = '0' + num % 10;
		num /= 10;
	}
	str[i++] = '0' + num % 10;
	return (ft_strrev(str));
}
