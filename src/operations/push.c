/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 08:16:57 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/18 07:48:17 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Pushes the first element from the stack src to the stack dst.
 * 
 * src: 1 2 3
 * dst: 4 5 6
 * 
 * push(src, dst)
 * 
 * src: 2 3
 * dst: 1 4 5 6
 * 
 * @param src
 * @param dst
 * @return int 1 if successful, 0 otherwise.
 */
static int	push_stack(t_stack **src, t_stack **dst)
{
	t_stack	*tmp;

	if (!*src)
		return (0);
	tmp = *src;
	*src = tmp->next;
	tmp->next = *dst;
	*dst = tmp;
	return (1);
}

/**
 * @brief Pushes the first element from B to A
 * 
 * A: 1 2 3
 * B: 4 5 6
 * 
 * pa()
 * 
 * A: 4 1 2 3
 * B: 5 6
 * 
 * @param pswap
 * @return char* "pa" if successful, NULL otherwise
 */
char	*pa(t_dstack *pswap)
{
	if (!push_stack(&pswap->b, &pswap->a))
		return (NULL);
	return ("pa");
}

/**
 * @brief Pushes the first element from A to B
 * 
 * A: 1 2 3
 * B: 4 5 6
 * 
 * pb()
 * 
 * A: 2 3
 * B: 1 4 5 6
 * 
 * @param pswap
 * @return char* "pb" if successful, NULL otherwise
 */
char	*pb(t_dstack *pswap)
{
	if (!push_stack(&pswap->a, &pswap->b))
		return (NULL);
	return ("pb");
}
