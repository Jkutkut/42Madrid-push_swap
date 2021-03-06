/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_is_sorted.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 10:34:12 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/06/28 23:11:44 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"


int	list_is_sorted(t_list *lst, int type)
{
	int	i;

	if (!lst)
		return (1);
	i = lst->content;
	while (lst)
	{
		if (lst->content != i)
			return (0);
		i += type;
		lst = lst->next;
	}
	return (1);
}
