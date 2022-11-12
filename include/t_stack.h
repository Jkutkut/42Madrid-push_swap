/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:59:46 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/12 19:46:41 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_STACK_H
#define T_STACK_H

#include <stdlib.h>

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}					t_stack;

void	ft_stack_addb(t_stack **stack, t_stack *new);
void	ft_stack_addf(t_stack **stack, t_stack *new);
void	ft_stack_clear(t_stack **stack);
void	ft_stack_del(t_stack *stack);
void	ft_stack_iter(t_stack *stack, int (*f)(int)); // TODO use to normalize
t_stack	*ft_stack_last(t_stack *stack);
int		ft_stack_len(t_stack *stack);
t_stack	*ft_stack_new(int value);
#endif
