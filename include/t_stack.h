/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:59:46 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/17 13:43:18 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_STACK_H
# define T_STACK_H

# include "push_swap.h"

void	ft_stack_addb(t_stack **stack, t_stack *new);
void	ft_stack_addf(t_stack **stack, t_stack *new);
void	ft_stack_clear(t_stack **stack);
void	ft_stack_del(t_stack *stack);
t_stack	*ft_stack_last(t_stack *stack);
int		ft_stack_len(t_stack *stack);
t_stack	*ft_stack_new(int value);

#endif
