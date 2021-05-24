/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sbroderi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 15:03:38 by Sbroderi          #+#    #+#             */
/*   Updated: 2020/05/03 15:03:41 by Sbroderi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *s1)
{
	int		count;
	char	*str;

	count = 0;
	while (s1[count])
		count++;
	str = (char *)malloc(sizeof(*str) * count + 1);
	if (str == NULL)
		return (NULL);
	count = 0;
	while (s1[count] != '\0')
	{
		str[count] = s1[count];
		count++;
	}
	str[count] = '\0';
	return (str);
}
