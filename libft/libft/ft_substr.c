/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 14:25:34 by mweerts           #+#    #+#             */
/*   Updated: 2019/11/12 16:32:53 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*substr;

	i = 0;
	if (s == NULL)
		return (NULL);
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
