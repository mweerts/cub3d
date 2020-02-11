/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:14:41 by mweerts           #+#    #+#             */
/*   Updated: 2019/11/12 16:33:03 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;
	char		*str;

	str = (char *)haystack;
	i = 0;
	if (!(*needle))
		return (str);
	while (str[i] && i <= len)
	{
		j = 0;
		while ((str[i + j] == needle[j] || needle[j] == 0) && i + j <= len)
		{
			if (needle[j] == 0)
			{
				while (i--)
					str++;
				return (str);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}
