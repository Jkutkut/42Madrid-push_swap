/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_is_sorted.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 10:34:12 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/09 20:02:59 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


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
