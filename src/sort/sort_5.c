/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 09:16:21 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/18 10:12:58 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define REVERSE_ROTATE 3

/**
 * @brief Sends elements to B until there are exactly 3 elements in A.
 * 
 * Algorithm: (While A has more than 3 elements)
 * - If the current is the next value relative to the next position:
 *   - Swap positions (In the next iteration).
 * - Else if value too big, keep it on A.
 * - Else if second value is small, send that one (In the next iteration).
 * - Else if 1st value is greater than the last and the last is less than 3
 *   - Send the lower value (In the next iteration).
 * - Else:
 *   - Send the value to B.
 * @param pswap 
 */
static void	ft_send_to_b(t_pswap *pswap)
{
	while (ft_stack_len(pswap->a) > 3)
	{
		if (pswap->a->content == pswap->a->next->content + 1)
			ft_apply(pswap, SA);
		else if (pswap->a->content >= 4)
			ft_apply(pswap, RA);
		else if (pswap->a->content >= 3 && pswap->a->next->content <= 2)
			ft_apply(pswap, SA);
		else if (pswap->a->content > ft_stack_last(pswap->a)->content && \
				ft_stack_last(pswap->a)->content < 3)
			ft_apply(pswap, RRA);
		else
			ft_apply(pswap, PB);
	}
}

/**
 * @brief Sends the values from B back to A.
 * Once done, the stack A is sorted.
 *
 * Algorithm:
 * While B has elements:
 * - Get the spot where the value should be in A.
 * - Rotate (or reverse rotate) until the spot is ready to receive the value.
 * - Send the value to A.
 * If there is a need to rotate A to set it in the final position, doit.
 * 
 * @param pswap
 */
static void	ft_back_to_a(t_pswap *pswap)
{
	int	d;
	int	reverse;

	while (pswap->b)
	{
		d = ft_dist_to(pswap->b->content, pswap->a);
		reverse = 0;
		if (d >= ft_stack_len(pswap->a) - ft_stack_len(pswap->a) / 2)
		{
			d = ft_stack_len(pswap->a) - d;
			reverse = REVERSE_ROTATE;
		}
		while (d--)
			ft_apply(pswap, RA + reverse);
		ft_apply(pswap, PA);
	}
	if (ft_ready_just_rotate(pswap))
		ft_just_rotate(pswap, STACK_A);
}

/**
 * @brief Sort algorithm for stacks of 5 elements or less.
 * 
 * Algorithm:
 * If the stack can be sorted just by rotating it, it will do it.
 * Otherwise, elements are moved to B until there are only 3 left on A.
 * Then, sort_3 is called on A (Sorted) and B is also sorted (Inversed sort).
 * Finally, elements are moved back to A in order.
 * 
 * @param pswap
 */
void	ft_sort_5(t_pswap *pswap)
{
	if (ft_ready_just_rotate(pswap))
		return (ft_just_rotate(pswap, STACK_A));
	ft_send_to_b(pswap);
	ft_sort_3(pswap, STACK_A);
	if (ft_stack_len(pswap->b) == 2 && pswap->b->content < \
		pswap->b->next->content)
		ft_apply(pswap, SB);
	ft_back_to_a(pswap);
}
