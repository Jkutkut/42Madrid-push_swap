/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:03:54 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/02/21 23:07:17 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_list.h"

void	ft_lstiter(t_list *lst, void (*f)(int))
{
	if (lst == NULL)
		return ;
	f(lst->content);
	if (lst->next != NULL)
		ft_lstiter(lst->next, f);
}
