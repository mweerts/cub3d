/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 19:44:58 by mweerts           #+#    #+#             */
/*   Updated: 2020/05/03 13:38:45 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_create(int c, int len)
{
	char	*str;

	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_memset(str, c, len);
	str[len] = '\0';
	return (str);
}
