/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 10:21:19 by mweerts           #+#    #+#             */
/*   Updated: 2020/02/07 19:38:44 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	t_number	get_number(va_list ap, t_flag *flag)
{
	t_number				number;
	unsigned long	long	nbr;

	number.len = 0;
	nbr = 0;
	if (flag->ll)
		nbr = va_arg(ap, unsigned long long int);
	else if (flag->hh)
		nbr = (unsigned long long)(unsigned char)va_arg(ap, int);
	else if (flag->l)
		nbr = (unsigned long long)va_arg(ap, unsigned long int);
	else if (flag->h)
		nbr = (unsigned long long)(unsigned short int)va_arg(ap, int);
	else
		nbr = (unsigned long long)va_arg(ap, unsigned int);
	number.sign = '+';
	if (nbr == 0)
		number.is_zero = 1;
	else
		number.is_zero = 0;
	ft_ulonglongtoa(nbr, &number, flag->precision);
	return (number);
}

int					print_uint(va_list ap, t_flag *flag)
{
	t_number	nbr;
	int			count;

	nbr = get_number(ap, flag);
	count = nbr.len;
	if (nbr.is_zero == 1 && flag->precision == 0)
		count = 0;
	if (flag->minus && (!(flag->precision == 0 && nbr.is_zero == 1)))
		ft_putstr(nbr.str);
	print_width(flag, &count);
	if (!flag->minus && (!(flag->precision == 0 && nbr.is_zero == 1)))
		ft_putstr(nbr.str);
	free(nbr.str);
	return (count);
}
