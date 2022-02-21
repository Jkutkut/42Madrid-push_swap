/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:04:01 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/02/21 23:06:39 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_list.h"

t_list	*ft_lstnew(int);
void	ft_lstclear(t_list **lst, void (*del)(int));
void	ft_lstadd_back(t_list **lst, t_list *new);

t_list	*ft_lstmap(t_list *lst, int(*f)(int), void (*del)(int))
{
	t_list	*new;
	t_list	*tmp;

	if (lst == NULL || f == NULL)
		return (NULL);
	new = NULL;
	while (lst != NULL)
	{
		tmp = ft_lstnew(f(lst->content));
		if (tmp == NULL)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, tmp);
		lst = lst->next;
	}
	return (new);
}
