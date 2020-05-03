/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 10:01:50 by mweerts           #+#    #+#             */
/*   Updated: 2020/02/07 19:38:31 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_percent(t_flag *flag)
{
	int	count;

	count = 1;
	if (flag->minus)
		ft_putchar('%');
	while (flag->width > count)
	{
		if (flag->zero && !flag->minus)
			count += ft_putchar('0');
		else
			count += ft_putchar(' ');
	}
	if (!flag->minus)
		ft_putchar('%');
	return (count);
}
