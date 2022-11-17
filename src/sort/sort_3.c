/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 17:15:54 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/17 15:35:09 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Sorts a stack of 3 elements.
 * 
 * @param pswap Structure with push_swap.
 * @param s Stack to sort
 * @param l Stack to rotate.
 * @param min min value of the 3.
 * @param max max value of the 3.
 */
static void	sort_tiny(t_dstack *pswap, t_tstack l, int min, int max)
{
	t_stack *s;

	s = pswap->a;
	if (l == STACK_B)
		s = pswap->b;
	if (s->content == min && s->next->content == max)
	{
		apply(pswap, RRA + l);
		apply(pswap, SA + l);
	}
	else if(s->next->content == min && s->content != max)
			apply(pswap, SA + l);
	else if(s->next->content == max && s->content != min)
		apply(pswap, RRA + l);
	else if (s->content == max && s->next->content == min)
		apply(pswap, RA + l);
	else if (s->content == max && s->next->content != min)
	{
		apply(pswap, SA + l);
		apply(pswap, RRA + l);
	}
}

/**
 * @brief Sort algorithm for a stack of 5 elements or less.
 * 
 * @param pswap
 * @param l Stack to sort.
 */
void	sort_3(t_dstack *pswap, t_tstack l)
{
	t_stack	*s;
	int		max;
	int		min;

	s = pswap->a;
	if (l == STACK_B)
		s = pswap->b;
	if (ft_stack_len(s) < 3)
	{
		if (ft_stack_len(s) == 2 && s->content > s->next->content)
			apply(pswap, SA + l);
		return ;
	}
	max = get_from_stack(ft_max, s);
	min = get_from_stack(ft_min, s);
	sort_tiny(pswap, l, min, max);
}
