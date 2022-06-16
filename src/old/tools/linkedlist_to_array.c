/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist_to_array.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 22:00:58 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/22 22:01:18 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

int	*linkedlist_to_array(t_list *lst, int size)
{
	int		*array;
	int		i;
	t_list	*tmp;

	array = (int *) malloc(sizeof(int) * size);
	if (!array)
		return (NULL);
	i = 0;
	tmp = lst;
	while (tmp)
	{
		array[i++] = tmp->content;
		tmp = tmp->next;
	}
	return (array);
}