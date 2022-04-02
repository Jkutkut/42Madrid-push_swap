/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_from_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 21:03:51 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/02 21:07:18 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

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