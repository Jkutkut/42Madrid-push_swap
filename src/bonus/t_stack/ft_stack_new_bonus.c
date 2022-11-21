/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_new_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 17:59:52 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/21 12:07:26 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

/**
 * @brief Creates a new element of a stack and returns a pointer to it.
 * 
 * @param content Pointer to the content of the new element.
 * @return t_stack* Pointer to the new element.
 */
t_stack	*ft_stack_new(int content)
{
	t_stack	*e;

	e = malloc(sizeof(t_stack));
	if (e == NULL)
		return (NULL);
	e->content = content;
	e->next = NULL;
	return (e);
}
