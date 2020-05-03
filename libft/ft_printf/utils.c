/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 13:52:33 by mweerts           #+#    #+#             */
/*   Updated: 2020/02/07 19:38:47 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ulonglong_len(unsigned long long nbr)
{
	int count;

	count = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr = nbr / 10;
		count++;
	}
	return (count);
}

int			ft_isformat(int c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd'
		|| c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%')
	{
		return (1);
	}
	return (0);
}

void		print_width(t_flag *flag, int *count)
{
	while (flag->width > *count)
	{
		if (flag->zero && !flag->minus && flag->precision == -1)
			*count += ft_putchar('0');
		else
			*count += ft_putchar(' ');
	}
}

int			ft_ulonglongtoa(unsigned long long nbr,
							t_number *number, int precision)
{
	char	*str;
	int		i;

	number->len = ulonglong_len(nbr);
	if (number->len < precision)
		number->len = precision;
	i = number->len;
	if (!(str = ft_str_create('0', number->len)))
		return (0);
	str[i--] = '\0';
	if (nbr == 0)
		str[0] = '0';
	while (nbr != 0)
	{
		str[i] = (nbr % 10) + '0';
		nbr /= 10;
		i--;
	}
	number->str = str;
	return (1);
}
