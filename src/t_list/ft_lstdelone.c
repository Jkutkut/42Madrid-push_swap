/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:03:33 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/02/21 23:07:46 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_list.h"

void	ft_lstdelone(t_list *lst, void (*del)(int))
{
	if (lst == NULL || del == NULL)
		return ;
	del(lst->content);
	free(lst);
}
