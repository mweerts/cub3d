/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 06:01:34 by mweerts           #+#    #+#             */
/*   Updated: 2020/02/07 19:38:40 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*get_string(va_list ap)
{
	char	*str;

	str = va_arg(ap, char*);
	if (str == NULL)
		return (ft_strdup("(null)"));
	return (ft_strdup(str));
}

static	int		ft_putstr_max(const char *str, int max)
{
	if (!str)
		return (0);
	if (max != -1 && (int)ft_strlen(str) > max)
	{
		write(1, str, max);
		return (max);
	}
	write(1, str, ft_strlen(str));
	return (ft_strlen(str));
}

int				print_string(va_list ap, t_flag *flag)
{
	char	*str;
	int		count;

	count = 0;
	str = get_string(ap);
	if (flag->precision != -1 && (int)ft_strlen(str) > flag->precision)
		count = flag->precision;
	else
		count = ft_strlen(str);
	if (flag->minus)
		ft_putstr_max(str, flag->precision);
	while (flag->width > count)
	{
		if (flag->zero && !flag->minus)
			count += ft_putchar('0');
		else
			count += ft_putchar(' ');
	}
	if (!flag->minus)
		ft_putstr_max(str, flag->precision);
	free(str);
	return (count);
}
