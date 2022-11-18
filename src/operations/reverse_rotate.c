/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 09:40:11 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/18 10:20:24 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Rotates in reverse the given stack once.
 * 
 * s: 1 2 3 4 5
 * 
 * r()
 * 
 * s: 5 1 2 3 4
 * 
 * @param pswap
 * @return int 1 if successful, 0 otherwise
 */
static int	ft_reverse_rotate_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*tmp;

	if (*stack == NULL || (*stack)->next == NULL)
		return (0);
	current = *stack;
	while (current->next->next)
		current = current->next;
	tmp = current->next;
	current->next = NULL;
	tmp->next = *stack;
	*stack = tmp;
	return (1);
}

/**
 * @brief Rotates in reverse the stack A once.
 * 
 * A: 1 2 3 4 5
 * 
 * rra()
 * 
 * A: 5 1 2 3 4
 * 
 * @param pswap
 * @return int "rra" if successful, NULL otherwise
 */
char	*ft_rra(t_pswap *pswap)
{
	if (!ft_reverse_rotate_stack(&pswap->a))
		return (NULL);
	return ("rra");
}

/**
 * @brief Rotates in reverse the stack B once.
 * 
 * B: 1 2 3 4 5
 * 
 * rrb()
 * 
 * B: 5 1 2 3 4
 * 
 * @param pswap
 * @return int "rrb" if successful, NULL otherwise
 */
char	*ft_rrb(t_pswap *pswap)
{
	if (!ft_reverse_rotate_stack(&pswap->b))
		return (NULL);
	return ("rrb");
}

/**
 * @brief Rotates in reverse the stacks A and B once each.
 * 
 * A: 1 2 3 4 5
 * B: 6 7 8 9 10
 * 
 * rrr()
 * 
 * A: 5 1 2 3 4
 * B: 10 6 7 8 9
 * 
 * @param pswap
 * @return int "rrr" if successful, NULL otherwise
 */
char	*ft_rrr(t_pswap *pswap)
{
	if (!ft_reverse_rotate_stack(&pswap->a))
		return (NULL);
	if (!ft_reverse_rotate_stack(&pswap->b))
		return (NULL);
	return ("rrr");
}
