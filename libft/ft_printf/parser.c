/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 08:24:45 by mweerts           #+#    #+#             */
/*   Updated: 2020/02/07 19:38:15 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	init_flag(t_flag *flag)
{
	flag->minus = 0;
	flag->plus = 0;
	flag->zero = 0;
	flag->width = -1;
	flag->precision = -1;
	flag->format = 0;
	flag->l = 0;
	flag->ll = 0;
	flag->h = 0;
	flag->hh = 0;
	flag->blank = 0;
	flag->diese = 0;
}

static int		parse_star(t_flag *flag, va_list ap, char is_preci)
{
	int nbr;

	nbr = va_arg(ap, int);
	if (!is_preci)
	{
		if (nbr < 0)
			flag->minus = 1;
		return (ft_abs(nbr));
	}
	else
	{
		if (nbr < 0)
			nbr = -1;
		return (nbr);
	}
}

static	void	simple_flag(char c, t_flag *flag)
{
	if (c == '-')
		flag->minus = 1;
	else if (c == '+')
		flag->plus = 1;
	else if (c == '0')
		flag->zero = 1;
	else if (c == '#')
		flag->diese = 1;
	else if (c == ' ')
		flag->blank = 1;
	else if (c == 'l')
	{
		if (flag->l == 1)
			flag->ll = 1;
		flag->l = 1;
	}
	else if (c == 'h')
	{
		if (flag->h == 1)
			flag->hh = 1;
		else
			flag->h = 1;
	}
}

static int		ft_atoi_printf(const char *str, int *width)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i] - 48);
		i++;
	}
	*width = nbr;
	return (i);
}

t_flag			parse(const char *str, va_list ap, int *index)
{
	int		i;
	t_flag	flag;

	i = 0;
	init_flag(&flag);
	while (str[i] && !ft_isformat(str[i]))
	{
		if (ft_isdigit(str[i]) && str[i] != '0')
			i += ft_atoi_printf(&str[i], &flag.width) - 1;
		else if (str[i] == '.')
		{
			if (str[++i] == '*')
				flag.precision = parse_star(&flag, ap, 1);
			else
				i += ft_atoi_printf(&str[i], &flag.precision) - 1;
		}
		else if (str[i] == '*')
			flag.width = parse_star(&flag, ap, 0);
		else
			simple_flag(str[i], &flag);
		i++;
	}
	flag.format = ft_isformat(str[i]) ? str[i++] : 0;
	*index += i;
	return (flag);
}
