/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 09:40:11 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/18 10:02:48 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Rotates the given stack once.
 * 
 * s: 1 2 3 4 5
 * 
 * r()
 * 
 * s: 2 3 4 5 1
 * 
 * @param pswap
 * @return int 1 if successful, 0 otherwise
 */
static int	ft_rotate_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (*stack == NULL || (*stack)->next == NULL)
		return (0);
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	ft_stack_last(*stack)->next = tmp;
	return (1);
}

/**
 * @brief Rotates the stack A once.
 * 
 * A: 1 2 3 4 5
 * B: 6 7 8 9 10
 * 
 * ra()
 * 
 * A: 2 3 4 5 1
 * B: 6 7 8 9 10
 * 
 * @param pswap
 * @return int "ra" if successful, NULL otherwise
 */
char	*ft_ra(t_pswap *pswap)
{
	if (!ft_rotate_stack(&pswap->a))
		return (NULL);
	return ("ra");
}

/**
 * @brief Rotates the stack B once.
 * 
 * A: 1 2 3 4 5
 * B: 6 7 8 9 10
 * 
 * rb()
 * 
 * A: 1 2 3 4 5
 * B: 7 8 9 10 6
 * 
 * @param pswap
 * @return int "rb" if successful, NULL otherwise
 */
char	*ft_rb(t_pswap *pswap)
{
	if (!ft_rotate_stack(&pswap->b))
		return (NULL);
	return ("rb");
}

/**
 * @brief Rotates the stack A and B once.
 * 
 * A: 1 2 3 4 5
 * B: 1 2 3 4 5
 * 
 * rr()
 * 
 * A: 2 3 4 5 1
 * B: 2 3 4 5 1
 * 
 * @param pswap
 * @return int "rr" if successful, NULL otherwise
 */
char	*ft_rr(t_pswap *pswap)
{
	if (!ft_rotate_stack(&pswap->a) || !ft_rotate_stack(&pswap->b))
		return (NULL);
	return ("rr");
}
