/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sbroderi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 11:30:39 by Sbroderi          #+#    #+#             */
/*   Updated: 2020/06/05 11:30:42 by Sbroderi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	*ft_memset(void *b, int c, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
		((unsigned char *)b)[i++] = (unsigned char)c;
	return (b);
}

void		ft_print_pointer(t_flags *flags, size_t p)
{
	char	*tmp_str;
	char	*zero_str;
	char	*tmp;
	int		size;

	tmp_str = ft_hextoa(p);
	size = ft_strlen(tmp_str);
	if (flags->prsn <= size + 2)
		flags->prsn = DEFAULT;
	else
	{
		zero_str = (char*)ft_calloc((flags->prsn - size + 3), sizeof(char));
		ft_memset(zero_str, '0', (flags->prsn - size));
		tmp = tmp_str;
		tmp_str = ft_strjoin(zero_str, tmp_str);
		free(tmp);
		flags->prsn += 2;
		free(zero_str);
	}
	tmp = tmp_str;
	tmp_str = ft_strjoin("0x", tmp_str);
	free(tmp);
	ft_print_string(flags, tmp_str);
	free(tmp_str);
}
