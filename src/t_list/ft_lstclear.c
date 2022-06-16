/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:03:47 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/21 20:08:25 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_list.h"

void	ft_lstdelone(t_list *lst);

/**
 * @brief Destroys the given linked list.
 * 
 * @param lst Linked list.
 */
void	ft_lstclear(t_list **lst)
{
	if (lst == NULL || *lst == NULL)
		return ;
	ft_lstclear(&(*lst)->next);
	ft_lstdelone(*lst);
	*lst = NULL;
}
