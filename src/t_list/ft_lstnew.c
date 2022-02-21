/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 17:59:52 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/02/21 22:48:08 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_list.h"

t_list	*ft_lstnew(int value)
{
	t_list	*e;

	e = malloc(sizeof(t_list));
	if (e == NULL)
		return (NULL);
	e->content = value;
	e->next = NULL;
	return (e);
}
