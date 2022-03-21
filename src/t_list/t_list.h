/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_list.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:59:46 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/21 22:25:53 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef T_LIST_H
#define T_LIST_H

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}					t_list;

#include "../ft_pushswap.h"

t_list	*ft_lstnew(int value);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst);
void	ft_lstclear(t_list **lst);
void	ft_lstiter(t_list *lst, void (*f)(int));
t_list	*ft_lstmap(t_list *lst, int (*f)(int));

#endif
