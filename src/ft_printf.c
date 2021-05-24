/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sbroderi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 12:16:15 by Sbroderi          #+#    #+#             */
/*   Updated: 2020/05/22 12:16:18 by Sbroderi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_fill_basic_flags(char ch, t_flags **flags)
{
	if (ch == ' ')
		(*flags)->space = 1;
	else if (ch == '+')
		(*flags)->plus = 1;
	else if (ch == '-')
		(*flags)->minus = 1;
	else if (ch == '0')
		(*flags)->zero = 1;
}

int			ft_check_symbol_for_flag_values(char ch, t_flags *fl)
{
	int result;

	result = (ch != T_INT && ch != T_CHAR && ch != T_STRING
			&& ch != T_DECIMAL && ch != T_POINTER && ch != T_UINT
			&& ch != T_HEX_L && ch != T_HEX_U && ch != PERCENT
			&& ch != '\0');
	if (result)
		ft_fill_basic_flags(ch, &fl);
	return (result);
}

t_flags		*ft_flags_handler(char *s, t_flags *fl, va_list ap)
{
	int	i;

	i = 0;
	while ((ft_check_symbol_for_flag_values(s[i], fl)))
	{
		if (((s[i] >= '1' && s[i] <= '9') || s[i] == '*')
			&& fl->width < 0 && fl->prsn < 0)
		{
			fl->width = (s[i] == '*') ? va_arg(ap, int) : ft_atoi(&s[i]);
			fl->minus = (fl->width < 0) ? 1 : fl->minus;
			fl->width = (fl->width < 0) ? (fl->width * (-1)) : fl->width;
			i += (s[i] == '*') ? 0 : ft_digits_in_number(fl->width) - 1;
		}
		else if (s[i] == '.' && fl->prsn < 0)
		{
			fl->prsn = (s[i + 1] == '*') ? va_arg(ap, int) : ft_atoi(&s[++i]);
			fl->prsn = (fl->prsn < 0) ? DEFAULT : fl->prsn;
			i += (s[i] == '*') ? 0 :
				ft_digits_in_number(fl->prsn) - 1 - (fl->prsn == 0);
		}
		i++;
	}
	fl->offset = i + 1;
	fl->type = s[i];
	return (fl);
}

void		ft_type_selector(t_flags *flags, char *f_str, va_list ap)
{
	char *tmp_str;

	ft_default_flags(flags);
	ft_flags_handler(f_str, flags, ap);
	if (flags->type == T_CHAR)
		ft_print_char(flags, va_arg(ap, int));
	else if (flags->type == PERCENT)
		ft_print_char(flags, PERCENT);
	else if (flags->type == T_STRING)
	{
		tmp_str = va_arg(ap, char *);
		(tmp_str == NULL) ? ft_print_string(flags, "(null)")
		: ft_print_string(flags, tmp_str);
	}
	else if (flags->type == T_INT || flags->type == T_DECIMAL)
		ft_print_int(flags, va_arg(ap, int));
	else if (flags->type == T_POINTER)
		ft_print_pointer(flags, va_arg(ap, size_t));
	else if (flags->type == T_UINT || flags->type == T_HEX_L
		|| flags->type == T_HEX_U)
		ft_print_uint(flags, va_arg(ap, unsigned int));
}

int			ft_printf(const char *format, ...)
{
	va_list ap;
	int		i;
	t_flags	flags;

	flags.result = 0;
	flags.error = 0;
	i = 0;
	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '\%')
		{
			i++;
			ft_type_selector(&flags, (char *)&format[i], ap);
			i += flags.offset;
			continue;
		}
		ft_putchar(format[i], &flags);
		i++;
	}
	va_end(ap);
	if (flags.error == -1)
		return (-1);
	return (flags.result);
}
