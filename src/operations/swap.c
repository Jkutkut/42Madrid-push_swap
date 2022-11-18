/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:39:14 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/18 10:03:29 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Swaps first 2 elements of the given stack.
 * 
 * s: 1 2 3 4 5
 * 
 * swap()
 * 
 * s: 2 1 3 4 5
 * 
 * @param pswap
 * @return int 1 if successful, 0 otherwise
 */
static int	ft_swap_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!*stack || !(*stack)->next)
		return (0);
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = *stack;
	*stack = tmp;
	return (1);
}

/**
 * @brief Swaps first 2 elements of A.
 * 
 * A: 1 2 3 4 5
 * B: 6 7 8 9 10
 * 
 * sa()
 * 
 * A: 2 1 3 4 5
 * B: 6 7 8 9 10
 * 
 * @param pswap 
 * @return int "sa" if successful, NULL otherwise
 */
char	*ft_sa(t_pswap *pswap)
{
	if (!ft_swap_stack(&pswap->a))
		return (NULL);
	return ("sa");
}

/**
 * @brief Swaps first 2 elements of B.
 * 
 * A: 1 2 3 4 5
 * B: 6 7 8 9 10
 * 
 * sb()
 * 
 * A: 1 2 3 4 5
 * B: 7 6 8 9 10
 * 
 * @param pswap 
 * @return int "sb" if successful, NULL otherwise
 */
char	*ft_sb(t_pswap *pswap)
{
	if (!ft_swap_stack(&pswap->b))
		return (NULL);
	return ("sb");
}

/**
 * @brief Swaps first 2 elements of A and B.
 * 
 * A: 1 2 3 4 5
 * B: 6 7 8 9 10
 * 
 * ss()
 * 
 * A: 2 1 3 4 5
 * B: 7 6 8 9 10
 * 
 * @param pswap 
 * @return int "ss" if successful, NULL otherwise
 */
char	*ft_ss(t_pswap *pswap)
{
	if (!ft_sa(pswap) || !ft_sb(pswap))
		return (NULL);
	return ("ss");
}
