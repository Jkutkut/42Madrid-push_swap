/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 09:16:21 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/09 20:02:25 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

# define REVERSE_ROTATE 3

void	sort_5(t_dstack *pswap)
{
	int	d;
	int reverse;

	if (ready_just_rotate(pswap))
		return just_rotate(pswap, 0);

	while (ft_lstsize(pswap->a) > 3)
	{
		// If the current is the next value relative to the next position -> swap positions
		if (pswap->a->content == pswap->a->next->content + 1)
			apply(pswap, SA);
		// If too big, keep it here
		else if (pswap->a->content >= 4)
			apply(pswap, RA);
		// If second value is small, send that one
		else if (pswap->a->content >= 3 && pswap->a->next->content <= 2)
			apply(pswap, SA);
		// If 1st value is greater than the last and the last is less than 3 -> send the lower
		else if (pswap->a->content > ft_lstlast(pswap->a)->content && ft_lstlast(pswap->a)->content < 3)
			apply(pswap, RRA);
		else
			apply(pswap, PB);
	}
	sort_3(pswap, 0);

	if (ft_lstsize(pswap->b) == 2 && pswap->b->content < pswap->b->next->content)
		apply(pswap, SB);

	while (pswap->b)
	{
		// Get distance to correct spot in stack a
		d = dist_to(pswap->b->content, pswap->a);
		reverse = 0;
		// Check the fastest way to get there
		// TODO refactor with sortest_dist_to
		if (d >= ft_lstsize(pswap->a) - ft_lstsize(pswap->a) / 2)
		{
			d = ft_lstsize(pswap->a) - d;
			reverse = REVERSE_ROTATE;
		}
		while (d--)
			apply(pswap, RA + reverse);
		apply(pswap, PA);
	}
	if (ready_just_rotate(pswap))
		just_rotate(pswap, 0);
}
