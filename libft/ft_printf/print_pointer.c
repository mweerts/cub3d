/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 10:03:42 by mweerts           #+#    #+#             */
/*   Updated: 2020/02/07 19:38:35 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	put_x(void)
{
	return (ft_putstr("0x"));
}

int			print_pointer(va_list ap, t_flag *flag)
{
	t_number	number;
	int			count;

	number = get_number_hex(ap, flag);
	count = ft_strlen(number.str) + 2;
	if (flag->precision == 0 && number.is_zero)
		count--;
	if (flag->minus || (flag->zero && flag->precision == -1))
		put_x();
	if (flag->minus && (!(flag->precision == 0 && number.is_zero)))
		ft_putstr(number.str);
	print_width(flag, &count);
	if (!flag->minus)
	{
		if (!flag->zero || (flag->zero && flag->precision != -1))
			put_x();
		if (!(flag->precision == 0 && number.is_zero))
			ft_putstr(number.str);
	}
	free(number.str);
	return (count);
}
