/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_forced.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 18:56:43 by mweerts           #+#    #+#             */
/*   Updated: 2020/02/07 19:23:30 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr_forced(const char *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*substr;

	i = 0;
	if (s == NULL)
	{
		substr = malloc(sizeof(char));
		if (substr == NULL)
			return (NULL);
		substr[0] = '\0';
		return (substr);
	}
	substr = malloc(sizeof(char) * (len + 1));
	if (substr == NULL)
		return (NULL);
	if (start <= ft_strlen(s))
	{
		while (i < len)
			substr[i++] = s[start++];
	}
	substr[i] = '\0';
	return (substr);
}