/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 15:33:52 by mweerts           #+#    #+#             */
/*   Updated: 2020/05/01 15:34:59 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		close_event(void *param)
{
	t_game *game;

	game = (t_game*)param;
	quit(game);
	return (0);
}

int		ft_endswith(char *str, char *end)
{
	int i;
	int len;

	i = ft_strlen(end);
	if ((len = ft_strlen(str)) < i)
		return (0);
	while (i > 0)
	{
		if (str[len - i] != end[ft_strlen(end) - i])
			return (0);
		i--;
	}
	return (1);
}

int	ft_inrange(int i, int min, int max)
{
	return (i >= min && i < max);
}

size_t	ft_numberlen(int number, unsigned int baselen)
{
	size_t			res;
	unsigned int	un;

	res = 1 + (number < 0);
	un = (number < 0 ? -number : number);
	while (un / baselen > 0)
	{
		res++;
		un /= baselen;
	}
	return (res);
}

int	ft_onlypattern(char *str, char *pattern)
{
	int i;
	int j;
	int patternlen;

	patternlen = ft_strlen(pattern);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != pattern[j])
			return (0);
		i++;
		j++;
		j = j % patternlen;
	}
	return (1);
}