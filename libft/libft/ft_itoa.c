/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:20:23 by mweerts           #+#    #+#             */
/*   Updated: 2020/05/03 13:26:23 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_intlen(int n)
{
	int nb_char;

	nb_char = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		nb_char++;
	}
	return (nb_char);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		is_neg;
	int		i;

	i = ft_intlen(n);
	is_neg = 0;
	if (n < 0)
		is_neg = 1;
	str = malloc(sizeof(char) * (i + is_neg + 1));
	if (str == NULL)
		return (NULL);
	str[i + 1] = '\0';
	if (n < 0)
		str[0] = '-';
	else if (n == 0)
		str[0] = '0';
	else
		i--;
	while (n != 0)
	{
		str[i] = ft_abs((n % 10)) + '0';
		n /= 10;
		i--;
	}
	return (str);
}
