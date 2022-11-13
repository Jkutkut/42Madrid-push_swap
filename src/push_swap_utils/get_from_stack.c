/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_from_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 21:03:51 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/14 11:25:03 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_from_stack(int (*f)(int, int), t_stack *lst)
{
	int		val;
	t_stack	*tmp;

	val = lst->content;
	tmp = lst;
	while (tmp)
	{
		val = f(val, tmp->content);
		tmp = tmp->next;
	}
	return (val);
}
