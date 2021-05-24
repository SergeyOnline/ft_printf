/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sbroderi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 17:12:57 by Sbroderi          #+#    #+#             */
/*   Updated: 2020/05/29 15:54:31 by Sbroderi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# define T_INT 'i'
# define T_DECIMAL 'd'
# define T_STRING 's'
# define T_CHAR 'c'
# define T_POINTER 'p'
# define T_UINT 'u'
# define T_HEX_L 'x'
# define T_HEX_U 'X'
# define PERCENT '%'
# define DEFAULT -1

typedef struct	s_flags
{
	int			prsn;
	char		type;
	int			width;
	int			minus;
	int			plus;
	int			space;
	int			offset;
	int			zero;
	int			result;
	int			error;
}				t_flags;

void			ft_default_flags(t_flags *flags);
void			ft_print_pointer(t_flags *flags, size_t p);
char			*ft_hextoa(size_t num);
void			ft_print_int_on_left_side(t_flags *flags, int num);
void			ft_print_int_on_right_side(t_flags *flags, int num);
void			ft_print_int_without_flags(t_flags *flags, int num);
void			ft_print_int(t_flags *flags, int num);
void			ft_print_uint_on_left_side(t_flags *flags, unsigned int num);
void			ft_print_uint_on_right_side(t_flags *flags, unsigned int num);
void			ft_print_uint_without_flags(t_flags *flags, unsigned int num);
void			ft_print_uint(t_flags *flags, unsigned int num);
void			ft_print_string(t_flags *flags, char *str);
int				ft_digits_in_number(int num);
void			ft_print_char(t_flags *flags, char ch);
char			*ft_strdup(const char *s1);
void			ft_putchar(char c, t_flags *flags);
void			ft_putstr(char *str, t_flags *flags);
int				ft_printf(const char *format, ...);
char			*ft_itoa(int n);
void			*ft_calloc(size_t count, size_t size);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_strlen(const char *s);
char			*ft_strjoin(char const *s1, char const *s2);
int				ft_atoi(const char *str);
char			*ft_uitoa(unsigned int n);
char			*ft_str_uppercase(char *str);

#endif
