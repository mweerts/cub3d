/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 14:33:55 by mweerts           #+#    #+#             */
/*   Updated: 2020/05/03 19:15:58 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_is_wall(char c)
{
	if (c == '1' || c == ' ')
		return (1);
	return (0);
}

char	*ft_strjoin_point(char *s1, char *s2)
{
	int		i;
	int		n;
	int		len_s;
	char	*new_s;

	i = 0;
	len_s = ft_strlen(s1) + ft_strlen(s2);
	new_s = (char *)malloc(sizeof(char) * (len_s + 2));
	if (new_s == NULL)
		return (0);
	while (s1[i])
	{
		new_s[i] = s1[i];
		i++;
	}
	n = 0;
	while (s2[n])
		new_s[i++] = s2[n++];
	new_s[i++] = '.';
	new_s[i] = '\0';
	free(s1);
	return (new_s);
}

char	*ft_strdup_map(char *s)
{
	int		i;
	char	*dest;

	i = 0;
	while (s[i])
		i++;
	if (!(dest = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == ' ')
			dest[i] = '1';
		else
			dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	free(s);
	return (dest);
}
