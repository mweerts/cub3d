/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstat_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 15:55:56 by mweerts           #+#    #+#             */
/*   Updated: 2020/05/01 15:56:32 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstat(t_list *list, size_t index)
{
	size_t i;

	i = 0;
	if (!list)
		return (0);
	while (i < index && list)
	{
		list = list->next;
		i++;
	}
	return (list);
}
