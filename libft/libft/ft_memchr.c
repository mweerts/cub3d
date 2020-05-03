/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 14:00:16 by mweerts           #+#    #+#             */
/*   Updated: 2019/11/19 17:16:16 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*psrc;

	i = 0;
	psrc = (unsigned char*)s;
	while (i < n)
	{
		if (psrc[i] == (unsigned char)c)
			return ((void*)s + i);
		i++;
	}
	return (NULL);
}
