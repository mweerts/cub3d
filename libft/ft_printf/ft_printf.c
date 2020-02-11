/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 15:33:28 by mweerts           #+#    #+#             */
/*   Updated: 2020/02/07 19:38:06 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_convert	g_tab[] = {
	{'c', &print_char},
	{'s', &print_string},
	{'p', &print_pointer},
	{'d', &print_int},
	{'i', &print_int},
	{'u', &print_uint},
	{'x', &print_hex},
	{'X', &print_hex},
	{-1, NULL}};

static	int		get_format(char format, va_list ap, t_flag *flag)
{
	int	i;

	i = 0;
	while (g_tab[i].c != -1)
	{
		if (g_tab[i].c == format)
			return (g_tab[i].function(ap, flag));
		else if (format == '%')
			return (print_percent(flag));
		i++;
	}
	return (-1);
}

static	int		ft_print_flag(const char *str, va_list ap, int *index)
{
	t_flag	flag;
	int		count;

	count = 0;
	flag = parse(str, ap, index);
	count += get_format(flag.format, ap, &flag);
	return (count);
}

int				ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(ap, str);
	while (str && str[i])
	{
		if (str[i] != '%')
		{
			write(1, &str[i], 1);
			count++;
		}
		else
			count += ft_print_flag(&str[i + 1], ap, &i);
		i++;
	}
	va_end(ap);
	return (count);
}
