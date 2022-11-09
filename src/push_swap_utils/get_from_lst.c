/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_from_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 21:03:51 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/09 20:07:48 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_from_lst(int (*f)(int, int), t_list *lst)
{
	int		val;
	t_list	*tmp;

	val = lst->content;
	tmp = lst;
	while (tmp)
	{
		val = f(val, tmp->content);
		tmp = tmp->next;
	}
	return (val);
}
